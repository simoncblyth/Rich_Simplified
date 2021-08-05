// $Id: $
#ifndef INCLUDE_RICHTBCRYSTALGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBCRYSTALGEOMETRYPARAMETERS_HH 1

// Include files
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbVesselGeometryParameters RichTbVesselGeometryParameters.hh include/RichTbVesselGeometryParameters.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */

const G4double RichTbCrystalXSize=100.0 * CLHEP::mm;
const G4double RichTbCrystalYSize=100.0 * CLHEP::mm;
const G4double RichTbCrystalZSize=10.0 * CLHEP::mm;

//const G4double RichTbCrystalOriginShiftFromLeftEdgeX=0.0 * CLHEP::mm;  // for now assume middle part. to be verified.
//const G4double RichTbCrystalOriginShiftFromFloorY=0.0 * CLHEP::mm;
//const G4double RichTbCrystalOriginShiftFromLeftZ=0.0 * CLHEP::mm;
//G4double CrystalXRotation = appoConfig ->getSpecialStudyCrystalRotationX();
//const G4double RichTbCrystalXRotation=CrystalXRotation*rad;  
//G4double CrystalYRotation = appoConfig ->getSpecialStudyCrystalRotationY();
//const G4double RichTbCrystalYRotation=CrystalYRotation*rad;
const G4double RichTbCrystalYLocation = 0.0;
//const G4double RichTbCrystalXShiftAlongCrystal = RichTbCrystalOriginShiftFromLeftEdgeX;
//const G4double RichTbCrystalZShiftAlongCrystal = -RichTbCrystalOriginShiftFromLeftZ;

const G4double RichTbCrystalXLocation = 0.0;
const G4double RichTbCrystalZLocation = 0.0 * CLHEP::mm;

// now for variables used after creating the geometry in stepaction.

const G4double RichTbCrystalEnvPlateThickness=0.0 * CLHEP::mm;
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
