// $Id: $
// Include files



// local
#include "RichTbROGeometry.hh"
#include "RichTbUpgradeDetectorConstruction.hh"
#include "RichTbRunConfig.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"

#include "RichTbUpgradeCrystalMaster.hh"
#include "RichTbUpgradePhDetSupFrame.hh"
#include "RichTbUpgradeEC.hh"

#include "RichTbPMT.hh"

#include "RichTbContainerVesselBox.hh"



//-----------------------------------------------------------------------------
// Implementation file for class : RichTbROGeometry
//
// 2003-12-11 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbROGeometry::RichTbROGeometry(G4String RoNameString,
		RichTbDetectorConstruction* aDet  )
: G4VReadOutGeometry(RoNameString){

	CurDet = aDet;

}
G4VPhysicalVolume* RichTbROGeometry::Build()
{
	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();


	// now construct the readout geometry.
	RichTbHall* rTbHallRO = new RichTbHall();

  if( aRadiatorConfiguration == 10 ) {
    
    RichTbContainerVesselBox *   aRichTbContainerVesselBoxRO = new  RichTbContainerVesselBox (rTbHallRO );
    if(aRichTbContainerVesselBoxRO) G4cout<<"RichTbContainerVesselBoxRO created"<<G4endl;
    


  }else {

	RichTbUpgradeVessel*  rTbVesselRO = new RichTbUpgradeVessel(rTbHallRO );

	RichTbUpgradeCrystalMaster*  rTbCrystalMasterRO = new RichTbUpgradeCrystalMaster(rTbVesselRO );

	G4int aRadiatorConfiguration = aConfig->getRadiatorConfiguration();
	if(aRadiatorConfiguration == 0){

		//  RichTbCrystal*  rTbCrystalRO = new RichTbCrystal(rTbCrystalMasterRO );
		//  RichTbLens*  rTbLensRO = new RichTbLens(rTbCrystalMasterRO );
		// RichTbCrystalCover*  rTbCrystalCoverRO = new RichTbCrystalCover(rTbCrystalMasterRO );

	}else{

		// RichTbUpgradeRadiator*  rTbUpgradeRadiatorRO = new RichTbUpgradeRadiator(rTbCrystalMasterRO );
		//   RichTbUpgradeMirror*  rTbMirrorRO = new RichTbUpgradeMirror(rTbCrystalMasterRO );
		// RichTbUpgradeDarkCover*  rTbDarkCoverRO = new RichTbUpgradeDarkCover(rTbRadiatorRO );

		RichTbUpgradePhDetSupFrame* rTbUpgradePhotSupFrameRO = new RichTbUpgradePhDetSupFrame(rTbCrystalMasterRO);
		if( aRadiatorConfiguration == 1){
			rTbUpgradePhotSupFrameRO ->constructRichTbPhotoDetectorSupFrame();
		}else if (aRadiatorConfiguration == 2) {
			rTbUpgradePhotSupFrameRO ->constructRichTbPhotoDetectorSupFrameWithHpd();
		}else if (aRadiatorConfiguration == 3)  {
			rTbUpgradePhotSupFrameRO->constructRichTbPhotoDetectorSupFrame15();
		} else if (aRadiatorConfiguration == 6) {
		        rTbUpgradePhotSupFrameRO->constructRichTbPhotoDetectorSupFrame16LT();
		}else if (aRadiatorConfiguration == 7)  {
			rTbUpgradePhotSupFrameRO->constructRichTbPhotoDetectorSupFrame17();
		}
    



		RichTbUpgradeEC *  rTbECRO =  new RichTbUpgradeEC(rTbUpgradePhotSupFrameRO);
		if( aRadiatorConfiguration == 1){
			rTbECRO ->  constructRichTbUpgradeEC ();
			rTbECRO ->  constructRichTbUpgradeECSupport ();
		}else if( aRadiatorConfiguration == 2) {
			rTbECRO ->  constructRichTbUpgradeSingleEC ();
			rTbECRO ->  constructRichTbUpgradeSingleECSupport ();
		}else if (aRadiatorConfiguration == 3 )    {
			rTbECRO->constructRichTbUpgradeEC15();
		}else if ( aRadiatorConfiguration == 6){

		  for (G4int is=0; is< NumPhDetSupFrames16 ; is++){
        
		       rTbECRO->constructRichTbUpgradeEC16LT(is);
        
		  }
      
		}else if (aRadiatorConfiguration == 7 )    {
			rTbECRO->constructRichTbUpgradeEC17();
		}
    
    



		RichTbPMT * rTbPMTRO =  new RichTbPMT( rTbECRO );
		rTbPMTRO ->setTrackingSwitch(false);
		rTbPMTRO ->buildPMTGeometry() ;
		G4cout<<"created pmt ro geometry "<<G4endl;

	}
  }
  
	return  rTbHallRO->getRichTbHallPhysicalVolume();

}


//=============================================================================
// Destructor
//=============================================================================
RichTbROGeometry::~RichTbROGeometry() {}

//=============================================================================
