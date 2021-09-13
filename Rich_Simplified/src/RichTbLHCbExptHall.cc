// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbExptHall.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterial.hh"
#include <iostream>

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbExptHall
// SE 22-07-2021 
//--------------------------------------------------------
RichTbLHCbExptHall::RichTbLHCbExptHall() {


RichTbMaterial * RMaterial = RichTbMaterial::getRichTbMaterialInstance();

G4Box* RichTbLHCbHallBox 
  = new G4Box("WorldBox",RichTbLHCbExpHallHalfX,
                      RichTbLHCbExpHallHalfY,RichTbLHCbExpHallHalfZ);

rTbLHCbExptHallLVol
  = new G4LogicalVolume(RichTbLHCbHallBox,RMaterial->getAir(),"WorldLog",0,0,0);

rTbLHCbExptHallPVol
  = new  G4PVPlacement(0,G4ThreeVector(),"WorldPhys",rTbLHCbExptHallLVol,0,false,0);


}
RichTbLHCbExptHall::~RichTbLHCbExptHall() { ; }
