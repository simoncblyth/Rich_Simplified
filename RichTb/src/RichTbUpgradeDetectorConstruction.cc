// Geant4 headers
#include "G4Box.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SDManager.hh"

// STL etc
#include <iostream>

// local headers
#include "RichTbMiscNames.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbUpgradeDetectorConstruction.hh"
#include "RichTbHall.hh"

#include "RichTbSurfaceDefinition.hh"
#include "RichTbSurface.hh"

#include "RichTbUpgradeSD.hh"
#include "RichTbUpgradeHpdSD.hh"

RichTbDetectorConstruction::RichTbDetectorConstruction()
{;
}

RichTbDetectorConstruction::~RichTbDetectorConstruction()
{;
}

G4VPhysicalVolume *RichTbDetectorConstruction::Construct()
{

	// now create all the materials and surface properties.
	// RichTbMaterial* rMaterial = RichTbMaterial::getRichTbMaterialInstance();
	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();
  G4int aQWRadiatorInstallConfig =  aConfig ->getQWRadInstallFlag();
  G4int aMirrConfig =  aConfig ->  getRichTbMirrorGeomFlag();
  

	G4int CurNumPmts = NumPmtsOld;
//	G4int CurNumPmts = RichTbPMTGeometryParameters::getNumPmts(); //TESTnumPmts
	if (aRadiatorConfiguration == 2){
    CurNumPmts = NumPmtsWithHpd;
  } else if (aRadiatorConfiguration == 3) {
    CurNumPmts = NumPmtsUpgrade15;
  } else if (aRadiatorConfiguration == 6) {
    CurNumPmts = NumPmtsUpgrade16;
  } else if (aRadiatorConfiguration == 7) {
    CurNumPmts = NumPmtsUpgrade17;
  }

  
//	else if(aRadiatorConfiguration == 3) CurNumPmts = RichTbPMTGeometryParameters::getNumPmtsUpgrade();//TESTnumPmts


	RichTbSurfaceDefinition* rSurfaceDef=
			RichTbSurfaceDefinition::getRichTbSurfaceDefinitionInstance();
	if(rSurfaceDef) G4cout<<" RichTb Surface definitions created "<<G4endl;

	InitializeRichTbGeometry();


	rTbHall = new RichTbHall();

  if(aRadiatorConfiguration == 10 ) {

    rTbContainerVessel = new  RichTbContainerVesselBox(rTbHall );
    ResetStdVol();
    if( aQWRadiatorInstallConfig == 0 ){
      
      rTbPolymerPlusRadiator = new RichTbPolymerRadiator(rTbContainerVessel);
    }else {
      rTbQWRadiator  = new RichTbQuartzRadiator(rTbContainerVessel); 

    }
    
    
    rTbMirrParabola = new RichTbMirrorParabola(rTbContainerVessel);

    rTbMirrSph=0;
    rTbLargeMirrorParab=0;
    
    if( aMirrConfig == 0 ){

      rTbMirrSph  = new RichTbMirrorSph(rTbContainerVessel);

    }else if ( aMirrConfig == 1 ) {

      rTbLargeMirrorParab = new RichTbLargeMirrorParabola(rTbContainerVessel);
      
    }
    
    


    rTbPhCPhDetSupFrame = new RichTbPhCPhotDetSupFrame(rTbContainerVessel);

  }else {
    
    // now for geometry until 2016  
  

	rTbVessel = new RichTbUpgradeVessel(rTbHall );

	rTbCrystalMaster = new RichTbUpgradeCrystalMaster(rTbVessel );


	if(aRadiatorConfiguration == 0){

		rTbCrystal = new RichTbCrystal(rTbCrystalMaster );

		rTbLens = new RichTbLens(rTbCrystalMaster );

		rTbCrystalCover = new RichTbCrystalCover(rTbCrystalMaster );

	} else{
		//Radiator + Mirror + Cover
    
      
		rTbUpgradeRadiator = new RichTbUpgradeRadiator(rTbCrystalMaster);
		rTbUpgradeMirror = (aRadiatorConfiguration != 6) ? new RichTbUpgradeMirror(rTbCrystalMaster, rTbUpgradeRadiator) : 0;
	

		// rTbMirror = RichTbUpgradeMirror::getRichTbUpgradeMirrorInstance( rTbVessel );

    rTbUpgradeDarkCover =  new RichTbUpgradeDarkCover(rTbUpgradeRadiator );
    
    
		//rTbUpgradeDarkCover =  (aRadiatorConfiguration != 6) ?  new RichTbUpgradeDarkCover(rTbUpgradeRadiator ) : 0;

    if( 	rTbUpgradeDarkCover ){
      
      

		  if ((aRadiatorConfiguration == 3) )  {
        rTbUpgradeDarkCover->constructRichTbUpgradeDarkCover15(); 
			  rTbUpgradeDarkCover->constructRichTbUpgradeUpsDarkCoverEnvelope15(rTbCrystalMaster);
		  	rTbUpgradeDarkCover->constructRichTbUpgradeSideDarkCoverEnvelope15(rTbCrystalMaster);

      }else if ((aRadiatorConfiguration == 7) )  {
        rTbUpgradeDarkCover->constructRichTbUpgradeDarkCover15(); 
			  rTbUpgradeDarkCover->constructRichTbUpgradeUpsDarkCoverEnvelope15(rTbCrystalMaster);
		  	rTbUpgradeDarkCover->constructRichTbUpgradeSideDarkCoverEnvelope15(rTbCrystalMaster);

		  }else if ( aRadiatorConfiguration == 6){
        

		  	rTbUpgradeDarkCover-> constructRichTbUpgradeSideDarkCoverEnvelopePhC(rTbCrystalMaster);
        rTbUpgradeDarkCover-> constructRichTbUpgradeUpsDarkCoverEnvelopePhC(rTbCrystalMaster);

      } else   {

        rTbUpgradeDarkCover->constructRichTbUpgradeDarkCover();
			  rTbUpgradeDarkCover->constructRichTbUpgradeUpsDarkCoverEnvelope(rTbCrystalMaster);
			  rTbUpgradeDarkCover->constructRichTbUpgradeSideDarkCoverEnvelope(rTbCrystalMaster);
      }
      
      

    }
    
    

		//Elementary Cells, PMT's and Support
		rTbUpgradePhotSupFrame = new RichTbUpgradePhDetSupFrame(rTbCrystalMaster);
		if(aRadiatorConfiguration == 1){
			rTbUpgradePhotSupFrame->constructRichTbPhotoDetectorSupFrame();
		}else if (aRadiatorConfiguration == 2) {
			rTbUpgradePhotSupFrame->constructRichTbPhotoDetectorSupFrameWithHpd();
		}else if(  aRadiatorConfiguration == 3 ){

			rTbUpgradePhotSupFrame->constructRichTbPhotoDetectorSupFrame15();

		}else if (aRadiatorConfiguration == 6 ) {

    	rTbUpgradePhotSupFrame->constructRichTbPhotoDetectorSupFrame16LT();
		}else if (aRadiatorConfiguration == 7 ) {

    	rTbUpgradePhotSupFrame->constructRichTbPhotoDetectorSupFrame17();
		}
    

		rTbEC  = new RichTbUpgradeEC(rTbUpgradePhotSupFrame);

		if(aRadiatorConfiguration == 1){
			rTbEC->constructRichTbUpgradeEC();
			rTbEC->constructRichTbUpgradeECSupport();
		}else if(aRadiatorConfiguration == 2) {
			rTbEC->constructRichTbUpgradeSingleEC();
			rTbEC->constructRichTbUpgradeSingleECSupport ();
		}else if(aRadiatorConfiguration == 3) {
			rTbEC->constructRichTbUpgradeEC15();
			rTbEC->constructRichTbUpgradeECSupport15();
		}else if(aRadiatorConfiguration == 7) {
			rTbEC->constructRichTbUpgradeEC17();
			rTbEC->constructRichTbUpgradeECSupport17();
		}else if(aRadiatorConfiguration == 6){


      for (G4int is=0; is< NumPhDetSupFrames16 ; is++){

        
     	  rTbEC->constructRichTbUpgradeEC16LT(is);
        rTbEC->constructRichTbUpgradeECSupport16LT(is);
        
        
      }
      
      
    }
    
    
    


		rTbPMT = new RichTbPMT( rTbEC );
		rTbPMT ->buildPMTGeometry();


		if( aRadiatorConfiguration == 2 ) {
			rTbHpd = new RichTbHpd(0, rTbUpgradePhotSupFrame);
			rTbHpd -> buildHpdGeometry();
		}

	}
  }
  
	//now for the surfaces

	rTbSurface = new  RichTbSurface(this);

	//sensitive detector creation for PMT

	G4SDManager* SDman = G4SDManager::GetSDMpointer();


	RichTbUpgradeSD* PMTSD = new RichTbUpgradeSD( PMTSDname );


	//sensitive detector creation for HPD
	RichTbUpgradeHpdSD* HPDSD = (aRadiatorConfiguration == 2) ? new RichTbUpgradeHpdSD(HPDSDname):0;



	// now for the readout Geometry.

	G4cout<< " Now for readout geometry in Pmt "<<G4endl;

	rTbROGeom = new  RichTbROGeometry( ROgeometryName, this);

	rTbROGeom -> BuildROGeometry();
	PMTSD->SetROgeometry(rTbROGeom);
	SDman->AddNewDetector( PMTSD );
	G4cout<< " Now associate sensdet to  readout geometry in Pmt "<<G4endl;
	//begin test
        G4int HCID = G4SDManager::GetSDMpointer()->GetCollectionID (RichTbHColname);
        G4cout<< " Now associate sensdet to  readout geometry in Pmt "<< HCID <<  G4endl;

	// end test
	//  Associate the anode of each pmt to the sensitive detector.
  //	for(G4int ipmt=0; ipmt< CurNumPmts; ipmt++) {
  if(aRadiatorConfiguration < 10 ) {
    

	for(G4int ipmt=0; ipmt< CurNumPmts; ipmt++) {

		G4LogicalVolume* RichTbPmtAnode_LV = rTbPMT->getRichTbPMTAnodeLVol()  [ipmt];
		RichTbPmtAnode_LV ->SetSensitiveDetector( PMTSD );
		G4cout<<"associate pmtsd to sensdet "<<RichTbPmtAnode_LV->GetName()<<"  "<<  ipmt<<G4endl;

	}

  }
  
	// Now for the HPD sensitive detector
	if( aRadiatorConfiguration == 2 ) {
		if( HPDSD ) {
			G4cout<< " Now for readout geometry in hpd "<<G4endl;

			// now for the hpd readout
			rTbROGeomHpd = new  RichTbROGeometryHpd( ROgeometryNameHpd, this);
			rTbROGeomHpd -> BuildROGeometry();

			HPDSD ->SetROgeometry( rTbROGeomHpd);
			SDman->AddNewDetector( HPDSD );

			G4cout<<"associate hpdsd to sensdet " << G4endl;
			//begin test
			G4int numberOfCollections = HPDSD->GetNumberOfCollections();
			G4cout<<"hpdsd test   "<< numberOfCollections<<"  "
					<< HPDSD ->GetName() <<"  "<< HPDSD->GetCollectionName(0) <<G4endl;



			G4int HCIDHA = G4SDManager::GetSDMpointer()->GetCollectionID (RichTbHColnameHpd);

			G4cout<< "associated hpdsd to sensdet A  "<< HCIDHA <<  G4endl;
			// end test

			G4LogicalVolume*  RichTbHpdAnode_LV =  rTbHpd ->getRichTbHpdSiDetLVol();
			RichTbHpdAnode_LV -> SetSensitiveDetector( HPDSD );
			G4cout<<"associated hpdsd to sensdet "<<RichTbHpdAnode_LV->GetName()<<"  "<<G4endl;

			//begin test
			G4int HCIDH = G4SDManager::GetSDMpointer()->GetCollectionID (RichTbHColnameHpd);

			G4cout<< "associated hpdsd to sensdet  "<< HCIDH <<  G4endl;
			// end test


		}


	}


	// Now for the graphics setups.
	RichTbGraphics* rTbGraphics = new RichTbGraphics(this);
	if( rTbGraphics) G4cout<<" Graphics definitions created "<<G4endl;


	return rTbHall->getRichTbHallPhysicalVolume();
}

void RichTbDetectorConstruction::ResetStdVol() {
  

  rTbVessel=0;  
  rTbUpgradeRadiator=0;
  rTbCrystalMaster =0;
  rTbCrystalCover =0;
  rTbUpgradeDarkCover=0;
  rTbPhDFrame=0;
  rTbUpgradeMirror=0;
  rTbLens=0;
  rTbUpgradePhotSupFrame=0;
  rTbEC =0;
  rTbHpd=0;
  rTbPolymerPlusRadiator=0;
  rTbQWRadiator =0;
  
}
