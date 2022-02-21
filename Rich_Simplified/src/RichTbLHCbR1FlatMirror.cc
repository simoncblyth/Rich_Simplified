// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1FlatMirror.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterial.hh"

#include <iostream>
//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbR1FlatMirror
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1FlatMirror::RichTbLHCbR1FlatMirror(RichTbLHCbRich1SubMaster* rTbLHCbR1SubMaster, bool tinyFlatMirror) {
  mTbLHCbR1SubMaster = rTbLHCbR1SubMaster;
  m_tinyFlatMirror = tinyFlatMirror;
  constructLbR1FlatMirror();
}

RichTbLHCbR1FlatMirror::~RichTbLHCbR1FlatMirror() {; }

void RichTbLHCbR1FlatMirror::constructLbR1FlatMirror() {
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  
    
  G4Sphere* RichTbR1FlatFull = new G4Sphere ("RichTbR1FlatFull",RichTbR1FlatMirrInnerRadius,
                                           RichTbR1FlatMirrOuterRadius,RichTbR1FlatMirrStartPhi,
                                           RichTbR1FlatMirrDeltaPhi, RichTbR1FlatMirrStartTheta,
                                           RichTbR1FlatMirrDeltaTheta);

   G4RotationMatrix MirrFlatRotationX,MirrFlatRotationY;
   MirrFlatRotationX.rotateX(RichTbR1FlatMirrRotX);
   MirrFlatRotationY.rotateY(RichTbR1FlatMirrRotY);
   G4ThreeVector  MirrFlatPos (RichTbR1FlatMirrPosX,RichTbR1FlatMirrPosY,RichTbR1FlatMirrPosZ);

   
   G4Transform3D MirrFlatTransform (MirrFlatRotationX * MirrFlatRotationY, MirrFlatPos  ) ;
   rTbR1FlatMirrorLVol = 
        new G4LogicalVolume(RichTbR1FlatFull, aMaterial->getMirrorQuartz(),RichTbR1FlatMirrorLogName,0,0,0);
   rTbR1FlatMirrorPVol = new G4PVPlacement(MirrFlatTransform,RichTbR1FlatMirrorPhysName,rTbR1FlatMirrorLVol,
					   mTbLHCbR1SubMaster->getRichTbLHCbRich1SubMasterPhysicalVolume(),false,1);

}                                          

