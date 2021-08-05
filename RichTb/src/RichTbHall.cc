#include "G4Box.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"

#include <iostream>

#include "RichTbUpgradeDetectorConstruction.hh"
#include "RichTbHall.hh"
#include "RichTbMaterial.hh"
#include "RichTbGeometryParameters.hh"

RichTbHall::RichTbHall()
{


  RichTbMaterial * RMaterial = RichTbMaterial::getRichTbMaterialInstance();
  
  G4Box * RichTbHallBox
    = new G4Box("World",ExpHallHalfX,ExpHallHalfY,ExpHallHalfZ);
  G4LogicalVolume * RichTbHallLog
    = new G4LogicalVolume(RichTbHallBox,RMaterial->getRichTbVaccum(),"World",0,0,0);
  G4VPhysicalVolume * RichTbHallPhys
    = new G4PVPlacement(0,G4ThreeVector(),"World",RichTbHallLog,0,false,0);

  RichTbHallLVol  = RichTbHallLog;
  RichTbHallPVol  = RichTbHallPhys;

}


RichTbHall::~RichTbHall()
{
    ;
}
