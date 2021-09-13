// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1Module.hh"
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
// Implementation file for class : RichTbLHCbR1Module : Pmt Modules
// SE 22-07-2021
//--------------------------------------------------------

RichTbLHCbR1Module::RichTbLHCbR1Module(RichTbLHCbR1PhDetSupFrame * rPhDetSupFrame ) {
  mPhDetSupFrame = rPhDetSupFrame ;
  constructR1Module();
}
RichTbLHCbR1Module::~RichTbLHCbR1Module() {; }
void RichTbLHCbR1Module::constructR1Module() {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * aR1ModuleBox = new G4Box ("R1ModuleBox", 0.5 * RichTbLbModuleXSize, 0.5 * RichTbLbModuleYSize, 
				     0.5 * RichTbLbModuleZSize);
   G4RotationMatrix aR1ModuleRot;
   aR1ModuleRot.rotateZ( RichTbLbModuleRotZ);

   rTbLbR1ModuleLVol.resize(RichTbLbNumModules);
   rTbLbR1ModulePVol.resize(RichTbLbNumModules);



   for (G4int iRow=0; iRow < RichTbLbNumModuleRow ; iRow++ ) {
     for (G4int iCol=0; iCol <   RichTbLbNumModuleCol ; iCol++) {
         G4int iM = iRow * RichTbLbNumModuleCol + iCol ;

         G4ThreeVector aR1ModulePos(RichTbLbModuleXPos[iCol],RichTbLbModuleYPos[iRow],  RichTbLbModuleZPos );
         G4Transform3D aR1ModuleTrans( aR1ModuleRot, aR1ModulePos );
         std::string aMNameStr= std::to_string(iM);

         rTbLbR1ModuleLVol[iM] = new G4LogicalVolume(aR1ModuleBox,aMaterial->getNitrogenGas(),
                       RichTbLbModuleLogBaseName+aMNameStr ,0,0,0);

         rTbLbR1ModulePVol[iM] =  new G4PVPlacement(aR1ModuleTrans,RichTbLbModulePhysBaseName+aMNameStr,
					 rTbLbR1ModuleLVol[iM],
                                      mPhDetSupFrame->getRichTbLHCbR1PhDetSupFramePhysicalVolume(),false,iM);



     } 
   }   
        
   
} 

G4int RichTbLHCbR1Module::GetModuleNumRC ( G4int aMCol, G4int aMRow ) {
  return (aMRow * RichTbLbNumModuleCol + aMCol) ;
}
