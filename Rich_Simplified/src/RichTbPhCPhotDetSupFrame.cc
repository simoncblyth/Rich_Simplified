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
#include "RichTbPhCPhotDetSupFrame.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbPhCPhotDetSupFrame
//
// 2017-03-25 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbPhCPhotDetSupFrame::RichTbPhCPhotDetSupFrame(RichTbContainerVesselBox* aVessel  ) {
  aCVessel = aVessel;
  
  constructRichTbPhCSupFrame();
  
  constructRichTbPhCDetPlaneSegment();
  
  
      
}
//=============================================================================
// Destructor
//=============================================================================
RichTbPhCPhotDetSupFrame::~RichTbPhCPhotDetSupFrame() {} 

//=============================================================================

void RichTbPhCPhotDetSupFrame::constructRichTbPhCSupFrame(){
  

  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();
  
  G4int aQWRadiatorInstallConfig =  aConfig ->getQWRadInstallFlag();
 
  G4Box * RichTbPhCFrameBox = new G4Box ( "RichTbPhCFrameBox", 0.5*PhCPhotDetSupFrameXSize, 
                                          0.5*PhCPhotDetSupFrameYSize,
                                          0.5*PhCPhotDetSupFrameZSize);

  G4double aPXPos = (aQWRadiatorInstallConfig == 0) ?   PhCPhotDetSupFrameXPos :  PhCPhotDetSupFrameQWXPos;
  G4double aPZPos = (aQWRadiatorInstallConfig == 0) ?   PhCPhotDetSupFrameZPos :  PhCPhotDetSupFrameQWZPos;
  

  //  G4ThreeVector RichTbPhCFramePos ( PhCPhotDetSupFrameXPos, PhCPhotDetSupFrameYPos,PhCPhotDetSupFrameZPos);

  G4ThreeVector RichTbPhCFramePos ( aPXPos,PhCPhotDetSupFrameYPos, aPZPos);

  G4RotationMatrix PhCFrameRotX, PhCFrameRotY;
  PhCFrameRotX.rotateX(PhCPhotDetSupFrameRotX);
  PhCFrameRotY.rotateY(PhCPhotDetSupFrameRotY);
  G4Transform3D RichTbPhCFrameTransform(PhCFrameRotX*PhCFrameRotY, RichTbPhCFramePos);
  
  G4LogicalVolume*  PhCFrameLog = new G4LogicalVolume(RichTbPhCFrameBox, aMaterial->getNitrogenGas(),
                                                      RichTbPhCFrameLogName,0,0,0);
  G4VPhysicalVolume* PhCFramePhys =  new G4PVPlacement( RichTbPhCFrameTransform,RichTbPhCFramePhysName,PhCFrameLog,
                                                        aCVessel ->getRichTbContainerVesselBoxPVol(),  
                                                        false,0);
  RichTbPhCSupFrameLVol = PhCFrameLog;
  RichTbPhCSupFramePVol =  PhCFramePhys;
  
}

void RichTbPhCPhotDetSupFrame::constructRichTbPhCDetPlaneSegment() {

  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

  G4Box * RichTbPhCPlaneBox = new G4Box ("RichTbPhCDetPlaneBox", 0.5* PhCDetPlaneSegXSize, 
                           0.5*PhCDetPlaneSegYSize, 0.5* PhCDetPlaneSegZSize);
  G4ThreeVector RichTbPhCPlanePos(PhCDetPlaneXPos,PhCDetPlaneYPos,PhCDetPlaneZPos);
  G4RotationMatrix  PhCPlaneRotX, PhCPlaneRotY;
  PhCPlaneRotX.rotateX(PhCDetPlaneInSupFrameRotX);
  PhCPlaneRotY.rotateY(PhCDetPlaneInSupFrameRotY);
  G4Transform3D  PhCPlaneTransform( PhCPlaneRotX * PhCPlaneRotY, RichTbPhCPlanePos);
  G4LogicalVolume*  PhCPlaneLog = new G4LogicalVolume(RichTbPhCPlaneBox, aMaterial->getCarbon(), RichTbPhCPlaneLogName,
                                                      0,0,0);
  G4VPhysicalVolume* PhCPlanePhys = new G4PVPlacement(PhCPlaneTransform,RichTbPhCPlanePhysName,
                                                      PhCPlaneLog,RichTbPhCSupFramePVol,false,0);

  RichTbPhCDetPlaneSegmentLVol = PhCPlaneLog;
  RichTbPhCDetPlaneSegmentPVol = PhCPlanePhys;

}
