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
#include "RichTbMirrorParabola.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbMirrorParabola
//
// 2017-03-17 : Sajan Easo
//-----------------------------------------------------------------------------


//=============================================================================
// Standard constructor, initializes variables
//=============================================================================

RichTbMirrorParabola::RichTbMirrorParabola(RichTbContainerVesselBox* aVessel  ) {

  aCVessel = aVessel;
  
  constructRichMirrParabola();

}
//=============================================================================
// Destructor
//=============================================================================
RichTbMirrorParabola::~RichTbMirrorParabola() {} 

//=============================================================================

void   RichTbMirrorParabola::constructRichMirrParabola(){


  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();
 
  G4Paraboloid  * aMirrPOuterBox = new G4Paraboloid ("RichTbMirrParabOuter", 0.5*MirrorParabOuterLength  , 
                                                0.5*MirrorParbDnsOuterCentralHoleDiameter, 0.5* MirrorParbDnsOuterDiameter );
  

  G4Paraboloid  * aMirrPInnerBox = new G4Paraboloid ("RichTbMirrParabInnerSub", 
                                                     0.5* MirrorParabLength  , 
                                                     0.5* MirrorParabCenterHoleDiameter , 0.5* MirrorParbDnsDiameter );

  G4Tubs * aMirrorPHole = new G4Tubs("RichTbParabHole", 0.0*(CLHEP::mm), 0.5* MirrorParabCenterHoleDiameter,  MirrorParabHoleLargeZSize,
                                     MirrParabCylSPhi, MirrParabCylDPhi);
  
  


  G4ThreeVector ParabInnerPos( 0.0, 0.0,  MirrorParabThickness);
    
  G4RotationMatrix ParabInnerRotX, ParabInnerRotY, ParabHRotX, ParabHRotY;
  G4ThreeVector ParabHolePos(0.0,0.0,0.0);
  
  
  G4Transform3D MirrPSubTransform( ParabInnerRotX *  ParabInnerRotY ,  ParabInnerPos);
  
  G4Transform3D aMirrorPHoleTransform( ParabHRotX * ParabHRotY, ParabHolePos);
  

  G4SubtractionSolid*  aMirrParabS1 = new  G4SubtractionSolid("RichTbMirrParabS1", aMirrPOuterBox, 
                                         aMirrPInnerBox, MirrPSubTransform);
  
  G4SubtractionSolid*  aMirrParab  =  new  G4SubtractionSolid("RichTbMirrParab", aMirrParabS1, aMirrorPHole, 
                                                              aMirrorPHoleTransform);
  


  G4ThreeVector  aMirrPrabPos ( MirrorParabPosX,MirrorParabPosY,MirrorParabPosZ);

  G4RotationMatrix aMirrPrabRotX, aMirrPrabRotY;
  aMirrPrabRotX.rotateX(MirrorParabRotX);
  aMirrPrabRotY.rotateY(MirrorParabRotY);
  
  
  G4Transform3D  aMirrPrabTransform (aMirrPrabRotX * aMirrPrabRotY , aMirrPrabPos);
  
  G4LogicalVolume*  MirrPLog = new  G4LogicalVolume( aMirrParab, aMaterial-> getMirrorQuartz(), 
                                                     MirrParabolaLogName, 0,0,0);
  
  G4VPhysicalVolume* MirrPPhys = new G4PVPlacement(aMirrPrabTransform, MirrParabolaPhysName, 
                                                   MirrPLog ,  aCVessel ->getRichTbContainerVesselBoxPVol() ,
                                                  false,0);  

  RichTbMirrParabolaLVol  = MirrPLog;
  RichTbMirrParabolaPVol  =  MirrPPhys;
  

}
