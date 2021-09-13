#ifndef INCLUDE_RICHTBR1SPHMIRRORGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBR1SPHMIRRORGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbR1SphMirrorGeometryParameters RichTbR1SphMirrorGeometryParameters.hh include/RichTbR1SphMirrorGeometryParameters.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2021-07-22
 */
//Parameters for simplified rich1 sph mirror.
const G4double RichTbR1SphMirrInnerRadius = 3650.0 *  CLHEP::mm;
const G4double RichTbR1SphMirrThickness   = 1.5 * CLHEP::mm;
const G4double RichTbR1SphMirrOuterRadius =  RichTbR1SphMirrInnerRadius + RichTbR1SphMirrThickness ;
const G4double RichTbR1SphMirrSegmentSizeX = 1500.0 * CLHEP::mm;
const G4double RichTbR1SphMirrSegmentSizeY = 650.0  * CLHEP::mm;
const G4double RichTbR1SphMirrCOCInLHCbPosX =  0.0       * CLHEP::mm;
const G4double RichTbR1SphMirrCOCInLHCbPosY =  932.897   * CLHEP::mm;
const G4double RichTbR1SphMirrCOCInLHCbPosZ =  -1493.286 * CLHEP::mm;
const G4double RichTbR1SphMirrVertTilt = 
             asin ( RichTbR1SphMirrCOCInLHCbPosY/RichTbR1SphMirrInnerRadius) * CLHEP::rad;

// To account for spherical geometry with straight edges, the angluar sizes are increased by a factor and then boolen subtraction made. 
const G4double RichTbR1SphMirrDeltaExtendedFactor = 1.2; 
const G4double RichTbR1SphMirrDeltaTheta =  2 * asin(RichTbR1SphMirrSegmentSizeX/(2.0*RichTbR1SphMirrInnerRadius)) * RichTbR1SphMirrDeltaExtendedFactor *  CLHEP::rad;
const G4double RichTbR1SphMirrDeltaPhi =  2 * asin(RichTbR1SphMirrSegmentSizeY/(2.0*RichTbR1SphMirrInnerRadius) )* RichTbR1SphMirrDeltaExtendedFactor * CLHEP::rad;
const G4double RichTbR1SphMirrThetaStart = (0.5 * CLHEP::pi * CLHEP::rad)  - (0.5 * RichTbR1SphMirrDeltaTheta) ;
const G4double RichTbR1SphMirrPhiStart   =  -0.5 * RichTbR1SphMirrDeltaPhi ;
const G4double RichTbR1SphMirrSubLargeSize = 5000 *  CLHEP::mm;
const G4double RichTbR1SphMirrSubHalfSizeX = RichTbR1SphMirrSubLargeSize;
const G4double RichTbR1SphMirrSubHalfSizeY = RichTbR1SphMirrSubLargeSize;
const G4double RichTbR1SphMirrSubHalfSizeZ = RichTbR1SphMirrSubLargeSize;
const G4double RichTbR1SphMirrSubPosX = 0.0 *  CLHEP::mm;
const G4double RichTbR1SphMirrSubPosY = 0.0 *  CLHEP::mm;
const G4double RichTbR1SphMirrSubUpPosY = (0.5 * RichTbR1SphMirrSegmentSizeY) + RichTbR1SphMirrSubHalfSizeY;
const G4double RichTbR1SphMirrSubDownPosY = -1.0 * RichTbR1SphMirrSubUpPosY ;
const G4double RichTbR1SphMirrSubPosZ = 0.0 * CLHEP::mm;
const G4double RichTbR1SphMirrSubRightPosZ =(0.5 * RichTbR1SphMirrSegmentSizeX) +  RichTbR1SphMirrSubHalfSizeZ;
const G4double RichTbR1SphMirrSubLeftPosZ = -1.0* RichTbR1SphMirrSubRightPosZ;
const G4double RichTbR1SphMirrYShiftFromEdge = 1.0 * CLHEP::mm;
const G4double RichTbR1SphMirrPhiGapShift =  asin (RichTbR1SphMirrYShiftFromEdge/RichTbR1SphMirrInnerRadius) * CLHEP::rad;
const G4double RichTbR1SphMirrRotY = -0.5 * CLHEP::pi * CLHEP::rad;
const G4double RichTbR1SphMirrRotZ =  RichTbR1SphMirrPhiGapShift + (0.5 * RichTbR1SphMirrDeltaPhi) -  RichTbR1SphMirrVertTilt ;
const G4double RichTbR1SphMirrPosX = RichTbR1SphMirrCOCInLHCbPosX - RichTbR1SubMasterPosX -  RichTbR1MasterPosX ;
const G4double RichTbR1SphMirrPosY = RichTbR1SphMirrCOCInLHCbPosY - RichTbR1SubMasterPosY -  RichTbR1MasterPosY ;
const G4double RichTbR1SphMirrPosZ = RichTbR1SphMirrCOCInLHCbPosZ - RichTbR1SubMasterPosZ -  RichTbR1MasterPosZ ;



#endif // INCLUDE_RICHTBR1SPHMIRRORGEOMETRYPARAMETERS_HH
