#ifndef INCLUDE_RICHTBHPDGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBHPDGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

const G4int NumHpds= 1;

const G4double RichTbHpdMasterRadius = 43.5 * CLHEP::mm;
const G4double RichTbHpdMasterZSize = 160.0 * CLHEP::mm;

const G4double RichTbHpdEnvLargeTubeOutR = 40.3 * CLHEP::mm;
const G4double RichTbHpdEnvLargeTubeThickness = 0.75 * CLHEP::mm;

const G4double RichTbHpdEnvLargeTubInnR=
        RichTbHpdEnvLargeTubeOutR-RichTbHpdEnvLargeTubeThickness;

const G4double RichTbHpdEnvLargeTubeZSize = 96.0 * CLHEP::mm;
const G4double RichTbHpdEnvEndCapZsize = 2.0 * CLHEP::mm;
const G4double RichTbHpdEnvEndCapRadTolerence = 0.1 * CLHEP::mm;

const G4double RichTbHpdQuartzWOuterRad = 62.0 * CLHEP::mm;


const G4double RichTbHpdQuartzWThickness = 7.0 * CLHEP::mm;



const G4double RichTbHpdPhCathodeThickness= 0.05 * CLHEP::mm;
const G4double RichTbHpdActiveInputRad=37.5 * CLHEP::mm;
//const G4double RichTbHpdActiveInputRad=36.0 * CLHEP::mm;
const G4double RichTbHpdQuartzWCylEnvInnerR= RichTbHpdActiveInputRad;
const G4double RichTbHpdQuartzWCylEnvOuterR = 40.3 * CLHEP::mm;

const G4double RichTbHpdEnvFromEndZ= 40.5 * CLHEP::mm;
const G4double RichTbHpdQuartzWindowFromEndZ=20.0 * CLHEP::mm;
//const G4double RichTbHpdSiDetDistZFromPhCathode=100.0 * CLHEP::mm;
const G4double RichTbHpdSiDetDistZFromPhCathode=111.2 * CLHEP::mm;
const G4double RichTbHpdQWCylEnvOuterLargeValue=500.0 * CLHEP::mm;
const G4double RichTbHpdQWCylEnvZLargeValue=1000.0 * CLHEP::mm;

// create a hexagonal array. The max radius= 22/2=11 mm

const G4double RichTbHpdSiDetRadiusSize= 11 * CLHEP::mm;
const G4double RichTbHpdSiDetZSize=0.3 * CLHEP::mm;

const G4double RichTbHpdSiDetHexPixelFlatToFlatSize=1.4 * CLHEP::mm;
const G4double RichTbHpdSiDetHexPixelDiagonalSize = RichTbHpdSiDetHexPixelFlatToFlatSize * 2.0/ sqrt(3.0);
const G4double RichTbHpdSiDetHexPixelEdgeSize= RichTbHpdSiDetHexPixelFlatToFlatSize/sqrt(3.0);
const G4double RichTbHpdSiDetHexPixelRadius= RichTbHpdSiDetHexPixelDiagonalSize/2.0;
const G4double RichTbHpdSiDetPixelZSize = RichTbHpdSiDetZSize;

const G4double RichTbHpdSiDetPixelHexPhiStart=0.0 * CLHEP::rad;
const G4double RichTbHpdSiDetPixelHexPhiEnd=pi * CLHEP::rad;
const G4int RichTbHpdSiDetPixelHexNumSide=6;
const G4int RichTbHpdSiDetPixelHexNumZPlanes=2;
const G4double  RichTbHpdSiDetPixelHexZPlane []= {-0.5*RichTbHpdSiDetPixelZSize, 0.5*RichTbHpdSiDetPixelZSize};
const G4double  RichTbHpdSiDetPixelHexRInner [] ={ 0.0 * CLHEP::mm, 0.0 * CLHEP::mm};
const G4double  RichTbHpdSiDetPixelHexROuter [] ={RichTbHpdSiDetHexPixelRadius,RichTbHpdSiDetHexPixelRadius};
const G4int NumPixelTotInSingleHpd= 163;
const G4int NumHpdPixelRows=15;
const std::vector<G4int> NumHpdPixelInRows ={6,9,10,11,12,13,14,13,14,13,12,11,10,9,6  };

const G4double HpdPixelYCenterStart= -10.5* RichTbHpdSiDetHexPixelEdgeSize;
const G4double HpdPixelYCenterShift= 1.5*  RichTbHpdSiDetHexPixelEdgeSize;
const G4double HpdPixelXCenterShift = 0.5* RichTbHpdSiDetHexPixelFlatToFlatSize;
const G4double RichTbSiDetShiftAlongX  = 0.0 * CLHEP::mm;
const G4double RichTbSiDetShiftAlongY  = 0.0 * CLHEP::mm;

const G4double RichTbHpdSMasterRadius = RichTbHpdMasterRadius;
const G4double RichTbHpdSMasterZSize = RichTbHpdMasterZSize;
const G4double RichTbHpdEnvEndCapRad = RichTbHpdEnvLargeTubInnR - RichTbHpdEnvEndCapRadTolerence;
const G4double RichTbHpdQuartzWInnerRad = RichTbHpdQuartzWOuterRad - RichTbHpdQuartzWThickness;
const G4double RichTbHpdPhCathodeOuterRad = RichTbHpdQuartzWInnerRad;
const G4double RichTbHpdPhCathodeInnerRad = RichTbHpdPhCathodeOuterRad - RichTbHpdPhCathodeThickness;

const G4double RichTbHpdQuartzWDeltaTheta = asin( RichTbHpdActiveInputRad / RichTbHpdQuartzWInnerRad );

const G4double  RichTbHpdPhCathodeDeltaTheta = RichTbHpdQuartzWDeltaTheta;

// now positioning the various parts in an hpd.
const G4double RichTbEnvLargeTubZLocation =
 -0.5*(RichTbHpdSMasterZSize-RichTbHpdEnvLargeTubeZSize)+ RichTbHpdEnvFromEndZ;
const G4double RichTbHpdEndCapZLocation =
 -0.5*(RichTbHpdSMasterZSize-RichTbHpdEnvEndCapZsize)+
 RichTbHpdEnvFromEndZ+RichTbHpdEnvLargeTubeZSize;
const G4double RichTbHpdQuartzWZLocation = -0.5*RichTbHpdSMasterZSize
 +RichTbHpdQuartzWindowFromEndZ+ RichTbHpdQuartzWOuterRad;
const G4double RichTbHpdPhCathodeZLocation=RichTbHpdQuartzWZLocation;
const G4double RichTbHpdSiDetZLocation=-0.5*RichTbHpdSMasterZSize + RichTbHpdQuartzWindowFromEndZ
                              + RichTbHpdQuartzWThickness+RichTbHpdSiDetDistZFromPhCathode
                              + 0.5*RichTbHpdSiDetZSize;

const G4double RichTbHpdQuartzWRotY=pi * CLHEP::rad;
const G4double RichTbHpdPhCathodeRotY=RichTbHpdQuartzWRotY;

// default parameters for Hpd componenets
const G4double RichTbHpdSMasterXLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdSMasterYLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdSMasterZLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdEnvTubeXLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdEnvTubeYLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdEndCapXLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdEndCapYLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdQuartzWindowXLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdQuartzWindowYLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdPhCathodeXLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdPhCathodeYLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdQWCylXLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdQWCylYLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdQWCylZLocation=0.0 * CLHEP::mm;
const G4double RichTbHpdMasterInnerRad=0.0 * CLHEP::mm;
const G4double  RichTbHpdSMasterInnerRad=0.0 * CLHEP::mm;
const G4double  RichTbHpdMasterStartPhi=0.0 * CLHEP::rad;
const G4double  RichTbHpdMasterEndPhi = (2.0*pi) * CLHEP::rad;
const G4double  RichTbHpdSMasterStartPhi=0.0 * CLHEP::rad;
const G4double  RichTbHpdSMasterEndPhi = (2.0*pi) * CLHEP::rad;
const G4double  RichTbHpdEnvelopeTubeStartPhi=0.0 * CLHEP::rad;
const G4double  RichTbHpdEnvelopeTubeEndPhi=(2.0*pi) * CLHEP::rad;
const G4double  RichTbHpdEnvelopeEndCapStartPhi=0.0 * CLHEP::rad;
const G4double  RichTbHpdEnvelopeEndCapEndPhi=(2.0*pi) * CLHEP::rad;
const G4double  RichTbHpdEndCapInnerRad=0.0 * CLHEP::mm;
const G4double  RichTbHpdQuartzWStartPhi=0.0 * CLHEP::rad;
const G4double  RichTbHpdQuartzWDeltaPhi=(2.0*pi) * CLHEP::rad;
const G4double  RichTbHpdQuartzWStartTheta=0.0 * CLHEP::rad;
const G4double  RichTbHpdPhCathodeStartPhi=0.0 * CLHEP::rad;
const G4double  RichTbHpdPhCathodeDeltaPhi=(2.0*pi) * CLHEP::rad;
const G4double  RichTbHpdPhCathodeStartTheta=0.0 * CLHEP::rad;
const G4double  RichTbSiDetNominalXLocation=0.0 * CLHEP::mm;
const G4double  RichTbSiDetNominalYLocation=0.0 * CLHEP::mm;
const G4double  RichTbHpdQWCylEnvStartPhi=0.0 * CLHEP::rad;
const G4double  RichTbHpdQWCylEnvEndPhi=(2.0*pi) * CLHEP::rad;
const G4double  RichHpdSiPixelPosZInSiDet=0.0 * CLHEP::mm;
const G4double RichTbHpdSiDetInnerRadiusSize= 0.0 * CLHEP::mm;
const G4double RichTbHpdSiDetStartPhi=0.0 * CLHEP::rad;
const G4double RichTbHpdSiDetEndPhi= (2.0*pi) * CLHEP::rad;

// now for the HPD locations.
const G4String HpdNamesBox="Hpd0Box";

const G4String HpdNamesLog= "Hpd0Log";

const G4String HpdNamesPhys= "Hpd0Phys";
const G4double HpdPhCathodeXCenterInPhSup= 0.0 * CLHEP::mm;

const G4double HpdPhCathodeYCenterInPhSup = 0.0 * CLHEP::mm;

const G4double RichTbHpdMasterXLocation = HpdPhCathodeXCenterInPhSup;
const G4double RichTbHpdMasterYLocation = HpdPhCathodeYCenterInPhSup;

 const G4double RichTbHpdMasterZLocation = (-0.5*PhDetSupFrameZSize)  +
  +0.5*RichTbHpdMasterZSize;

const G4double RichTbHpdMasterRotationYAxis = 0.0 * CLHEP::rad;
const G4double RichTbHpdMasterRotationZAxis = 0.0 * CLHEP::rad;



#endif // INCLUDE_RICHTBHPDGEOMETRYPARAMETERS_HH
