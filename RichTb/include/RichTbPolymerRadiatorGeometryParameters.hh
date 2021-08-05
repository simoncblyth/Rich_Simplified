#ifndef INCLUDE_RICHTBPOLYMERRADIATORGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBPOLYMERRADIATORGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


/** @class RichTbPolymerRadiatorGeometryParameters RichTbPolymerRadiatorGeometryParameters.hh include/RichTbPolymerRadiatorGeometryParameters.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-15
 */

//const G4double PolymerPlusRadiatorXSize =  10.0 * CLHEP::mm;
//const G4double PolymerPlusRadiatorYSize =  10.0 * CLHEP::mm;
const G4double PolymerPlusRadiatorXSize =  20.0 * CLHEP::mm;
const G4double PolymerPlusRadiatorYSize =  20.0 * CLHEP::mm;
const G4double PolymerPlusRadiatorZSize =  0.2 * CLHEP::mm;

const G4double PolymerPlusRadiatorXLocation = 0.0 * CLHEP::mm;
const G4double PolymerPlusRadiatorYLocation = 0.0 * CLHEP::mm;

//const G4double PolymerPlusRadiatorZShift = 100.0 * CLHEP::mm;
//const G4double PolymerPlusRadiatorZLocation = -0.5*RichTbContainerVesselBoxZSize + PolymerPlusRadiatorZShift;

const G4double PolymerPlusRadiatorZLocation = MirrorParabBegZ + MirrorParabFocalShift ;

const G4double PolymerPlusRadiatorXRotation = 0.0 * CLHEP::rad;
const G4double PolymerPlusRadiatorYRotation = 0.0 * CLHEP::rad;






#endif // INCLUDE_RICHTBPOLYMERRADIATORGEOMETRYPARAMETERS_HH
