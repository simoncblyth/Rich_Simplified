#ifndef RichTbRunConfig_h
#define RichTbRunConfig_h 1

#include "globals.hh"
#include <vector>
#include <cmath>
#include <fstream>
#include "G4ThreeVector.hh"
#include "CLHEP/Units/PhysicalConstants.h"

class RichTbRunConfig {
  public:
    //RichTbRunConfig();
    virtual ~ RichTbRunConfig();

    static RichTbRunConfig* getRunConfigInstance();

  G4int getRichTbHall_visib()
  {return  RichTbHall_visib;}

  G4int   getRichTbUpgradeVessel_visib()
  {    return RichTbUpgradeVessel_visib;  }

 G4int   getRichTbCrystal_visib()
  {    return RichTbCrystal_visib;  }

 G4int   getRichTbLens_visib()
  {    return RichTbLens_visib;  }

  G4int   getRichTbUpgradeRadiator_visib()
  {    return RichTbUpgradeRadiator_visib;  }

  G4int   getRichTbUpgradeMirror_visib()
  {    return RichTbUpgradeMirror_visib;  }

  G4int   getRichTbUpgradeDarkCover_visib()
  {    return RichTbUpgradeDarkCover_visib;  }

  G4int   getRichTbUpgradeUpsDarkCover_visib()
  {    return RichTbUpgradeUpsDarkCover_visib;  }
  G4int   getRichTbUpgradeSideDarkCover_visib()
  {    return RichTbUpgradeSideDarkCover_visib;  }

  G4int   getRichTbUpgradeDnsDarkCover_visib()
  {    return RichTbUpgradeDnsDarkCover_visib;  }


 G4int   getRichTbCrystalCover_visib()
  {    return RichTbCrystalCover_visib;  }

  // G4int   getRichTbMaster_visib()
  // {    return RichTbMaster_visib;  }

  G4int getRichTbUpgradeLTCover_visib() 
  {return RichTbUpgradeLTCover_visib;}
  


 G4int   getRichTbPMTEnvelope_visib()
  {    return RichTbPMTEnvelope_visib;  }

 G4int   getRichTbPMTQuartzW_visib()
  {    return RichTbPMTQuartzW_visib;  }

 G4int   getRichTbPMTPhCathode_visib()
  {    return RichTbPMTPhCathode_visib;  }

 G4int   getRichTbPMTAnode_visib()
  {    return RichTbPMTAnode_visib;  }

  G4int   getRichTbPhDFrame_visib()
  {    return RichTbPhDFrame_visib;  }


  G4int getRichTbPhDetSupFrame_visib()
  {    return RichTbPhDetSupFrame_visib;}

  G4int getRichTbEC_visib()
  {
    return RichTbEC_visib;
  }



  G4int getRichTbGasQuWin_visib() {return RichTbGasQuWin_visib;}

  G4int getRichTbPMTMaster_visib()
  { return  RichTbPMTMaster_visib;}
  G4int getRichTbPMTSMaster_visib()
  {  return RichTbPMTSMaster_visib;}
  // G4int getRichTbPMTEnvelope_visib()
  // {    return RichTbPMTEnvelope_visib;}
  G4int getRichTbPMTEndCap_visib()
  {    return RichTbPMTEndCap_visib;}
  // G4int getRichTbPMTQuartzW_visib()
  // {    return RichTbPMTQuartzW_visib;  }
  // G4int getRichTbPMTPhCathode_visib()
  // {    return  RichTbPMTPhCathode_visib;}
  G4int getRichTbPMTFrontRing_visib()
  {    return RichTbPMTFrontRing_visib; }




  G4int getGasTypeCode() {return  GasTypeCode;}

  G4double getNitrogenPressure()
  {   return NitrogenPressure;}
  G4double getNitrogenTemperature()
  {    return NitrogenTemperature;}

 G4double getNominalNitrogenPressure()
  {   return NominalNitrogenPressure;}
  G4double getNominalNitrogenTemperature()
  {    return NominalNitrogenTemperature;}

  G4double getc4f10Pressure()
  {   return c4f10Pressure;}
  G4double getc4f10Temperature()
  {    return c4f10Temperature;}

 G4double getNominalc4f10Pressure()
  {   return Nominalc4f10Pressure;}
  G4double getNominalc4f10Temperature()
  {    return Nominalc4f10Temperature;}



  G4int  getMirrorOrientCode() {
    return MirrorOrientCode;
  }

  G4double  getMirrorAddTiltX()
  {    return  MirrorAddTiltX;}

  G4double getMirrorAddTiltY()
  {   return MirrorAddTiltY;}


  G4int getNonOptimalPMTCondition() {return  mNonOptimalPMTCondition;}
  void setNonOptimalPMTCondition(G4int acond)
     {mNonOptimalPMTCondition=acond;}
  G4double getNonOptimalPMTAbsEff() {return  mNonOptimalPMTAbsEff;}
  void setNonOptimalPMTAbsEff(G4double ahpdeff)
     {mNonOptimalPMTAbsEff= ahpdeff;}

  G4double getHpdpeBackScaProb() {return mHpdpeBackScaProb;}





  G4int getRichTbNumPartEvent()
  {
   return  RichTbNumPartEvent;
  }
  G4int  getRichTbParticleTypeCode()
  {
    return RichTbParticleTypeCode;
  }
  G4int  getRichTbParticleStartPosCode()
  {
    return RichTbParticleStartPosCode;
  }
  G4int  getRichTbParticleDirectionCode()
  {
    return RichTbParticleDirectionCode;
  }
  G4int  getRichTbParticleEnergyCode()
  {
    return RichTbParticleEnergyCode;
  }
  G4double  getRichTbParticleMomentum()
  {
    return RichTbParticleMomentum;
  }
  G4double getPosBeamFraction()
  {
    return PosBeamFraction;

  }

  G4double getBeamDirX()
  {    return  mBeamDirX;  }
  G4double getBeamDirY()
  {  return mBeamDirY;}
  G4double getBeamDivergenceX()
  {    return mBeamDivergenceX;}
  G4double getBeamDivergenceY()
  {    return mBeamDivergenceY;}


 G4double getPMTPEMomInit()
  {
    return PMTPEMomInit;
  }
 G4double getHpdPEMomInit ()
  {
    return PMTPEMomInit;
  }


  G4int getHitCreationOption()
  {
    return HitCreationOption;

  }

  G4double getECXShift() {
	  return ECXShift;
  }

  G4String getOutputFileName()
  {
    return OutputFileName;

  }
  G4int  DoWriteOutputFile() {return WriteOutputFile; }

  G4String getMirrorReflFileName() {
    return MirrorReflFileName;
  }

  G4String getOutputHistoFileName()
  {
    return OutputHistoFileName;
  }
  G4String getOutputNtupleFileName()
  {
    return OutputNtupleFileName;
  }


  G4int VerboseInfoFlag()
  {
    return mVerboseInfoFlag;
  }
  void setVerboseInfoFlag(G4int aVerboseFlag)
  {
    mVerboseInfoFlag=aVerboseFlag;

  }
  G4int VerboseOutputFileFlag()
  { return  mVerboseOutputFileFlag;}
  void setVerboseOutputFileFlag(G4int aVouf )
  {mVerboseOutputFileFlag=aVouf ;}

  G4int getBatchModeFlag()  {    return mBatchModeFlag;}
  void setBatchModeFlag( G4int abatchFlag ){    mBatchModeFlag=abatchFlag;}

  G4int getNumEventInBatchMode(){    return mNumEventInBatchMode;}
  void setNumEventInBatchMode(G4int aNumEv )
  {mNumEventInBatchMode=aNumEv;}

  G4double getBeamXPosShift()  {    return mBeamXPosShift;}
  G4double getBeamYPosShift()  {    return mBeamYPosShift;}
  void setBeamXPosShift(G4double abeamXs )
  {mBeamXPosShift= abeamXs;}
  void setBeamYPosShift(G4double abeamYs )
  {mBeamYPosShift= abeamYs;}

  G4double getBeamSpecialXPos()
  {
    return mBeamSpecialXPos;
  }
  G4double getBeamSpecialYPos()
  {
    return mBeamSpecialYPos;
  }
  G4double getBeamSpecialZPos()
  {
    return mBeamSpecialZPos;
  }
  void setBeamSpecialXPos (G4double asPosX)
  {    mBeamSpecialXPos= asPosX;  }
  void setBeamSpecialYPos (G4double asPosY)
  {    mBeamSpecialYPos= asPosY;  }
  void setBeamSpecialZPos (G4double asPosZ)
  {    mBeamSpecialZPos= asPosZ;  }

  void setBeamSpecialXRange(G4double aBeamSpecialXRange)
  {mBeamSpecialXRange=aBeamSpecialXRange;}


  G4double getBeamSpecialXRange()
  {return  mBeamSpecialXRange; }

  G4int getActivateBeamShiftNtuple() {return  mActivateBeamShiftNtuple; }
  void setActivateBeamShiftNtuple(G4int aAc ) {mActivateBeamShiftNtuple=aAc;}

  G4double getConstPhotWlenBeam()
  {    return  mConstPhotWlenBeam;}
  G4double getPhotWlenMinBeam()
  {    return mPhotWlenMinBeam;}
  G4double getPhotWlenMaxBeam()
  {    return  mPhotWlenMaxBeam;}

  void setConstPhotWlenBeam( G4double aPhw)
  { mConstPhotWlenBeam= aPhw;}
  void setPhotWlenMinBeam(G4double aPhwMin)
  {mPhotWlenMinBeam=aPhwMin;}
  void setPhotWlenMaxBeam(G4double aPhwMax)
  {mPhotWlenMaxBeam=aPhwMax;}

  G4int getSpecialStudyVesselRotation()
  {return mSpecialStudyVesselRotation ;}

  G4int getSpecialStudyCrystalRotation()
  {return mSpecialStudyCrystalRotation ;}
  G4double getSpecialStudyCrystalRotationX()
  {return mSpecialStudyCrystalRotationX ;}
  G4double getSpecialStudyCrystalRotationY()
  {return mSpecialStudyCrystalRotationY ;}

  G4int getSpecialStudyMasterRotation()
  {return mSpecialStudyMasterRotation ;}
  G4double getSpecialStudyMasterRotationX()
  {return mSpecialStudyMasterRotationX ;}
  G4double getSpecialStudyMasterRotationY()
  {return mSpecialStudyMasterRotationY ;}

  std::vector<G4double> getDemagConstShiftAtAnodeX()
  {    return mDemagConstShiftAtAnodeX;}
  std::vector<G4double> getDemagConstShiftAtAnodeY()
  {    return mDemagConstShiftAtAnodeY;}
  std::vector<G4double> getPMTAdditionalLocalRotationZ()
  {    return mPMTAdditionalLocalRotationZ;}

  G4double getCurrentPMTAdditionalLocalRotationZ (G4int aPMTNum)
  {
    G4double aAdRot=0.0;
    if(aPMTNum < (G4int) mPMTAdditionalLocalRotationZ.size() )
      aAdRot= mPMTAdditionalLocalRotationZ[aPMTNum];

    return aAdRot;
  }

  std::vector<G4double> getPMTAlignmentLocalShiftX()
  {    return mPMTAlignmentLocalShiftX;}

  G4double getCurrentPMTAlignmentLocalShiftX(G4int bPMTNum)
  {
    G4double bShiftX=0.0 * CLHEP::mm;
    if(  bPMTNum < (G4int) mPMTAlignmentLocalShiftX.size() )bShiftX= mPMTAlignmentLocalShiftX[bPMTNum];
    return bShiftX;
  }

  std::vector<G4double> getPMTAlignmentLocalShiftY()
  {    return mPMTAlignmentLocalShiftY;}

  G4double getCurrentPMTAlignmentLocalShiftY(G4int cPMTNum)
  {
    G4double cShiftY=0.0 * CLHEP::mm;
    if(  cPMTNum < (G4int) mPMTAlignmentLocalShiftY.size() )cShiftY= mPMTAlignmentLocalShiftY[cPMTNum];
    return cShiftY;
  }

  std::vector<G4double> getPhSupFrameAdditionalShift() {
    return mPhSupFrameAdditionalShift;}
  void setPhSupFrameAdditionalShift(std::vector<G4double> aPhSupFrameAdditionalShift){
    mPhSupFrameAdditionalShift=aPhSupFrameAdditionalShift;}
  G4double getPhSupFrameAdditionalVertTilt() {
    return mPhSupFrameAdditionalVertTilt;}
  void setPhSupFrameAdditionalVertTilt(G4double aPhSupFrameAdditionalVertTilt) {
    mPhSupFrameAdditionalVertTilt=aPhSupFrameAdditionalVertTilt;}
  G4double getPhSupFrameAdditionalZRot(){
    return mPhSupFrameAdditionalZRot;}
  void setPhSupFrameAdditionalZRot(G4double aPhSupFrameAdditionalZRot) {
    mPhSupFrameAdditionalZRot=aPhSupFrameAdditionalZRot;}

  G4int getPMTSiReflFlag() {
    return mPMTSiReflFlag;}

  G4int getRadiatorConfiguration() {
    return mRadiatorConfiguration;}

  G4int getLTRadiatorSampleType() {
   return    mLTRadiatorSampleType; 
  }

  G4int getLTSelectRadiatorActivate(){
    return mLTSelectRadiatorActivate;
  }

  G4int getLTMapCreate(){
    return mLTMapCreate;
  }
  
  G4int getLTRadGeometryFlag(){
    return mLTRadGeometryFlag;
  }
  

   G4double getMapmtDetectionEfficiency()
   {return mMapmtDetectionEfficiency;}

  //   G4double getMapmtPixelGap()
  //  {  return mMapmtPixelGap;}

  G4bool ApplyPixelEff() {
    return (mMapmtPixelEfficiencyFlag == 0 ) ? false : true;
  }

  G4int MapmtPixelEfficiencyFlag ()
  {  return mMapmtPixelEfficiencyFlag;}



  G4String MapmtPixelOptEffFileNameJura()
  {  return mMapmtPixelOptEffFileNameJura;}

  G4String MapmtPixelThr7EffFileNameJura()
  {  return mMapmtPixelThr7EffFileNameJura;}

  G4String MapmtPixelOptEffFileNameSaleve()
  {  return mMapmtPixelOptEffFileNameSaleve;}

  G4String MapmtPixelThr7EffFileNameSaleve()
  {  return mMapmtPixelThr7EffFileNameSaleve;}

  //tesbeam 2015 upgrade
  G4String MapmtPixelOptEffFileNameJuraUpgr()
  {  return mMapmtPixelOptEffFileNameJuraUpgradeDummy;}
  G4String MapmtPixelOptEffFileNameSaleveUpgr()
  {  return mMapmtPixelOptEffFileNameSaleveUpgradeDummy;}

  G4String MapmtPixelEffFileNameJuraTop100()
  {  return mMapmtPixelEffFileNameJuraTop100;}
  G4String MapmtPixelEffFileNameSaleveTop100()
  {  return mMapmtPixelEffFileNameSaleveTop100;}
  G4String MapmtPixelEffFileNameJuraBottom100()
  {  return mMapmtPixelEffFileNameJuraBottom100;}
  G4String MapmtPixelEffFileNameSaleveBottom100()
  {  return mMapmtPixelEffFileNameSaleveBottom100;}

  G4int getRichTbHpdQW_visib() {return  RichTbHpdQW_visib;}


  G4int  getRichTbHpdPHC_visib() {return RichTbHpdPHC_visib; }

  G4int  getRichTbHpdSID_visib() {return RichTbHpdSID_visib; }

  G4int  getRichTbHpdENV_visib() {return RichTbHpdENV_visib; }

  G4int  getRichTbHpdENVCAP_visib() {return RichTbHpdENVCAP_visib; }

  G4int  getRichTbHpdSM_visib() {return RichTbHpdSM_visib; }

  G4int  getRichTbHpdMas_visib() {return RichTbHpdMas_visib; }

  G4int  getRichTbHpdSiPix_visib()  {  return RichTbHpdSiPix_visib;}


  G4int  getRichTbLTSubstrate_visib()  {  return RichTbLTSubstrate_visib;}
  G4int  getRichTbLTPhC_visib()  {  return RichTbLTPhC_visib;}
  G4int  getRichTbLTFilter_visib(){  return  RichTbLTFilter_visib;}
  
  G4int getRichTbMirrParabola_visib() {return  RichTbMirrParabola_visib;}
  
  G4int getRichTbPhCDetPlane_visib() { return  RichTbPhCDetPlane_visib;}
  
  G4int  getRichTbQuartzRadiator_visib() {return   RichTbQuartzRadiator_visib;}
  G4int  getRichTbQuartzRadiatorCover_visib() {return   RichTbQuartzRadiatorCover_visib;}
  
  
  G4int  getaLHCbExptHall_visib(){return RichTbLHCbExptHall_visib;}
  G4int  getaRich1Master_visib(){return RichTbRich1Master_visib;}
  G4int  getaRich1SubMaster_visib(){return RichTbRich1SubMaster_visib; }
  G4int  getaR1SphMirror_visib(){return  RichTbR1SphMirror_visib; }
  G4int  getaR1FlatMirror_visib(){return  RichTbR1FlatMirror_visib; }
  G4int  getaR1MagShRegion_visib(){return RichTbR1MagShRegion_visib; }
  G4int  getaR1QW_visib() {return RichTbR1QW_visib ; }
  G4int  getaR1PhDetSupFrame_visib() {return RichTbR1PhDetSupFrame_visib; }

  G4int  getaRichTbR1Module_visib() {return    RichTbR1Module_visib  ; }
  G4int  getaRichTbR1EC_visib() {return        RichTbR1EC_visib ;}
  G4int  getaRichTbR1PmtMaster_visib(){return  RichTbR1PmtMaster_visib ;}

  G4int  getaRichTbR1PmtSMaser_visib(){return     RichTbR1PmtSMaser_visib;}
  G4int  getaRichTbR1PmtAnode_visib (){return     RichTbR1PmtAnode_visib;}
  G4int  getaRichTbR1PmtQuartz_visib(){return     RichTbR1PmtQuartz_visib;}
  G4int  getaRichTbR1PmtPhCath_visib(){return      RichTbR1PmtPhCath_visib;}
  G4int  getaRichTbR1PmtSideWin_visib(){return      RichTbR1PmtSideWin_visib;}
  G4int  getaRichTbR1PmtFrontRing_visib(){return     RichTbR1PmtFrontRing_visib;}
  G4int  getaRichTbR1ModuleBackPl_visib() {return  RichTbR1ModuleBackPl_visib; }



  G4long getRandomSeedInput () {  return mRandomSeedInput;}

  G4int getQWRadInstallFlag() {return  mQWRadInstallFlag; }
  
  G4int getGasCherenkovSwitchOffFlag() {return  mGasCherenkovSwitchOffFlag ;}
  
  G4int getRichTbMirrorGeomFlag() {return    mRichTbMirrorGeomFlag;}
 
 
  private:

    RichTbRunConfig();
    static RichTbRunConfig* RunConfigInstance;

 //Graphics setups
    //For Following variables 0 means make the volume invisible;
    //                        1 means make it visible as a solid.
    //                        2 means make it visible as a wireframe.

    // for the hpdsipix visib : <5 means it is not activated at all (default)
    //                          >=5 activated for special interactive session (not for creating hits.
    //                          10  means make the volume invisible, even though activated
    //                          11 means make it visible as a solid.
    //                          12 means make it visible as a wireframe.
    //
   G4int RichTbHall_visib;
  G4int RichTbUpgradeVessel_visib;
  G4int RichTbCrystal_visib;
  G4int RichTbLens_visib;
  G4int RichTbUpgradeRadiator_visib;
  G4int RichTbCrystalCover_visib;
  G4int RichTbUpgradeDarkCover_visib;
  G4int RichTbUpgradeUpsDarkCover_visib;
  G4int RichTbUpgradeSideDarkCover_visib;
   G4int RichTbUpgradeDnsDarkCover_visib;
  G4int RichTbUpgradeLTCover_visib;
  

  G4int RichTbPMTEnvelope_visib;
  G4int RichTbPMTQuartzW_visib;
  G4int RichTbPMTPhCathode_visib;
  G4int RichTbPMTAnode_visib;
  G4int RichTbPhDFrame_visib;
  G4int RichTbUpgradeMirror_visib;
  G4int RichTbPhDetSupFrame_visib;
  G4int  RichTbEC_visib;
  G4int RichTbPMTMaster_visib;
  G4int RichTbPMTSMaster_visib;
  G4int RichTbPMTEndCap_visib;
  G4int RichTbPMTFrontRing_visib;

   G4int RichTbGasQuWin_visib;




  G4int RichTbHpdQW_visib;
  G4int RichTbHpdPHC_visib;
  G4int RichTbHpdSID_visib;
  G4int RichTbHpdENV_visib;
  G4int RichTbHpdENVCAP_visib ;
  G4int RichTbHpdSM_visib;
  G4int RichTbHpdMas_visib;
  G4int RichTbHpdSiPix_visib;

  G4int RichTbLTSubstrate_visib;
  G4int RichTbLTPhC_visib;
  G4int RichTbLTFilter_visib;


  G4int RichTbMirrParabola_visib;
  G4int RichTbPhCDetPlane_visib;
  
  G4int  RichTbQuartzRadiator_visib;
  G4int  RichTbQuartzRadiatorCover_visib;


  G4int  RichTbLHCbExptHall_visib;
  G4int  RichTbRich1Master_visib;
  G4int  RichTbRich1SubMaster_visib;
  G4int  RichTbR1SphMirror_visib;
  G4int  RichTbR1FlatMirror_visib;
  G4int  RichTbR1MagShRegion_visib;
  G4int  RichTbR1QW_visib;
  G4int  RichTbR1PhDetSupFrame_visib;
  G4int  RichTbR1Module_visib;
  G4int  RichTbR1EC_visib;
  G4int  RichTbR1PmtMaster_visib;
  G4int  RichTbR1PmtSMaser_visib;
  G4int  RichTbR1PmtAnode_visib;
  G4int  RichTbR1PmtQuartz_visib;
  G4int  RichTbR1PmtPhCath_visib;
  G4int  RichTbR1PmtSideWin_visib;
  G4int  RichTbR1PmtFrontRing_visib;
  G4int  RichTbR1ModuleBackPl_visib;

  G4int GasTypeCode;

  G4double NitrogenPressure;
  G4double NitrogenTemperature;
  G4double NominalNitrogenPressure;
  G4double NominalNitrogenTemperature;

  G4double c4f10Pressure;
  G4double c4f10Temperature;
  G4double Nominalc4f10Pressure;
  G4double Nominalc4f10Temperature;

  G4int MirrorOrientCode;
  G4double MirrorAddTiltX;
  G4double MirrorAddTiltY;
  G4int mNonOptimalPMTCondition;
  G4double mNonOptimalPMTAbsEff;
  G4double mHpdpeBackScaProb;
  G4long mRandomSeedInput;



  G4int  RichTbNumPartEvent;
  G4int  RichTbParticleTypeCode;
  G4int  RichTbParticleStartPosCode;
  G4int  RichTbParticleDirectionCode;
  G4int  RichTbParticleEnergyCode;
  G4double  RichTbParticleMomentum;
  G4double PosBeamFraction;
  G4double mBeamDirX;
  G4double mBeamDirY;
  G4double mBeamDivergenceX;
  G4double mBeamDivergenceY;
  G4double mBeamXPosShift;
  G4double mBeamYPosShift;

  G4double mBeamSpecialXPos;
  G4double mBeamSpecialYPos;
  G4double mBeamSpecialZPos;

  G4double mBeamSpecialXRange;

  G4int mActivateBeamShiftNtuple;

  G4double PMTPEMomInit;

  G4int HitCreationOption;

  G4double ECXShift;

  G4int WriteOutputFile;

  G4String MirrorReflFileName;
  G4String OutputFileName;
  G4String OutputHistoFileName;
  G4String OutputNtupleFileName;

  G4int mVerboseInfoFlag ;
  G4int mBatchModeFlag;
  G4int mNumEventInBatchMode;
  G4int mVerboseOutputFileFlag;
  G4int mPMTSiReflFlag;


  G4double mConstPhotWlenBeam;
  G4double mPhotWlenMinBeam;
  G4double mPhotWlenMaxBeam;

  G4int mSpecialStudyVesselRotation;
  G4int mSpecialStudyCrystalRotation;
  G4double mSpecialStudyCrystalRotationX;
  G4double mSpecialStudyCrystalRotationY;
  G4int mSpecialStudyMasterRotation;
  G4double mSpecialStudyMasterRotationX;
  G4double mSpecialStudyMasterRotationY;
  G4int mRadiatorConfiguration;
  G4int mLTRadiatorSampleType;
  G4int mLTSelectRadiatorActivate;
  // This is by default 0 means all radiators are activated if it is installed.
  // 1 means only the LTphC activated and the LTSubstrate and LTFilter are deactiated
  // 2 means only the LTphC activated and the LTSubstrate and LTFilter and Nitrogen (ambient atmosphere) are
  //         deactivated
  G4int mLTMapCreate;
  G4int mLTRadGeometryFlag;  // 0 means the first testbeam setup in 2016 LT crystal run (default)
                             // 1 means the second testbeam setup in 2016 LT crystal run
 
  G4int mQWRadInstallFlag;  // 0 means the QW radiator is not installed for the Run config 10
                            // 1 means QW radiator is installed instead of the plymerplus radiator , for run config 10

  
  G4int mGasCherenkovSwitchOffFlag ;  // 0 means the  Cherenkov photon production in air is switched as normal
                                    // 1 means the  Cherenkov photon production in air is switced off for test.
 
  G4int mRichTbMirrorGeomFlag;  // 0 means it is the spherical mirror
                                // 1 means it is the large parabolic mirror

  std::vector<G4double> mDemagConstShiftAtAnodeX;
  std::vector<G4double> mDemagConstShiftAtAnodeY;
  std::vector<G4double> mPMTAdditionalLocalRotationZ;
  std::vector<G4double> mPMTAlignmentLocalShiftX;
  std::vector<G4double> mPMTAlignmentLocalShiftY;
  std::vector<G4double> mPhSupFrameAdditionalShift;
  G4double mPhSupFrameAdditionalZRot;
  G4double mPhSupFrameAdditionalVertTilt;
  G4double mMapmtDetectionEfficiency;
  G4int mMapmtPixelEfficiencyFlag; // 1 means the optimized pixel efficiency applied.The overall detection efficiency not applied.
                                  //  2 means the threshold7 pixel efficiency applied. The  overall detection efficiency not applied.
                                 // 0 means the pixel efficiency not applied. The overall detectione efficiency applied.


  G4String mMapmtPixelOptEffFileNameJura;
  G4String mMapmtPixelThr7EffFileNameJura;
  G4String mMapmtPixelOptEffFileNameSaleve;
  G4String mMapmtPixelThr7EffFileNameSaleve;
  G4String mMapmtPixelOptEffFileNameJuraUpgradeDummy;
  G4String mMapmtPixelOptEffFileNameSaleveUpgradeDummy;
  G4String mMapmtPixelEffFileNameJuraTop100;
  G4String mMapmtPixelEffFileNameJuraBottom100;
  G4String mMapmtPixelEffFileNameSaleveTop100;
  G4String mMapmtPixelEffFileNameSaleveBottom100;





};
#endif                          /*RichTbRunConfig_h */
