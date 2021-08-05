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
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "G4Paraboloid.hh"
#include "G4SubtractionSolid.hh"




// local
#include "RichTbLargeMirrorParabola.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLargeMirrorParabola
//
// 2017-06-06 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbLargeMirrorParabola::RichTbLargeMirrorParabola( RichTbContainerVesselBox* aVessel  ) {

  aCVessel = aVessel;
  constructRichTbLargeMirrorParabola();


}
//=============================================================================
// Destructor
//=============================================================================
RichTbLargeMirrorParabola::~RichTbLargeMirrorParabola() {} 

//=============================================================================
void RichTbLargeMirrorParabola::constructRichTbLargeMirrorParabola(){
   
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();  
  // RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

  G4Paraboloid  * aLargeMirrPOuterBox = new G4Paraboloid ("RichTbLargeMirrParabOuter", 
                                                          0.5*LargeMirrorParabolaOuterLength,
                                                          0.5* LargeMirrorParabDnsOuterCenterHoleDiameter, 
                                                          0.5* LargeMirrorParabolaDnsOuterDiameter);
  
  G4Paraboloid  * aLargeMirrPInnerBox = new G4Paraboloid ("RichTbLargeMirrParabInnerSub",
                                                          0.5*LargeMirrorParabLength,
                                                          0.5*LargeMirrorParabCenterHoleDiameter,
                                                          0.5* LargeMirrorParbDnsDiameter);

  G4ThreeVector LargeParabInnerPos( 0.0, 0.0,  LargeMirrorParabolaThickness );  


  G4RotationMatrix LParabInnerRotX, LParabInnerRotY;
  
  G4Transform3D LMirrPSubTransform( LParabInnerRotX *  LParabInnerRotY ,  LargeParabInnerPos);    
  G4SubtractionSolid*  aLargeMirrParab = new  G4SubtractionSolid("RichTbLargeMirrParab", aLargeMirrPOuterBox ,
                                                                 aLargeMirrPInnerBox , LMirrPSubTransform );
  
  G4ThreeVector  aLMirrPrabPos ( LargeMirrorParabolaXLocation,LargeMirrorParabolaYLocation,LargeMirrorParabolaZLocation);
  
  G4RotationMatrix aLMirrPrabRotX, aLMirrPrabRotY;
  aLMirrPrabRotX.rotateX(LargeMirrorParabolaXRotation);
  aLMirrPrabRotY.rotateY(LargeMirrorParabolaYRotation);
  
  G4Transform3D  aLMirrPrabTransform (aLMirrPrabRotX *  aLMirrPrabRotY,aLMirrPrabPos );
  G4LogicalVolume*  MirrLargePLog = new  G4LogicalVolume(aLargeMirrParab, aMaterial-> getMirrorQuartz(), 
                                                         LargeMirrParabolaLogName,  0,0,0);
  
  G4VPhysicalVolume* MirrLargePPhys = new G4PVPlacement( aLMirrPrabTransform, LargeMirrParabolaPhysName,
                                                         MirrLargePLog,aCVessel ->getRichTbContainerVesselBoxPVol() ,
                                                         false,0);
  
  RichTbLargeMirrorParabolaLVol = MirrLargePLog;
  RichTbLargeMirrorParabolaPVol = MirrLargePPhys;
  
}
