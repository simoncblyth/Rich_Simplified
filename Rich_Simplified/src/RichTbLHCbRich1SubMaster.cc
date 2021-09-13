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
#include "RichTbLHCbRich1SubMaster.hh"
//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbRich1SubMaster
// 2021-07-22   SE
//
//------------------------------------------------------------------------------
RichTbLHCbRich1SubMaster::RichTbLHCbRich1SubMaster(RichTbLHCbRich1Master* rTbLHCbR1Master ) {
  mTbLHCbR1Master = rTbLHCbR1Master;
  constructLbR1SubMaster();

}
RichTbLHCbRich1SubMaster::~RichTbLHCbRich1SubMaster() {; }

void RichTbLHCbRich1SubMaster::constructLbR1SubMaster() {
 RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
 
 G4Box * RichTbR1SubMasterBox = new G4Box("RichTbR1SubMasterBox", 
		    RichTbR1SubMasterHalfSizeX,RichTbR1SubMasterHalfSizeY,RichTbR1SubMasterHalfSizeZ);

 G4ThreeVector RichTbR1SubMasterPos( RichTbR1SubMasterPosX,RichTbR1SubMasterPosY,RichTbR1SubMasterPosZ);
 G4RotationMatrix RichTbR1SubMasterRot;
 G4Transform3D RichTbR1SubMasterTransform(RichTbR1SubMasterRot,RichTbR1SubMasterPos);
 rTbRich1SubMasterLVol = new G4LogicalVolume(RichTbR1SubMasterBox, aMaterial->getc4f10Gas(),
					  RichTbR1SubMasterLogName,0,0,0);

 rTbRich1SubMasterPVol = new G4PVPlacement(RichTbR1SubMasterTransform,RichTbR1SubMasterPhysName,
                                        rTbRich1SubMasterLVol,
					mTbLHCbR1Master->getRichTbLHCbRich1MasterPhysicalVolume() ,false,1);

}
