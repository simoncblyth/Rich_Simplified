// $Id: $
#ifndef INCLUDE_RICHTBCRYSTALCOVERGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBCRYSTALCOVERGEOMETRYPARAMETERS_HH 1

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
const G4double RichTbCrystalCoverXSize=100.0 * CLHEP::mm + 6.0 * CLHEP::mm;
const G4double RichTbCrystalCoverYSize=100.0 * CLHEP::mm + 6.0 * CLHEP::mm;
const G4double RichTbCrystalCoverZSize=7.6 * CLHEP::mm + 3.0 * CLHEP::mm;

const G4double RichTbCrystalCoverOriginShiftFromLeftEdgeX=0.0 * CLHEP::mm;  
const G4double RichTbCrystalCoverOriginShiftFromFloorY=0.0 * CLHEP::mm;
const G4double RichTbCrystalCoverOriginShiftFromLeftZ=0.0 * CLHEP::mm;

const G4double RichTbCrystalCoverSubPartXSize=100.0 * CLHEP::mm;
const G4double RichTbCrystalCoverSubPartYSize=100.0 * CLHEP::mm;
const G4double RichTbCrystalCoverSubPartZSize=100.0 * CLHEP::mm;

const G4double RichTbCrystalCoverYLocation = - RichTbCrystalCoverOriginShiftFromFloorY;
const G4double RichTbCrystalCoverXShiftAlongCrystal = RichTbCrystalCoverOriginShiftFromLeftEdgeX;
const G4double RichTbCrystalCoverZShiftAlongCrystal = -RichTbCrystalCoverOriginShiftFromLeftZ;

const G4double RichTbCrystalCoverXLocation = RichTbCrystalCoverXShiftAlongCrystal;
const G4double RichTbCrystalCoverZLocation = -1.5 * CLHEP::mm;

const G4double RichTbCrystalCoverSubPartXLocation = 0.0 * CLHEP::mm;
const G4double RichTbCrystalCoverSubPartYLocation = 0.0 * CLHEP::mm;
const G4double RichTbCrystalCoverSubPartZLocation =0.5 * (RichTbCrystalCoverSubPartZSize - RichTbCrystalCoverZSize) + 2.5 * CLHEP::mm;

// now for variables used after creating the geometry in stepaction.

const G4double RichTbCrystalCoverEnvPlateThickness=0.0 * CLHEP::mm;
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
