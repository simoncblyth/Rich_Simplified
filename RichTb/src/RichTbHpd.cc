// $Id: $
// Include files 


#include "globals.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4Polyhedra.hh"

// local
#include "RichTbMaterial.hh"
#include "RichTbHpd.hh"
#include "RichTbUpgradePhDetSupFrame.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbMaterialParameters.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SubtractionSolid.hh"
#include "G4SDManager.hh"
#include "RichTbUpgradeSD.hh"
#include "RichTbHpdRODummySD.hh"
#include "RichTbMiscNames.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbHpd
//
// 2003-11-19 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbHpd::RichTbHpd(G4int aHpdNum , RichTbUpgradePhDetSupFrame* aSupFrame  )
{  MotherOfHpd = aSupFrame;
  CurHpdNum = aHpdNum;
  m_TrackingSwitch=true;
  
}

RichTbHpd::~RichTbHpd(  ) {
}

void RichTbHpd::buildHpdGeometry() {


  constructHpdMasterTree();
  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  G4int agraphics=   aConfig ->getRichTbHpdSiPix_visib() ;
  
  
  if(m_TrackingSwitch) { 
    constructHpdComponentsLVol();
    constructHpdComponentsPVol();
    if( agraphics > 5 ) {
      // special config to just visualize the pixel geometry. Not for simulating data.
      constructHpdSiPixel();

    }
    


  }else {
    constructHpdSiPixel();
  }
  
  

}

void RichTbHpd::constructHpdComponentsLVol() 
{
  RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();

   G4Tubs*  HpdEnvelopeTube = 
     new G4Tubs("HpdEnvelopeTube", RichTbHpdEnvLargeTubInnR,  
                RichTbHpdEnvLargeTubeOutR,
                0.5*RichTbHpdEnvLargeTubeZSize,
                 RichTbHpdEnvelopeTubeStartPhi, RichTbHpdEnvelopeTubeEndPhi);
   
   G4Tubs* HpdEndCapTube=
     new G4Tubs("HpdEndCap",    RichTbHpdEndCapInnerRad,RichTbHpdEnvEndCapRad,
                0.5*RichTbHpdEnvEndCapZsize,  RichTbHpdEnvelopeEndCapStartPhi,
                 RichTbHpdEnvelopeEndCapEndPhi);
   G4Sphere* HpdQuartzWindowOverallSphe=
     new G4Sphere("HpdQuartzWSphe",  RichTbHpdQuartzWInnerRad,
                  RichTbHpdQuartzWOuterRad, RichTbHpdQuartzWStartPhi,
                   RichTbHpdQuartzWDeltaPhi, RichTbHpdQuartzWStartTheta,
                  RichTbHpdQuartzWDeltaTheta);
   
    G4Tubs* HpdQWCylEnvTube=
      new G4Tubs("HpdQWCylEnvTube", RichTbHpdQuartzWCylEnvInnerR,
                 RichTbHpdQWCylEnvOuterLargeValue,
                 0.5*RichTbHpdQWCylEnvZLargeValue,
                 RichTbHpdQWCylEnvStartPhi,RichTbHpdQWCylEnvEndPhi);
    
   G4Sphere* HpdPhCathodeSphe=
     new G4Sphere("HpdPhCathodeSphe", RichTbHpdPhCathodeInnerRad,
                  RichTbHpdPhCathodeOuterRad, RichTbHpdPhCathodeStartPhi,
                  RichTbHpdPhCathodeDeltaPhi,    RichTbHpdPhCathodeStartTheta,
                  RichTbHpdPhCathodeDeltaTheta);
   
    G4RotationMatrix  RichTbHpdQWCylRot;

    G4ThreeVector RichTbHpdQWCylPos(RichTbHpdQWCylXLocation,
                                   RichTbHpdQWCylYLocation,
                                   RichTbHpdQWCylZLocation);
   
   G4Transform3D   RichTbHpdQWCylTransform(   RichTbHpdQWCylRot,
                                              RichTbHpdQWCylPos);
   
   G4SubtractionSolid* HpdQuartzWSub =
     new    G4SubtractionSolid("HpdQWSubtr",HpdQuartzWindowOverallSphe,
                               HpdQWCylEnvTube, RichTbHpdQWCylTransform);
   
 

   G4LogicalVolume*  HpdEnvelopeLog =
     new G4LogicalVolume( HpdEnvelopeTube ,
                          aMaterial->getHpdTubeEnvelopeMaterial(),
                          "HpdEnvelopeLog",0,0,0);
   G4LogicalVolume* HpdEndCapLog =
     new G4LogicalVolume( HpdEndCapTube,
                    aMaterial->getHpdTubeEnvelopeMaterial(),
                          "HpdEndCapLog",0,0,0);
   G4LogicalVolume* HpdQuartzWLog= 
      new  G4LogicalVolume( HpdQuartzWSub,
                            aMaterial->getHpdQuartzWindowMaterial(),
                            "HpdQuartzWLog",0,0,0);
   G4LogicalVolume* HpdPhCathodeLog =
     new G4LogicalVolume( HpdPhCathodeSphe,
                          aMaterial->getHpdPhCathodeMaterial() ,
                          "HpdPhCathodeLog",0,0,0);

   RichTbHpdEnvelopeTubeLVol=HpdEnvelopeLog;
   RichTbHpdEnvelopeEndCapLVol=HpdEndCapLog;
   RichTbHpdQuartzWLVol= HpdQuartzWLog;
   RichTbHpdPhCathodeLVol=HpdPhCathodeLog;
   


   
}
void RichTbHpd::constructHpdComponentsPVol() 
{

   G4RotationMatrix  HpdEnvelopeTubeRot;
   G4RotationMatrix  HpdEndCapTubeRot,  HpdQuartzWindowRot, HpdPhCathodeRot;

    G4ThreeVector HpdEnvelopeTubePos( RichTbHpdEnvTubeXLocation,
                                     RichTbHpdEnvTubeYLocation,
                                     RichTbEnvLargeTubZLocation);
   
   G4Transform3D   HpdEnvelopeTubeTransform( HpdEnvelopeTubeRot,
                                             HpdEnvelopeTubePos);
   
   G4ThreeVector HpdEndCapPos(RichTbHpdEndCapXLocation, 
                              RichTbHpdEndCapYLocation,
                              RichTbHpdEndCapZLocation);
   
   G4Transform3D HpdEndCapTransform( HpdEndCapTubeRot, HpdEndCapPos);


   HpdQuartzWindowRot.rotateY(RichTbHpdQuartzWRotY);
   HpdPhCathodeRot.rotateY( RichTbHpdPhCathodeRotY);

   
   G4ThreeVector HpdQuartzWindowPos(  RichTbHpdQuartzWindowXLocation,
                                      RichTbHpdQuartzWindowYLocation,
                                      RichTbHpdQuartzWZLocation);


   G4Transform3D  HpdQuartzWindowTransform(  HpdQuartzWindowRot, 
                                            HpdQuartzWindowPos);
   
   G4ThreeVector   HpdPhCathodePos(RichTbHpdPhCathodeXLocation,
                                   RichTbHpdPhCathodeYLocation,
                                   RichTbHpdPhCathodeZLocation);
   
   G4Transform3D HpdPhCathodeTransform( HpdPhCathodeRot, HpdPhCathodePos);
   
    
     
   G4VPhysicalVolume*   HpdEnvelopePhys =
     new G4PVPlacement(  HpdEnvelopeTubeTransform,"HpdEnvelopeTubePhys",
                       RichTbHpdEnvelopeTubeLVol  , RichTbHpdSMasterPVol,
                        false,0);
   
   G4VPhysicalVolume*  HpdEndCapPhys =
     new G4PVPlacement(  HpdEndCapTransform,"HpdEndCapPhys",
                         RichTbHpdEnvelopeEndCapLVol,
                        RichTbHpdSMasterPVol,false,0);

   G4VPhysicalVolume*   HpdQuartzWPhys=
     new G4PVPlacement(  HpdQuartzWindowTransform,HpdQuartzPhysName  ,
                        RichTbHpdQuartzWLVol ,
                       RichTbHpdSMasterPVol,false,0);

   G4VPhysicalVolume*   HpdPhCathodePhys=
     new G4PVPlacement(  HpdPhCathodeTransform, HpdPhCathodePhysName ,
                          RichTbHpdPhCathodeLVol, 
                         RichTbHpdSMasterPVol,false,0);

   RichTbHpdEnvelopeTubePVol= HpdEnvelopePhys;   
   RichTbHpdEnvelopeEndCapPVol=  HpdEndCapPhys;  
   RichTbHpdQuartzWPVol= HpdQuartzWPhys;   
   RichTbHpdPhCathodePVol= HpdPhCathodePhys;   

   


}

void RichTbHpd::constructHpdMasterTree(){

  RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();
  //  RichTbRunConfig* aRunConfig= RichTbRunConfig::getRunConfigInstance();
  
  //  G4String HpdMasterBoxName = HpdNamesBox[ CurHpdNum ];
  // G4String HpdMasterLogVolName= HpdNamesLog[CurHpdNum ];
  //  G4String HpdMasterPhysVolName = HpdNamesPhys[ CurHpdNum ];

  G4String HpdMasterBoxName = HpdNamesBox;
  G4String HpdMasterLogVolName= HpdNamesLog;
  G4String HpdMasterPhysVolName = HpdNamesPhys;


   G4Tubs* HpdMasterTube= 
     new G4Tubs( HpdMasterBoxName, RichTbHpdMasterInnerRad,
                 RichTbHpdMasterRadius,
                0.5* RichTbHpdMasterZSize, RichTbHpdMasterStartPhi,  
                RichTbHpdMasterEndPhi);
   G4Tubs* HpdSMasterTube= 
     new G4Tubs("HPDSMaster", RichTbHpdSMasterInnerRad,RichTbHpdSMasterRadius,
                0.5* RichTbHpdSMasterZSize, RichTbHpdSMasterStartPhi, 
                 RichTbHpdSMasterEndPhi);


   //   G4double SiDetXSize= RichTbHpdSiDetXSize[CurHpdNum];
   // G4double SiDetYSize= RichTbHpdSiDetYSize[CurHpdNum];
   // G4double SiDetZSize= RichTbHpdSiDetZSize;
   //   G4Box* HpdSiDetBox =
   //  new G4Box("HpdSiDetBox", 0.5*SiDetXSize,
   //            0.5*SiDetYSize,
   //            0.5*SiDetZSize);

    G4Tubs* HpdSiDetTube =
      new G4Tubs("HpdSiDetTube",  RichTbHpdSiDetInnerRadiusSize, RichTbHpdSiDetRadiusSize,
                 0.5*RichTbHpdSiDetZSize, RichTbHpdSiDetStartPhi,  RichTbHpdSiDetEndPhi);
    


  
   G4RotationMatrix HpdMasterRotZ, HpdMasterRotY;
   G4RotationMatrix HpdSMasterRot;
   G4RotationMatrix  HpdSiDetRot;
   
   //   G4double CurHpdAdditionalRotZ=
   //   aRunConfig->getCurrentHpdAdditionalLocalRotationZ;  
   //G4double CurHpdTotalRotZ= RichTbHpdMasterRotationZAxis+
   //  CurHpdAdditionalRotZ;

   G4double CurHpdTotalRotZ= RichTbHpdMasterRotationZAxis;
   

   //   G4double CurHpdAdditionalShiftX=  
   //  aRunConfig->getCurrentHpdAlignmentLocalShiftX;

   //   G4double CurHpdAdditionalShiftY=  
   //  aRunConfig->getCurrentHpdAlignmentLocalShiftY;
   
   //  G4cout<<" Hpd Master hpdNUm RotZ Orig Additional "
   //      <<CurHpdNum<<"  "<<RichTbHpdMasterRotationZAxis
   //      <<"   "<< CurHpdAdditionalRotZ<<G4endl;
   
   //  G4cout<<" Hpd MasterInphdetframe  hpdNum OrginalX ShiftX OriginalY ShiftY "
   //      << CurHpdNum<<"   "<< RichTbHpdMasterXLocation
   //      <<"    "<<CurHpdAdditionalShiftX<<"    "
   //      << RichTbHpdMasterYLocation<<"    "
   //      << CurHpdAdditionalShiftY<<G4endl;

   // G4double RichTbHpdMasterXPosFinal= RichTbHpdMasterXLocation+
   //  CurHpdAdditionalShiftX;
   //  G4double  RichTbHpdMasterYPosFinal= RichTbHpdMasterYLocation+
   //  CurHpdAdditionalShiftY;

   G4double RichTbHpdMasterXPosFinal= RichTbHpdMasterXLocation;
   G4double RichTbHpdMasterYPosFinal= RichTbHpdMasterYLocation;
   
   
   

   HpdMasterRotZ.rotateZ(CurHpdTotalRotZ);
   HpdMasterRotY.rotateY(RichTbHpdMasterRotationYAxis);
   HpdSiDetRot.rotateZ( RichTbSiDetRotZ) ;
   
     

  G4ThreeVector HpdMasterPos(RichTbHpdMasterXPosFinal,
                             RichTbHpdMasterYPosFinal,
                             RichTbHpdMasterZLocation);
 
   G4Transform3D HpdMasterTransform(HpdMasterRotY*HpdMasterRotZ, 
                         HpdMasterPos);

   
   G4ThreeVector HpdSMasterPos(RichTbHpdSMasterXLocation,
                               RichTbHpdSMasterYLocation,
                               RichTbHpdSMasterZLocation);
   
   G4Transform3D HpdSMasterTransform( HpdSMasterRot,HpdSMasterPos);

    
   G4ThreeVector   HpdSiDetPos(
     RichTbSiDetNominalXLocation+ RichTbSiDetShiftAlongX,
     RichTbSiDetNominalYLocation+ RichTbSiDetShiftAlongY,
     RichTbHpdSiDetZLocation);
   
   G4Transform3D  HpdSiDetTransform( HpdSiDetRot, HpdSiDetPos);
   
      
   G4LogicalVolume* HpdMasterLog=
     new G4LogicalVolume(HpdMasterTube,aMaterial-> getRichTbVaccum(),
                         HpdMasterLogVolName ,0,0,0);
   G4LogicalVolume* HpdSMasterLog=
     new G4LogicalVolume(HpdSMasterTube,aMaterial-> getRichTbVaccum(),
                         "HpdSMasterLog",0,0,0);
   G4LogicalVolume* HpdSiDetLog =
     new G4LogicalVolume( HpdSiDetTube,
                          aMaterial->getHpdSiDetMaterial(),
                          "HpdSiDetLog",0,0,0);
   
        
   
   G4VPhysicalVolume* HpdMasterPhys =
     new G4PVPlacement(HpdMasterTransform,HpdMasterPhysVolName,
                       HpdMasterLog,  
                       MotherOfHpd-> getRichTbPhDetSupFrameRightPVol(),
                       false, CurHpdNum);

   G4VPhysicalVolume* HpdSMasterPhys=
     new G4PVPlacement(HpdSMasterTransform,HpdSMasterPhysName,
                       HpdSMasterLog,HpdMasterPhys,false,0);


   G4VPhysicalVolume*  HpdSiDetPhys=
      new G4PVPlacement(  HpdSiDetTransform, HpdSiDetPhysName ,
                          HpdSiDetLog , HpdSMasterPhys,false,0);

   RichTbHpdMasterLVol=HpdMasterLog;
   RichTbHpdSMasterLVol=HpdSMasterLog;
   RichTbHpdSiDetLVol= HpdSiDetLog;
   RichTbHpdMasterPVol=HpdMasterPhys;   
   RichTbHpdSMasterPVol=HpdSMasterPhys;   
   RichTbHpdSiDetPVol= HpdSiDetPhys;
   
   
}

void  RichTbHpd::constructHpdSiPixel()
{

  RichTbSiPixelPVol.clear();
  RichTbSiPixelPVol.reserve(NumPixelTotInSingleHpd);
  
 
  RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();

  //G4double aPixelXSize= RichTbHpdSiDetHexPixelFlatToFlatSize;
  
  // G4double aPixelYSize= RichTbHpdSiDetHexPixelFlatToFlatSize;
  
  G4Polyhedra* HpdSiPxHex= new G4Polyhedra("HpdSiPxHex",RichTbHpdSiDetPixelHexPhiStart,
                                           RichTbHpdSiDetPixelHexPhiEnd, RichTbHpdSiDetPixelHexNumSide,
                                           RichTbHpdSiDetPixelHexNumZPlanes,RichTbHpdSiDetPixelHexZPlane,
                                           RichTbHpdSiDetPixelHexRInner, RichTbHpdSiDetPixelHexROuter);
   G4LogicalVolume* HpdSiPxLog =
     new G4LogicalVolume( HpdSiPxHex,
                          aMaterial->getHpdSiDetMaterial(),
                          "HpdSiPxLog",0,0,0);

     //Now for the readout dummy sensitive detector
      // This just flags the pixel as active.
   // for now all pixels are set active. To deactivate 
   // specific pixels, the log vol must be created for each 
   // given pixel and the set to be active as done below. This means
   // a separate log vol must be created for every pixel. 

       G4bool      thisPixelisAlive=true;         
       if(thisPixelisAlive){
        RichTbHpdRODummySD * DummyHpdSensi = new  RichTbHpdRODummySD;
        HpdSiPxLog->SetSensitiveDetector(DummyHpdSensi);
       }
 
   
   // now positioning the pixels in the Silicon Det.

   G4RotationMatrix  HpdSiPixelRot;
   HpdSiPixelRot.rotateZ(RichTbHpdSiDetPixelHexRotZ);
   

   G4int PixelNumAcc = 0;
   
   for(G4int iPixelRowY = 0; iPixelRowY < NumHpdPixelRows ; iPixelRowY++) {

     G4double aPixelColStartX = -0.5*(NumHpdPixelInRows[iPixelRowY] - 1 ) *  HpdPixelXCenterShift;
     G4double curPixelPosY = HpdPixelYCenterStart + HpdPixelYCenterShift *iPixelRowY ;
       
	  for (G4int iPixelColX = 0; iPixelColX < NumHpdPixelInRows[iPixelRowY] ; iPixelColX++)
	    {
        G4double curPixelPosX = aPixelColStartX + iPixelColX *  HpdPixelXCenterShift;
        
	      G4int PixelCopyNumber = iPixelColX + PixelNumAcc ;
       

	      G4ThreeVector HpdSiPixelPos(curPixelPosX, curPixelPosY, RichHpdSiPixelPosZInSiDet);
	      G4Transform3D HpdSiPixelTransform(HpdSiPixelRot, HpdSiPixelPos);
       
	      G4VPhysicalVolume*  HpdSiPxPhys =
     		new G4PVPlacement(  HpdSiPixelTransform,"HpdSiPxPhys",
				    HpdSiPxLog, RichTbHpdSiDetPVol, false, PixelCopyNumber);  
	      
	      RichTbSiPixelPVol.push_back(HpdSiPxPhys);
	      
	    }
      PixelNumAcc += NumHpdPixelInRows[iPixelRowY ];
    
    
   }
   
      
  
      RichTbSiPixelLVol=HpdSiPxLog;
      
}

//=============================================================================
