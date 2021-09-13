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
#include "RichTbLHCbR1QW.hh"
#include <iostream>
//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbR1QW
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1QW::RichTbLHCbR1QW(RichTbLHCbR1MagShRegion * rTbR1MagShRegion ) {
  mTbR1MagShRegion = rTbR1MagShRegion;
  constructR1QW();
}
RichTbLHCbR1QW::~RichTbLHCbR1QW() { ;}
void RichTbLHCbR1QW::constructR1QW() {
 RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
 G4Box * RichTbR1QwBox = new  G4Box("RichTbR1QwBox", RichTbR1QWHalfXSize, RichTbR1QWHalfYSize,
				   RichTbR1QWHalfZSize);
 G4RotationMatrix RichTbR1QwRot;
 RichTbR1QwRot.rotateX(RichTbR1QWRotX);
 G4ThreeVector RichTbR1QwPos(RichTbR1QWPosX,RichTbR1QWPosY,RichTbR1QWPosZ);
 G4Transform3D RichTbR1QwTrans(RichTbR1QwRot, RichTbR1QwPos);
 rTbR1QWLVol = new G4LogicalVolume(RichTbR1QwBox,aMaterial->getRichTbGasWinQuartz(),RichTbR1QwLogName,
				   0,0,0);
 rTbR1QWPVol = new G4PVPlacement(RichTbR1QwTrans,RichTbR1QwPhysName,rTbR1QWLVol,
				  mTbR1MagShRegion->getRichTbLHCbR1MagShRegionPhysicalVolume() ,false,1);


}
