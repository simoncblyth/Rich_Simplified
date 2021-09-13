// $Id: $
#ifndef INCLUDE_RICHTBLHCBEXPTHALLGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBLHCBEXPTHALLGEOMETRYPARAMETERS_HH 1

// Include files

#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbLHCbExptHallGeometryParameters RichTbLHCbExptHallGeometryParameters.hh include/RichTbLHCbExptHallGeometryParameters.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2021-07-22
 */
//Size of the LHCb Expt Hall. 

const G4double RichTbLHCbExpHallHalfX = 5000.0 * CLHEP::mm;
const G4double RichTbLHCbExpHallHalfY = 5000.0 * CLHEP::mm;
const G4double RichTbLHCbExpHallHalfZ = 15000.0 * CLHEP::mm;

// The Hall is kept at the orgin of the coord system.
// The coord system has +z along the beam direction and +y
// going upwards.
// The uptream end of the box part of the vessel 
// is at z=0. The origin is approximately where the 
// beam enters the vessel.

#endif // INCLUDE_RICHTBLHCBEXPTHALLGEOMETRYPARAMETERS_HH
