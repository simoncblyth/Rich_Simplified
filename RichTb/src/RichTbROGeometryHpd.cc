// Include files



// local
#include "RichTbROGeometryHpd.hh"
#include "RichTbUpgradeDetectorConstruction.hh"
#include "RichTbRunConfig.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystalMaster.hh"
#include "RichTbUpgradePhDetSupFrame.hh"
#include "RichTbUpgradeEC.hh"

#include "RichTbHpd.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbROGeometryHpd
//
// 2015-05-16 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbROGeometryHpd::RichTbROGeometryHpd(G4String RoNameString,
            RichTbDetectorConstruction* aDet  )
: G4VReadOutGeometry(RoNameString){

  CurDet = aDet;

}
G4VPhysicalVolume* RichTbROGeometryHpd::Build() {

  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  // now construct the readout geometry.
  RichTbHall* rTbHallRO = new RichTbHall();
  RichTbUpgradeVessel*  rTbVesselRO = new RichTbUpgradeVessel(rTbHallRO );
  RichTbUpgradeCrystalMaster*  rTbCrystalMasterRO = new RichTbUpgradeCrystalMaster(rTbVesselRO );

  G4int aRadiatorConfiguration =aConfig ->getRadiatorConfiguration();

  if(aRadiatorConfiguration == 2){

	RichTbUpgradePhDetSupFrame* rTbUpgradePhotSupFrameRO = new RichTbUpgradePhDetSupFrame(rTbCrystalMasterRO);
	rTbUpgradePhotSupFrameRO ->constructRichTbPhotoDetectorSupFrameWithHpd();

	RichTbHpd*  rTbHpdRO = new RichTbHpd(0, rTbUpgradePhotSupFrameRO);
	rTbHpdRO -> setTrackingSwitch(false);
	rTbHpdRO  -> buildHpdGeometry();
	G4cout<<"created hpd ro geometry "<<G4endl;


  }


  return  rTbHallRO->getRichTbHallPhysicalVolume();


}

//=============================================================================
// Destructor
//=============================================================================
RichTbROGeometryHpd::~RichTbROGeometryHpd() {}

//=============================================================================
