// $Id: $
// Include files 



// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradePhDFrame.hh"
#include "RichTbUpgradeMaster.hh"
#include "RichTbHall.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbVessel
//
// 2003-11-05 : Sajan EASO
// 2005-02-20:  SE Modifed for the 2004 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbMaster::RichTbMaster(RichTbPhDFrame* rTbPhDFrame, int MasterNum ) {

  aMasterNum = MasterNum;
  aRTbPhDFrame = rTbPhDFrame;

  if(aMasterNum == 1)
    constructRichTbMaster1();
  if(aMasterNum == 2)
    constructRichTbMaster2();
  if(aMasterNum == 3)
    constructRichTbMaster3();
  if(aMasterNum == 4)
    constructRichTbMaster4();
}
RichTbMaster::~RichTbMaster(  )
{
}
void RichTbMaster::constructRichTbMaster1()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  
  G4Box * RichTbMasterBox 
    = new G4Box("RichTbMasterBox", 0.5*RichTbMasterXSize,
                0.5*RichTbMasterYSize, 0.5*RichTbMasterZSize);

  G4ThreeVector MasterPos(RichTbMaster1XLocation,
                          RichTbMaster1YLocation,
                          RichTbMaster1ZLocation);
 
  G4RotationMatrix MasterRotX,MasterRotY;
  

   G4int aSpecialStudyMasterRotFlag =  
      aConfig ->getSpecialStudyMasterRotation();

  if( aSpecialStudyMasterRotFlag != 1 ) {
    
    MasterRotX.rotateX(aConfig ->getSpecialStudyMasterRotationX());
    MasterRotY.rotateY(aConfig ->getSpecialStudyMasterRotationY());

  }

  
 
  G4Transform3D MasterTransform(  MasterRotX * MasterRotY, MasterPos);
  
 
    G4LogicalVolume* MasterLog;
    
     
    //master material
     MasterLog = 
       new G4LogicalVolume(RichTbMasterBox,
                           aMaterial->getRichTbVaccum(), "MasterLog",0,0,0);

     //master location  
     G4VPhysicalVolume* MasterPhys =
       new G4PVPlacement(MasterTransform, MasterPhysName, MasterLog ,
                         aRTbPhDFrame->getRichTbPhDFramePVol(),
                         false,0);
     
     RichTbMasterLVol = MasterLog;
     RichTbMasterPVol = MasterPhys;
     

}

void RichTbMaster::constructRichTbMaster2()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  
  G4Box * RichTbMasterBox 
    = new G4Box("RichTbMasterBox", 0.5*RichTbMasterXSize,
                0.5*RichTbMasterYSize, 0.5*RichTbMasterZSize);

  G4ThreeVector MasterPos(RichTbMaster2XLocation,
                          RichTbMaster2YLocation,
                          RichTbMaster2ZLocation);
 
  G4RotationMatrix MasterRotX,MasterRotY;

   G4int aSpecialStudyMasterRotFlag =  
      aConfig ->getSpecialStudyMasterRotation();

  if( aSpecialStudyMasterRotFlag != 1 ) {
    
    MasterRotX.rotateX(aConfig ->getSpecialStudyMasterRotationX());
    MasterRotY.rotateY(aConfig ->getSpecialStudyMasterRotationY());

  }

  
 
  G4Transform3D MasterTransform(  MasterRotX * MasterRotY, MasterPos);
  
 
    G4LogicalVolume* MasterLog;
    
     
    //master material
     MasterLog = 
       new G4LogicalVolume(RichTbMasterBox,
                           aMaterial->getAir(), "MasterLog",0,0,0);

     //master location  
     G4VPhysicalVolume* MasterPhys =
       new G4PVPlacement(MasterTransform, MasterPhysName, MasterLog ,
                         aRTbPhDFrame->getRichTbPhDFramePVol(),
                         false,0);
     
     RichTbMasterLVol = MasterLog;
     RichTbMasterPVol = MasterPhys;
     

}

void RichTbMaster::constructRichTbMaster3()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  
  G4Box * RichTbMasterBox 
    = new G4Box("RichTbMasterBox", 0.5*RichTbMasterXSize,
                0.5*RichTbMasterYSize, 0.5*RichTbMasterZSize);

  G4ThreeVector MasterPos(RichTbMaster3XLocation,
                          RichTbMaster3YLocation,
                          RichTbMaster3ZLocation);
 
  G4RotationMatrix MasterRotX,MasterRotY;
 
   G4int aSpecialStudyMasterRotFlag =  
      aConfig ->getSpecialStudyMasterRotation();

  if( aSpecialStudyMasterRotFlag != 1 ) {
    
    MasterRotX.rotateX(aConfig ->getSpecialStudyMasterRotationX());
    MasterRotY.rotateY(aConfig ->getSpecialStudyMasterRotationY());

  }

  
 
  G4Transform3D MasterTransform(  MasterRotX * MasterRotY, MasterPos);
  
 
    G4LogicalVolume* MasterLog;
    
     
    //master material
     MasterLog = 
       new G4LogicalVolume(RichTbMasterBox,
                           aMaterial->getAir(), "MasterLog",0,0,0);

     //master location  
     G4VPhysicalVolume* MasterPhys =
       new G4PVPlacement(MasterTransform, MasterPhysName, MasterLog ,
                         aRTbPhDFrame->getRichTbPhDFramePVol(),
                         false,0);
     
     RichTbMasterLVol = MasterLog;
     RichTbMasterPVol = MasterPhys;
     

}

void RichTbMaster::constructRichTbMaster4()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  
  G4Box * RichTbMasterBox 
    = new G4Box("RichTbMasterBox", 0.5*RichTbMasterXSize,
                0.5*RichTbMasterYSize, 0.5*RichTbMasterZSize);

  G4ThreeVector MasterPos(RichTbMaster4XLocation,
                          RichTbMaster4YLocation,
                          RichTbMaster4ZLocation);
 
  G4RotationMatrix MasterRotX,MasterRotY;

   G4int aSpecialStudyMasterRotFlag =  
      aConfig ->getSpecialStudyMasterRotation();

  if( aSpecialStudyMasterRotFlag != 1 ) {
    
    MasterRotX.rotateX(aConfig ->getSpecialStudyMasterRotationX());
    MasterRotY.rotateY(aConfig ->getSpecialStudyMasterRotationY());

  }

  
 
  G4Transform3D MasterTransform(  MasterRotX * MasterRotY, MasterPos);
  
 
    G4LogicalVolume* MasterLog;
    
     
    //master material
     MasterLog = 
       new G4LogicalVolume(RichTbMasterBox,
                           aMaterial->getAir(), "MasterLog",0,0,0);

     //master location  
     G4VPhysicalVolume* MasterPhys =
       new G4PVPlacement(MasterTransform, MasterPhysName, MasterLog ,
                         aRTbPhDFrame->getRichTbPhDFramePVol(),
                         false,0);
     
     RichTbMasterLVol = MasterLog;
     RichTbMasterPVol = MasterPhys;
     

}




//void RichTbMaster::constructRichTbMasterEnvelope()
//{
  
//}


//=============================================================================
