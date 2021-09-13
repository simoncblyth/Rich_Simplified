// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1PhDetSupFrame.hh"
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
// Implementation file for class : RichTbLHCbR1PhDetSupFrame
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1PhDetSupFrame::RichTbLHCbR1PhDetSupFrame(RichTbLHCbR1MagShRegion* rMagShRegion) {
  mMagShRegion = rMagShRegion;
  constructPhDetSupFrame();
  constructPhDetModuleBackPl();

}

RichTbLHCbR1PhDetSupFrame::~RichTbLHCbR1PhDetSupFrame() {; }

void RichTbLHCbR1PhDetSupFrame::constructPhDetSupFrame() {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * R1PhDetSupFrameBox = new G4Box ( "R1PhDetSupFrameBox", 
            RichTbR1PhDetSupFrameHalfSizeX,RichTbR1PhDetSupFrameHalfSizeY, 
            RichTbR1PhDetSupFrameHalfSizeZ);
   G4RotationMatrix rTbR1PhDetSupFrameRotX;
   rTbR1PhDetSupFrameRotX.rotateX( RichTbR1PhDetSupFrameRotX);
   G4ThreeVector RichTbR1PhDetSupFramePos( RichTbR1PhDetSupFramePosX , 
                 RichTbR1PhDetSupFramePosY,RichTbR1PhDetSupFramePosZ );
   G4Transform3D RichTbR1PhDetSupFrameTrans (rTbR1PhDetSupFrameRotX,
                                             RichTbR1PhDetSupFramePos);
   rTbR1PhDetSupFrameLVol= new G4LogicalVolume(R1PhDetSupFrameBox,
	      aMaterial->getNitrogenGas(),RichTbR1PhDetSupportLogName,0,0,0);
   rTbR1PhDetSupFramePVol = new G4PVPlacement(RichTbR1PhDetSupFrameTrans,
		RichTbR1PhDetSupportPhysName,rTbR1PhDetSupFrameLVol,
	       mMagShRegion-> getRichTbLHCbR1MagShRegionPhysicalVolume(),false,1);

}

void RichTbLHCbR1PhDetSupFrame::constructPhDetModuleBackPl() {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * aR1ModuleBackPlBox =  new G4Box ("R1ModuleBackPlBox", 0.5 * RichTbLbModuleBackPlXSize, 0.5 * RichTbLbModuleBackPlYSize,0.5 *RichTbLbModuleBackPlZSize );
   G4ThreeVector aR1ModuleBackPlPos(RichTbLbModuleBackPlXPos,
          RichTbLbModuleBackPlYPos ,RichTbLbModuleBackPlZPos);
   G4RotationMatrix aR1ModuleBackPlRot;
   G4Transform3D aR1ModuleBackPlTrans (aR1ModuleBackPlRot,aR1ModuleBackPlPos);
   rTbLbR1ModuleBackPlLVol = new G4LogicalVolume(aR1ModuleBackPlBox,aMaterial->getPMTModuleBackPlMaterial(),
						 RichTbLbModuleBackPlLogBaseName,0,0,0);

         
    rTbLbR1ModuleBackPlPVol = new G4PVPlacement(aR1ModuleBackPlTrans,rTbLbR1ModuleBackPlLVol,
		       RichTbLbModuleBackPlPhysBaseName,rTbR1PhDetSupFrameLVol ,false, 200);
		      

}



