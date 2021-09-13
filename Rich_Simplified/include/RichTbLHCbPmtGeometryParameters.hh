#ifndef INCLUDE_RICHTBLHCBPMTGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBLHCBPMTGEOMETRYPARAMETERS_HH 1


const G4double RichLbPMTMasterLateralSize= 26.4* CLHEP::mm;
const G4double RichLbPMTMasterBoxXSize = RichLbPMTMasterLateralSize;
const G4double RichLbPMTMasterBoxYSize = RichLbPMTMasterLateralSize;
const G4double RichLbPMTMasterBoxZSize = 19.4 * CLHEP::mm;
const G4double RichLbPMTSMasterBoxXSize = RichLbPMTMasterBoxXSize ;
const G4double RichLbPMTSMasterBoxYSize = RichLbPMTMasterBoxYSize ;
const G4double RichLbPMTSMasterBoxZSize = RichLbPMTMasterBoxZSize;
const G4double RichLbPMTEndToQuartzOuterSurface= 2.7 * CLHEP::mm;
const G4double RichLbPMTQuartzToAnodeSurface = 10.0 * CLHEP::mm;

const G4double RichLbPMTAnodeXSize = 23.0*CLHEP::mm;
const G4double RichLbPMTAnodeYSize = RichLbPMTAnodeXSize;
const G4double RichLbPMTAnodeZSize = 0.5 *CLHEP::mm;

const G4double RichLbPMTPixelXSize = 2.875 *CLHEP::mm;
const G4double RichLbPMTPixelYSize = RichLbPMTPixelXSize;
const G4double RichLbPMTPixelZSize = RichLbPMTAnodeZSize;
const G4double RichLbPMTPixelPosZ = 0.0* CLHEP::mm;

const G4double RichLbPMTPixelGap = 0.2 * CLHEP::mm;

const G4int RichLbPMTNumPixelsInRow=8;
const G4int RichLbPMTNumPixelsInCol=8;
const G4int RichLbNumPixelsInPmt= RichLbPMTNumPixelsInRow * RichLbPMTNumPixelsInCol;
 
const G4double RichLbPMTQuartzXSize = 25.2 * CLHEP::mm;
const G4double RichLbPMTQuartzYSize = RichLbPMTQuartzXSize ;
const G4double RichLbPMTQuartzZSize = 0.8 * CLHEP::mm;
const G4double RichLbPMTPhCathXSize = RichLbPMTQuartzXSize;
const G4double RichLbPMTPhCathYSize = RichLbPMTPhCathXSize;
const G4double RichLbPMTPhCathZSize = 0.1 * CLHEP::mm;
const G4double RichLbPMTLateralTolerence=0.05 * CLHEP::mm;
const G4double RichLbPMTZTolerence = 0.25 * CLHEP::mm;


const G4double RichLbPMTFrontRingXSize = RichLbPMTSMasterBoxXSize - RichLbPMTLateralTolerence;
const G4double RichLbPMTFrontRingYSize = RichLbPMTFrontRingXSize;
const G4double RichLbPMTFrontRingZSize =  0.5 * CLHEP::mm;
const G4double RichLbPMTComponentGapZ = 0.2 * CLHEP::mm;
const G4double RichLbPMTFrontRingLateralThickness= 1.2 * CLHEP::mm; 
const G4double RichLbPMTFrontRingSubBoxZSize = 100 * CLHEP::mm; 
const G4double RichLbPMTFrontRingSubBoxXSize = RichLbPMTFrontRingXSize-2.0* RichLbPMTFrontRingLateralThickness;
const G4double RichLbPMTFrontRingSubBoxYSize = RichLbPMTFrontRingSubBoxXSize;
const G4double RichLbPMTFrontRingSubBoxXPos = 0.0 * CLHEP::mm; 
const G4double RichLbPMTFrontRingSubBoxYPos = 0.0 * CLHEP::mm; 
const G4double RichLbPMTFrontRingSubBoxZPos = 0.0 * CLHEP::mm; 


const G4double RichLbPMTSideEnvelopeThickness = 0.8 * CLHEP::mm;
const G4double RichLbPMTSideEnvelopeZSize = 14.0 * CLHEP::mm;
const G4double RichLbPMTSideEnvelopeXSize = RichLbPMTSMasterBoxXSize- RichLbPMTLateralTolerence;
const G4double RichLbPMTSideEnvelopeYSize = RichLbPMTSideEnvelopeXSize ;
const G4double RichLbPMTSideEnvelopeSubBoxXSize = RichLbPMTSideEnvelopeXSize - 2* RichLbPMTSideEnvelopeThickness;
const G4double RichLbPMTSideEnvelopeSubBoxYSize =  RichLbPMTSideEnvelopeSubBoxXSize;
const G4double RichLbPMTSideEnvelopeSubBoxZSize = 100.0* CLHEP::mm;
const G4double RichLbPMTSideEnvelopeSubBoxXPos = 0.0 * CLHEP::mm;
const G4double RichLbPMTSideEnvelopeSubBoxYPos = 0.0 * CLHEP::mm;
const G4double RichLbPMTSideEnvelopeSubBoxZPos = -0.5 * ( RichLbPMTSideEnvelopeZSize - RichLbPMTSideEnvelopeSubBoxZSize) + RichLbPMTSideEnvelopeThickness;


const G4double RichLbPMTQuartzPosZ = (0.5 *  RichLbPMTMasterBoxZSize) -  RichLbPMTEndToQuartzOuterSurface - ( 0.5 * RichLbPMTQuartzZSize) ;

const G4double RichLbPMTPhCathPosZ = RichLbPMTQuartzPosZ - 0.5 * (  RichLbPMTQuartzZSize - RichLbPMTPhCathZSize);
const G4double RichLbPMTFrontRingPosZ = RichLbPMTQuartzPosZ + 0.5 * ( RichLbPMTQuartzZSize + RichLbPMTFrontRingZSize) + RichLbPMTComponentGapZ ;
const G4double RichLbPMTSideEnvelopePosZ = RichLbPMTQuartzPosZ  
  - 0.5 * ( RichLbPMTQuartzZSize + RichLbPMTSideEnvelopeZSize ) -  RichLbPMTComponentGapZ ;
const G4double RichLbPMTAnodePosZ = RichLbPMTQuartzPosZ -RichLbPMTQuartzToAnodeSurface -0.5 * (RichLbPMTQuartzZSize + RichLbPMTAnodeZSize );



#endif // INCLUDE_RICHTBLHCBPMTGEOMETRYPARAMETERS_HH
