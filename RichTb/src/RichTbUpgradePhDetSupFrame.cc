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
#include "RichTbUpgradePhDetSupFrame.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUpgradePhDetSupFrame
//
// 2014-10-23 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradePhDetSupFrame::RichTbUpgradePhDetSupFrame(RichTbUpgradeCrystalMaster * rTbCrysMaster   ):
  RichTbPhDetSupFrameLVol(std::vector<G4LogicalVolume*> (2)), 
  RichTbPhDetSupFramePVol(std::vector<G4VPhysicalVolume*> (2))  {
  aRTbCrystalMaster = rTbCrysMaster;


  // constructRichTbPhotoDetectorSupFrame();

}
//=============================================================================
// Destructor
//=============================================================================
RichTbUpgradePhDetSupFrame::~RichTbUpgradePhDetSupFrame() {}

//=============================================================================
void RichTbUpgradePhDetSupFrame::constructRichTbPhotoDetectorSupFrame()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  //  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

    G4Box * PhDetSupFrameBox
       = new G4Box( "PhDetSupFrameBox",
                    0.5*PhDetSupFrameXSize,0.5*PhDetSupFrameYSize,0.5*PhDetSupFrameZSize);



    G4RotationMatrix PhDetSupRotX,PhDetSupRotY ;

    G4ThreeVector PhDetSupFramePosLeft ( PhDetSupFrameXLocation[0],PhDetSupFrameYLocation[0],PhDetSupFrameZLocation);
    G4ThreeVector PhDetSupFramePosRight ( PhDetSupFrameXLocation[1],PhDetSupFrameYLocation[1],PhDetSupFrameZLocation);

    G4Transform3D PhDetSupFrameTransformLeft(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePosLeft );
    G4Transform3D PhDetSupFrameTransformRight(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePosRight );

    G4LogicalVolume* PhDetSupFrameLogLeft = new   G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameLeftLog", 0,0,0);

    G4LogicalVolume* PhDetSupFrameLogRight = new  G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameRightLog", 0,0,0);

    G4VPhysicalVolume* PhDetSupFramePhysLeft = new G4PVPlacement(PhDetSupFrameTransformLeft,
                                                                 PhDetSupPhysNameLeft,PhDetSupFrameLogLeft,
                                                 aRTbCrystalMaster ->getRichTbUpgradeCrystalMasterPVol(),false,0);

    G4VPhysicalVolume* PhDetSupFramePhysRight = new G4PVPlacement(PhDetSupFrameTransformRight,
                                                        PhDetSupPhysNameRight,PhDetSupFrameLogRight,
                                                 aRTbCrystalMaster ->getRichTbUpgradeCrystalMasterPVol(),false,1);

    RichTbPhDetSupFrameLeftLVol  = PhDetSupFrameLogLeft;
    RichTbPhDetSupFrameRightLVol = PhDetSupFrameLogRight;
    RichTbPhDetSupFrameLeftPVol  = PhDetSupFramePhysLeft;
    RichTbPhDetSupFrameRightPVol = PhDetSupFramePhysRight;





}

void RichTbUpgradePhDetSupFrame::constructRichTbPhotoDetectorSupFrameWithHpd()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  //  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

    G4Box * PhDetSupFrameBox
       = new G4Box( "PhDetSupFrameBox",
                    0.5*PhDetSupFrameXSize,0.5*PhDetSupFrameYSize,0.5*PhDetSupFrameZSize);



    G4RotationMatrix PhDetSupRotX,PhDetSupRotY ;

    G4ThreeVector PhDetSupFramePosLeft ( PhDetSupFrameXLocation[0],PhDetSupFrameYLocation[0],PhDetSupFrameZLocation);
    G4Transform3D PhDetSupFrameTransformLeft(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePosLeft );
    G4LogicalVolume* PhDetSupFrameLogLeft = new   G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameLeftLog", 0,0,0);
    G4VPhysicalVolume* PhDetSupFramePhysLeft = new G4PVPlacement(PhDetSupFrameTransformLeft,
                                                                 PhDetSupPhysNameLeft,PhDetSupFrameLogLeft,
                                                 aRTbCrystalMaster ->getRichTbUpgradeCrystalMasterPVol(),false,0);



    G4Box * PhDetHpdSupFrameBox
       = new G4Box( "PhDetHpdSupFrameBox",
                    0.5*HpdPhDetSupFrameXSize,0.5*HpdPhDetSupFrameYSize,0.5*HpdPhDetSupFrameZSize);


    G4ThreeVector PhDetSupFramePosRight ( HpdPhotonDetectorSupFrameXLocation,
                HpdPhotonDetectorSupFrameYLocation, HpdPhDetSupFrameZLocation);

    G4RotationMatrix PhDetHpdSupRotX,PhDetHpdSupRotY ;

    G4Transform3D PhDetSupFrameTransformRight(PhDetHpdSupRotX*PhDetHpdSupRotY,PhDetSupFramePosRight );


    G4LogicalVolume* PhDetSupFrameLogRight = new  G4LogicalVolume(PhDetHpdSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameRightLog", 0,0,0);


    G4VPhysicalVolume* PhDetSupFramePhysRight = new G4PVPlacement(PhDetSupFrameTransformRight,
                                                        PhDetSupPhysNameRight,PhDetSupFrameLogRight,
                                                 aRTbCrystalMaster ->getRichTbUpgradeCrystalMasterPVol(),false,1);

    RichTbPhDetSupFrameLeftLVol  = PhDetSupFrameLogLeft;
    RichTbPhDetSupFrameRightLVol = PhDetSupFrameLogRight;
    RichTbPhDetSupFrameLeftPVol  = PhDetSupFramePhysLeft;
    RichTbPhDetSupFrameRightPVol  = PhDetSupFramePhysRight;




}

void RichTbUpgradePhDetSupFrame::constructRichTbPhotoDetectorSupFrame15()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  //  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

    G4Box * PhDetSupFrameBox = new G4Box( "PhDetSupFrameBox",
                    0.5*PhDetSupFrameXSize,0.5*PhDetSupFrameYSize,0.5*PhDetSupFrameZSize);

    G4RotationMatrix PhDetSupRotX,PhDetSupRotY ;

    G4ThreeVector PhDetSupFramePosLeft(PhDetSupFrameXLocation15[0],PhDetSupFrameYLocation15[0],PhDetSupFrameZLocation15);
    G4ThreeVector PhDetSupFramePosRight(PhDetSupFrameXLocation15[1],PhDetSupFrameYLocation15[1],PhDetSupFrameZLocation15);
    G4ThreeVector PhDetSupFramePosBottomLeft(PhDetSupFrameBottomXLocation[0],PhDetSupFrameBottomYLocation[0],
             PhDetSupFrameZLocation15);
    G4ThreeVector PhDetSupFramePosBottomRight(PhDetSupFrameBottomXLocation[1],PhDetSupFrameBottomYLocation[1],
             PhDetSupFrameZLocation15);

    G4Transform3D PhDetSupFrameTransformLeft(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePosLeft);
    G4Transform3D PhDetSupFrameTransformRight(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePosRight);
    G4Transform3D PhDetSupFrameTransformBottomLeft(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePosBottomLeft);
    G4Transform3D PhDetSupFrameTransformBottomRight(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePosBottomRight);

    G4LogicalVolume* PhDetSupFrameLogLeft = new   G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameLeftLog", 0,0,0);
    G4LogicalVolume* PhDetSupFrameLogRight = new  G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameRightLog", 0,0,0);
    G4LogicalVolume* PhDetSupFrameLogBottomLeft = new   G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameBottomLeftLog", 0,0,0);
    G4LogicalVolume* PhDetSupFrameLogBottomRight = new  G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameBottomRightLog", 0,0,0);

    G4VPhysicalVolume* PhDetSupFramePhysLeft = new G4PVPlacement(PhDetSupFrameTransformLeft,
                                                                 PhDetSupPhysNameLeft,PhDetSupFrameLogLeft,
                                                 aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);
    G4VPhysicalVolume* PhDetSupFramePhysRight = new G4PVPlacement(PhDetSupFrameTransformRight,
                                                        PhDetSupPhysNameRight,PhDetSupFrameLogRight,
                                                 aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,1);
    G4VPhysicalVolume* PhDetSupFramePhysBottomLeft = new G4PVPlacement(PhDetSupFrameTransformBottomLeft,
    														PhDetSupPhysNameBottomLeft,PhDetSupFrameLogBottomLeft,
															aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);
    G4VPhysicalVolume* PhDetSupFramePhysBottomRight = new G4PVPlacement(PhDetSupFrameTransformBottomRight,
															PhDetSupPhysNameBottomRight,PhDetSupFrameLogBottomRight,
															aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,1);

    RichTbPhDetSupFrameLeftLVol  	= PhDetSupFrameLogLeft;
    RichTbPhDetSupFrameRightLVol	= PhDetSupFrameLogRight;
    RichTbPhDetSupFrameBottomLeftLVol  = PhDetSupFrameLogBottomLeft;
    RichTbPhDetSupFrameBottomRightLVol = PhDetSupFrameLogBottomRight;
    RichTbPhDetSupFrameLeftPVol  	= PhDetSupFramePhysLeft;
    RichTbPhDetSupFrameRightPVol 	= PhDetSupFramePhysRight;
    RichTbPhDetSupFrameBottomLeftPVol  = PhDetSupFramePhysBottomLeft;
    RichTbPhDetSupFrameBottomRightPVol = PhDetSupFramePhysBottomRight;
}

void RichTbUpgradePhDetSupFrame::constructRichTbPhotoDetectorSupFrame17()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  //  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

    G4Box * PhDetSupFrameBox = new G4Box( "PhDetSupFrameBox",
                    0.5*PhDetSupFrameXSize,0.5*PhDetSupFrameYSize2017,0.5*PhDetSupFrameZSize);

    G4RotationMatrix PhDetSupRotX,PhDetSupRotY ;


    G4ThreeVector PhDetSupFramePos2017(PhDetSupFrameFinalXPos17,PhDetSupFrameFinalYPos17,PhDetSupFrameZLocation17);

    G4Transform3D PhDetSupFrameTransform2017(PhDetSupRotX*PhDetSupRotY,PhDetSupFramePos2017);

    G4LogicalVolume* PhDetSupFrameLog2017 = new   G4LogicalVolume(PhDetSupFrameBox,aMaterial->getNitrogenGas(),"PhDetSupFrameLeftLog", 0,0,0);

    G4VPhysicalVolume* PhDetSupFramePhys2017 = new G4PVPlacement(PhDetSupFrameTransform2017,
                                                                 PhDetSupPhysName2017,PhDetSupFrameLog2017,
                                                 aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);

    RichTbPhDetSupFrame2017LVol  	= PhDetSupFrameLog2017;
    RichTbPhDetSupFrame2017PVol  	= PhDetSupFramePhys2017;
    G4cout<< "Coordinate of the frame of Mapmts :  "<< PhDetSupFramePos2017 <<G4endl;

}

void RichTbUpgradePhDetSupFrame::constructRichTbPhotoDetectorSupFrame16LT() {

   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
   RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

   G4int aLTGeomConfig = aConfig ->getLTRadGeometryFlag();
   

   RichTbPhDetSupFrameLVol.resize(NumPhDetSupFrames16);
   RichTbPhDetSupFramePVol.resize(NumPhDetSupFrames16);   

    G4Box * PhDetSupFrameGrandBox = new G4Box( "PhDetSupFrameGrandBox",
                    0.5*PhDetSupFrame16XSize,0.5*PhDetSupFrame16YSize,0.5*PhDetSupFrame16XSize);

    G4RotationMatrix PhDetSupGrandRotX,PhDetSupGrandRotY ;
    

    for (G4int iph=0; iph<  NumPhDetSupFrames16 ; iph++) {

      G4double aXPos = (aLTGeomConfig == 0)  ? PhDetSupFrameXLocationWithLTec[iph] : PhDetSupFrameXLocationWithLTecRun2[iph];

      G4ThreeVector PhDetSupFrameGrandPos(aXPos, PhDetSupFrameYLocationWithLTec[iph],PhDetSupFrameZLocationWithLT);
      
      
      G4Transform3D PhDetSupFrameGrandTransform(PhDetSupGrandRotX*PhDetSupGrandRotY,PhDetSupFrameGrandPos);
      G4LogicalVolume* PhDetSupFrameGrandLog = new  G4LogicalVolume(PhDetSupFrameGrandBox,aMaterial->getNitrogenGas(),
                      PhSupLogname[iph], 0,0,0);

      G4VPhysicalVolume* PhDetSupFrameGrandPhys = new  G4PVPlacement(PhDetSupFrameGrandTransform,PhSupPhysname[iph], 
                                                                     PhDetSupFrameGrandLog,  
                                                     aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);

      RichTbPhDetSupFrameLVol[iph]= PhDetSupFrameGrandLog;
      RichTbPhDetSupFramePVol[iph]= PhDetSupFrameGrandPhys;
      

    }
    




    //  G4ThreeVector PhDetSupFrameGrandPosLeft(PhDetSupFrameXLocationWithLTec[0],
    //               PhDetSupFrameYLocationWithLTec[0],  PhDetSupFrameZLocationWithLT);
    // G4ThreeVector PhDetSupFrameGrandPosRight(PhDetSupFrameXLocationWithLTec[1], 
    //               PhDetSupFrameYLocationWithLTec[1],  PhDetSupFrameZLocationWithLT);

    // G4Transform3D PhDetSupFrameGrandTransformLeft(PhDetSupGrandRotX*PhDetSupGrandRotY,PhDetSupFrameGrandPosLeft);
    // G4Transform3D PhDetSupFrameGrandTransformRight(PhDetSupGrandRotX*PhDetSupGrandRotY,PhDetSupFrameGrandPosRight);
  

    //  G4LogicalVolume* PhDetSupFrameGrandLogLeft = new   G4LogicalVolume(PhDetSupFrameGrandBox,aMaterial->getNitrogenGas(),
    ///              "PhDetSupFrameGrandLeftLog", 0,0,0);
    // G4LogicalVolume* PhDetSupFrameGrandLogRight = new  G4LogicalVolume(PhDetSupFrameGrandBox,aMaterial->getNitrogenGas(),
    //              "PhDetSupGrandFrameRightLog", 0,0,0);

    // G4VPhysicalVolume* PhDetSupFrameGrandPhysLeft = new G4PVPlacement(PhDetSupFrameGrandTransformLeft,
    //                                                             PhDetSupPhysNameLeft,PhDetSupFrameGrandLogLeft,
    //                                             aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);

    //  G4VPhysicalVolume* PhDetSupFrameGrandPhysRight = new G4PVPlacement(PhDetSupFrameGrandTransformRight,
    //                                                    PhDetSupPhysNameRight,PhDetSupFrameGrandLogRight,
    //                                             aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,1);
 

    //  RichTbPhDetSupFrameLeftLVol = PhDetSupFrameGrandLogLeft;
    //  RichTbPhDetSupFrameRightLVol =  PhDetSupFrameGrandLogRight;
    // RichTbPhDetSupFrameLeftPVol  =  PhDetSupFrameGrandPhysLeft;
    // RichTbPhDetSupFrameRightPVol =  PhDetSupFrameGrandPhysRight;


}

