// $Id: $
#ifndef INCLUDE_RICHTBHALLGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBHALLGEOMETRYPARAMETERS_HH 1

// Include files

#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbHallGeometryParameters RichTbHallGeometryParameters.hh include/RichTbHallGeometryParameters.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */
//Size of the LHCb Rich Testbeam Hall. 

const G4double ExpHallHalfX = 5000.0 * CLHEP::mm;
const G4double ExpHallHalfY = 5000.0 * CLHEP::mm;
const G4double ExpHallHalfZ = 10000.0 * CLHEP::mm;

// The Hall is kept at the orgin of the coord system.
// The coord system has +z along the beam direction and +y
// going upwards.
// The uptream end of the box part of the vessel 
// is at z=0. The origin is approximately where the 
// beam enters the vessel.

#endif // INCLUDE_RICHTBHALLGEOMETRYPARAMETERS_HH
