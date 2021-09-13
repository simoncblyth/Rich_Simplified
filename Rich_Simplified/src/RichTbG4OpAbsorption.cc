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
// $Id: G4OpAbsorption.cc,v 1.5 2004/10/19 02:15:15 gum Exp $
// GEANT4 tag $Name: geant4-07-00 $
//
////////////////////////////////////////////////////////////////////////
// Optical Photon Absorption Class Implementation
////////////////////////////////////////////////////////////////////////
//
// File:        RichTbG4OpAbsorption.cc
// Description: Discrete Process -- Absorption of Optical Photons  
// Version:     1.0
// Created:     1996-05-21
// Author:      Juliet Armstrong
// Updated:     2000-09-18 by Peter Gumplinger
//              > comment out warning - "No Absorption length specified" 
//              1997-04-09 by Peter Gumplinger
//              > new physics/tracking scheme
//              1998-08-25 by Stefano Magni
//              > Change process to use G4MaterialPropertiesTables
//              1998-09-03 by Peter Gumplinger
//              > Protect G4MaterialPropertyVector* AttenuationLengthVector
// mail:        gum@triumf.ca
//              magni@mi.infn.it
//
////////////////////////////////////////////////////////////////////////

#include "G4ios.hh"
#include "RichTbG4OpAbsorption.hh"

/////////////////////////
// Class Implementation
/////////////////////////

        //////////////
        // Operators
        //////////////

// RichTbG4OpAbsorption::operator=(const RichTbG4OpAbsorption &right)
// {
// }

        /////////////////
        // Constructors
        /////////////////

RichTbG4OpAbsorption::RichTbG4OpAbsorption(const G4String& processName)
              : G4VDiscreteProcess(processName)
{
        if (verboseLevel>0) {
           G4cout << GetProcessName() << " is created " << G4endl;
        }
}

// RichTbG4OpAbsorption::RichTbG4OpAbsorption(const G4OpAbsorpton &right)
// {
// }

        ////////////////
        // Destructors
        ////////////////

RichTbG4OpAbsorption::~RichTbG4OpAbsorption(){}

        ////////////
        // Methods
        ////////////

// PostStepDoIt
// -------------
//
G4VParticleChange*
RichTbG4OpAbsorption::PostStepDoIt(const G4Track& aTrack, const G4Step& aStep)
{
        aParticleChange.Initialize(aTrack);

        aParticleChange.ProposeTrackStatus(fStopAndKill);
        aStep.GetTrack()->SetTrackStatus(fStopAndKill);
        if (verboseLevel>0) {
	   G4cout << "\n** Photon absorbed! **" << G4endl;
        }
        return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);
}


// GetMeanFreePath
// ---------------
//
G4double RichTbG4OpAbsorption::GetMeanFreePath(const G4Track& aTrack,
 				         G4double ,
				         G4ForceCondition* )
{
	const G4DynamicParticle* aParticle = aTrack.GetDynamicParticle();
        const G4Material* aMaterial = aTrack.GetMaterial();

        //	G4double thePhotonMomentum = aParticle->GetTotalMomentum();
        G4double thePhotonEnergy = aParticle->GetTotalEnergy();

	G4MaterialPropertiesTable* aMaterialPropertyTable;
	G4MaterialPropertyVector* AttenuationLengthVector;
	
        G4double AttenuationLength = DBL_MAX;

	aMaterialPropertyTable = aMaterial->GetMaterialPropertiesTable();

	if ( aMaterialPropertyTable ) {
	   AttenuationLengthVector = aMaterialPropertyTable->
                                                GetProperty("ABSLENGTH");
           if ( AttenuationLengthVector ){
             // AttenuationLength = AttenuationLengthVector->
             //                         GetProperty (thePhotonMomentum);
             AttenuationLength = AttenuationLengthVector->
                                         Value (thePhotonEnergy);
           }
           else {
//             G4cout << "No Absorption length specified" << G4endl;
           }
        } 
        else {
//           G4cout << "No Absorption length specified" << G4endl;
        }

        return AttenuationLength;
}
