// $Id: $
#ifndef INCLUDE_RICHTBVESSELGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBVESSELGEOMETRYPARAMETERS_HH 1

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
const G4double RichTbVesselXSize=1000.0 * CLHEP::mm;
const G4double RichTbVesselYSize=600.0  * CLHEP::mm;
const G4double RichTbVesselZSize=2000.0 * CLHEP::mm;

// now for the boolean subtraction.
/*
const G4double RichTbVesselUpsExternalPartXSize=500.0 * CLHEP::mm;  // for now assume it to be half way point. to be verified.
const G4double RichTbVesselUpsExternalPartZSize=1000.0 * CLHEP::mm;
const G4double RichTbVesselUpsExternalPartYLargeSize=20000.0 * CLHEP::mm;
const G4double RichTbVesselUpsExternalPartZLargeSize=20000.0 * CLHEP::mm;

const G4double RichTbVesselUpsExternalPartXShift=0.5*(RichTbVesselXSize-RichTbVesselUpsExternalPartXSize);
const G4double RichTbVesselUpsExternalPartYShift=0.0 * CLHEP::mm;
const G4double RichTbVesselUpsExternalPartZShift=-0.5*RichTbVesselZSize+
               RichTbVesselUpsExternalPartZSize-0.5*RichTbVesselUpsExternalPartZLargeSize;
*/
// now for the location and rotation of the vessel

//const G4double RichTbVesselOriginShiftFromLeftEdgeX=250.0 * CLHEP::mm;  // for now assume middle part. to be verified.
//const G4double RichTbVesselOriginShiftFromFloorY=1300.0 * CLHEP::mm;
const G4double RichTbVesselXRotation=0.0 * CLHEP::rad;  // for now in the following vessel Xrot is not used in Euler rotations since it is 0.
//const G4double RichTbVesselYRotation=0.4817*rad;
const G4double RichTbVesselYRotation=0.0 * CLHEP::rad;
const G4double RichTbVesselYLocation = 0;
//const G4double RichTbVesselXShiftAlongVessel = RichTbVesselOriginShiftFromLeftEdgeX - 0.5 * RichTbVesselXSize;
//const G4double RichTbVesselZShiftAlongVessel = -RichTbVesselUpsExternalPartZSize + 0.5 * RichTbVesselZSize;
// X and Y location shifts in the global frame using Euler rotation wrt the Y axis.
//const G4double RichTbVesselXLocation= RichTbVesselXShiftAlongVessel*cos(RichTbVesselYRotation)+ 
//                                      RichTbVesselZShiftAlongVessel*sin(RichTbVesselYRotation);
//const G4double RichTbVesselZLocation=-RichTbVesselXShiftAlongVessel*sin(RichTbVesselYRotation)+ 
//                                      RichTbVesselZShiftAlongVessel*cos(RichTbVesselYRotation);
const G4double RichTbVesselXLocation = 0;
const G4double RichTbVesselZLocation = 0;

// now for variables used after creating the geometry in stepaction.

const G4double RichTbVesselEnvPlateThickness=0.0 * CLHEP::mm;
// the following are not exact values.

const G4double  RichTbVesselXNegExtremeAlongVessel=- 0.5 * RichTbVesselXSize;
const G4double  RichTbVesselXPosExtremeAlongVessel= +0.5 * RichTbVesselXSize;
const G4double  RichTbVesselZUpsExtremeAlongVessel= - 0.5 * RichTbVesselZSize;
const G4double  RichTbVesselZDnsExtremeAlongVessel= +0.5 * RichTbVesselZSize;
const G4double  RichTbVesselXNegExtreme=  RichTbVesselXNegExtremeAlongVessel*cos(RichTbVesselYRotation)+
                                          RichTbVesselZDnsExtremeAlongVessel*sin(RichTbVesselYRotation);
const G4double  RichTbVesselXPosExtreme=  RichTbVesselXPosExtremeAlongVessel*cos(RichTbVesselYRotation)+
                                          RichTbVesselZUpsExtremeAlongVessel*sin(RichTbVesselYRotation);

const G4double  RichTbVesselYNegExtreme= RichTbVesselYLocation-0.5*RichTbVesselYSize;
const G4double  RichTbVesselYPosExtreme= RichTbVesselYLocation+0.5*RichTbVesselYSize;
const G4double  RichTbVesselZDnsExtreme = -RichTbVesselXNegExtremeAlongVessel*sin(RichTbVesselYRotation)+
                                        RichTbVesselZDnsExtremeAlongVessel*cos(RichTbVesselYRotation);
const G4double  RichTbVesselDnsZEnd = RichTbVesselZDnsExtreme;

#endif // INCLUDE_RICHTBVESSELGEOMETRYPARAMETERS_HH
