// $Id: $
// Include files 
// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystal.hh"
#include "RichTbUpgradeCrystalMaster.hh"
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
// Implementation file for class : RichTbVessel
//
// 2003-11-05 : Sajan EASO
// 2005-02-20:  SE Modifed for the 2004 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbCrystal::RichTbCrystal(RichTbUpgradeCrystalMaster* rTbCrystalMaster ) {

  aRTbCrystalMaster = rTbCrystalMaster;
  
  constructRichTbCrystal();
  
}
RichTbCrystal::~RichTbCrystal(  )
{
}
void RichTbCrystal::constructRichTbCrystal()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  
  G4Box * RichTbCrystalBox 
    = new G4Box("RichTbCrystalBox", 0.5*RichTbCrystalXSize,
                0.5*RichTbCrystalYSize, 0.5*RichTbCrystalZSize);

  G4ThreeVector CrystalPos(RichTbCrystalXLocation,
                          RichTbCrystalYLocation,
                          RichTbCrystalZLocation);
 
  G4RotationMatrix CrystalRotX,CrystalRotY;
  /*
   G4int aSpecialStudyCrystalRotFlag =  
      aConfig ->getSpecialStudyCrystalRotation();

  if( aSpecialStudyCrystalRotFlag != 1 ) {
    
    CrystalRotX.rotateX(aConfig ->getSpecialStudyCrystalRotationX());
    CrystalRotY.rotateY(aConfig ->getSpecialStudyCrystalRotationY());

  }
  */
  
  //
  // G4cout<<" Vessel XRot Yrot "<<RichTbVesselXRotation<<"   "
  //      <<RichTbVesselYRotation<<G4endl;
  
  //G4Transform3D VesselUpsSubTransform(VesselUpsSubRot,VesselUpsSubPos);
  G4Transform3D CrystalTransform(  CrystalRotX * CrystalRotY, CrystalPos);
  
  /* G4SubtractionSolid* VesselUpsSub = 
      new G4SubtractionSolid("VesselUpsSub",  RichTbVesselBoxOverall ,
                             RichTbVesselUpsSubBox,VesselUpsSubTransform);
  
  */
    G4LogicalVolume* CrystalLog;
    
     
    //crystal material
     CrystalLog = 
       new G4LogicalVolume(RichTbCrystalBox,
                           aMaterial->getCrystalMaterial(), "CrystalLog",0,0,0);

     //crystal location  
     G4VPhysicalVolume* CrystalPhys =
       new G4PVPlacement(CrystalTransform, CrystalPhysName, CrystalLog ,
                         aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),
                         false,0);
     
     RichTbCrystalLVol =  CrystalLog;
     RichTbCrystalPVol =  CrystalPhys;
     

} 
void RichTbCrystal::constructRichTbCrystalEnvelope()
{
  
}


//=============================================================================
