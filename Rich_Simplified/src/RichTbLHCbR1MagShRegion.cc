// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"

#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1MagShRegion.hh"

#include <iostream>
//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbMagShRegion
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1MagShRegion::RichTbLHCbR1MagShRegion(RichTbLHCbRich1SubMaster* rTbLHCbR1SubMaster ) {
  mTbLHCbR1SubMaster = rTbLHCbR1SubMaster;
  constructLbR1MagShReg();

}

RichTbLHCbR1MagShRegion::~RichTbLHCbR1MagShRegion() { ; }

void RichTbLHCbR1MagShRegion::constructLbR1MagShReg() {
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  G4Box * RichTbR1MagShRegFullBox = new G4Box("RichTbR1MagShFullBox",
                                RichTbR1MagShRegHalfSizeX , 
                                RichTbR1MagShRegHalfSizeY, RichTbR1MagShRegHalfSizeZ);   
  G4Box * RichTbR1MagShSubBox = new G4Box("RichTbR1MagShSubBox", 
					  RichTbR1MagShRegSubBoxLargeHalfSizeX,
					  RichTbR1MagShRegSubBoxLargeHalfSizeY,
                                          RichTbR1MagShRegSubBoxLargeHalfSizeZ);
  G4RotationMatrix RichTbR1MagShSubBoxRot;
  RichTbR1MagShSubBoxRot.rotateX(RichTbR1MagShRegSubBoxRotX);
  G4ThreeVector RichTbR1MagShSubBoxPos(RichTbR1MagShRegSubBoxPosX,RichTbR1MagShRegSubBoxPosY,
                                       RichTbR1MagShRegSubBoxPosZ );
  G4Transform3D RichTbR1MagShSubBoxTrans(RichTbR1MagShSubBoxRot,RichTbR1MagShSubBoxPos);
  G4SubtractionSolid* RichTbR1MagShRegBox = new G4SubtractionSolid("RichTbR1MagShBox",
				RichTbR1MagShRegFullBox, 
                                RichTbR1MagShSubBox,RichTbR1MagShSubBoxTrans);

  G4RotationMatrix RichTbR1MagShRegRot;
  G4ThreeVector  RichTbR1MagShRegPos( RichTbR1MagShRegPosX,
                 RichTbR1MagShRegPosY,RichTbR1MagShRegPosZ);
  G4Transform3D RichTbR1MagShRegTrans(RichTbR1MagShRegRot,RichTbR1MagShRegPos);

  rTbR1MagShRegionLVol = new G4LogicalVolume(RichTbR1MagShRegBox,aMaterial->getNitrogenGas(),
					    RichTbR1MagShRegionLogName , 0,0,0);
  rTbR1MagShRegionPVol = new G4PVPlacement(RichTbR1MagShRegTrans,RichTbR1MagShRegionPhysName,
					   rTbR1MagShRegionLVol ,
                   mTbLHCbR1SubMaster->getRichTbLHCbRich1SubMasterPhysicalVolume(),false,1);  


}

