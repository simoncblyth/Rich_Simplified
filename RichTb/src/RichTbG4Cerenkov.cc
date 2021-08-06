//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: RichTbG4Cerenkov.cc,v 1.17 2004/12/10 18:49:57 gcosmo Exp $
// GEANT4 tag $Name: geant4-07-00 $
//
////////////////////////////////////////////////////////////////////////
// Cerenkov Radiation Class Implementation
////////////////////////////////////////////////////////////////////////
//
// File:        RichTbG4Cerenkov.cc 
// Description: Continuous Process -- Generation of Cerenkov Photons
// Version:     2.1
// Created:     1996-02-21  
// Author:      Juliet Armstrong
// Updated:     2001-09-17, migration of Materials to pure STL (mma) 
//              2000-11-12 by Peter Gumplinger
//              > add check on CerenkovAngleIntegrals->IsFilledVectorExist()
//              in method GetAverageNumberOfPhotons 
//              > and a test for MeanNumPhotons <= 0.0 in DoIt
//              2000-09-18 by Peter Gumplinger
//              > change: aSecondaryPosition=x0+rand*aStep.GetDeltaPosition();
//                        aSecondaryTrack->SetTouchable(0);
//              1999-10-29 by Peter Gumplinger
//              > change: == into <= in GetContinuousStepLimit
//              1997-08-08 by Peter Gumplinger
//              > add protection against /0
//              > G4MaterialPropertiesTable; new physics/tracking scheme
//
// mail:        gum@triumf.ca
// modifed  Se 1-3-2005 to extract some values to the usertrack for output.
//        renamed the class.
////////////////////////////////////////////////////////////////////////

#include "G4ios.hh"
#include "G4Poisson.hh"
#include "RichTbG4Cerenkov.hh"
#include "RichTbPhotonUserInfoAttach.hh"
#include "RichTbPhotonProdHisto.hh"

using namespace std;

/////////////////////////
// Class Implementation  
/////////////////////////

        //////////////
        // Operators
        //////////////

// RichTbG4Cerenkov::operator=(const RichTbG4Cerenkov &right)
// {
// }

        /////////////////
        // Constructors
        /////////////////

RichTbG4Cerenkov::RichTbG4Cerenkov(const G4String& processName)
           : G4VContinuousProcess(processName)
{
	fTrackSecondariesFirst = false;
	fMaxPhotons = 0;

        thePhysicsTable = NULL;

	if (verboseLevel>0) {
           G4cout << GetProcessName() << " is created " << G4endl;
	}

	BuildThePhysicsTable();
}

// RichTbG4Cerenkov::RichTbG4Cerenkov(const RichTbG4Cerenkov &right)
// {
// }

        ////////////////
        // Destructors
        ////////////////

RichTbG4Cerenkov::~RichTbG4Cerenkov() 
{
	if (thePhysicsTable != NULL) {
	   thePhysicsTable->clearAndDestroy();
           delete thePhysicsTable;
	}
}

        ////////////
        // Methods
        ////////////

// AlongStepDoIt
// -------------
//
G4VParticleChange*
RichTbG4Cerenkov::AlongStepDoIt(const G4Track& aTrack, const G4Step& aStep)

// This routine is called for each tracking Step of a charged particle
// in a radiator. A Poisson-distributed number of photons is generated
// according to the Cerenkov formula, distributed evenly along the track
// segment and uniformly azimuth w.r.t. the particle direction. The 
// parameters are then transformed into the Master Reference System, and 
// they are added to the particle change. 

{
	//////////////////////////////////////////////////////
	// Should we ensure that the material is dispersive?
	//////////////////////////////////////////////////////

        aParticleChange.Initialize(aTrack);

	//        G4cout<<" G4Cerenkov ch trackid stepnum "<<aTrack.GetTrackID()<<"  "<<aTrack.GetCurrentStepNumber() <<G4endl;
        const G4DynamicParticle* aParticle = aTrack.GetDynamicParticle();
        const G4Material* aMaterial = aTrack.GetMaterial();

	G4StepPoint* pPreStepPoint  = aStep.GetPreStepPoint();
	G4StepPoint* pPostStepPoint = aStep.GetPostStepPoint();

  //test print
  //    const G4String & aPreVolName=  pPreStepPoint ->GetPhysicalVolume()->GetLogicalVolume()->GetName();
  //   const G4String & aPostVolName=  pPostStepPoint ->GetPhysicalVolume()->GetLogicalVolume()->GetName();


     //G4cout<<"  Cherenkov prod preVolname  postVolname   "<<aPreVolName  << "   "<< aPostVolName<<  G4endl;
     // G4cout<<" Cherenkov pre psot location "<<  pPreStepPoint->GetPosition()<<"   "<<  pPostStepPoint ->GetPosition()<<G4endl;
    

  //end test print


	G4ThreeVector x0 = pPreStepPoint->GetPosition();
        G4ThreeVector p0 = aStep.GetDeltaPosition().unit();
	G4double t0 = pPreStepPoint->GetGlobalTime();

        G4MaterialPropertiesTable* aMaterialPropertiesTable =
                               aMaterial->GetMaterialPropertiesTable();
        if (!aMaterialPropertiesTable)
           return G4VContinuousProcess::AlongStepDoIt(aTrack, aStep);

	       G4MaterialPropertyVector* Rindex = 
                aMaterialPropertiesTable->GetProperty("CKVRNDX"); 
        if (!Rindex) 
	   return G4VContinuousProcess::AlongStepDoIt(aTrack, aStep);

	G4double MeanNumPhotons = 
                 GetAverageNumberOfPhotons(aParticle,aMaterial,Rindex);


  //  if( aPreVolName == "LTSampleAPHCLog" ) {  

  //   G4cout <<" PHC sample  "<<G4endl;
    
  //  G4cout<< "Cherenkov prod MeanNumphot prod  " << aPreVolName <<"   "<< MeanNumPhotons<<G4endl;
  //  }
  

        if (MeanNumPhotons <= 0.0) {

                // return unchanged particle and no secondaries

                aParticleChange.SetNumberOfSecondaries(0);
 
                return G4VContinuousProcess::AlongStepDoIt(aTrack, aStep);

        }

        G4double step_length;
        step_length = aStep.GetStepLength();
	//	G4cout<<"G4Cerenkov MeanNumPhot steplen zpre zpost "<< MeanNumPhotons<<"  "<<step_length<<"   "
        //      << (pPreStepPoint->GetPosition()).z()<<"   "<<(pPostStepPoint->GetPosition()).z()<< G4endl;

	MeanNumPhotons = MeanNumPhotons * step_length;


	G4int NumPhotons = (G4int) G4Poisson(MeanNumPhotons);

	if (NumPhotons <= 0) {

		// return unchanged particle and no secondaries  

		aParticleChange.SetNumberOfSecondaries(0);
		
                return G4VContinuousProcess::AlongStepDoIt(aTrack, aStep);
	}

	////////////////////////////////////////////////////////////////

	aParticleChange.SetNumberOfSecondaries(NumPhotons);

        if (fTrackSecondariesFirst) {
           if (aTrack.GetTrackStatus() == fAlive )
                   aParticleChange.ProposeTrackStatus(fSuspend);
        }
	
	////////////////////////////////////////////////////////////////

        //	G4double Pmin = Rindex->GetMinPhotonMomentum();
        //	G4double Pmax = Rindex->GetMaxPhotonMomentum();

  G4double Pmin = Rindex->GetMinLowEdgeEnergy(); // for G4.95 onwards
  G4double Pmax = Rindex->GetMaxLowEdgeEnergy();  //for G4.95.onwards


	G4double dp = Pmax - Pmin;

  //	G4double nMax = Rindex->GetMaxProperty();
  //	G4double nMin = Rindex->GetMinValue();	
	G4double nMax = Rindex->GetMaxValue();

        G4double BetaInverse = aParticle->GetTotalEnergy() /
	   	 	       aParticle->GetTotalMomentum();

        // G4cout<<" RichG4Cerenkov energy mom betainverse max refindex "<<
        //      aParticle->GetTotalEnergy()<<"  "<<aParticle->GetTotalMomentum()
        //      <<"   "<< BetaInverse<<"   "<< nMax << G4endl;
	G4double maxCos = BetaInverse / nMax; 
	G4double maxSin2 = (1.0 - maxCos) * (1.0 + maxCos);

	for (G4int i = 0; i < NumPhotons; i++) {

		// Determine photon momentum

		G4double rand;
    //	G4double sampledMomentum, sampled; 

    G4double sampledEnergy, sampledRI; 

		G4double cosTheta, sin2Theta;
		
		// sample a momentum 

		do {
			rand = G4UniformRand();	
      //			sampledMomentum = Pmin + rand * dp; 
      //	sampledRI = Rindex->GetProperty(sampledMomentum);
			sampledEnergy = Pmin + rand * dp; 
			sampledRI = Rindex->Value(sampledEnergy);
			cosTheta = BetaInverse / sampledRI;  
      //	G4cout<<"RichG4cerenkov SampledMom sampledRI costh th "
      //                      <<sampledMomentum<<"  "<<	sampledRI<<"   "
      //                      <<cosTheta<< "   "<<acos(cosTheta)<<G4endl;

			sin2Theta = (1.0 - cosTheta)*(1.0 + cosTheta);
			rand = G4UniformRand();	

		} while (rand*maxSin2 > sin2Theta);

		// Generate random position of photon on cone surface 
		// defined by Theta 

		rand = G4UniformRand();

		G4double phi = CLHEP::twopi*rand;
		G4double sinPhi = sin(phi);
		G4double cosPhi = cos(phi);

		// calculate x,y, and z components of photon momentum 
		// (in coord system with primary particle direction 
		//  aligned with the z axis)

		G4double sinTheta = sqrt(sin2Theta); 
		G4double px = sinTheta*cosPhi;
		G4double py = sinTheta*sinPhi;
		G4double pz = cosTheta;

		// Create photon momentum direction vector 
		// The momentum direction is still with respect
	 	// to the coordinate system where the primary
		// particle direction is aligned with the z axis  

		G4ParticleMomentum photonMomentum(px, py, pz);

		// Rotate momentum direction back to global reference
		// system 

                photonMomentum.rotateUz(p0);

		// Determine polarization of new photon 

		G4double sx = cosTheta*cosPhi;
		G4double sy = cosTheta*sinPhi; 
		G4double sz = -sinTheta;

		G4ThreeVector photonPolarization(sx, sy, sz);

		// Rotate back to original coord system 

                photonPolarization.rotateUz(p0);
		
                // Generate a new photon:

                G4DynamicParticle* aCerenkovPhoton =
                  new G4DynamicParticle(G4OpticalPhoton::OpticalPhoton(), 
  					                 photonMomentum);
		aCerenkovPhoton->SetPolarization
				     (photonPolarization.x(),
				      photonPolarization.y(),
				      photonPolarization.z());

    //	aCerenkovPhoton->SetKineticEnergy(sampledMomentum);
		aCerenkovPhoton->SetKineticEnergy(sampledEnergy);

                // Generate new G4Track object:

		rand = G4UniformRand();

                G4double delta = rand * aStep.GetStepLength();
		G4double deltaTime = delta /
                       ((pPreStepPoint->GetVelocity()+
                         pPostStepPoint->GetVelocity())/2.);

                G4double aSecondaryTime = t0 + deltaTime;

                G4ThreeVector aSecondaryPosition =
                                    x0 + rand * aStep.GetDeltaPosition();

		G4Track* aSecondaryTrack = 
		new G4Track(aCerenkovPhoton,aSecondaryTime,aSecondaryPosition);

                aSecondaryTrack->SetTouchableHandle((G4VTouchable*)0);

                aSecondaryTrack->SetParentID(aTrack.GetTrackID());
     //Additions and modif made by SE to Tag the info regarding photon
     //production. SE 1-3-2005
               G4Track* aTaggedSecondaryTrack
                   = RichTbCkvProdInfoAttach(aTrack,aSecondaryTrack,
                     cosTheta,phi,sampledEnergy);
               //    G4cout<<" Ckv prod  costheta pho sampledEn Photdir   chtrakDir " << cosTheta <<"   "<< phi <<"  "<<  sampledEnergy <<"   "
               //      << aSecondaryTrack->GetMomentumDirection()<<"   "<<aTrack.GetMomentumDirection()<<  G4endl;
               
    //		aParticleChange.AddSecondary(aSecondaryTrack);

		aParticleChange.AddSecondary(aTaggedSecondaryTrack);
		// now for histograms
		RichTbPhotonProductionHisto(aTrack, aTaggedSecondaryTrack,
    				    cosTheta,phi,sampledEnergy);
    //end of modif by SE

	}

	if (verboseLevel>0) {
	G4cout << "\n Exiting from RichTbG4Cerenkov::DoIt -- NumberOfSecondaries = " 
	     << aParticleChange.GetNumberOfSecondaries() << G4endl;
	}

	return G4VContinuousProcess::AlongStepDoIt(aTrack, aStep);
}


// BuildThePhysicsTable for the Cerenkov process
// ---------------------------------------------
//

void RichTbG4Cerenkov::BuildThePhysicsTable()
{
	if (thePhysicsTable) return;

	const G4MaterialTable* theMaterialTable=
	 		       G4Material::GetMaterialTable();
	G4int numOfMaterials = G4Material::GetNumberOfMaterials();

	// create new physics table
	
	thePhysicsTable = new G4PhysicsTable(numOfMaterials);

	// loop for materials

	for (G4int i=0 ; i < numOfMaterials; i++)
	{
		G4PhysicsOrderedFreeVector* aPhysicsOrderedFreeVector =
					new G4PhysicsOrderedFreeVector();

		// Retrieve vector of refraction indices for the material
		// from the material's optical properties table 

		G4Material* aMaterial = (*theMaterialTable)[i];

		G4MaterialPropertiesTable* aMaterialPropertiesTable =
				aMaterial->GetMaterialPropertiesTable();

		if (aMaterialPropertiesTable) {

		   G4MaterialPropertyVector* theRefractionIndexVector = 
		    	   aMaterialPropertiesTable->GetProperty("CKVRNDX");

		   if (theRefractionIndexVector) {
		
		      // Retrieve the first refraction index in vector
		      // of (photon momentum, refraction index) pairs 

		     // theRefractionIndexVector->ResetIterator();
		     // ++(*theRefractionIndexVector);	// advance to 1st entry

          G4double currentRI = (*theRefractionIndexVector)[0];
		      //G4double currentRI = theRefractionIndexVector->
          //		   GetProperty();

		      if (currentRI > 1.0) {

			 // Create first (photon momentum, Cerenkov Integral)
			 // pair  

            // G4double currentPM = theRefractionIndexVector->
            //	 GetPhotonMomentum();
            //G4double currentPM = theRefractionIndexVector->
			 			// GetPhotonMomentum();

       G4double currentPM = theRefractionIndexVector->Energy(0);
			 G4double currentCAI = 0.0;

			 aPhysicsOrderedFreeVector->
			 	 InsertValues(currentPM , currentCAI);

			 // Set previous values to current ones prior to loop

			 G4double prevPM  = currentPM;
			 G4double prevCAI = currentCAI;
                	 G4double prevRI  = currentRI;

			 // loop over all (photon momentum, refraction index)
			 // pairs stored for this material

       for (size_t i = 1;i < theRefractionIndexVector->GetVectorLength(); i++)
                           //			 while(++(*theRefractionIndexVector))
			 {

            currentRI = (*theRefractionIndexVector)[i];
            currentPM = theRefractionIndexVector->Energy(i);
            //	currentRI=theRefractionIndexVector->	
            //	GetProperty();

            //	currentPM = theRefractionIndexVector->
            //		GetPhotonMomentum();

				currentCAI = 0.5*(1.0/(prevRI*prevRI) +
					          1.0/(currentRI*currentRI));

				currentCAI = prevCAI + 
					     (currentPM - prevPM) * currentCAI;

				aPhysicsOrderedFreeVector->
				    InsertValues(currentPM, currentCAI);

				prevPM  = currentPM;
				prevCAI = currentCAI;
				prevRI  = currentRI;
			 }

		      }
		   }
		}

	// The Cerenkov integral for a given material
	// will be inserted in thePhysicsTable
	// according to the position of the material in
	// the material table. 

	thePhysicsTable->insertAt(i,aPhysicsOrderedFreeVector); 

	}
}

// GetContinuousStepLimit
// ----------------------
//

G4double 
RichTbG4Cerenkov::GetContinuousStepLimit(const G4Track& aTrack,
				   G4double  ,
				   G4double  ,
                                   G4double& )
{
	// If user has defined an average maximum number of photons to
	// be generated in a Step, then return the Step length for that 
	// number of photons. 
 
	if (fMaxPhotons <= 0) return DBL_MAX;

        const G4DynamicParticle* aParticle = aTrack.GetDynamicParticle();
        const G4Material* aMaterial = aTrack.GetMaterial();

        G4MaterialPropertiesTable* aMaterialPropertiesTable =
                               aMaterial->GetMaterialPropertiesTable();
        if (!aMaterialPropertiesTable) return DBL_MAX;

         G4MaterialPropertyVector* Rindex =
                aMaterialPropertiesTable->GetProperty("CKVRNDX");
        if (!Rindex) return DBL_MAX;

	G4double MeanNumPhotons = 
                 GetAverageNumberOfPhotons(aParticle,aMaterial,Rindex);

        if(MeanNumPhotons <= 0.0) return DBL_MAX;

	G4double StepLimit = fMaxPhotons / MeanNumPhotons;

	return StepLimit;
}

// GetAverageNumberOfPhotons
// -------------------------
// This routine computes the number of Cerenkov photons produced per
// GEANT-unit (millimeter) in the current medium. 
//             ^^^^^^^^^^

G4double 
RichTbG4Cerenkov::GetAverageNumberOfPhotons(const G4DynamicParticle* aParticle, 
			      const G4Material* aMaterial,
			       G4MaterialPropertyVector* Rindex) const
{
	const G4double Rfact = 369.81/(CLHEP::eV * CLHEP::cm);

        if(aParticle->GetTotalMomentum() <= 0.0)return 0.0;

	G4double BetaInverse = aParticle->GetTotalEnergy() /
			       aParticle->GetTotalMomentum();

  // G4cout<<" ckv prod beta partEn partMom "<<  BetaInverse  << "  "<<aParticle->GetTotalEnergy()<<"  "
  //      << aParticle->GetTotalMomentum()<<G4endl;
  
	// Vectors used in computation of Cerenkov Angle Integral:
	// 	- Refraction Indices for the current material
	//	- new G4PhysicsOrderedFreeVector allocated to hold CAI's
 
	G4int materialIndex = aMaterial->GetIndex();

	// Retrieve the Cerenkov Angle Integrals for this material  

	G4PhysicsOrderedFreeVector* CerenkovAngleIntegrals =
	(G4PhysicsOrderedFreeVector*)((*thePhysicsTable)(materialIndex));

        if(!(CerenkovAngleIntegrals->IsFilledVectorExist()))return 0.0;

	// Min and Max photon momenta  
        //	G4double Pmin = Rindex->GetMinPhotonMomentum();
        //	G4double Pmax = Rindex->GetMaxPhotonMomentum();
  G4double Pmin = Rindex->GetMinLowEdgeEnergy(); //G4.95 onwards
  G4double Pmax = Rindex->GetMaxLowEdgeEnergy(); //G4.95 onwards

  //  G4cout<<" G4ckv pin pmax "<<  Pmin <<"  "<<Pmax << G4endl;
  
	// Min and Max Refraction Indices 
  //	G4double nMin = Rindex->GetMinProperty();	
  //	G4double nMax = Rindex->GetMaxProperty();

	G4double nMin = Rindex->GetMinValue();	
	G4double nMax = Rindex->GetMaxValue();

  // G4cout<<" G4ckv nMin nMax "<<  nMin <<"  "<<nMax <<G4endl;


	// Max Cerenkov Angle Integral 
	G4double CAImax = CerenkovAngleIntegrals->GetMaxValue();

	G4double dp, ge;

	// If n(Pmax) < 1/Beta -- no photons generated 

	if (nMax < BetaInverse) {
		dp = 0;
		ge = 0;
	} 

	// otherwise if n(Pmin) >= 1/Beta -- photons generated  

	else if (nMin > BetaInverse) {
		dp = Pmax - Pmin;	
		ge = CAImax; 
	} 

	// If n(Pmin) < 1/Beta, and n(Pmax) >= 1/Beta, then
	// we need to find a P such that the value of n(P) == 1/Beta.
	// Interpolation is performed by the GetPhotonMomentum() and
	// GetProperty() methods of the G4MaterialPropertiesTable and
	// the GetValue() method of G4PhysicsVector.  

	else {
    //		Pmin = Rindex->GetPhotonMomentum(BetaInverse);
		Pmin = Rindex->GetEnergy(BetaInverse);
		dp = Pmax - Pmin;

		// need boolean for current implementation of G4PhysicsVector
		// ==> being phased out
		G4bool isOutRange;
		G4double CAImin = CerenkovAngleIntegrals->
                                  GetValue(Pmin, isOutRange);
		ge = CAImax - CAImin;

		if (verboseLevel>0) {
			G4cout << "CAImin = " << CAImin << G4endl;
			G4cout << "ge = " << ge << G4endl;
		}
	}
	
	// particle charge 
	G4double charge = aParticle->GetDefinition()->GetPDGCharge();

	// Calculate number of photons 
	G4double NumPhotons = Rfact * charge/CLHEP::eplus * charge/CLHEP::eplus *
                                 (dp - ge * BetaInverse*BetaInverse);

	return NumPhotons;		
}
