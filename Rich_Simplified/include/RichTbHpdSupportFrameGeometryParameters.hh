#ifndef INCLUDE_RICHTBHPDSUPPORTFRAMEGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBHPDSUPPORTFRAMEGEOMETRYPARAMETERS_HH 1

#include "CLHEP/Units/PhysicalConstants.h"



const G4double HpdPhDetSupFrameXSize = 100.0 * CLHEP::mm;
const G4double HpdPhDetSupFrameYSize = 100.0 * CLHEP::mm; 

const G4double HpdPhDetSupFrameZSize = 180.0 * CLHEP::mm;


//const G4double RadiatorHpdGap = 46.40 * CLHEP::mm;
 
const G4double HpdExtraZShiftFromFocalPlane= 26.4 * CLHEP::mm;

//const G4double RadiatorHpdGap = 25.5 * CLHEP::mm + 26.4 mm;

const G4double RadiatorHpdGap =    PhotonDetPlaneGapWrtRadiatorSurface + HpdExtraZShiftFromFocalPlane;

const G4double HpdPhotonDetectorPlaneZ = RadiatorLensThickness +  RadiatorHpdGap + RichTbHpdQuartzWThickness;

//const G4double HpdPhotonDetectorPlaneX = -68.1 * CLHEP::mm; // from the drawing

//const G4double HpdPhotonDetectorSupFrameXLocation = HpdPhotonDetectorPlaneX; 
const G4double HpdPhotonDetectorSupFrameXLocation = PhDetSupFrameXLocation [1]; // from later measurements.
const G4double HpdPhotonDetectorSupFrameYLocation = 0.0  * CLHEP::mm;
const G4double HpdPhDetFrameZTolerence = 10.0 * CLHEP::mm;


const G4double HpdPhotonDetPlaneToPhDetSupFrameFrontSurface = -1.0*(RichTbHpdQuartzWThickness + 
                                                                    RichTbHpdQuartzWindowFromEndZ + HpdPhDetFrameZTolerence );

const G4double HpdPhDetSupFrameZLocation =   HpdPhotonDetectorPlaneZ 
         +HpdPhotonDetPlaneToPhDetSupFrameFrontSurface+ 0.5* HpdPhDetSupFrameZSize;


const G4double RichTbHpdMasterZLocation = (-0.5*HpdPhDetSupFrameZSize)  +0.5*RichTbHpdMasterZSize + HpdPhDetFrameZTolerence ;


#endif // INCLUDE_RICHTBHPDSUPPORTFRAMEGEOMETRYPARAMETERS_HH
