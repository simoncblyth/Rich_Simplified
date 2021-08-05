// $Id: $
// Include files

// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
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
RichTbUpgradeCrystalMaster::RichTbUpgradeCrystalMaster(RichTbUpgradeVessel* rTbVessel ) {

  aRTbVessel = rTbVessel;

  constructRichTbUpgradeCrystalMaster();

}
RichTbUpgradeCrystalMaster::~RichTbUpgradeCrystalMaster(  )
{
}
void RichTbUpgradeCrystalMaster::constructRichTbUpgradeCrystalMaster()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

  G4Box * RichTbCrystalMasterBox
    = new G4Box("RichTbCrystalMasterBox", 0.5*RichTbCrystalMasterXSize,
                0.5*RichTbCrystalMasterYSize, 0.5*RichTbCrystalMasterZSize);

  G4ThreeVector CrystalMasterPos(RichTbCrystalMasterXLocation,
                          RichTbCrystalMasterYLocation,
                          RichTbCrystalMasterZLocation);

  G4RotationMatrix CrystalMasterRotX,CrystalMasterRotY;

   G4int aSpecialStudyCrystalRotFlag =
      aConfig ->getSpecialStudyCrystalRotation();

  if( aSpecialStudyCrystalRotFlag != 1 ) {
    //G4cout << "rotation " << -aConfig ->getSpecialStudyCrystalRotationY() << G4endl;
    CrystalMasterRotX.rotateX(aConfig ->getSpecialStudyCrystalRotationX());
    CrystalMasterRotY.rotateY(aConfig ->getSpecialStudyCrystalRotationY());

  }


  //
  // G4cout<<" Vessel XRot Yrot "<<RichTbVesselXRotation<<"   "
  //      <<RichTbVesselYRotation<<G4endl;

  //G4Transform3D VesselUpsSubTransform(VesselUpsSubRot,VesselUpsSubPos);
  G4Transform3D CrystalMasterTransform(  CrystalMasterRotX * CrystalMasterRotY, CrystalMasterPos);

  /* G4SubtractionSolid* VesselUpsSub =
      new G4SubtractionSolid("VesselUpsSub",  RichTbVesselBoxOverall ,
                             RichTbVesselUpsSubBox,VesselUpsSubTransform);

  */
    G4LogicalVolume* CrystalMasterLog;


    //crystal material
     CrystalMasterLog =
       new G4LogicalVolume(RichTbCrystalMasterBox,
                           aMaterial->getNitrogenGas(), "CrystalMasterLog",0,0,0);

     //crystal location
     G4VPhysicalVolume* CrystalMasterPhys =
       new G4PVPlacement(CrystalMasterTransform, CrystalMasterPhysName, CrystalMasterLog ,
                         aRTbVessel->getRichTbGasVesselPVol(),
                         false,0);

     RichTbUpgradeCrystalMasterLVol =  CrystalMasterLog;
     RichTbUpgradeCrystalMasterPVol =  CrystalMasterPhys;


}
void RichTbUpgradeCrystalMaster::constructRichTbUpgradeCrystalMasterEnvelope()
{

}


//=============================================================================
