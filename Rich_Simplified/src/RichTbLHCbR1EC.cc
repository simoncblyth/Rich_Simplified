// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1EC.hh"
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
RichTbLHCbR1EC::RichTbLHCbR1EC(RichTbLHCbR1Module * rTbR1Module ) {
  mTbR1Module = rTbR1Module;
  constructR1LbEC();

}
RichTbLHCbR1EC::~RichTbLHCbR1EC() {;}
void RichTbLHCbR1EC::constructR1LbEC() {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

   G4Box * aR1ECBox = new G4Box("R1ECBox", 0.5*RichTbLbECXSize , 0.5*RichTbLbECYSize,RichTbLbECZSize );
   G4RotationMatrix aR1ECRot;
   aR1ECRot.rotateZ(RichTbLbECRotZ);

   rTbLbR1ECLVol.resize(RichTbLbNumModules, std::vector< G4LogicalVolume*> (RichTbLbNumECInModule));  
   rTbLbR1ECPVol.resize(RichTbLbNumModules, std::vector<G4VPhysicalVolume*> (RichTbLbNumECInModule));
   for (int iec=0; iec<RichTbLbNumECInModule; iec++) {
     G4ThreeVector aR1ECPos( RichTbLbECXPos[iec], RichTbLbECYPos,RichTbLbECZPos);
     G4Transform3D aR1ECTrans(aR1ECRot,aR1ECPos);
     std::string aECnameStr = std::to_string(iec);
     for (int iM =0; iM <  RichTbLbNumModules; iM++ ) {
       std::string aMStr = std::to_string(iM);
       G4int aECCopyNum = iM* RichTbLbNumECInModule + iec ;

       rTbLbR1ECLVol [iM][iec]   = new G4LogicalVolume(aR1ECBox,aMaterial->getNitrogenGas(),
                RichTbLbECLogBaseName+aECnameStr+"_"+aMStr,0,0,0);
       
       rTbLbR1ECPVol[iM][iec]= new G4PVPlacement(aR1ECTrans,RichTbLbECPhysBaseName+aECnameStr+"_"+aMStr,
			 rTbLbR1ECLVol[iM][iec] ,
                         mTbR1Module->getRichTbLbR1ModulePhysicalVolume (iM),false,aECCopyNum);
             
     }
   }
   // test 
   
   //G4LogicalVolume * aModuleTestLV = mTbR1Module->getRichTbLbR1ModuleLogicalVolume (0);
   // G4int aNumDh = aModuleTestLV -> GetNoDaughters();
   // G4cout<<" Rich Pmt Module name NumDaughters "<< aModuleTestLV->GetName()<<"  "<<aNumDh <<G4endl;

   //end test

}
