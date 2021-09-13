#include <iostream>
#include <fstream>
#include "RichTbRunConfig.hh"
#include "RichTbMaterialParameters.hh"
#include "globals.hh"
#include "RichTbGeometryParameters.hh"

RichTbRunConfig *RichTbRunConfig::RunConfigInstance = 0;

RichTbRunConfig::RichTbRunConfig()
: mDemagConstShiftAtAnodeX(6), mDemagConstShiftAtAnodeY(6),
  mPMTAdditionalLocalRotationZ(6),mPMTAlignmentLocalShiftX(6),
  mPMTAlignmentLocalShiftY(6),
  mPhSupFrameAdditionalShift(std::vector<G4double>(3))  {

  // in the above 3 is a dummy value.


  // Now open the Run Configuration file.

 const char* RunConfigFile =
   "../options/RunConfig.dat";

G4cout<<" Run Configuration Input is from "<< RunConfigFile<<G4endl;

 std::ifstream finpconf( RunConfigFile);

 G4double  NitrogenPressureInAtmos=1.0;
 G4double NitrogenTemperatureInKelvin = 293.0*0;
 G4double  c4f10PressureInAtmos=1.0;
 G4double c4f10TemperatureInKelvin = 293.0*0;

 G4double MirrorAdditionalTiltX = 0.0;
 G4double MirrorAdditionalTiltY = 0.0;


 G4double aDemagConstShiftAtAnodeXPMT0 = 0.0;
 G4double aDemagConstShiftAtAnodeXPMT1 = 0.0;
 G4double aDemagConstShiftAtAnodeXPMT2 = 0.0;
 G4double aDemagConstShiftAtAnodeXPMT3 = 0.0;
 G4double aDemagConstShiftAtAnodeXPMT4 = 0.0;
 G4double aDemagConstShiftAtAnodeXPMT5 = 0.0;

 G4double aDemagConstShiftAtAnodeYPMT0 = 0.0;
 G4double aDemagConstShiftAtAnodeYPMT1 = 0.0;
 G4double aDemagConstShiftAtAnodeYPMT2 = 0.0;
 G4double aDemagConstShiftAtAnodeYPMT3 = 0.0;
 G4double aDemagConstShiftAtAnodeYPMT4 = 0.0;
 G4double aDemagConstShiftAtAnodeYPMT5 = 0.0;

 G4double aPMT0AdditionalLocalRotationZ =0.0;
 G4double aPMT1AdditionalLocalRotationZ =0.0;
 G4double aPMT2AdditionalLocalRotationZ =0.0;
 G4double aPMT3AdditionalLocalRotationZ =0.0;
 G4double aPMT4AdditionalLocalRotationZ =0.0;
 G4double aPMT5AdditionalLocalRotationZ =0.0;

 G4double aPMT0AlignmentShiftX=0.0 * CLHEP::mm;
 G4double aPMT1AlignmentShiftX=0.0 * CLHEP::mm;
 G4double aPMT2AlignmentShiftX=0.0 * CLHEP::mm;
 G4double aPMT3AlignmentShiftX=0.0 * CLHEP::mm;
 G4double aPMT4AlignmentShiftX=0.0 * CLHEP::mm;
 G4double aPMT5AlignmentShiftX=0.0 * CLHEP::mm;

 G4double aPMT0AlignmentShiftY=0.0 * CLHEP::mm;
 G4double aPMT1AlignmentShiftY=0.0 * CLHEP::mm;
 G4double aPMT2AlignmentShiftY=0.0 * CLHEP::mm;
 G4double aPMT3AlignmentShiftY=0.0 * CLHEP::mm;
 G4double aPMT4AlignmentShiftY=0.0 * CLHEP::mm;
 G4double aPMT5AlignmentShiftY=0.0 * CLHEP::mm;

 G4double aPhSupFrameAdditionalShiftX=0.0;
 G4double aPhSupFrameAdditionalShiftY=0.0;
 G4double aPhSupFrameAdditionalShiftZ=0.0;


 if(!finpconf) {
   G4cout<<" Unable to open the Run Configuration file.   "
         <<"  Please check the directory and file names "<<G4endl;


 }else {

   while(! (finpconf.eof())) {

     G4cout<<"Now reading the Run Configuration "<<G4endl;

     //line 1
     finpconf>>RichTbHall_visib;
     finpconf>>RichTbUpgradeVessel_visib;
     finpconf>>RichTbCrystal_visib;
     finpconf>>RichTbCrystalCover_visib;
     finpconf>>RichTbPhDFrame_visib;
     finpconf>>RichTbEC_visib;
     finpconf>>RichTbPMTMaster_visib;
     finpconf>>RichTbPMTSMaster_visib;
     finpconf>>RichTbPMTEnvelope_visib;
     finpconf>>RichTbPMTQuartzW_visib;
     finpconf>>RichTbPMTPhCathode_visib;
     finpconf>>RichTbPMTAnode_visib;
     finpconf>>RichTbPMTFrontRing_visib;
     finpconf>>RichTbLens_visib;
     finpconf>>RichTbUpgradeRadiator_visib;
     finpconf>> RichTbUpgradeMirror_visib;
     finpconf>> RichTbUpgradeDarkCover_visib;
     finpconf>> RichTbUpgradeUpsDarkCover_visib;
     finpconf>> RichTbUpgradeSideDarkCover_visib;
     finpconf>> RichTbUpgradeDnsDarkCover_visib;



  

     finpconf>> RichTbHpdQW_visib;
     finpconf>> RichTbHpdPHC_visib;
     finpconf>> RichTbHpdSID_visib;
     finpconf>> RichTbHpdENV_visib;
     finpconf>> RichTbHpdENVCAP_visib;
     finpconf>> RichTbHpdSM_visib;
     finpconf>> RichTbHpdMas_visib;
     finpconf>> RichTbHpdSiPix_visib;
     finpconf>> RichTbLTSubstrate_visib;
     finpconf>> RichTbLTPhC_visib;
     finpconf>> RichTbLTFilter_visib;
     finpconf>> RichTbUpgradeLTCover_visib;
     finpconf>> RichTbMirrParabola_visib;
     finpconf>> RichTbPhCDetPlane_visib;
     finpconf>> RichTbQuartzRadiator_visib;
     finpconf>> RichTbQuartzRadiatorCover_visib;
     


     RichTbPhDetSupFrame_visib=RichTbPhDFrame_visib;
     

     // finpconf>> RichTbPhDetSupFrame_visib;
     // finpconf>> RichTbGasQuWin_visib;
     // finpconf>> RichTbPMTMaster_visib;
     // finpconf>> RichTbPMTSMaster_visib;
     // finpconf>> RichTbPMTEnvelope_visib;
     // finpconf>> RichTbPMTEndCap_visib;
     // finpconf>> RichTbPMTQuartzW_visib;
     // finpconf>> RichTbPMTPhCathode_visib;

     //line 2

     finpconf>>  RichTbLHCbExptHall_visib;
     finpconf>>  RichTbRich1Master_visib;
     finpconf>>  RichTbRich1SubMaster_visib;
     finpconf>>  RichTbR1SphMirror_visib;
     finpconf>>  RichTbR1FlatMirror_visib;
     finpconf>>  RichTbR1MagShRegion_visib;
     finpconf>>  RichTbR1QW_visib;
     finpconf>>   RichTbR1PhDetSupFrame_visib;
     finpconf>>   RichTbR1Module_visib ;
     finpconf>>   RichTbR1EC_visib ;
     finpconf>>   RichTbR1PmtMaster_visib ;
     finpconf>>   RichTbR1PmtSMaser_visib ;
     finpconf>>   RichTbR1PmtAnode_visib ;
     finpconf>>   RichTbR1PmtQuartz_visib ;
     finpconf>>   RichTbR1PmtPhCath_visib ;
     finpconf>>   RichTbR1PmtSideWin_visib ;
     finpconf>>   RichTbR1PmtFrontRing_visib ;
     finpconf>>   RichTbR1ModuleBackPl_visib;

     //line 3
     finpconf>>  GasTypeCode;
     finpconf>>  NitrogenPressureInAtmos;
     finpconf>>  NitrogenTemperatureInKelvin;
     finpconf>>  c4f10PressureInAtmos;
     finpconf>>  c4f10TemperatureInKelvin;
     finpconf>>  MirrorOrientCode;
     finpconf>>  MirrorAdditionalTiltX;
     finpconf>>  MirrorAdditionalTiltY;

     //line 4
     finpconf>> mNonOptimalPMTCondition;
     finpconf>> mNonOptimalPMTAbsEff;
     finpconf>> mHpdpeBackScaProb;
     finpconf>> mRandomSeedInput;

     //line 5
     finpconf>> RichTbNumPartEvent;
     finpconf>> RichTbParticleTypeCode;
     finpconf>> RichTbParticleStartPosCode;
     finpconf>> RichTbParticleDirectionCode;
     finpconf>> RichTbParticleEnergyCode;

     finpconf>>  RichTbParticleMomentum;
     finpconf>>  PosBeamFraction;
     finpconf>>  mBeamDirX;
     finpconf>>  mBeamDirY;
     finpconf>>  mBeamDivergenceX;
     finpconf>>  mBeamDivergenceY;
     finpconf>>  mBeamXPosShift;
     finpconf>>  mBeamYPosShift;
     finpconf>> mBeamSpecialXPos;
     finpconf>> mBeamSpecialYPos;
     finpconf>> mBeamSpecialZPos;
     finpconf>> mBeamSpecialXRange;
     finpconf>> mConstPhotWlenBeam;
     finpconf>> mPhotWlenMinBeam;
     finpconf>> mPhotWlenMaxBeam;

     finpconf>> PMTPEMomInit;

     finpconf>>  WriteOutputFile;
     finpconf>>  HitCreationOption;

     finpconf>> ECXShift; //starting point is 70.6 mm

     //line 6
     finpconf>> MirrorReflFileName;
     //line 7
     finpconf>> OutputFileName;
     //line 8
     finpconf>> OutputHistoFileName;
     //line 9
     finpconf>> OutputNtupleFileName;

     //line 10
     finpconf>>  mBatchModeFlag;
     finpconf>> mNumEventInBatchMode;
     finpconf>> mVerboseInfoFlag ;
     finpconf>> mVerboseOutputFileFlag ;
     finpconf>> mSpecialStudyVesselRotation;
     finpconf>>   mPMTSiReflFlag;


     //line 11
     finpconf>> aDemagConstShiftAtAnodeXPMT0;
     finpconf>> aDemagConstShiftAtAnodeXPMT1;
     finpconf>> aDemagConstShiftAtAnodeXPMT2;
     finpconf>> aDemagConstShiftAtAnodeXPMT3;
     finpconf>> aDemagConstShiftAtAnodeXPMT4;
     finpconf>> aDemagConstShiftAtAnodeXPMT5;

     finpconf>> aDemagConstShiftAtAnodeYPMT0;
     finpconf>> aDemagConstShiftAtAnodeYPMT1;
     finpconf>> aDemagConstShiftAtAnodeYPMT2;
     finpconf>> aDemagConstShiftAtAnodeYPMT3;
     finpconf>> aDemagConstShiftAtAnodeYPMT4;
     finpconf>> aDemagConstShiftAtAnodeYPMT5;

     finpconf>> aPMT0AdditionalLocalRotationZ;
     finpconf>> aPMT1AdditionalLocalRotationZ;
     finpconf>> aPMT2AdditionalLocalRotationZ;
     finpconf>> aPMT3AdditionalLocalRotationZ;
     finpconf>> aPMT4AdditionalLocalRotationZ;
     finpconf>> aPMT5AdditionalLocalRotationZ;

     //line 12
     finpconf>>  aPMT0AlignmentShiftX;
     finpconf>>  aPMT1AlignmentShiftX;
     finpconf>>  aPMT2AlignmentShiftX;
     finpconf>>  aPMT3AlignmentShiftX;
     finpconf>>  aPMT4AlignmentShiftX;
     finpconf>>  aPMT5AlignmentShiftX;

     finpconf>>  aPMT0AlignmentShiftY;
     finpconf>>  aPMT1AlignmentShiftY;
     finpconf>>  aPMT2AlignmentShiftY;
     finpconf>>  aPMT3AlignmentShiftY;
     finpconf>>  aPMT4AlignmentShiftY;
     finpconf>>  aPMT5AlignmentShiftY;

     //line 13
     finpconf>> aPhSupFrameAdditionalShiftX;
     finpconf>> aPhSupFrameAdditionalShiftY;
     finpconf>> aPhSupFrameAdditionalShiftZ;

     finpconf>>  mPhSupFrameAdditionalVertTilt;
     finpconf>>   mPhSupFrameAdditionalZRot;

     //line 14
     finpconf>> mSpecialStudyCrystalRotation;
     finpconf>> mSpecialStudyCrystalRotationX;
     finpconf>> mSpecialStudyCrystalRotationY;

     //line 15
     finpconf>> mSpecialStudyMasterRotation;
     finpconf>> mSpecialStudyMasterRotationX;
     finpconf>> mSpecialStudyMasterRotationY;

     //line 16
     finpconf>> mRadiatorConfiguration;
     finpconf>> mLTRadiatorSampleType;
     finpconf>> mLTSelectRadiatorActivate;
     finpconf>> mLTMapCreate;
     finpconf>> mLTRadGeometryFlag;
     finpconf>>  mQWRadInstallFlag;    
     finpconf>>  mGasCherenkovSwitchOffFlag;
     finpconf>>   mRichTbMirrorGeomFlag;

     //line 17
     finpconf>> mMapmtDetectionEfficiency;
     finpconf>> mMapmtPixelEfficiencyFlag;
     //line 18
     finpconf>> mMapmtPixelOptEffFileNameJura;
     //line 19
     finpconf>> mMapmtPixelThr7EffFileNameJura;
     //line 20
     finpconf>> mMapmtPixelOptEffFileNameSaleve;
     //line 21
     finpconf>> mMapmtPixelThr7EffFileNameSaleve;
     //line 22
     finpconf>> mMapmtPixelOptEffFileNameJuraUpgradeDummy;
     //line 23
     finpconf>> mMapmtPixelOptEffFileNameSaleveUpgradeDummy;
     //line 24
     finpconf>> mMapmtPixelEffFileNameJuraTop100;
     //line 25
     finpconf>> mMapmtPixelEffFileNameSaleveTop100;
     //line 26
     finpconf>> mMapmtPixelEffFileNameJuraBottom100;
     //line 27
     finpconf>> mMapmtPixelEffFileNameSaleveBottom100;





     G4cout<<"End of reading the Run Configuration "<<G4endl;


   }


 }

 mDemagConstShiftAtAnodeX.clear();
 mDemagConstShiftAtAnodeY.clear();
 mPMTAdditionalLocalRotationZ.clear();
 mPMTAlignmentLocalShiftX.clear();
 mPMTAlignmentLocalShiftY.clear();

 mDemagConstShiftAtAnodeX.push_back(aDemagConstShiftAtAnodeXPMT0 * CLHEP::mm);
 mDemagConstShiftAtAnodeX.push_back(aDemagConstShiftAtAnodeXPMT1 * CLHEP::mm);
 mDemagConstShiftAtAnodeX.push_back(aDemagConstShiftAtAnodeXPMT2 * CLHEP::mm);
 mDemagConstShiftAtAnodeX.push_back(aDemagConstShiftAtAnodeXPMT3 * CLHEP::mm);
 mDemagConstShiftAtAnodeX.push_back(aDemagConstShiftAtAnodeXPMT4 * CLHEP::mm);
 mDemagConstShiftAtAnodeX.push_back(aDemagConstShiftAtAnodeXPMT5 * CLHEP::mm);
 mDemagConstShiftAtAnodeY.push_back(aDemagConstShiftAtAnodeYPMT0 * CLHEP::mm);
 mDemagConstShiftAtAnodeY.push_back(aDemagConstShiftAtAnodeYPMT1 * CLHEP::mm);
 mDemagConstShiftAtAnodeY.push_back(aDemagConstShiftAtAnodeYPMT2 * CLHEP::mm);
 mDemagConstShiftAtAnodeY.push_back(aDemagConstShiftAtAnodeYPMT3 * CLHEP::mm);
 mDemagConstShiftAtAnodeY.push_back(aDemagConstShiftAtAnodeYPMT4 * CLHEP::mm);
 mDemagConstShiftAtAnodeY.push_back(aDemagConstShiftAtAnodeYPMT5 * CLHEP::mm);
 mPMTAdditionalLocalRotationZ.push_back(aPMT0AdditionalLocalRotationZ * CLHEP::rad);
 mPMTAdditionalLocalRotationZ.push_back(aPMT1AdditionalLocalRotationZ * CLHEP::rad);
 mPMTAdditionalLocalRotationZ.push_back(aPMT2AdditionalLocalRotationZ * CLHEP::rad);
 mPMTAdditionalLocalRotationZ.push_back(aPMT3AdditionalLocalRotationZ * CLHEP::rad);
 mPMTAdditionalLocalRotationZ.push_back(aPMT4AdditionalLocalRotationZ * CLHEP::rad);
 mPMTAdditionalLocalRotationZ.push_back(aPMT5AdditionalLocalRotationZ * CLHEP::rad);

 mPMTAlignmentLocalShiftX.push_back(aPMT0AlignmentShiftX * CLHEP::mm);
 mPMTAlignmentLocalShiftX.push_back(aPMT1AlignmentShiftX * CLHEP::mm);
 mPMTAlignmentLocalShiftX.push_back(aPMT2AlignmentShiftX * CLHEP::mm);
 mPMTAlignmentLocalShiftX.push_back(aPMT3AlignmentShiftX * CLHEP::mm);
 mPMTAlignmentLocalShiftX.push_back(aPMT4AlignmentShiftX * CLHEP::mm);
 mPMTAlignmentLocalShiftX.push_back(aPMT5AlignmentShiftX * CLHEP::mm);

 mPMTAlignmentLocalShiftY.push_back( aPMT0AlignmentShiftY * CLHEP::mm);
 mPMTAlignmentLocalShiftY.push_back( aPMT1AlignmentShiftY * CLHEP::mm);
 mPMTAlignmentLocalShiftY.push_back( aPMT2AlignmentShiftY * CLHEP::mm);
 mPMTAlignmentLocalShiftY.push_back( aPMT3AlignmentShiftY * CLHEP::mm);
 mPMTAlignmentLocalShiftY.push_back( aPMT4AlignmentShiftY * CLHEP::mm);
 mPMTAlignmentLocalShiftY.push_back( aPMT5AlignmentShiftY * CLHEP::mm);




 mPhSupFrameAdditionalShift.clear();
 mPhSupFrameAdditionalShift.push_back( aPhSupFrameAdditionalShiftX);
 mPhSupFrameAdditionalShift.push_back( aPhSupFrameAdditionalShiftY);
 mPhSupFrameAdditionalShift.push_back( aPhSupFrameAdditionalShiftZ);

 G4cout<<"Current Run Configuration  is as follows "<<G4endl;
 G4cout<<" Graphics Visibility : Hall Vessel Crystal "
       << RichTbHall_visib<<"   "<<RichTbUpgradeVessel_visib<<"   "
       << RichTbCrystal_visib<<"  "
       <<"    " <<G4endl;

 G4cout<<"LHCb Simplified Rich1 Graphics visibility "<<G4endl;
 G4cout<<"LHCb ExptHall R1Master R1SubMaster, R1SphM R1FlatM, R1MagSh R1QW R1PhDetSup  "<<
       RichTbLHCbExptHall_visib<<"  "<< RichTbRich1Master_visib<<"  "<< RichTbRich1SubMaster_visib <<
       "    "<< RichTbR1SphMirror_visib<<"   "<< RichTbR1FlatMirror_visib<<"   "<<RichTbR1MagShRegion_visib
	   <<"    "<<RichTbR1QW_visib<<"  "<<RichTbR1PhDetSupFrame_visib<<G4endl;

 G4cout<<"LHCb Module EC PmtMaster "<< RichTbR1Module_visib<<"  "<<RichTbR1EC_visib<<"  "
       <<RichTbR1PmtMaster_visib<<G4endl;

 G4cout <<" LT visib subs PHC Filter LTCover "<<RichTbLTSubstrate_visib <<"  "<<RichTbLTPhC_visib
        <<"   "<< RichTbLTFilter_visib <<"    "<<RichTbUpgradeLTCover_visib<<G4endl;

 G4cout<<"  Graphics Visibility : PhDetSupFrame EC PMTMaster PMTSMaster "
       << " PMTEnvelope  PMTEndCap PMTQuartzW PMTPhCathode   "
       << RichTbPhDetSupFrame_visib<<"   "
       << RichTbEC_visib<<"   "<< RichTbPMTMaster_visib<<"   "
       <<RichTbPMTSMaster_visib<<"   "<<RichTbPMTEnvelope_visib<<"   "
       <<RichTbPMTEndCap_visib<<"   "<<RichTbPMTQuartzW_visib<<"   "
       <<RichTbPMTPhCathode_visib<<"   "<<G4endl;

 G4cout<<"Visibility  Mirr Parabola " << RichTbMirrParabola_visib <<G4endl;
 G4cout<<"Visibility Det plane " <<RichTbPhCDetPlane_visib <<G4endl;
 G4cout<<"Visibility QW radiator and its cover "<< RichTbQuartzRadiator_visib 
            <<"  "<<RichTbQuartzRadiatorCover_visib << G4endl;
 

 G4cout<<"Nitrogen Pressure Temp  "<<NitrogenPressureInAtmos<<"    "
       <<NitrogenTemperatureInKelvin<<G4endl;
 G4cout<<"c4f10 Pressure Temp  "<<c4f10PressureInAtmos<<"    "
       <<c4f10TemperatureInKelvin<<G4endl;
 G4cout<<" Mirror Orientation code Additional Tilt wrt XAxis YAxis  "
       <<  MirrorOrientCode<<"   "
       << MirrorAdditionalTiltX  <<"  "<<MirrorAdditionalTiltY <<G4endl;


 G4cout<<" NonOptimal PMT Condition  NonOptimal PMT absolute Efficiency  "
       << mNonOptimalPMTCondition<<"   "<<mNonOptimalPMTAbsEff<<G4endl;


 G4cout<<" ParticleGun  Generation: Num of Particles generated per event   "
       << RichTbNumPartEvent<<G4endl;
 G4cout<<" ParticleGun : Code for ParticleType StartPos Direction  Energy  "
       << "and   Value for MomValue PosBeamFraction:   "
       << RichTbParticleTypeCode<<"    "
       << RichTbParticleStartPosCode<<"   "
       << RichTbParticleDirectionCode<<"    "
       <<RichTbParticleEnergyCode<<"   "
       <<RichTbParticleMomentum<<"    "
       <<PosBeamFraction<<G4endl;
    G4cout<<" ParticleGun : BeamDirXY  BeamDivXY BeamPosShift XY   "
       <<   mBeamDirX <<"   "<< mBeamDirY<<"   "
       << mBeamDivergenceX<<"   "<<mBeamDivergenceY
          << "   "<<mBeamXPosShift<<"  "<< mBeamYPosShift <<G4endl;

    G4cout<<" Special studies Beam XYZ BeamXRange phot wlen wlenmin wlenmax "
          <<mBeamSpecialXPos<<"  "<< mBeamSpecialYPos<<"  "
          <<mBeamSpecialZPos<<"  "
          <<mBeamSpecialXRange<<"   "
          <<mConstPhotWlenBeam<<"   "
          << mPhotWlenMinBeam<<"   "
          << mPhotWlenMaxBeam<< G4endl;

  G4cout<<"Activate beamshiftntuple "<<mActivateBeamShiftNtuple<<G4endl;

 G4cout<<"  PMTPEMomInit  "<< PMTPEMomInit<<G4endl;
 G4cout<<"Flag to WriteOut  HitCreationOption   "
       <<WriteOutputFile<<"    "<<  HitCreationOption<<"     "
       << G4endl;

 G4cout <<" Radiator and  LTSample config "<<  mRadiatorConfiguration 
       <<"    "<< mLTRadiatorSampleType <<G4endl;
 

 G4cout<<" Mirror refl file name "<<MirrorReflFileName<<G4endl;

 G4cout<<" Event Output FileName "<<OutputFileName<<G4endl;
 G4cout<<"Histo Output file Name  "<< OutputHistoFileName<<G4endl;
 G4cout<<"Ntuple Output file Name  "<< OutputNtupleFileName<<G4endl;

 G4cout<<"BatchMode NumEvInBatchMode  VerboseInfo "
       <<"  VerboseOutput studyvesselRot   "
       <<  mBatchModeFlag<<"   "<< mNumEventInBatchMode
       << "    " <<mVerboseInfoFlag<<"   "
       << mVerboseOutputFileFlag<<"   "
       << mSpecialStudyVesselRotation<< G4endl;

 // G4cout<< " Mapmt Pixel gap "<<  mMapmtPixelGap<<G4endl;
 G4cout<< "Pmt pixel efficiency flag  "<< mMapmtPixelEfficiencyFlag <<G4endl;

 G4cout<< " Mirror geometry flag "<<mRichTbMirrorGeomFlag <<G4endl;
 
 /*
  for(G4int ihp=0; ihp< NumPMTs; ihp++) {
   G4cout<<"PMT Demag Const shiftX in PMT  "<<ihp <<"  "<<
           mDemagConstShiftAtAnodeX[ihp]<<G4endl;
   G4cout<<"PMT Demag Const ShiftY in PMT "<<ihp<<"  "<<
            mDemagConstShiftAtAnodeY[ihp]<<G4endl;

   G4cout<<"PMT Additional RotZ wrt its Axis  "<<ihp<<"   "<<
          mPMTAdditionalLocalRotationZ[ihp]<<G4endl;

   G4cout<<"PMT Additional Xshift in phdetsupframe "<<ihp<<"  "<<
   mPMTAlignmentLocalShiftX[ihp]<<G4endl;

   G4cout<<"PMT additionl Y shift in phdet supframe "<<ihp<<"  "<<
     mPMTAlignmentLocalShiftY[ihp]<<G4endl;
 }
 */
 G4cout<<" PhDet Frame Additional Shift XYZ   "
       << mPhSupFrameAdditionalShift[0]<<"    "
       << mPhSupFrameAdditionalShift[1]<<"    "
       << mPhSupFrameAdditionalShift[2]<<"    "
       <<G4endl;

 G4cout<<" PhDet Frame Additional VertTilt Zrot "
       << mPhSupFrameAdditionalVertTilt<<"    "
       <<  mPhSupFrameAdditionalZRot<<G4endl;

 G4cout << " RadiatorConfig LtSampletype RadiatorActivate "<<  mRadiatorConfiguration 
        <<"   "<< mLTRadiatorSampleType <<"   "<< mLTSelectRadiatorActivate <<  G4endl;

 G4cout << " quartz radiator install flag  GasCgerenkov switchoff Flag"<<  mQWRadInstallFlag 
        <<"   "<< mGasCherenkovSwitchOffFlag      <<  G4endl;


 NitrogenPressure = NitrogenPressureInAtmos* CLHEP::atmosphere;
 NitrogenTemperature = NitrogenTemperatureInKelvin* CLHEP::kelvin;

  NominalNitrogenPressure = 1.0*CLHEP::atmosphere;
  NominalNitrogenTemperature = 293.0*CLHEP::kelvin;

  c4f10Pressure = c4f10PressureInAtmos* CLHEP::atmosphere;
  c4f10Temperature = c4f10TemperatureInKelvin*CLHEP::kelvin;

  Nominalc4f10Pressure = 1.0*CLHEP::atmosphere;
  Nominalc4f10Temperature = 293.0*CLHEP::kelvin;

  MirrorAddTiltX= MirrorAdditionalTiltX * CLHEP::rad;
  MirrorAddTiltY = MirrorAdditionalTiltY * CLHEP::rad;


}


RichTbRunConfig::~RichTbRunConfig()
{
    ;
}


RichTbRunConfig *RichTbRunConfig::getRunConfigInstance()
{

    if (RunConfigInstance == 0) {
        RunConfigInstance = new RichTbRunConfig();
    }

    return RunConfigInstance;

}


