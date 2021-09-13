// $Id: $
#ifndef INCLUDE_RICHTBMASTERGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBMASTERGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbVesselGeometryParameters RichTbVesselGeometryParameters.hh include/RichTbVesselGeometryParameters.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */

const G4double RichTbMasterXSize=27.0 * CLHEP::mm;
const G4double RichTbMasterYSize=27.0 * CLHEP::mm;
const G4double RichTbMasterZSize=22.0 * CLHEP::mm;

const G4double RichTbMaster1XLocation = -57.0 * CLHEP::mm;
const G4double RichTbMaster1YLocation = +13.5 * CLHEP::mm;
const G4double RichTbMaster1ZLocation = 0.0 * CLHEP::mm;

const G4double RichTbMaster2XLocation = -57.0 * CLHEP::mm;
const G4double RichTbMaster2YLocation = -13.5 * CLHEP::mm;
const G4double RichTbMaster2ZLocation = 0.0 * CLHEP::mm;

const G4double RichTbMaster3XLocation = 57.0 * CLHEP::mm;
const G4double RichTbMaster3YLocation = 13.5 * CLHEP::mm;
const G4double RichTbMaster3ZLocation = 0.0 * CLHEP::mm;

const G4double RichTbMaster4XLocation = 57.0 * CLHEP::mm;
const G4double RichTbMaster4YLocation = -13.5 * CLHEP::mm;
const G4double RichTbMaster4ZLocation = 0.0 * CLHEP::mm;

// now for variables used after creating the geometry in stepaction.

const G4double RichTbMasterEnvPlateThickness=0.0 * CLHEP::mm;
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
