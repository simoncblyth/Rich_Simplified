// $Id: $
#ifndef INCLUDE_RICHTBLENSGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBLENSGEOMETRYPARAMETERS_HH 1

// Include files

#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbVesselGeometryParameters RichTbVesselGeometryParameters.hh include/RichTbVesselGeometryParameters.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */

const G4double SphRadius1=402.0 * CLHEP::mm;
const G4double SphRadius2=400.0 * CLHEP::mm;
const G4double LensThickness = 10.0 * CLHEP::mm;

const G4double CBoxXSize = 500.0 * CLHEP::mm;
const G4double CBoxYSize = 500.0 * CLHEP::mm;
const G4double CBoxZSize = 500.0 * CLHEP::mm;

const G4double DistanceSph= SphRadius1 + SphRadius2 - LensThickness; 

const G4double RichTbLensXLocation =0 * CLHEP::mm;

const G4double RichTbLensYLocation = 0 * CLHEP::mm;
const G4double RichTbLensZLocation = 500 * CLHEP::mm - 2*SphRadius2;

// now for variables used after creaxting the geometry in stepaction.

const G4double RichTbLensEnvPlateThickness=0.0 * CLHEP::mm;

#endif
