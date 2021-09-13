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
#include "RichTbLHCbRich1Master.hh"
//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbRich1Master
// 2021-07-22   SE
//
//------------------------------------------------------------------------------
RichTbLHCbRich1Master::RichTbLHCbRich1Master(RichTbLHCbExptHall* rTbLHCbExptHall) {
  mTbLHCbExptHall = rTbLHCbExptHall;
  constructLbR1Master();

}
RichTbLHCbRich1Master::~RichTbLHCbRich1Master() {; }

void RichTbLHCbRich1Master::constructLbR1Master() {
 RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
 
 G4Box * RichTbR1MasterBox = new G4Box("RichTbR1MasterBox", 
				       RichTbR1MasterHalfSizeX,RichTbR1MasterHalfSizeY,RichTbR1MasterHalfSizeZ);

 G4ThreeVector RichTbR1MasterPos( RichTbR1MasterPosX,RichTbR1MasterPosY,RichTbR1MasterPosZ);
 G4RotationMatrix RichTbR1MasterRot;
 G4Transform3D RichTbR1MasterTransform(RichTbR1MasterRot,RichTbR1MasterPos);
 rTbRich1MasterLVol = new G4LogicalVolume(RichTbR1MasterBox, aMaterial->getAir(),
					  RichTbR1MasterLogName,0,0,0);

 rTbRich1MasterPVol = new G4PVPlacement(RichTbR1MasterTransform,RichTbR1MasterPhysName,rTbRich1MasterLVol,
					mTbLHCbExptHall->getRichTbLHCbExptHallPhysicalVolume(),false,1);

}
