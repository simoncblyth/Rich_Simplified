// $Id: $
#ifndef INCLUDE_RICHTBRADIATORGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBRADIATORGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbVesselGeometryParameters RichTbVesselGeometryParameters.hh include/RichTbVesselGeometryParameters.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */

const G4double Box1XSize=600.0 * CLHEP::mm;
const G4double Box1YSize=600.0 * CLHEP::mm;
const G4double Box1ZSize=600.0 * CLHEP::mm;

const G4double Box2XSize=151.7 * CLHEP::mm;
const G4double Box2YSize=70.0 * CLHEP::mm;
const G4double Box2ZSize=500.0 * CLHEP::mm;

//const G4double SphereRadius=138.4 * CLHEP::mm;
//Didier radius
const G4double SphereRadius=144.6 * CLHEP::mm;
//Laser radius
//const G4double SphereRadius=141.3 * CLHEP::mm;
const G4double RadiatorLensThickness = 27.0 * CLHEP::mm;


const G4double Box2XLocation = 0.0;
const G4double Box2YLocation = 0.0;
//const G4double Box2ZLocation = +0.5* Box2ZSize + SphereRadius - 27.0 * CLHEP::mm;
const G4double Box2ZLocation = -0.5* Box2ZSize - SphereRadius + RadiatorLensThickness ;



const G4double BigBoxXLocation = 0.0;
const G4double BigBoxYLocation = 0.0;
const G4double BigBoxZLocation = 0.0;

const G4double RichTbUpgradeRadiatorXLocation = 0.0;
const G4double RichTbUpgradeRadiatorYLocation = 0.0;
const G4double RichTbUpgradeRadiatorZLocation = SphereRadius;

// now for variables used after creating the geometry in stepaction analysis.
// These are not used for geometry construction.
const G4double RichTbUpgradeRadiatorEnvPlateThickness=0.0 * CLHEP::mm;

const G4double RichTbRadiatorLensSizeLateralTolerence=5.0 * CLHEP::mm;
const G4double RichTbRadiatorLensSizeLongitudeTolerence=10.0 * CLHEP::mm;

const G4double  RichTbRadiatorXPosExtreme=  RichTbUpgradeRadiatorXLocation + SphereRadius
                                            +  RichTbRadiatorLensSizeLateralTolerence;
const G4double  RichTbRadiatorXNegExtreme=  RichTbUpgradeRadiatorXLocation - SphereRadius
                                            -  RichTbRadiatorLensSizeLateralTolerence;

const G4double  RichTbRadiatorYPosExtreme=  RichTbUpgradeRadiatorYLocation + SphereRadius
                                            +  RichTbRadiatorLensSizeLateralTolerence;
const G4double  RichTbRadiatorYNegExtreme=  RichTbUpgradeRadiatorYLocation - SphereRadius
                                            -  RichTbRadiatorLensSizeLateralTolerence;
const G4double  RichTbRadiatorZNegExtreme =  RichTbCrystalMasterZLocation -  RichTbRadiatorLensSizeLongitudeTolerence;
const G4double  RichTbRadiatorZPosExtreme =  RichTbCrystalMasterZLocation + RadiatorLensThickness
                                             + RichTbRadiatorLensSizeLongitudeTolerence;

const G4double RichTbRadiatorDnsZLocation = RichTbCrystalMasterZLocation + RadiatorLensThickness;
const G4double RichTbRadiatorDnsZLocationTolerence = 2.0 * CLHEP::mm;

//testbeam 2015 upgrade parameters
const G4double SphereRadius15=155.96 * CLHEP::mm;
const G4double RadiatorLensThickness15 = 24.397 * CLHEP::mm; //centre thickness of the lens

const G4double  RichTbRadiatorXPosExtreme15 =  RichTbUpgradeRadiatorXLocation + SphereRadius15
                                            +  RichTbRadiatorLensSizeLateralTolerence;
const G4double  RichTbRadiatorXNegExtreme15 =  RichTbUpgradeRadiatorXLocation - SphereRadius15
                                            -  RichTbRadiatorLensSizeLateralTolerence;

const G4double  RichTbRadiatorYPosExtreme15 =  RichTbUpgradeRadiatorYLocation + SphereRadius15
                                            +  RichTbRadiatorLensSizeLateralTolerence;
const G4double  RichTbRadiatorYNegExtreme15=  RichTbUpgradeRadiatorYLocation - SphereRadius15
                                            -  RichTbRadiatorLensSizeLateralTolerence;
const G4double  RichTbRadiatorZNegExtreme15 =  RichTbCrystalMasterZLocation -  RichTbRadiatorLensSizeLongitudeTolerence;
const G4double  RichTbRadiatorZPosExtreme15 =  RichTbCrystalMasterZLocation + RadiatorLensThickness15
                                             + RichTbRadiatorLensSizeLongitudeTolerence;

const G4double RichTbRadiatorDnsZLocation15 = RichTbCrystalMasterZLocation + RadiatorLensThickness15;

const G4double Box2XSize15=151.7 * CLHEP::mm;
const G4double Box2YSize15=150.0 * CLHEP::mm;
const G4double Box2ZSize15=500.0 * CLHEP::mm;

const G4double cylRmin = 0.0 * CLHEP::mm;
const G4double cylRmax = 149.845/2 * CLHEP::mm;
const G4double cylDarkRmin = 0.0 * CLHEP::mm;
const G4double cylDarkRmax = 11 * CLHEP::mm;
const G4double cylDarkHalfLength = 1.0 * CLHEP::mm;
const G4double cylHalfLength = 250.0 * CLHEP::mm;
const G4double cylSPhi = 0.0;
const G4double cylDPhi = 2*M_PI;

const G4double Cyl1XLocation = 0.0;
const G4double Cyl1YLocation = 0.0;
//const G4double Box2ZLocation = +0.5* Box2ZSize + SphereRadius - 27.0 * CLHEP::mm;
const G4double Cyl1ZLocation = -cylHalfLength - SphereRadius15 + RadiatorLensThickness15;

const G4double RichTbUpgradeRadiatorXLocation15 = 0.0;
const G4double RichTbUpgradeRadiatorYLocation15 = 0.0;
const G4double RichTbUpgradeRadiatorZLocation15 = SphereRadius15;


#endif
