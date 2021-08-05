// Include files 

#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeCrystalMaster.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"

#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"

// local
#include "RichTbUpgradeLTPhC.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUpgradeLTPhC
//
// 2016-10-07 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradeLTPhC::RichTbUpgradeLTPhC(RichTbUpgradeCrystalMaster* rTbCrystalMaster  ) {
	RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

  aRTbCrystalMaster =  rTbCrystalMaster ;
  
  // G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();
 
  G4int aLTSampleType =  aConfig ->getLTRadiatorSampleType();
  G4int aLTMapCreate  =  aConfig ->getLTMapCreate();
  
 
  if( aLTSampleType == 0) {  
    constructRichTbUpgradeLTSampleTypeAMaster();
    constructRichTbUpgradeLTSampleTypeA();
    if( aLTMapCreate ==0 ){
      constructRichTbUpgradeLTFilterTypeA();
    }else if (aLTMapCreate ==1 ){
      // constructRichTbUpgradeLTFilterTypeATestForMapfile();
      RichTbUpgradeLTFilterALVol=0;      

  }
    
    
  }else if (aLTSampleType == 1) {
     constructRichTbUpgradeLTSampleTypeBMaster();
     constructRichTbUpgradeLTSampleTypeB();
     constructRichTbUpgradeLTFilterTypeB();
  }  

}

//=============================================================================
// Destructor
//=============================================================================
RichTbUpgradeLTPhC::~RichTbUpgradeLTPhC() {} 

//=============================================================================

void RichTbUpgradeLTPhC::constructRichTbUpgradeLTSampleTypeA() {
  
 	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
	
  G4Tubs * aTubLTA = new G4Tubs("LTACyl",0.0* CLHEP::mm, RichTbLTSampleARadius, RichTbLTSampleAThickness*0.5, cylSPhi, cylDPhi );

  
  G4LogicalVolume* aTubLTALog = new G4LogicalVolume(aTubLTA ,aMaterial->getLTSubstrateMaterial(),"LTSampleALog", 0,0,0);

  G4ThreeVector aTubLTAPos(RichTbLTSampleXLocation, RichTbLTSampleYLocation, RichTbLTSampleAZLocation);
  G4RotationMatrix aTubLTARotX, aTubLTARotY;
  G4Transform3D aTubLTATransform(aTubLTARotX * aTubLTARotY, aTubLTAPos );

  G4VPhysicalVolume* aTubLTAPhys = new G4PVPlacement(aTubLTATransform, "LTSampleAPhys", aTubLTALog,
                                                      RichTbUpgradeLTSampleAMasterPVol,false,0);
  

  G4Tubs * aPhCLTA =  new G4Tubs("PhACyl", 0.0*CLHEP::mm,  RichTbLTSampleARadius,  RichTbLTPhCSampleAThickness*0.5, cylSPhi, cylDPhi );
  G4LogicalVolume*  aPHCLTALog = new G4LogicalVolume(aPhCLTA ,aMaterial->getLTPhCSampleAMaterial(),"LTSampleAPHCLog", 0,0,0);
  G4ThreeVector aTubLTAPHCPos(0.0*CLHEP::mm,0.0*CLHEP::mm, RichTbLTSampleAPhCLocationInSample);
  G4RotationMatrix aTubLTAPHCRotX, aTubLTAPHCRotY;
  G4Transform3D aTubLTAPHCTransform( aTubLTAPHCRotX*aTubLTAPHCRotY, aTubLTAPHCPos);
  G4VPhysicalVolume* aTubLTAPHCPhys= new G4PVPlacement( aTubLTAPHCTransform, "LTSampleAPHCPhys",aPHCLTALog,aTubLTAPhys,false,0);


  RichTbUpgradeLTPhCSampleALVol = aTubLTALog ;
  RichTbUpgradeLTPhCSampleAPVol = aTubLTAPhys;
  
  RichTbUpgradeLTPhCLayerALVol = aPHCLTALog;
  RichTbUpgradeLTPhCLayerAPVol = aTubLTAPHCPhys;

}

void RichTbUpgradeLTPhC::constructRichTbUpgradeLTSampleTypeAMaster(){
 	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

 G4Tubs * aTubMasterA = new G4Tubs("LTAMasterA",0.0*CLHEP::mm, RichTbLTSampleAMasterRadius , 
                       RichTbLTSampleAMasterThickness*0.5, cylSPhi, cylDPhi );

 G4Tubs * aTubMasterHoleA = new G4Tubs("LTAMasterHoleA",0.0*CLHEP::mm, RichTbLTSampleAMasterHoleRadius , 
                       RichTbLTSampleAMasterHoleZLargeSize*0.5, cylSPhi, cylDPhi );

 G4RotationMatrix aTubMasterAHoleRotX, aTubMasterAHoleRotY;
 
 G4ThreeVector aTubMasterAHolePos(0.0,0.0,RichTbLTSampleAMasterHoleZLocation);


 G4Transform3D aTubMasterAHoleTransform(aTubMasterAHoleRotX*aTubMasterAHoleRotY, aTubMasterAHolePos);
 
   
 G4SubtractionSolid* aTubMasterASub = new G4SubtractionSolid("LTAMasterASubTube", 
                                                             aTubMasterA,aTubMasterHoleA , aTubMasterAHoleTransform);
 
 
 G4LogicalVolume* aSampleAMasterLog =  new G4LogicalVolume( aTubMasterASub, 
                                       aMaterial->getCarbon(), "LTSampleAMasterLog", 0,0,0);
 	
 RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();
  G4int aLTMapCreate  =  aConfig ->getLTMapCreate();
  if( aLTMapCreate == 1 ){
    
    aSampleAMasterLog =  new G4LogicalVolume( aTubMasterASub, 
                                       aMaterial->getCrystalMaterial(), "LTSampleAMasterLog", 0,0,0);

  }
  
  G4int aLTGeomCreate  =  aConfig ->getLTRadGeometryFlag();

 G4RotationMatrix MasterCoverRotX, MasterCoverRotY;

 G4double aZLocationM = (aLTGeomCreate == 0)  ? RichTbLTSampleAMasterZLocation : RichTbLTSampleAMasterZLocationRun2;
 

 G4ThreeVector  aSampleAMasterPos(0.0,0.0,aZLocationM);

 G4Transform3D aSampleAMasterTransform (MasterCoverRotX*MasterCoverRotY, aSampleAMasterPos);
 
 G4VPhysicalVolume* aSampleAMasterPhys = new G4PVPlacement(aSampleAMasterTransform, "LTSampleAMasterPhys",  aSampleAMasterLog,
                                                          aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(), false,0);

 RichTbUpgradeLTSampleAMasterLVol =  aSampleAMasterLog;
 RichTbUpgradeLTSampleAMasterPVol =  aSampleAMasterPhys;
 

}

void RichTbUpgradeLTPhC::constructRichTbUpgradeLTSampleTypeBMaster(){
 	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

 G4Tubs * aTubMasterB = new G4Tubs("LTAMasterB",0.0*CLHEP::mm, RichTbLTSampleBMasterRadius , 
                       RichTbLTSampleBMasterThickness*0.5, cylSPhi, cylDPhi );

 G4Tubs * aTubMasterHoleB = new G4Tubs("LTAMasterHoleB",0.0*CLHEP::mm, RichTbLTSampleBMasterHoleRadius , 
                       RichTbLTSampleBMasterHoleZLargeSize*0.5, cylSPhi, cylDPhi );

 G4RotationMatrix aTubMasterBHoleRotX, aTubMasterBHoleRotY;
 
 G4ThreeVector aTubMasterBHolePos(0.0,0.0,RichTbLTSampleBMasterHoleZLocation);
 G4Transform3D aTubMasterBHoleTransform(aTubMasterBHoleRotX*aTubMasterBHoleRotY, aTubMasterBHolePos);
 
   
 G4SubtractionSolid* aTubMasterBSub = new G4SubtractionSolid("LTAMasterBSubTube", 
                                                             aTubMasterB,aTubMasterHoleB , aTubMasterBHoleTransform);
 
 


 G4LogicalVolume* aSampleBMasterLog =  new G4LogicalVolume( aTubMasterBSub, 
                                       aMaterial->getCarbon(), "LTSampleBMasterLog", 0,0,0);

 G4RotationMatrix MasterBCoverRotX, MasterBCoverRotY;
 G4ThreeVector  aSampleBMasterPos(0.0,0.0, RichTbLTSampleBMasterZLocation);

 G4Transform3D aSampleBMasterTransform (MasterBCoverRotX*MasterBCoverRotY, aSampleBMasterPos);
 
 G4VPhysicalVolume* aSampleBMasterPhys = new G4PVPlacement(aSampleBMasterTransform, "LTSampleBMasterPhys",  aSampleBMasterLog,
                                                          aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(), false,0);

 RichTbUpgradeLTSampleBMasterLVol =  aSampleBMasterLog;
 RichTbUpgradeLTSampleBMasterPVol =  aSampleBMasterPhys;
 

}

void RichTbUpgradeLTPhC::constructRichTbUpgradeLTSampleTypeB(){
  
 	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
	
  G4Tubs * aTubLTB = new G4Tubs("LTBCyl",0.0*CLHEP::mm, RichTbLTSampleBRadius, RichTbLTSampleBThickness*0.5, cylSPhi, cylDPhi );

  
  G4LogicalVolume* aTubLTBLog = new G4LogicalVolume(aTubLTB ,aMaterial->getLTSubstrateMaterial(),"LTSampleBLog", 0,0,0);

  G4ThreeVector aTubLTBPos(RichTbLTSampleXLocation, RichTbLTSampleYLocation, RichTbLTSampleBZLocation);

  G4RotationMatrix aTubLTBRotX, aTubLTBRotY;

  G4Transform3D aTubLTBTransform(aTubLTBRotX*aTubLTBRotY, aTubLTBPos );

  G4VPhysicalVolume* aTubLTBPhys = new G4PVPlacement(aTubLTBTransform, "LTSampleBPhys", aTubLTBLog,
                                                     RichTbUpgradeLTSampleBMasterPVol,false,0);
  

  G4Tubs * aPhCLTB =  new G4Tubs("PhBCyl", 0.0*CLHEP::mm,  RichTbLTSampleBRadius,  RichTbLTPhCSampleBThickness*0.5, cylSPhi, cylDPhi );
  G4LogicalVolume*  aPHCLTBLog = new G4LogicalVolume(aPhCLTB ,aMaterial->getLTPhCSampleBMaterial(),"LTSampleBPHCLog", 0,0,0);
  G4ThreeVector aTubLTBPHCPos(0.0*CLHEP::mm,0.0*CLHEP::mm, RichTbLTSampleBPhCLocationInSample);
  G4RotationMatrix aTubLTBPHCRotX, aTubLTBPHCRotY;
  G4Transform3D aTubLTBPHCTransform( aTubLTBPHCRotX*aTubLTBPHCRotY, aTubLTBPHCPos);
  G4VPhysicalVolume* aTubLTBPHCPhys= new G4PVPlacement( aTubLTBPHCTransform, "LTSampleBPHCPhys",aPHCLTBLog,aTubLTBPhys,false,0);


  RichTbUpgradeLTPhCSampleBLVol = aTubLTBLog ;
  RichTbUpgradeLTPhCSampleBPVol = aTubLTBPhys;
  
  RichTbUpgradeLTPhCLayerBLVol = aPHCLTBLog;
  RichTbUpgradeLTPhCLayerBPVol = aTubLTBPHCPhys;



}




void RichTbUpgradeLTPhC::constructRichTbUpgradeLTFilterTypeA(){
 	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();




  G4Tubs * aTubLTFilterA = new G4Tubs("FilterACyl",0.0*CLHEP::mm, RichTbLTFilterARadius, 
                                  RichTbLTFilterAThickness*0.5, cylSPhi, cylDPhi );

  G4Tubs * aTubLTFilterGlassA = new G4Tubs("FilterGlassACyl",0.0*CLHEP::mm, RichTbLTFilterAGlassRadius, 
                                  RichTbLTFilterAGlassThickness*0.5, cylSPhi, cylDPhi );
 
  G4Tubs * aTubLTFilterHoleA = new G4Tubs("FilterHoleACyl",0.0*CLHEP::mm, RichTbLTFilterHoleARadius, 
                                          RichTbLTFilterHoleALargeZSize*0.5, cylSPhi, cylDPhi ); 

 
  G4RotationMatrix aTubLTFilterAHoleRotX, aTubLTFilterAHoleRotY;
  G4ThreeVector aTubLTFilterADnsPos (0.0,0.0,RichTbLTFilterHoleADnsZLocation );
  G4ThreeVector aTubLTFilterAUpsPos (0.0,0.0,RichTbLTFilterHoleAUpsZLocation );
  G4Transform3D aTubLTFilterADnsTransform (aTubLTFilterAHoleRotX*aTubLTFilterAHoleRotY,aTubLTFilterADnsPos);
  G4Transform3D aTubLTFilterAUpsTransform (aTubLTFilterAHoleRotX*aTubLTFilterAHoleRotY,aTubLTFilterAUpsPos);
  

  G4SubtractionSolid* aTubLTFilterADnsSub = new G4SubtractionSolid("LTFilterADnsSub", aTubLTFilterA, aTubLTFilterHoleA,
                                                                   aTubLTFilterADnsTransform);
  G4SubtractionSolid* aTubLTFilterADnsUpsSub = new G4SubtractionSolid("LTFilterADnsUpsSub",aTubLTFilterADnsSub 
                                        , aTubLTFilterHoleA, aTubLTFilterAUpsTransform);






  G4LogicalVolume* aLTFilterALog = new G4LogicalVolume(aTubLTFilterADnsUpsSub ,aMaterial->getCarbon(),
                                            "LTFilterALog", 0,0,0);

  G4LogicalVolume* aLTFilterGlassALog = new G4LogicalVolume(aTubLTFilterGlassA ,aMaterial->getLTFilterSampleAMaterial(),
                                            "LTFilterGlassALog", 0,0,0);

  // G4LogicalVolume* aLTFilterGlassALog = new G4LogicalVolume(aTubLTFilterGlassA ,aMaterial->getCrystalMaterial(),
  //                                          "LTFilterGlassALog", 0,0,0);

   
   RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

   G4int aLTGeomCreate  =  aConfig ->getLTRadGeometryFlag();


   G4double aZLTFilter = (aLTGeomCreate == 0 )  ? RichTbLTFilterAZLocation :  RichTbLTFilterAZLocationRun2;
   

  G4ThreeVector aLTFilterAPos( RichTbLTFilterAXLocation, RichTbLTFilterYLocation,aZLTFilter );

  G4RotationMatrix aLTFilterARotX, aLTFilterARotY;
  G4Transform3D aLTFIlterATransform(aLTFilterARotX * aLTFilterARotY, aLTFilterAPos  );

  G4VPhysicalVolume* aLTFilterAPhys = new G4PVPlacement(aLTFIlterATransform, "LTFilterAPhys",aLTFilterALog,
                                       aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);

    
  G4ThreeVector aLTFilterGlassAPos( RichTbLTFilterGlassAXLocation, RichTbLTFilterGlassAYLocation,  RichTbLTFilterGlassAZLocation);

  G4RotationMatrix aLTFilterGlassARotX, aLTFilterGlassARotY;
  G4Transform3D aLTFIlterGlassATransform(aLTFilterGlassARotX * aLTFilterGlassARotY, aLTFilterGlassAPos  );
  G4VPhysicalVolume* aLTFilterGlassAPhys = new G4PVPlacement(aLTFIlterGlassATransform, "LTFilterGlassAPhys",aLTFilterGlassALog,
                                                             aLTFilterAPhys,false,0);


  
  
  RichTbUpgradeLTFilterALVol= aLTFilterALog;
  RichTbUpgradeLTFilterAPVol= aLTFilterAPhys;

  RichTbUpgradeLTFilterGlassALVol= aLTFilterGlassALog;
  RichTbUpgradeLTFilterGlassAPVol= aLTFilterGlassAPhys;
 
  
}

void RichTbUpgradeLTPhC::constructRichTbUpgradeLTFilterTypeATestForMapfile(){
 	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

  //	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();



  G4Tubs * aTubLTFilterA = new G4Tubs("FilterACyl",0.0*CLHEP::mm, RichTbLTFilterARadiusTestForMapfile, 
                                  RichTbLTFilterAThicknessTestForMapfile*0.5, cylSPhi, cylDPhi );

  G4Tubs * aTubLTFilterGlassA = new G4Tubs("FilterGlassACyl",0.0*CLHEP::mm, RichTbLTFilterAGlassRadiusTestForMapfile, 
                                  RichTbLTFilterAGlassThicknessTestForMapfile*0.5, cylSPhi, cylDPhi );




  G4LogicalVolume* aLTFilterALog = new G4LogicalVolume( aTubLTFilterA ,aMaterial->getCrystalMaterial(),
                                            "LTFilterALog", 0,0,0);
  G4LogicalVolume* aLTFilterGlassALog = new G4LogicalVolume(aTubLTFilterGlassA ,aMaterial->getCrystalMaterial(),
                                            "LTFilterGlassALog", 0,0,0);


    RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

   G4int aLTGeomCreate  =  aConfig ->getLTRadGeometryFlag();


   G4double aZLTFilterTestMap = 
    (aLTGeomCreate == 0 )  ?RichTbLTFilterAZLocationTestForMapfile  :  RichTbLTFilterAZLocationTestForMapfileRun2 ;
 


  G4ThreeVector aLTFilterAPos( RichTbLTFilterAXLocation, RichTbLTFilterYLocation,aZLTFilterTestMap  );


  G4RotationMatrix aLTFilterARotX, aLTFilterARotY;
  G4Transform3D aLTFIlterATransform(aLTFilterARotX * aLTFilterARotY, aLTFilterAPos  );

  G4VPhysicalVolume* aLTFilterAPhys = new G4PVPlacement(aLTFIlterATransform, "LTFilterAPhys",aLTFilterALog,
                                       aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);

    
  G4ThreeVector aLTFilterGlassAPos( RichTbLTFilterGlassAXLocation, RichTbLTFilterGlassAYLocation,  RichTbLTFilterGlassAZLocation);
  G4RotationMatrix aLTFilterGlassARotX, aLTFilterGlassARotY;
  G4Transform3D aLTFIlterGlassATransform(aLTFilterGlassARotX * aLTFilterGlassARotY, aLTFilterGlassAPos  );
  G4VPhysicalVolume* aLTFilterGlassAPhys = new G4PVPlacement(aLTFIlterGlassATransform, "LTFilterGlassAPhys",aLTFilterGlassALog,
                                                             aLTFilterAPhys,false,0);


  
  
  RichTbUpgradeLTFilterALVol= aLTFilterALog;
  RichTbUpgradeLTFilterAPVol= aLTFilterAPhys;

  RichTbUpgradeLTFilterGlassALVol= aLTFilterGlassALog;
  RichTbUpgradeLTFilterGlassAPVol= aLTFilterGlassAPhys;
 
  
}





void RichTbUpgradeLTPhC::constructRichTbUpgradeLTFilterTypeB(){

 	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  G4Tubs * aTubLTFilterB = new G4Tubs("FilterBCyl",0.0*CLHEP::mm, RichTbLTFilterBRadius, 
                                  RichTbLTFilterBThickness*0.5, cylSPhi, cylDPhi );
 
   G4Tubs * aTubLTFilterGlassB = new G4Tubs("FilterGlassBCyl",0.0*CLHEP::mm, RichTbLTFilterBGlassRadius, 
                                  RichTbLTFilterBGlassThickness*0.5, cylSPhi, cylDPhi );



  G4Tubs * aTubLTFilterHoleB = new G4Tubs("FilterHoleBCyl",0.0*CLHEP::mm, RichTbLTFilterHoleBRadius, 
                                          RichTbLTFilterHoleBLargeZSize*0.5, cylSPhi, cylDPhi );
  
  G4RotationMatrix aTubLTFilterBHoleRotX, aTubLTFilterBHoleRotY;
  G4ThreeVector aTubLTFilterBDnsPos (0.0,0.0,RichTbLTFilterHoleBDnsZLocation );
  G4ThreeVector aTubLTFilterBUpsPos (0.0,0.0,RichTbLTFilterHoleBUpsZLocation );
  G4Transform3D aTubLTFilterBDnsTransform (aTubLTFilterBHoleRotX*aTubLTFilterBHoleRotY,aTubLTFilterBDnsPos);
  G4Transform3D aTubLTFilterBUpsTransform (aTubLTFilterBHoleRotX*aTubLTFilterBHoleRotY,aTubLTFilterBUpsPos);
  

  G4SubtractionSolid* aTubLTFilterBDnsSub = new G4SubtractionSolid("LTFilterBDnsSub", aTubLTFilterB, aTubLTFilterHoleB,
                                                                   aTubLTFilterBDnsTransform);
  G4SubtractionSolid* aTubLTFilterBDnsUpsSub = new G4SubtractionSolid("LTFilterBDnsUpsSub",aTubLTFilterBDnsSub 
                                        , aTubLTFilterHoleB, aTubLTFilterBUpsTransform);



  G4LogicalVolume* aLTFilterBLog = new G4LogicalVolume(aTubLTFilterBDnsUpsSub ,aMaterial->getCarbon(),
                                            "LTFilterBLog", 0,0,0);
  G4LogicalVolume* aLTFilterGlassBLog = new G4LogicalVolume(aTubLTFilterGlassB ,aMaterial->getLTFilterSampleBMaterial(),
                                            "LTFilterGlassBLog", 0,0,0);
   G4ThreeVector aLTFilterBPos( RichTbLTFilterBXLocation, RichTbLTFilterYLocation,  RichTbLTFilterBZLocation);
  G4RotationMatrix aLTFilterBRotX, aLTFilterBRotY;
  G4Transform3D  aLTFIlterBTransform(aLTFilterBRotX * aLTFilterBRotY, aLTFilterBPos  );

  G4VPhysicalVolume* aLTFilterBPhys = new G4PVPlacement(aLTFIlterBTransform, "LTFilterBPhys",aLTFilterBLog,
                                       aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);


  G4ThreeVector aLTFilterGlassBPos( RichTbLTFilterGlassBXLocation, RichTbLTFilterGlassBYLocation,  RichTbLTFilterGlassBZLocation);
  G4RotationMatrix aLTFilterGlassBRotX, aLTFilterGlassBRotY;
  G4Transform3D  aLTFIlterGlassBTransform(aLTFilterGlassBRotX * aLTFilterGlassBRotY, aLTFilterGlassBPos  );

  G4VPhysicalVolume* aLTFilterGlassBPhys = new G4PVPlacement(aLTFIlterGlassBTransform, "LTFilterGlassBPhys",aLTFilterGlassBLog,
                                       aLTFilterBPhys,false,0);

  
  RichTbUpgradeLTFilterBLVol= aLTFilterBLog;
  RichTbUpgradeLTFilterBPVol= aLTFilterBPhys;
  
  RichTbUpgradeLTFilterGlassBLVol= aLTFilterGlassBLog;
  RichTbUpgradeLTFilterGlassBPVol= aLTFilterGlassBPhys;

  

}
