// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1Pmt.hh"
#include "RichTbLHCbR1PmtComponents.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbRODummySD.hh"

#include <iostream>
#include <string>
//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbR1Module : Pmt EC
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1PmtComponents::RichTbLHCbR1PmtComponents(RichTbLHCbR1Pmt * rTbR1mt ) {
  mTbR1Pmt = rTbR1mt ;
  constructR1PmtSubMaster();
  constructR1PmtAnode();

}
RichTbLHCbR1PmtComponents::~RichTbLHCbR1PmtComponents() {; }

void RichTbLHCbR1PmtComponents::constructR1PmtSubMaster() {
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * aR1PmtSMasterBox = new G4Box("R1PmtSubMasterBox",
					0.5*RichLbPMTSMasterBoxXSize,
                                        0.5*RichLbPMTSMasterBoxYSize,
					0.5*RichLbPMTSMasterBoxZSize);

   G4RotationMatrix aR1PmtSMRot;
   G4ThreeVector aR1PmtSMPos(0.0,0.0,0.0);
   G4Transform3D aR1PmtSMPosTrans( aR1PmtSMRot,aR1PmtSMPos);
   rTbR1PmtSubMasterLVol = new G4LogicalVolume(aR1PmtSMasterBox,
               aMaterial->getRichTbVaccum(), RichTbLbPmtSMLogName,0,0,0);

    rTbR1PmtSubMasterPVol = new G4PVPlacement(aR1PmtSMPosTrans,
        rTbR1PmtSubMasterLVol,
	RichTbLbPmtSMPhysBaseName+"Common", 
        mTbR1Pmt-> getRichTbLbR1PmtLogicalVolume(),false,1 ) ;

     
   
   //rTbR1PmtSubMasterPVol.resize(RichTbLbNumModules,
   // std::vector<std::vector<G4VPhysicalVolume*> >(RichTbLbNumECInModule,
   // std::vector<G4VPhysicalVolume* >(RichTbLbNumPmtInEC)));
   // rTbR1PmtSubMasterPVol = new G4PVPlacement(aR1PmtSMPosTrans,rTbR1PmtSubMasterLVol,
   //		       RichTbLbPmtSMPhysBaseName+"Common", mTbR1Pmt->       
   /*
   for (int iM =0; iM <  RichTbLbNumModules; iM++ ) {
     std::string aMStr = std::to_string(iM);
     for (int iec=0; iec<RichTbLbNumECInModule; iec++) {
        std::string aECnameStr = std::to_string(iec);
        for (int ip =0; ip<RichTbLbNumPmtInEC ; ip++) {
          std::string aPmtNameStr= std::to_string(ip);
	  rTbR1PmtSubMasterPVol[iM] [iec] [ip]  = new G4PVPlacement(aR1PmtSMPosTrans,
		     RichTbLbPmtSMPhysBaseName+aMStr+"_"+aECnameStr+"_"+aPmtNameStr,
		     rTbR1PmtSubMasterLVol,
		     mTbR1Pmt->getRichTbLbR1PmtPhysicalVolume(ip,iec,iM),false,1);

	}
     }

   }
   */

}
void RichTbLHCbR1PmtComponents::constructR1PmtAnode() {
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * aR1PmtAnodeBox = new G4Box("R1PmtAnodeBox",
					0.5* RichLbPMTAnodeXSize,
                                        0.5* RichLbPMTAnodeYSize,
					0.5* RichLbPMTAnodeZSize);
   G4RotationMatrix aR1PmtAnodeRot;
   G4ThreeVector aR1PmtAnodePos(0.0,0.0,RichLbPMTAnodePosZ);
   G4Transform3D aR1PmtAnodeTrans( aR1PmtAnodeRot,aR1PmtAnodePos);
   rTbR1PmtAnodeLVol = new G4LogicalVolume(aR1PmtAnodeBox,aMaterial-> getPMTAnodeMaterial(),
					   RichTbLbPmtAnodeLogName,0,0,0);
   rTbR1PmtAnodePVol =  new G4PVPlacement(aR1PmtAnodeTrans, rTbR1PmtAnodeLVol,
					  RichTbLbPmtAnodePhysName,
                                          rTbR1PmtSubMasterLVol,false,1);

					  
}

void RichTbLHCbR1PmtComponents::constructR1PmtComp() {
 RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
    G4Box * aR1PmtQuartzBox = new G4Box("R1PmtQuartzBox",
					0.5* RichLbPMTQuartzXSize,
                                        0.5* RichLbPMTQuartzYSize,
					0.5* RichLbPMTQuartzZSize);
    G4Box * aR1PmtPhCathBox = new G4Box("R1PmtPhCathBox",
					0.5* RichLbPMTPhCathXSize,
                                        0.5* RichLbPMTPhCathYSize,
					0.5* RichLbPMTPhCathZSize);

    G4Box * aR1PmtFrontRingFullBox = new G4Box("R1PmtPhFrontRingFullBox",
					0.5* RichLbPMTFrontRingXSize,
                                        0.5* RichLbPMTFrontRingYSize,
					0.5* RichLbPMTFrontRingZSize);

    G4Box * aR1PmtFrontRingSubBox = new G4Box("R1PmtPhFrontRingSubBox",
					0.5* RichLbPMTFrontRingSubBoxXSize,
                                        0.5* RichLbPMTFrontRingSubBoxYSize,
					0.5* RichLbPMTFrontRingSubBoxZSize);
    G4RotationMatrix aR1PmtFrontRingSubBoxRot;
    G4ThreeVector aR1PmtFrontRingSubBoxPos(RichLbPMTFrontRingSubBoxXPos,
					   RichLbPMTFrontRingSubBoxYPos,
                                           RichLbPMTFrontRingSubBoxZPos);

    G4Transform3D aR1PmtFrontRingSubBoxTrans(aR1PmtFrontRingSubBoxRot,
                                             aR1PmtFrontRingSubBoxPos);
    G4SubtractionSolid*  aR1PmtFrontRingBox = new G4SubtractionSolid("R1PmtFrontRingBox",
		aR1PmtFrontRingFullBox,aR1PmtFrontRingSubBox,aR1PmtFrontRingSubBoxTrans);

    G4Box * aR1PmtSideEnvFullBox = new G4Box("R1PmtSideEnvFullBox",
					0.5*  RichLbPMTSideEnvelopeXSize,
                                        0.5*  RichLbPMTSideEnvelopeYSize,
					0.5*   RichLbPMTSideEnvelopeZSize);
    G4Box * aR1PmtSideEnvSubBox = new G4Box("R1PmtSideEnvSubBox",
					0.5*  RichLbPMTSideEnvelopeSubBoxXSize,
                                        0.5*  RichLbPMTSideEnvelopeSubBoxYSize,
					0.5*  RichLbPMTSideEnvelopeSubBoxZSize);
    G4RotationMatrix aR1PmtSideEnvSubRot;
    G4ThreeVector aR1PmtSideEnvSubPos(RichLbPMTSideEnvelopeSubBoxXPos,
                                      RichLbPMTSideEnvelopeSubBoxYPos,
                                      RichLbPMTSideEnvelopeSubBoxZPos);
    G4Transform3D aR1PmtSideEnvSubTrans(aR1PmtSideEnvSubRot,aR1PmtSideEnvSubPos);
    G4SubtractionSolid* aR1PmtSideEnvBox= new G4SubtractionSolid("R1PmtSideEnvBox",
								 aR1PmtSideEnvFullBox,
								 aR1PmtSideEnvSubBox,
                                                               aR1PmtSideEnvSubTrans );    
    

   G4RotationMatrix aR1PmtQuartzRot;
   G4ThreeVector aR1PmtQuartzPos(0.0,0.0,RichLbPMTQuartzPosZ);
   G4Transform3D aR1PmtQuartzTrans( aR1PmtQuartzRot,aR1PmtQuartzPos);

   G4RotationMatrix aR1PmtPhCathRot;
   G4ThreeVector aR1PmtPhCathPos(0.0,0.0,RichLbPMTPhCathPosZ);
   G4Transform3D aR1PmtPhCathTrans( aR1PmtPhCathRot,aR1PmtPhCathPos);

   G4RotationMatrix aR1PmtFrontRingRot;
   G4ThreeVector aR1PmtFrontRingPos(0.0,0.0,RichLbPMTFrontRingPosZ);
   G4Transform3D aR1PmtFrontRingTrans( aR1PmtFrontRingRot,aR1PmtFrontRingPos);

   G4RotationMatrix aR1PmtSideEnvRot;
   G4ThreeVector aR1PmtSideEnvPos(0.0,0.0,RichLbPMTSideEnvelopePosZ);
   G4Transform3D aR1PmtSideEnvTrans( aR1PmtSideEnvRot,aR1PmtSideEnvPos);
  

   rTbR1PmtQuartzLVol = new G4LogicalVolume(aR1PmtQuartzBox,
        aMaterial->getPMTQuartzWindowMaterial(),RichTbLbPmtQuartzLogName,0,0,0);

   rTbR1PmtPhCathLVol = new G4LogicalVolume(aR1PmtPhCathBox,
	aMaterial->getPMTPhCathodeMaterial(),RichTbLbPmtPhCathLogName,0,0,0);

   rTbR1PmtFrontRingLVol = new G4LogicalVolume(aR1PmtFrontRingBox,
        aMaterial->getPMTFrontRingMaterial(),RichTbLbPmtFrontRingLogName,0,0,0);

    rTbR1PmtSideEnvelopeLVol = new G4LogicalVolume(aR1PmtSideEnvBox,
        aMaterial->getPMTTubeEnvelopeMaterial(),RichTbLbPmtSideEnvLogName,0,0,0);



   rTbR1PmtQuartzPVol = new G4PVPlacement(aR1PmtQuartzTrans,rTbR1PmtQuartzLVol,
               RichTbLbPmtQuartzPhysName,rTbR1PmtSubMasterLVol,false,2);

   rTbR1PmtPhCathPVol = new G4PVPlacement(aR1PmtPhCathTrans,rTbR1PmtPhCathLVol,
               RichTbLbPmtPhCathPhysName,rTbR1PmtSubMasterLVol,false,3);

   rTbR1PmtFrontRingPVol = new G4PVPlacement(aR1PmtFrontRingTrans,rTbR1PmtFrontRingLVol,
               RichTbLbPmtFrontRingPhysName,rTbR1PmtSubMasterLVol,false,4);
					  
   rTbR1PmtSideEnvelopePVol = new G4PVPlacement(aR1PmtSideEnvTrans ,rTbR1PmtSideEnvelopeLVol ,
               RichTbLbPmtSideEnvPhysName,rTbR1PmtSubMasterLVol,false,5);

}
void RichTbLHCbR1PmtComponents::constructR1PmtAnodePixel() {
   RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();
   G4Box* PMTSiPxBox =
	       new G4Box("PMTAnodePxBox",0.5*RichLbPMTPixelXSize,0.5*RichLbPMTPixelYSize,
					0.5* RichLbPMTPixelZSize);
   rTbR1PmtPixelLVol =   new G4LogicalVolume( PMTSiPxBox,
					aMaterial->getPMTAnodeMaterial(),
					"RichTbPMTAnodePxLog",0,0,0);
//Now for the readout dummy sensitive detector
   G4bool thisPixelisAlive=true;
   if(thisPixelisAlive){
	   RichTbLHCbRODummySD * DummySensi = new RichTbLHCbRODummySD;
	   rTbR1PmtPixelLVol ->SetSensitiveDetector(DummySensi);
   }

	G4RotationMatrix  PMTAnodePxRot;
	G4double aPixelColStartX = -0.5*( RichLbPMTNumPixelsInRow-1)*RichLbPMTPixelXSize;
	G4double aPixelColStartY = -0.5*(RichLbPMTNumPixelsInCol-1)*RichLbPMTPixelYSize;
	rTbR1PmtPixelPVol.resize(RichLbNumPixelsInPmt);

	for(G4int iPixelRowY = 0; iPixelRowY <RichLbPMTNumPixelsInCol  ; iPixelRowY++){
		G4double curPixelPosY =   aPixelColStartY +  iPixelRowY*RichLbPMTPixelYSize;
		for (G4int iPixelColX = 0; iPixelColX < RichLbPMTNumPixelsInRow ; iPixelColX++){

			G4int PixelCopyNumber = iPixelColX + iPixelRowY*NumPixelInPmtRow;
                        G4String PixelCopyStr= std::to_string(PixelCopyNumber);

			G4double curPixelPosX =   aPixelColStartX +  iPixelColX*RichLbPMTPixelXSize ;

			G4ThreeVector PMTAnodePxPos(curPixelPosX, curPixelPosY, RichLbPMTPixelPosZ);
			G4Transform3D PMTAnodePxTransform(PMTAnodePxRot, PMTAnodePxPos);
                       
                        rTbR1PmtPixelPVol[PixelCopyNumber] =
			  new G4PVPlacement(  PMTAnodePxTransform,("PMTAnodePxPhys"+PixelCopyStr),
					      rTbR1PmtPixelLVol,rTbR1PmtAnodePVol,false, PixelCopyNumber);
                       

		}
        }

   
}
