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
#include "RichTbUpgradeEC.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUpgradeEC
//
// 2014-10-23 : Sajan Easo
// 2015-06-11 : Michele Blago
// 2016-11-01 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradeEC::RichTbUpgradeEC(RichTbUpgradePhDetSupFrame * rTbPhotSupFrame   ):
  RichTbECLVol(std::vector<G4LogicalVolume*> (8)),
  RichTbECPVol(std::vector<G4VPhysicalVolume*> (8)),
  RichTbECSupportLVol(std::vector<G4LogicalVolume*> (8)),
  RichTbECSupportPVol(std::vector<G4VPhysicalVolume*> (8))     {

   aRTbPhotSupFrame = rTbPhotSupFrame ;
   // constructRichTbUpgradeEC ();
   // constructRichTbUpgradeECSupport ();


}
//=============================================================================
// Destructor
//=============================================================================
RichTbUpgradeEC::~RichTbUpgradeEC() {}

//=============================================================================
void RichTbUpgradeEC::constructRichTbUpgradeEC () {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * ECBox = new G4Box("ECBox", 0.5*ECXSize,0.5*ECYSize, 0.5*ECZSize);
   G4RotationMatrix ECBoxRotX, ECBoxRotY;
   G4ThreeVector ECPosLeft(ECXLocation ,ECYLocation ,ECZLocation);
   G4ThreeVector ECPosRight(ECXLocation ,ECYLocation ,ECZLocation);
   G4Transform3D ECTransformLeft( ECBoxRotX*ECBoxRotY, ECPosLeft);
   G4Transform3D ECTransformRight( ECBoxRotX*ECBoxRotY, ECPosRight);

   G4LogicalVolume*  ECLogLeft = new G4LogicalVolume( ECBox, aMaterial->getNitrogenGas(),
                                                      "ECLeftLog", 0,0,0);
   G4LogicalVolume*  ECLogRight = new G4LogicalVolume( ECBox, aMaterial->getNitrogenGas(),
                                                      "ECRightLog", 0,0,0);
   G4VPhysicalVolume* ECPhysLeft = new G4PVPlacement(ECTransformLeft, "ECLeftPhys",
                                                     ECLogLeft, aRTbPhotSupFrame->getRichTbPhDetSupFrameLeftPVol(),false,0);

   G4VPhysicalVolume* ECPhysRight = new G4PVPlacement(ECTransformRight, "ECRightPhys",
                                                     ECLogRight, aRTbPhotSupFrame->getRichTbPhDetSupFrameRightPVol(),false,1);


   RichTbECLeftLVol  =   ECLogLeft;
   RichTbECRightLVol =   ECLogRight;
   RichTbECLeftPVol  =   ECPhysLeft;
   RichTbECRightPVol =  ECPhysRight;

}
void RichTbUpgradeEC::constructRichTbUpgradeECSupport () {

   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * ECSupBox = new G4Box("ECBox", 0.5*ECSupportXSize,0.5*ECSupportYSize, 0.5*ECSupportZSize);

   G4ThreeVector ECSupPos(ECXLocation ,ECYLocation , ECSupportZLocation);

   G4RotationMatrix ECSupportBoxRot;
   G4Transform3D ECSupTransform( ECSupportBoxRot, ECSupPos);
   G4LogicalVolume*  ECSupLog  = new G4LogicalVolume( ECSupBox, aMaterial->getCarbon(),
                                                      "ECSupLog", 0,0,0);

   G4VPhysicalVolume* ECSupPhysLeft = new G4PVPlacement(ECSupTransform, "ECSupLeftPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrameLeftPVol(),false,0);

   G4VPhysicalVolume* ECSupPhysRight = new G4PVPlacement(ECSupTransform, "ECSupRightPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrameRightPVol(),false,0);

   RichTbECSupLVol      =  ECSupLog ;
   RichTbECSupLeftPVol  =  ECSupPhysLeft;
   RichTbECSupRightPVol =  ECSupPhysRight;


}
void RichTbUpgradeEC::constructRichTbUpgradeSingleEC () {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * ECBox = new G4Box("ECBox", 0.5*ECXSize,0.5*ECYSize, 0.5*ECZSize);
   G4RotationMatrix ECBoxRotX, ECBoxRotY;
   G4ThreeVector ECPosLeft(ECXLocation ,ECYLocation ,ECZLocation);
   G4Transform3D ECTransformLeft( ECBoxRotX*ECBoxRotY, ECPosLeft);

   G4LogicalVolume*  ECLogLeft = new G4LogicalVolume( ECBox, aMaterial->getNitrogenGas(),
                                                      "ECLeftLog", 0,0,0);
   G4VPhysicalVolume* ECPhysLeft = new G4PVPlacement(ECTransformLeft, "ECLeftPhys",
                                                     ECLogLeft, aRTbPhotSupFrame->getRichTbPhDetSupFrameLeftPVol(),false,0);



   RichTbECLeftLVol  =   ECLogLeft;
   RichTbECLeftPVol  =   ECPhysLeft;

}
void RichTbUpgradeEC::constructRichTbUpgradeSingleECSupport () {

   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * ECSupBox = new G4Box("ECBox", 0.5*ECSupportXSize,0.5*ECSupportYSize, 0.5*ECSupportZSize);

   G4ThreeVector ECSupPos(ECXLocation ,ECYLocation , ECSupportZLocation);

   G4RotationMatrix ECSupportBoxRot;
   G4Transform3D ECSupTransform( ECSupportBoxRot, ECSupPos);
   G4LogicalVolume*  ECSupLog  = new G4LogicalVolume( ECSupBox, aMaterial->getCarbon(),
                                                      "ECSupLog", 0,0,0);

   G4VPhysicalVolume* ECSupPhysLeft = new G4PVPlacement(ECSupTransform, "ECSupLeftPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrameLeftPVol(),false,0);


   RichTbECSupLVol      =  ECSupLog ;
   RichTbECSupLeftPVol  =  ECSupPhysLeft;



}
void RichTbUpgradeEC::constructRichTbUpgradeEC15() {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * ECBox = new G4Box("ECBox", 0.5*ECXSize,0.5*ECYSize, 0.5*ECZSize);
   G4RotationMatrix ECBoxRotX, ECBoxRotY;
   G4ThreeVector ECPosLeft(ECXLocation15,ECYLocation15,ECZLocation15);
   G4ThreeVector ECPosRight(ECXLocation15,ECYLocation15,ECZLocation15);
   G4ThreeVector ECPosBottomLeft(ECXLocation15,ECYLocation15,ECZLocation15);
   G4ThreeVector ECPosBottomRight(ECXLocation15,ECYLocation15,ECZLocation15);
   G4Transform3D ECTransformLeft(ECBoxRotX*ECBoxRotY,ECPosLeft);
   G4Transform3D ECTransformRight(ECBoxRotX*ECBoxRotY,ECPosRight);
   G4Transform3D ECTransformBottomLeft(ECBoxRotX*ECBoxRotY,ECPosBottomLeft);
   G4Transform3D ECTransformBottomRight(ECBoxRotX*ECBoxRotY,ECPosBottomRight);

   G4LogicalVolume*  ECLogLeft = new G4LogicalVolume( ECBox, aMaterial->getNitrogenGas(),
                                                      "ECLeftLog", 0,0,0);
   G4LogicalVolume*  ECLogRight = new G4LogicalVolume( ECBox, aMaterial->getNitrogenGas(),
                                                      "ECRightLog", 0,0,0);
   G4LogicalVolume*  ECLogBottomLeft = new G4LogicalVolume(ECBox, aMaterial->getNitrogenGas(),
                                                      "ECBottomLeftLog", 0,0,0);
   G4LogicalVolume*  ECLogBottomRight = new G4LogicalVolume(ECBox, aMaterial->getNitrogenGas(),
                                                      "ECBottomRightLog", 0,0,0);

   G4VPhysicalVolume* ECPhysLeft = new G4PVPlacement(ECTransformLeft, "ECLeftPhys",
                                                     ECLogLeft, aRTbPhotSupFrame->getRichTbPhDetSupFrameLeftPVol(),false,0);
   G4VPhysicalVolume* ECPhysRight = new G4PVPlacement(ECTransformRight, "ECRightPhys",
                                                     ECLogRight, aRTbPhotSupFrame->getRichTbPhDetSupFrameRightPVol(),false,1);
   G4VPhysicalVolume* ECPhysBottomLeft = new G4PVPlacement(ECTransformBottomLeft, "ECBottomLeftPhys",
      ECLogBottomLeft, aRTbPhotSupFrame->getRichTbPhDetSupFrameBottomLeftPVol(),false,2);
   G4VPhysicalVolume* ECPhysBottomRight = new G4PVPlacement(ECTransformBottomRight, "ECRBottomightPhys",
      ECLogBottomRight, aRTbPhotSupFrame->getRichTbPhDetSupFrameBottomRightPVol(),false,3);


   RichTbECLeftLVol  = ECLogLeft;
   RichTbECRightLVol = ECLogRight;
   RichTbECBottomLeftLVol  = ECLogBottomLeft;
   RichTbECBottomRightLVol = ECLogBottomRight;

   RichTbECLeftPVol  = ECPhysLeft;
   RichTbECRightPVol = ECPhysRight;
   RichTbECBottomLeftPVol  = ECPhysBottomLeft;
   RichTbECBottomRightPVol = ECPhysBottomRight;

}


void RichTbUpgradeEC::constructRichTbUpgradeEC17() {
   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

   G4Box * ECBox = new G4Box("ECBox", 0.5*ECXSize,0.5*ECYSize, 0.5*ECZSize);

   G4RotationMatrix ECBoxRotX, ECBoxRotY;

   G4ThreeVector ECPosBottom(ECXLocation17,ECYLocation17-1.5*ECYSize,ECZLocation17);
   G4ThreeVector ECPosBottomMedium(ECXLocation17,ECYLocation17-0.5*ECYSize,ECZLocation17);
   G4ThreeVector ECPosHightMedium(ECXLocation17,ECYLocation17+0.5*ECYSize,ECZLocation17);
   G4ThreeVector ECPosHight(ECXLocation17,ECYLocation17+1.5*ECYSize,ECZLocation17);

   G4Transform3D ECTransformBottom(ECBoxRotX*ECBoxRotY,ECPosBottom);
   G4Transform3D ECTransformBottomMedium(ECBoxRotX*ECBoxRotY,ECPosBottomMedium);
   G4Transform3D ECTransformHightMedium(ECBoxRotX*ECBoxRotY,ECPosHightMedium);
   G4Transform3D ECTransformHight(ECBoxRotX*ECBoxRotY,ECPosHight);

   G4LogicalVolume*  ECLogBottom = new G4LogicalVolume( ECBox, aMaterial->getNitrogenGas(),
                                                      "ECBottomLog", 0,0,0);
   G4LogicalVolume*  ECLogBottomMedium = new G4LogicalVolume( ECBox, aMaterial->getNitrogenGas(),
                                                      "ECBottomMediumLog", 0,0,0);
   G4LogicalVolume*  ECLogHightMedium = new G4LogicalVolume(ECBox, aMaterial->getNitrogenGas(),
                                                      "ECHightMediumLog", 0,0,0);
   G4LogicalVolume*  ECLogHight = new G4LogicalVolume(ECBox, aMaterial->getNitrogenGas(),
                                                      "ECHightLog", 0,0,0);

   G4VPhysicalVolume* ECPhysBottom = new G4PVPlacement(ECTransformBottom, "ECBottomPhys",
                                                     ECLogBottom, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,0);
   G4VPhysicalVolume* ECPhysBottomMedium = new G4PVPlacement(ECTransformBottomMedium, "ECBottomMediumPhys",
                                                     ECLogBottomMedium, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,1);
   G4VPhysicalVolume* ECPhysHightMedium = new G4PVPlacement(ECTransformHightMedium, "ECHightMediumPhys",
      ECLogHightMedium, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,2);
   G4VPhysicalVolume* ECPhysHight = new G4PVPlacement(ECTransformHight, "ECHightPhys",
      ECLogHight, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,3);


   RichTbECBottomLVol  = ECLogBottom;
   RichTbECBottomMediumLVol = ECLogBottomMedium;
   RichTbECHightMediumLVol  = ECLogHightMedium;
   RichTbECHightLVol = ECLogHight;

  RichTbECBottomPVol  = ECPhysBottom;
   RichTbECBottomMediumPVol = ECPhysBottomMedium;
   RichTbECHightMediumPVol  = ECPhysHightMedium;
   RichTbECHightPVol = ECPhysHight;
 G4cout<< "Coordinate of the of EC0 :  "<< ECPosHight <<G4endl;

}

void RichTbUpgradeEC::constructRichTbUpgradeECSupport15() {

  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

   G4Box * ECSupBox = new G4Box("ECBox", 0.5*ECSupportXSize,0.5*ECSupportYSize, 0.5*ECSupportZSize );


   G4ThreeVector ECSupPos(ECSupportXLocation15 ,ECSupportYLocation15 , ECSupportZLocation15);
   G4ThreeVector ECSupPosBottom(ECSupportXLocation15 ,ECSupportYLocation15 , ECSupportZLocation15);

   G4RotationMatrix ECSupportBoxRot;
  

  G4Transform3D ECSupTransform( ECSupportBoxRot, ECSupPos);
   G4Transform3D ECSupTransformBottom( ECSupportBoxRot, ECSupPos);

   G4LogicalVolume*  ECSupLog  = new G4LogicalVolume( ECSupBox, aMaterial->getCarbon(),
                                                      "ECSupLog", 0,0,0);

   G4VPhysicalVolume* ECSupPhysLeft = new G4PVPlacement(ECSupTransform, "ECSupLeftPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrameLeftPVol(),false,0);
   G4VPhysicalVolume* ECSupPhysRight = new G4PVPlacement(ECSupTransform, "ECSupRightPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrameRightPVol(),false,1);

   G4VPhysicalVolume* ECSupPhysBottomLeft = new G4PVPlacement(ECSupTransformBottom, "ECSupBottomLeftPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrameBottomLeftPVol(),false,2);
   G4VPhysicalVolume* ECSupPhysBottomRight = new G4PVPlacement(ECSupTransformBottom, "ECSupBottomRightPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrameBottomRightPVol(),false,3);

   RichTbECSupLVol      =  ECSupLog ;
   RichTbECSupLeftPVol  =  ECSupPhysLeft;
   RichTbECSupRightPVol =  ECSupPhysRight;
   RichTbECSupBottomLeftPVol  =  ECSupPhysBottomLeft;
   RichTbECSupBottomRightPVol =  ECSupPhysBottomRight;
}

void RichTbUpgradeEC::constructRichTbUpgradeECSupport17() { 

  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

   G4Box * ECSupBox = new G4Box("ECBox", 0.5*ECSupportXSize,0.5*ECSupportYSize, 0.5*ECSupportZSize );

   G4RotationMatrix ECSupportBoxRot;

   G4ThreeVector ECSupPosBottom(ECXSupportLocation17,ECYSupportLocation17-1.5*ECYSize,ECZSupportLocation17);
   G4ThreeVector ECSupPosBottomMedium(ECXSupportLocation17,ECYSupportLocation17-0.5*ECYSize,ECZSupportLocation17);
   G4ThreeVector ECSupPosHightMedium(ECXSupportLocation17,ECYSupportLocation17+0.5*ECYSize,ECZSupportLocation17);
   G4ThreeVector ECSupPosHight(ECXSupportLocation17,ECYSupportLocation17+1.5*ECYSize,ECZSupportLocation17);


   G4Transform3D ECSupTransformBottom (ECSupportBoxRot,ECSupPosBottom);
   G4Transform3D ECSupTransformBottomMedium( ECSupportBoxRot,ECSupPosBottomMedium);
   G4Transform3D ECSupTransformHightMedium( ECSupportBoxRot,ECSupPosHightMedium);
   G4Transform3D ECSupTransformHight( ECSupportBoxRot,ECSupPosHight);

 
 G4LogicalVolume*  ECSupLog  = new G4LogicalVolume( ECSupBox, aMaterial->getCarbon(),
                                                      "ECSupLog", 0,0,0);

 
   G4VPhysicalVolume* ECSupPhysBottom = new G4PVPlacement(ECSupTransformBottom, "ECSupBottomPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,0);
   G4VPhysicalVolume* ECSupPhysBottomMedium = new G4PVPlacement(ECSupTransformBottomMedium, "ECSupBottomMediumPhys",
                                                     ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,1);
   G4VPhysicalVolume* ECSupPhysHightMedium = new G4PVPlacement(ECSupTransformHightMedium, "ECSupHightMediumPhys",
      ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,2);
   G4VPhysicalVolume* ECSupPhysHight = new G4PVPlacement(ECSupTransformHight, "ECSupHightPhys",
      ECSupLog, aRTbPhotSupFrame->getRichTbPhDetSupFrame2017PVol(),false,3);

   RichTbECSupLVol      =  ECSupLog ;
  

   RichTbECSupBottomPVol  = ECSupPhysBottom;
   RichTbECSupBottomMediumPVol = ECSupPhysBottomMedium;
   RichTbECSupHightMediumPVol  = ECSupPhysHightMedium;
   RichTbECSupHightPVol = ECSupPhysHight;


}
void RichTbUpgradeEC::constructRichTbUpgradeEC16LT(G4int aSide  ) {
  
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * ECBoxA = new G4Box("ECBoxA", 0.5*ECXSize,0.5*ECYSize, 0.5*ECZSize);
   G4RotationMatrix ECBoxRotX, ECBoxRotY;
   G4int NumEC= NumElementaryCell16InPF;
   //G4VPhysicalVolume* apF =  aRTbPhotSupFrame->getRichTbPhDetGrandSupFrame(aSide);
   
   
   //  for (G4int iEC=0; iEC < NumEC; iEC++) {

   for (G4int iEC=0; iEC < NumEC; iEC++) {


     G4ThreeVector ECPosCur (ECXLocationInSupFrame16LT[iEC], ECYLocationInSupFrame16LT[iEC], ECZLocation);
     G4Transform3D ECT(ECBoxRotX*ECBoxRotY,ECPosCur);
    
    G4int ECNum = aSide* NumEC + iEC;
    
    G4LogicalVolume*  ECLog = new G4LogicalVolume( ECBoxA, aMaterial->getNitrogenGas(),
                                                   ECLogName[ECNum], 0,0,0);
    
    G4VPhysicalVolume* ECPhys = new G4PVPlacement(ECT,ECPhysName[ECNum],ECLog,
                            aRTbPhotSupFrame->getRichTbPhDetGrandSupFramePVol(aSide) ,false,0);
     
    RichTbECLVol[ECNum] =  ECLog;
    RichTbECPVol[ECNum] =  ECPhys;
    
   }


}
void RichTbUpgradeEC::constructRichTbUpgradeECSupport16LT(G4int aSide  ) {
  
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   G4Box * ECSupBoxA = new G4Box("ECSupBoxA", 0.5*ECSupportXSize,0.5*ECSupportYSize, 0.5*ECSupportZSize);
   G4RotationMatrix ECSupportBoxRotX, ECSupportBoxRotY;
   G4int NumEC= NumElementaryCell16InPF;
   //G4VPhysicalVolume* apF =  aRTbPhotSupFrame->getRichTbPhDetGrandSupFrame(aSide);
   
   for (G4int iEC=0; iEC< NumEC ; iEC++) {

    G4ThreeVector ECSupPosCur (  ECSupportXLocationInSupFrame16LT[iEC], 
                                 ECSupportYLocationInSupFrame16LT[iEC], ECSupportZLocation);
    G4Transform3D ECSupT(ECSupportBoxRotX*ECSupportBoxRotY,ECSupPosCur);
    
    G4int ECNum = aSide* NumEC + iEC;
    
    G4LogicalVolume*  ECSupLog = new G4LogicalVolume( ECSupBoxA, aMaterial->getCarbon(),
                                                   ECSupportLogName[ECNum], 0,0,0);
    
    G4VPhysicalVolume* ECSupPhys = new G4PVPlacement(ECSupT,ECSupportPhysName[ECNum],ECSupLog,
                            aRTbPhotSupFrame->getRichTbPhDetGrandSupFramePVol(aSide) ,false,0);
     
    RichTbECSupportLVol[ECNum] =  ECSupLog;
    RichTbECSupportPVol[ECNum] =  ECSupPhys;
    
   }


}
