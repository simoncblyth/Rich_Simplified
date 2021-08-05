// Include files 

#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"

#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "G4SubtractionSolid.hh"


// local
#include "RichTbMirrorSph.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbMirrorSph
//
// 2017-03-23 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbMirrorSph::RichTbMirrorSph( RichTbContainerVesselBox* aVessel  ) {
   aCVessel = aVessel;
   constructRichMirrSph();

}
//=============================================================================
// Destructor
//=============================================================================
RichTbMirrorSph::~RichTbMirrorSph() {} 

//=============================================================================
void RichTbMirrorSph::constructRichMirrSph() {


  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  //RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

  G4Sphere* MirrSph = new G4Sphere ( "MirrSphSeg", MirrorSphInnerROC, MirrorSphOuterROC,MirrSphPhiStart , MirrorSphPhiSize,
                                     MirrSphThetaStart,MirrorSphThetaSize);
  G4RotationMatrix MirrorSphRotationX, MirrorSphRotationY;

  G4ThreeVector MirrorSphPos ( MirrorSphXLocation , MirrorSphYLocation, MirrorSphZLocation); 
  MirrorSphRotationX.rotateX(MirrorSphXRotation);
  MirrorSphRotationY.rotateY(MirrorSphYRotation);

  G4Transform3D MirrorSphTransform (  MirrorSphRotationX * MirrorSphRotationY , MirrorSphPos);
  
  G4LogicalVolume* MirrorSphLog = new G4LogicalVolume(MirrSph, aMaterial->getMirrorQuartz(), MirrSphLogName,0,0,0);
  
  G4VPhysicalVolume* MirrorSphPhys= new G4PVPlacement( MirrorSphTransform,MirrSphPhysName, 
                                                       MirrorSphLog,aCVessel->getRichTbContainerVesselBoxPVol(), false,0);
  

  RichTbMirrSphLVol =  MirrorSphLog;
  RichTbMirrSphPVol =  MirrorSphPhys;
  
}
