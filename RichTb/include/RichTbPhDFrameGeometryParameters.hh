// $Id: $
#ifndef INCLUDE_RICHTBPHDFRAMEGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBPHDFRAMEGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


/** @class RichTbVesselGeometryParameters RichTbVesselGeometryParameters.hh include/RichTbVesselGeometryParameters.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */

// first for the overall vessel.
const G4double RichTbPhDFrameXSize=600.0 * CLHEP::mm;
const G4double RichTbPhDFrameYSize=600.0 * CLHEP::mm;
const G4double RichTbPhDFrameZSize=30.0 * CLHEP::mm;

const G4double RichTbPhDFrameOriginShiftFromLeftEdgeX=0.0 * CLHEP::mm;  // for now assume middle part. to be verified.
const G4double RichTbPhDFrameOriginShiftFromFloorY=0.0 * CLHEP::mm;
const G4double RichTbPhDFrameOriginShiftFromLeftZ=  30 * CLHEP::mm + 15 * CLHEP::mm + 22.5 * CLHEP::mm;

const G4double RichTbPhDFrameXRotation=0.0 * CLHEP::rad;  // for now in the following vessel Xrot is not used in Euler rotations since it is 0.
//const G4double RichTbVesselYRotation=0.4817 * CLHEP::rad;
const G4double RichTbPhDFrameYRotation=0.0;
const G4double RichTbPhDFrameYLocation = -RichTbPhDFrameOriginShiftFromFloorY;
const G4double RichTbPhDFrameXShiftAlongCrystal =0.0;
const G4double RichTbPhDFrameZShiftAlongCrystal = +RichTbPhDFrameOriginShiftFromLeftZ;

const G4double RichTbPhDFrameXLocation = RichTbPhDFrameXShiftAlongCrystal;
const G4double RichTbPhDFrameZLocation = RichTbPhDFrameZShiftAlongCrystal;

// now for variables used after creating the geometry in stepaction.

const G4double RichTbPhDFrameEnvPlateThickness=0.0 * CLHEP::mm;
// the following are not exact values.
//const G4double  RichTbCrystalXNegExtremeAlongCrystal=RichTbCrystalOriginShiftFromLeftEdgeX-RichTbCrystalXSize;
//const G4double  RichTbCrystalXPosExtremeAlongCrystal=RichTbCrystalOriginShiftFromLeftEdgeX;
//const G4double  RichTbCrystalZUpsExtremeAlongCrystal= -RichTbCrystalUpsExternalPartZSize;
//const G4double  RichTbCrystalZDnsExtremeAlongCrystal= -RichTbcrystalUpsExternalPartZSize+RichTbCrystalZSize;
//const G4double  RichTbCrystalXNegExtreme=  RichTbCrystalXNegExtremeAlongCrystal*cos(RichTbCrystalYRotation)+
//                                          RichTbCrystalZDnsExtremeAlongCrystal*sin(RichTbCrystalYRotation);
//const G4double  RichTbCrystalXPosExtreme=  RichTbCrystalXPosExtremeAlongCrystal*cos(RichTbCrystalYRotation)+
//                                          RichTbCrystalZUpsExtremeAlongCrystal*sin(RichTbCrystalYRotation);

//const G4double  RichTbCrystalYNegExtreme= RichTbCrystalYLocation-0.5*RichTbCrystalYSize;
//const G4double  RichTbCrystalYPosExtreme= RichTbCrystalYLocation+0.5*RichTbCrystalYSize;
//const G4double  RichTbCrystalZDnsExtreme = -RichTbCrystalXNegExtremeAlongCrystal*sin(RichTbCrystalYRotation)+
//                                        RichTbCrystalZDnsExtremeAlongCrystal*cos(RichTbCrystalYRotation);
//const G4double  RichTbCrystalDnsZEnd = RichTbCrystalZDnsExtreme;
#endif
