#ifndef INCLUDE_RICHTBR1MAGSHREGIONGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBR1MAGSHREGIONGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbR1MagShRegionGeometryParameters RichTbR1MagShRegionGeometryParameters.hh include/RichTbR1MagShRegionGeometryParameters.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2021-07-22
 */
//Parameters for simplified rich1 magsh region.
const G4double RichTbR1MagShRegHalfSizeX = 900.0 * CLHEP::mm;
const G4double RichTbR1MagShRegMaxYLim = 2050.0 * CLHEP::mm;
const G4double RichTbR1MagShRegMinYLim = 880.0 *  CLHEP::mm;
const G4double RichTbR1MagShRegHalfSizeY = 0.5* (RichTbR1MagShRegMaxYLim - RichTbR1MagShRegMinYLim);
const G4double RichTbR1MagShRegHalfSizeZ = 600.0 * CLHEP::mm;

const G4double RichTbR1MagShYDistFromFlatMirror = 650.0 *  CLHEP::mm;
const G4double RichTbR1MagShZDistFromFlatMirror = 400.0 *  CLHEP::mm;
const G4double RichTbR1MagShRegGapZ = 20 *  CLHEP::mm;

const G4double RichTbR1MagShRegPosX = (0.0 * CLHEP::mm) - RichTbR1SubMasterPosX -  RichTbR1MasterPosX ;
const G4double RichTbR1MagShRegPosY = 0.5 * (RichTbR1MagShRegMaxYLim + RichTbR1MagShRegMinYLim) 
                                      -  RichTbR1SubMasterPosY -  RichTbR1MasterPosY ;
const G4double RichTbR1MagShRegPosZ = - RichTbR1SubMasterHalfSizeZ + RichTbR1MagShRegHalfSizeZ + RichTbR1MagShRegGapZ ;

const G4double RichTbR1MagShRegSubBoxLargeHalfSize=3000.0 * CLHEP::mm;
const G4double RichTbR1MagShRegSubBoxLargeHalfSizeX = RichTbR1MagShRegSubBoxLargeHalfSize;
const G4double RichTbR1MagShRegSubBoxLargeHalfSizeY = RichTbR1MagShRegSubBoxLargeHalfSize;
const G4double RichTbR1MagShRegSubBoxLargeHalfSizeZ = RichTbR1MagShRegSubBoxLargeHalfSize;

//The following defined in RichTbLHCbR1PhDetSupFraneGeometryParameters.hh
//const G4double RichTbR1MagShRegSubBoxRotX = RichTbR1DetPlaneRotX ;
const G4double RichTbR1MagShRegSubBoxPosX = 0.0 * CLHEP::mm;
const G4double RichTbR1MagShRegSubBoxPosY = -1.0* RichTbR1MagShRegSubBoxLargeHalfSizeY + RichTbR1MagShYDistFromFlatMirror  ;
const G4double RichTbR1MagShRegSubBoxPosZ = -1.0* RichTbR1MagShRegSubBoxLargeHalfSizeZ + RichTbR1MagShZDistFromFlatMirror ;


#endif // INCLUDE_RICHTBR1MAGSHREGIONGEOMETRYPARAMETERS_HH
