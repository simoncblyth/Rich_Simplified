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



// local
#include "RichTbContainerVesselBox.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbContainerVesselBox
//
// 2017-03-14 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbContainerVesselBox::RichTbContainerVesselBox(RichTbHall* rTbHall  ) {

  aRTbHall = rTbHall;

  constructRichTbContainerVesselBox();


}
//=============================================================================
// Destructor
//=============================================================================
RichTbContainerVesselBox::~RichTbContainerVesselBox() {} 

//=============================================================================
void RichTbContainerVesselBox::constructRichTbContainerVesselBox(){

  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  //  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();


 G4Box * RichTbContainerVesselBox  =
   new G4Box("RichTbContainerVesselBox", 0.5*RichTbContainerVesselBoxXSize,  0.5*RichTbContainerVesselBoxYSize, 
             0.5*RichTbContainerVesselBoxZSize);

 G4ThreeVector RichTbContainerVesselPos( RichTbContainerVesselBoxXLocation,
                                         RichTbContainerVesselBoxYLocation,
                                         RichTbContainerVesselBoxZLocation);
 G4RotationMatrix CVesselRotX,CVesselRotY;
 CVesselRotX.rotateX(RichTbContainerVesselBoxXRotation);
 CVesselRotY.rotateY(RichTbContainerVesselBoxYRotation);
 

 G4Transform3D CVesselTransform(  CVesselRotX * CVesselRotY , RichTbContainerVesselPos  );
  
 G4LogicalVolume* CVesselLog = 
   new G4LogicalVolume(RichTbContainerVesselBox, aMaterial->getNitrogenGas(), RichTbContainerVesselLogName,0,0,0);

 G4VPhysicalVolume* CVesselPhys =
   new G4PVPlacement( CVesselTransform,RichTbContainerVesselPhysName ,
                      CVesselLog,  aRTbHall->getRichTbHallPhysicalVolume(),false,0);
 
 RichTbContainerVesselBoxLVol=CVesselLog;
 RichTbContainerVesselBoxPVol=CVesselPhys;
 
}
