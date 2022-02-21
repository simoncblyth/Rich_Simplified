#ifndef INCLUDE_RICHTBR1FLATMIRRORGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBR1FLATMIRRORGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbR1FlatMirrorGeometryParameters RichTbR1FlatMirrorGeometryParameters.hh include/RichTbR1FlatMirrorGeometryParameters.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2021-07-22
 */
//Parameters for simplified rich1 flat mirror.
const G4double RichTbR1FlatMirrInnerRadius = 5000.0 *  CLHEP::m;
const G4double RichTbR1FlatMirrThickness   = 6.0 * CLHEP::mm;
const G4double RichTbR1FlatMirrOuterRadius =  RichTbR1FlatMirrInnerRadius + RichTbR1FlatMirrThickness ;
const G4double RichTbR1FlatMirrSegmentSizeX = 1480.0 * CLHEP::mm;
const G4double RichTbR1FlatMirrSegmentSizeY = 880.0 * CLHEP::mm;
//const G4double RichTbR1FlatMirrSegmentSizeX = 1.0 * CLHEP::mm;
//const G4double RichTbR1FlatMirrSegmentSizeY = 1.0 * CLHEP::mm;
const G4double RichTbR1FlatMirrBotInLHCbPosY  = 337.90 * CLHEP::mm;
const G4double RichTbR1FlatMirrBotInLHCbPosZ  = 1323.31 * CLHEP::mm;
const G4double RichTbR1FlatMirrVertTilt = 0.25656 * CLHEP:: rad; 
const G4double RichTbR1FlatMirrRotX = -1.0 * RichTbR1FlatMirrVertTilt;
const G4double RichTbR1FlatMirrRotY = (0.5 * CLHEP::pi * CLHEP::rad);

const G4double RichTbR1FlatMirrDeltaTheta = asin(RichTbR1FlatMirrSegmentSizeX/RichTbR1FlatMirrInnerRadius) * CLHEP::rad;
const G4double RichTbR1FlatMirrDeltaPhi = asin(RichTbR1FlatMirrSegmentSizeY/RichTbR1FlatMirrInnerRadius) * CLHEP::rad;
const G4double RichTbR1FlatMirrStartTheta = (0.5 * CLHEP::pi * CLHEP::rad)  - (0.5*  RichTbR1FlatMirrDeltaTheta);
const G4double RichTbR1FlatMirrStartPhi = -0.5 * RichTbR1FlatMirrDeltaPhi;
const G4double RichTbR1FlatMirrInLHCbPosX = 0.0* CLHEP::mm;
const G4double RichTbR1FlatMirrInLHCbPosY = RichTbR1FlatMirrBotInLHCbPosY + 
                                             0.5 * RichTbR1FlatMirrSegmentSizeY * cos (RichTbR1FlatMirrVertTilt) +
                                             RichTbR1FlatMirrOuterRadius * sin ( RichTbR1FlatMirrVertTilt );

const G4double RichTbR1FlatMirrInLHCbPosZ = RichTbR1FlatMirrBotInLHCbPosZ - 
                                             0.5 *  RichTbR1FlatMirrSegmentSizeY * sin ( RichTbR1FlatMirrVertTilt) +
                                             RichTbR1FlatMirrOuterRadius * cos ( RichTbR1FlatMirrVertTilt );

const G4double RichTbR1FlatMirrPosX = RichTbR1FlatMirrInLHCbPosX - RichTbR1SubMasterPosX -  RichTbR1MasterPosX ;
const G4double RichTbR1FlatMirrPosY = RichTbR1FlatMirrInLHCbPosY - RichTbR1SubMasterPosY -  RichTbR1MasterPosY ;
const G4double RichTbR1FlatMirrPosZ = RichTbR1FlatMirrInLHCbPosZ - RichTbR1SubMasterPosZ -  RichTbR1MasterPosZ ;


#endif // INCLUDE_RICHTBR1FLATMIRRORGEOMETRYPARAMETERS_HH
