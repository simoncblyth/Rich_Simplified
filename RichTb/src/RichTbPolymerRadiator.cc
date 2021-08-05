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
#include "RichTbPolymerRadiator.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbPolymerRadiator
//
// 2017-03-15 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbPolymerRadiator::RichTbPolymerRadiator(  RichTbContainerVesselBox* aVessel  ) {

  aCVessel = aVessel ;
  constructPolymerPlusGeometry();


}
//=============================================================================
// Destructor
//=============================================================================
RichTbPolymerRadiator::~RichTbPolymerRadiator() {} 

//=============================================================================


void RichTbPolymerRadiator::constructPolymerPlusGeometry(){
  
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

  G4Box *  RichTbPolymerBox = 
    new G4Box("RichTbPolymerBox", 0.5*PolymerPlusRadiatorXSize, 0.5*PolymerPlusRadiatorYSize, 0.5*PolymerPlusRadiatorZSize);
  
  G4ThreeVector  RichTbPolymerPos (PolymerPlusRadiatorXLocation,PolymerPlusRadiatorYLocation,PolymerPlusRadiatorZLocation);
  
  G4RotationMatrix PolymerPlusRadiatorRotX,PolymerPlusRadiatorRotY;
  PolymerPlusRadiatorRotX.rotateX( PolymerPlusRadiatorXRotation);
  PolymerPlusRadiatorRotY.rotateY( PolymerPlusRadiatorYRotation);
  
  G4Transform3D PolymerTransform(PolymerPlusRadiatorRotX * PolymerPlusRadiatorRotY, RichTbPolymerPos);
  
  G4LogicalVolume* PolymerRadiatorLog = 
    new  G4LogicalVolume( RichTbPolymerBox, aMaterial->getPolymerPlusMaterial(), RichTbPolymerLogName, 0,0,0);
  
  G4VPhysicalVolume*  PolymerRadiatorPhys =
    new G4PVPlacement( PolymerTransform, RichTbPolymerPhysName,PolymerRadiatorLog,
                       aCVessel ->getRichTbContainerVesselBoxPVol() , false, 0);
  
  
  RichTbPolymerPlusLVol = PolymerRadiatorLog ;
  RichTbPolymerPlusPVol = PolymerRadiatorPhys;

}
