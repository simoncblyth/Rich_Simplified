// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1Pmt.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterial.hh"

#include <iostream>
#include <string>
//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbR1Module : Pmt EC
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1Pmt::RichTbLHCbR1Pmt(RichTbLHCbR1EC * rTbR1EC ) {
  mTbR1EC=rTbR1EC;
  constructLbR1Pmt();

}
RichTbLHCbR1Pmt::~RichTbLHCbR1Pmt() {;}
void RichTbLHCbR1Pmt::constructLbR1Pmt() {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   //G4bool aTestGraphicsSinglePmt = true;
    G4bool aTestGraphicsSinglePmt = false;

 
   G4Box * aR1PmtMasterBox = new G4Box("R1PmtMasterBox", 0.5 * RichLbPMTMasterBoxXSize ,
				       0.5 * RichLbPMTMasterBoxYSize , 
                                       0.5 * RichLbPMTMasterBoxZSize);

   G4RotationMatrix aR1PmtMasterRotY;
   aR1PmtMasterRotY.rotateY(RichLbPmtMasterInECRotY );  


   //rTbLbR1PmtLVol.resize(RichTbLbNumModules, 
   // std::vector<std::vector<G4LogicalVolume*> >(RichTbLbNumECInModule,
   // std::vector<G4LogicalVolume* >(RichTbLbNumPmtInEC)));

   rTbLbR1PmtLVol  =  
     new G4LogicalVolume(aR1PmtMasterBox,aMaterial->getNitrogenGas(),
			     RichTbLbPmtLogBaseName+"Common", 0,0,0);

   rTbLbR1PmtPVol.resize(RichTbLbNumModules, 
    std::vector<std::vector<G4VPhysicalVolume*> >(RichTbLbNumECInModule,
    std::vector<G4VPhysicalVolume* >(RichTbLbNumPmtInEC)));
   for (int ip =0; ip<RichTbLbNumPmtInEC ; ip++) {
     G4ThreeVector aR1PmtPos(RichLbPmtMasterInECXPos [ip], RichLbPmtMasterInECYPos [ip],
                             RichLbPmtMasterInECZPos);
     G4RotationMatrix aR1PmtMasterRotZ;
     aR1PmtMasterRotZ.rotateZ(RichLbPmtMasterInECRotZ[ip] );
     G4Transform3D aR1PmtTrans(aR1PmtMasterRotZ * aR1PmtMasterRotY , aR1PmtPos);
     std::string aPmtNameStr= std::to_string(ip); 

     for (int iM =0; iM <  RichTbLbNumModules; iM++ ) {
        std::string aMStr = std::to_string(iM);
        for (int iec=0; iec<RichTbLbNumECInModule; iec++) {
            std::string aECnameStr = std::to_string(iec);
               G4int aPmtCopyNum = 
                 (iM * RichTbLbNumECInModule * RichTbLbNumPmtInEC)  + iec *RichTbLbNumPmtInEC + ip  ;
	       //               rTbLbR1PmtLVol [iM] [iec] [ip]  =  
               //    new G4LogicalVolume(aR1PmtMasterBox,aMaterial->getNitrogenGas(),
	       //		     RichTbLbPmtLogBaseName+aMStr+"_"+aECnameStr+"_"+aPmtNameStr, 0,0,0);
               if( ! aTestGraphicsSinglePmt ) {

		 //rTbLbR1PmtPVol[iM] [iec] [ip]  = new G4PVPlacement(aR1PmtTrans,
                 //  RichTbLbPmtPhysBaseName+aMStr+"_"+aECnameStr+"_"+aPmtNameStr,
                 //    rTbLbR1PmtLVol [iM] [iec] [ip] ,
                 //    mTbR1EC->getRichTbLbR1ECPhysicalVolume(iec,iM),false,aPmtCopyNum);

		 rTbLbR1PmtPVol[iM] [iec] [ip]  = new G4PVPlacement(aR1PmtTrans,  rTbLbR1PmtLVol ,
                   RichTbLbPmtPhysBaseName+aMStr+"_"+aECnameStr+"_"+aPmtNameStr,
                   mTbR1EC->getRichTbLbR1ECLogicalVolume(iec,iM),false,aPmtCopyNum);

               } else {

                 if( iM == 0 && iec == 0 && ip == 0 ) {

		   //  rTbLbR1PmtPVol[iM] [iec] [ip]  = new G4PVPlacement(aR1PmtTrans,
                   //   RichTbLbPmtPhysBaseName+aMStr+"_"+aECnameStr+"_"+aPmtNameStr,
                   //   rTbLbR1PmtLVol [iM] [iec] [ip] ,
                   //   mTbR1EC->getRichTbLbR1ECPhysicalVolume(iec,iM),false,aPmtCopyNum);
		   rTbLbR1PmtPVol[iM] [iec] [ip]  = new G4PVPlacement(aR1PmtTrans, rTbLbR1PmtLVol,
                      RichTbLbPmtPhysBaseName+aMStr+"_"+aECnameStr+"_"+aPmtNameStr,
                      mTbR1EC->getRichTbLbR1ECLogicalVolume(iec,iM),false,aPmtCopyNum);


		 }

	       } 
	}
     }
   }
}


