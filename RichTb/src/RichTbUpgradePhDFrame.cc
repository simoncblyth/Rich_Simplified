// $Id: $
// Include files 

// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystal.hh"
#include "RichTbUpgradeCrystalMaster.hh"
#include "RichTbUpgradePhDFrame.hh"
#include "RichTbHall.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUpgradeVessel
//
// 2003-11-05 : Sajan EASO
// 2005-02-20:  SE Modifed for the 2004 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbPhDFrame::RichTbPhDFrame(RichTbUpgradeCrystalMaster* rTbCrystalMaster ) {

  aRTbCrystalMaster = rTbCrystalMaster;
  
  constructRichTbPhDFrame();
  
}
RichTbPhDFrame::~RichTbPhDFrame(  )
{
}
void RichTbPhDFrame::constructRichTbPhDFrame()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  
  G4Box * RichTbPhDFrameBox 
    = new G4Box("RichTbPhDFrameBox", 0.5*RichTbPhDFrameXSize,
                0.5*RichTbPhDFrameYSize, 0.5*RichTbPhDFrameZSize);

  G4ThreeVector PhDFramePos(RichTbPhDFrameXLocation,
                          RichTbPhDFrameYLocation,
                          RichTbPhDFrameZLocation);
 
  G4RotationMatrix PhDFrameRotX,PhDFrameRotY;
  PhDFrameRotY.rotateY(RichTbPhDFrameYRotation);
  PhDFrameRotX.rotateX(RichTbPhDFrameXRotation);
  /* G4int aSpeicalStudyVesselRotFlag =  
      aConfig ->getSpecialStudyVesselRotation();

  if( aSpeicalStudyVesselRotFlag != 1 ) {
    
  VesselRotX.rotateX(RichTbUpgradeVesselXRotation);
  VesselRotY.rotateY(RichTbUpgradeVesselYRotation);

  }

  */
  //
  // G4cout<<" Vessel XRot Yrot "<<RichTbUpgradeVesselXRotation<<"   "
  //      <<RichTbUpgradeVesselYRotation<<G4endl;
  
  //G4Transform3D VesselUpsSubTransform(VesselUpsSubRot,VesselUpsSubPos);

  G4Transform3D PhDFrameTransform(  PhDFrameRotX * PhDFrameRotY, PhDFramePos);
 
  G4LogicalVolume* PhDFrameLog;
    
     
    //material
     PhDFrameLog = 
       new G4LogicalVolume(RichTbPhDFrameBox,
                           aMaterial->getNitrogenGas(), "PhDFrameLog",0,0,0);

     //position of the frame  
     G4VPhysicalVolume* PhDFramePhys =
       new G4PVPlacement(PhDFrameTransform, PhDFramePhysName, PhDFrameLog ,
                         aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),
                         false,0);
     
     RichTbPhDFrameLVol =  PhDFrameLog;
     RichTbPhDFramePVol =  PhDFramePhys;
     

} 
void RichTbPhDFrame::constructRichTbPhDFrameEnvelope()
{
  
}


//=============================================================================
