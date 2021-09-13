#ifndef INCLUDE_RICHTBLTPHCGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBLTPHCGEOMETRYPARAMETERS_HH 1

// Include files
#include "CLHEP/Units/PhysicalConstants.h"
//  SampelA= Sample 101715
// SampleB = Sample 100919

const G4double RichTbLTSubstrateThickness=6.35 * CLHEP::mm;
const G4double RichTbLTPhCSampleAThickness=0.1195 * CLHEP::mm;
const G4double RichTbLTPhCSampleBThickness=0.0965 * CLHEP::mm;
const G4double RichTbLTSubstrateThicknessTolerence=0.02 * CLHEP::mm;

//const G4double RichTbLTPhCSampleAThickness=0.01195 * CLHEP::mm;
//const G4double RichTbLTPhCSampleBThickness=0.00965 * CLHEP::mm;
//const G4double RichTbLTSubstrateThicknessTolerence=0.002 * CLHEP::mm;


// sample composition: upstreamto downstream    tolerencethickness-->PhC-->substrate


//const G4double RichTbLTSampleDownstreamSurfaceLocation= 15.0 * CLHEP::mm;

//const G4double PhotonDetectorPlaneZGapSampleAFromLTDnsSurface = 30.0 * CLHEP::mm;
const G4double PhotonDetectorPlaneZGapSampleAFromLTDnsSurface = 45.0 * CLHEP::mm;

const G4double PhotonDetectorPlaneZGapSampleAFromLTDnsSurfaceRun2 = 36.0 * CLHEP::mm;

const G4double PhotonDetectorPlaneZGapSampleBFromLTDnsSurface = 62.0 * CLHEP::mm;


const G4double RichTbLTSampleADownstreamSurfaceLocation =  PhotonDetectorPlaneZWithLTRadiator 
                   -PhotonDetectorPlaneZGapSampleAFromLTDnsSurface;

const G4double RichTbLTSampleADownstreamSurfaceLocationRun2 =  PhotonDetectorPlaneZWithLTRadiator 
                   -PhotonDetectorPlaneZGapSampleAFromLTDnsSurfaceRun2;

const G4double RichTbLTSampleBDownstreamSurfaceLocation =  PhotonDetectorPlaneZWithLTRadiator 
                   -PhotonDetectorPlaneZGapSampleBFromLTDnsSurface;




const G4double RichTbLTSampleAThickness= RichTbLTSubstrateThickness+
                                         RichTbLTPhCSampleAThickness+ 
                                         RichTbLTSubstrateThicknessTolerence;

const G4double RichTbLTSampleBThickness= RichTbLTSubstrateThickness+
                                         RichTbLTPhCSampleBThickness+ 
                                         RichTbLTSubstrateThicknessTolerence;


const G4double RichTbLTSampleADiameter=12.7 * CLHEP::mm;

const G4double RichTbLTSampleBDiameter=25.0 * CLHEP::mm;


const G4double RichTbLTSampleARadius=  RichTbLTSampleADiameter*0.5;
const G4double RichTbLTSampleBRadius=  RichTbLTSampleBDiameter*0.5;




const G4double RichTbLTSampleXLocation=0.0 * CLHEP::mm;
const G4double RichTbLTSampleYLocation=0.0 * CLHEP::mm;


const G4double RichTbLTSampleSiliconeExtraThickness = 2.0 * CLHEP::mm;
const G4double RichTbLTSampleSiliconeExtraRadius = 1.0 * CLHEP::mm;

const G4double RichTbLTSampleAMasterThickness= RichTbLTSampleAThickness+RichTbLTSampleSiliconeExtraThickness;
const G4double RichTbLTSampleBMasterThickness= RichTbLTSampleBThickness+RichTbLTSampleSiliconeExtraThickness;

const G4double RichTbLTSampleAMasterRadius= RichTbLTSampleARadius +  RichTbLTSampleSiliconeExtraRadius;
const G4double RichTbLTSampleBMasterRadius= RichTbLTSampleBRadius +  RichTbLTSampleSiliconeExtraRadius;


const G4double RichTbLTSampleAMasterHoleRadius= RichTbLTSampleARadius;
const G4double RichTbLTSampleAMasterHoleZLargeSize= 30.0 * CLHEP::mm;
//const G4double RichTbLTSampleAMasterHoleZLocation= 0.5*(RichTbLTSampleAMasterThickness
//                                                        +RichTbLTSampleAMasterHoleZLargeSize
//                                                        -RichTbLTSampleSiliconeExtraThickness);

const G4double RichTbLTSampleAMasterHoleZLocation= 0.5*(RichTbLTSampleAMasterThickness
                                                        +RichTbLTSampleAMasterHoleZLargeSize);

const G4double RichTbLTSampleBMasterHoleRadius= RichTbLTSampleBRadius;
const G4double RichTbLTSampleBMasterHoleZLargeSize= 30.0 * CLHEP::mm;

//const G4double RichTbLTSampleBMasterHoleZLocation= 0.5*(RichTbLTSampleBMasterThickness
//                                                        +RichTbLTSampleBMasterHoleZLargeSize
//                                                        -RichTbLTSampleSiliconeExtraThickness);

const G4double RichTbLTSampleBMasterHoleZLocation= 0.5*(RichTbLTSampleBMasterThickness
                                                        +RichTbLTSampleBMasterHoleZLargeSize);


const G4double RichTbLTSampleAMasterZLocation=RichTbLTSampleADownstreamSurfaceLocation 
                     + 0.5*RichTbLTSampleSiliconeExtraThickness - RichTbLTSampleAMasterThickness*0.5;

const G4double RichTbLTSampleAMasterZLocationRun2=RichTbLTSampleADownstreamSurfaceLocationRun2 
                     + 0.5*RichTbLTSampleSiliconeExtraThickness - RichTbLTSampleAMasterThickness*0.5;



const G4double RichTbLTSampleBMasterZLocation=RichTbLTSampleBDownstreamSurfaceLocation 
                     + 0.5*RichTbLTSampleSiliconeExtraThickness - RichTbLTSampleBMasterThickness*0.5;


const G4double RichTbLTSampleAZLocation=  0.5*(RichTbLTSampleAMasterThickness 
                            -RichTbLTSampleAThickness);
const G4double RichTbLTSampleBZLocation=  0.5*(RichTbLTSampleBMasterThickness 
                             -RichTbLTSampleBThickness);

//const G4double RichTbLTSampleAZLocation=  0.5*(RichTbLTSampleAMasterThickness 
//                            - RichTbLTSampleSiliconeExtraThickness -RichTbLTSampleAThickness);
//const G4double RichTbLTSampleBZLocation=  0.5*(RichTbLTSampleBMasterThickness 
//                            - RichTbLTSampleSiliconeExtraThickness -RichTbLTSampleBThickness);






const G4double RichTbLTSampleASubstrateLocationInSample=0.5*(RichTbLTSampleAThickness-RichTbLTSubstrateThickness);
const G4double RichTbLTSampleAPhCLocationInSample=0.5*(RichTbLTSampleAThickness-RichTbLTPhCSampleAThickness)-
                                                  RichTbLTSubstrateThickness;


const G4double RichTbLTSampleBSubstrateLocationInSample=0.5*(RichTbLTSampleBThickness-RichTbLTSubstrateThickness);
const G4double RichTbLTSampleBPhCLocationInSample=0.5*(RichTbLTSampleBThickness-RichTbLTPhCSampleBThickness)-
                                                  RichTbLTSubstrateThickness;





//const G4double RichTbLTFilterAGlassThickness=2.0 * CLHEP::mm;

const G4double RichTbLTFilterAGlassThickness=12.0 * CLHEP::mm;


const G4double RichTbLTFilterBGlassThickness=2.0 * CLHEP::mm;

const G4double RichTbLTFilterSiliconeExtraThickness=0.5 * CLHEP::mm;


const G4double RichTbLTFilterAThickness=RichTbLTFilterAGlassThickness+RichTbLTFilterSiliconeExtraThickness;
const G4double RichTbLTFilterBThickness=RichTbLTFilterBGlassThickness+RichTbLTFilterSiliconeExtraThickness;

//const G4double RichTbLTFilterAGlassRadius=10.0 * CLHEP::mm;

const G4double RichTbLTFilterAGlassRadius=25.5 * CLHEP::mm;

const G4double RichTbLTFilterBGlassRadius=15.0 * CLHEP::mm;
const G4double RichTbLTFilterSiliconeThickness=2.0 * CLHEP::mm;

const G4double RichTbLTFilterARadius=RichTbLTFilterAGlassRadius+RichTbLTFilterSiliconeThickness;
const G4double RichTbLTFilterBRadius=RichTbLTFilterBGlassRadius+RichTbLTFilterSiliconeThickness;

const G4double RichTbLTFilterHoleARadius =  RichTbLTFilterAGlassRadius;






//const G4double RichTbLTFilterHoleALargeZSize= 20.0 * CLHEP::mm;
const G4double RichTbLTFilterHoleALargeZSize= 40.0 * CLHEP::mm;
const G4double RichTbLTFilterHoleADnsZLocation = 0.5*(RichTbLTFilterHoleALargeZSize
                                                     +RichTbLTFilterAThickness-RichTbLTFilterSiliconeExtraThickness);

const G4double RichTbLTFilterHoleAUpsZLocation = -1.0*RichTbLTFilterHoleADnsZLocation;



const G4double RichTbLTFilterHoleBRadius =  RichTbLTFilterBGlassRadius;
const G4double RichTbLTFilterHoleBLargeZSize= 20.0 * CLHEP::mm;
const G4double RichTbLTFilterHoleBDnsZLocation = 0.5*(RichTbLTFilterHoleBLargeZSize
                                                      +RichTbLTFilterBThickness-RichTbLTFilterSiliconeExtraThickness);

const G4double RichTbLTFilterHoleBUpsZLocation = -1.0*RichTbLTFilterHoleBDnsZLocation;



//const G4double RichTbLTFilterSampleGap=2.0 * CLHEP::mm;

const G4double RichTbLTFilterSampleGap=14.0 * CLHEP::mm;

//const G4double RichTbLTFilterAXLocation=14.0 * CLHEP::mm;
//const G4double RichTbLTFilterBXLocation=18.0 * CLHEP::mm;
// Filter on the right side as one looks downstream

//const G4double RichTbLTFilterAXLocation=-14.0 * CLHEP::mm;

const G4double RichTbLTFilterAXLocation=-47.3 * CLHEP::mm;


const G4double RichTbLTFilterBXLocation=-20.0 * CLHEP::mm;

const G4double RichTbLTFilterYLocation=0.0 * CLHEP::mm;

const G4double RichTbLTFilterGlassAXLocation=0.0 * CLHEP::mm;
const G4double RichTbLTFilterGlassAYLocation=0.0 * CLHEP::mm;
const G4double RichTbLTFilterGlassAZLocation=0.0 * CLHEP::mm;

const G4double RichTbLTFilterGlassBXLocation=0.0 * CLHEP::mm;
const G4double RichTbLTFilterGlassBYLocation=0.0 * CLHEP::mm;
const G4double RichTbLTFilterGlassBZLocation=0.0 * CLHEP::mm;


const G4double RichTbLTFilterAZLocation = RichTbLTSampleAMasterZLocation +
  0.5*(RichTbLTSampleAMasterThickness+RichTbLTFilterAThickness)+RichTbLTFilterSampleGap;

const G4double RichTbLTFilterAZLocationRun2 = RichTbLTSampleAMasterZLocationRun2 +
  0.5*(RichTbLTSampleAMasterThickness+RichTbLTFilterAThickness)+RichTbLTFilterSampleGap;

const G4double RichTbLTFilterBZLocation = RichTbLTSampleBMasterZLocation+
  0.5*(RichTbLTSampleBMasterThickness+RichTbLTFilterBThickness)+RichTbLTFilterSampleGap;



//Now for the sameple A cover

//const G4double SampleASiliconCoverRadialTolerence=0.01 * CLHEP::mm;
//const G4double SampleASiliconCoverLengthTolerence=0.01 * CLHEP::mm;

//const G4double SampleASiliconCoverInnerRadius= 0.5* RichTbLTSampleADiameter + SampleASiliconCoverRadialTolerence;
//const G4double SampleASiliconCoverOuterRadius = 8.0 * CLHEP::mm;
//const G4double SampleASiliconCoverOuterLength = 8.0 * CLHEP::mm;
//const G4double SampleASiliconCoverLocalShift = 0.5*SampleASiliconCoverOuterLength 
//  - RichTbLTSampleAThickness - SampleASiliconCoverLengthTolerence;
//const G4double SampleASiliconCoverInnerLargeLength = 30.0 * CLHEP::mm;
//const G4double SampleASiliconCoverInnerLocation = 0.5*SampleASiliconCoverInnerLargeLength + SampleASiliconCoverLocalShift;
//const G4double SampleASiliconCoverOuterLocation= RichTbLTSampleAZLocation 
//  + 0.5*(RichTbLTSampleAThickness -SampleASiliconCoverOuterLength);


//Now for the sampel B cover

//const G4double SampleBSiliconCoverRadialTolerence=0.01 * CLHEP::mm;
//const G4double SampleBSiliconCoverLengthTolerence=0.01 * CLHEP::mm;

//const G4double SampleBSiliconCoverInnerRadius= 0.5* RichTbLTSampleBDiameter + SampleBSiliconCoverRadialTolerence;
//const G4double SampleBSiliconCoverOuterRadius = 15.0 * CLHEP::mm;
//const G4double SampleBSiliconCoverOuterLength = 8.0 * CLHEP::mm;

//const G4double SampleBSiliconCoverLocalShift = 0.5*SampleBSiliconCoverOuterLength 
//  - RichTbLTSampleBThickness - SampleBSiliconCoverLengthTolerence;
//const G4double SampleBSiliconCoverInnerLargeLength = 30.0 * CLHEP::mm;
//const G4double SampleBSiliconCoverInnerLocation = 0.5*SampleBSiliconCoverInnerLargeLength + SampleBSiliconCoverLocalShift//;
//const G4double SampleBSiliconCoverOuterLocation= RichTbLTSampleBZLocation 
//                   + 0.5* SampleBSiliconCoverOuterLength - RichTbLTSampleBThickness;



const G4double RichTbLTFilterAGlassRadiusTestForMapfile=70.0 * CLHEP::mm;
const G4double RichTbLTFilterBGlassRadiusTestForMapfile=70.0 * CLHEP::mm;
const G4double RichTbLTFilterAGlassThicknessTestForMapfile=4.0 * CLHEP::mm;
const G4double RichTbLTFilterBGlassThicknessTestForMapfile=4.0 * CLHEP::mm;

const G4double RichTbLTFilterAThicknessTestForMapfile=RichTbLTFilterAGlassThicknessTestForMapfile;
const G4double RichTbLTFilterBThicknessTestForMapfile=RichTbLTFilterBGlassThicknessTestForMapfile;
const G4double RichTbLTFilterARadiusTestForMapfile=RichTbLTFilterAGlassRadiusTestForMapfile;
const G4double RichTbLTFilterBRadiusTestForMapfile=RichTbLTFilterBGlassRadiusTestForMapfile;
const G4double RichTbLTFilterHoleARadiusTestForMapfile =  RichTbLTFilterAGlassRadiusTestForMapfile;

const G4double RichTbLTFilterAZLocationTestForMapfile = RichTbLTSampleAMasterZLocation +
  0.5*(RichTbLTSampleAMasterThickness+RichTbLTFilterAThicknessTestForMapfile)+RichTbLTFilterSampleGap;


const G4double RichTbLTFilterAZLocationTestForMapfileRun2 = RichTbLTSampleAMasterZLocationRun2 +
  0.5*(RichTbLTSampleAMasterThickness+RichTbLTFilterAThicknessTestForMapfile)+RichTbLTFilterSampleGap;

const G4double RichTbLTFilterBZLocationTestForMapfile = RichTbLTSampleBMasterZLocation+
  0.5*(RichTbLTSampleBMasterThickness+RichTbLTFilterBThicknessTestForMapfile)+RichTbLTFilterSampleGap;





#endif // INCLUDE_RICHTBLTPHCGEOMETRYPARAMETERS_HH
