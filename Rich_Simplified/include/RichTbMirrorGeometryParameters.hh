// $Id: $
#ifndef INCLUDE_RICHTBMIRRORGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBMIRRORGEOMETRYPARAMETERS_HH

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


//const G4double MirrorGap = 1.0* CLHEP::mm;
const G4double MirrorGap = 0.0* CLHEP::mm;

const G4double MirrorInnerRadius  = SphereRadius+MirrorGap;

const G4double MirrorThickness = 5.0 * CLHEP::mm;

const G4double MirrorOuterRadius  = MirrorInnerRadius+ MirrorThickness;

const G4double MirrorSubBoxLargeXSize=500 * CLHEP::mm;
const G4double MirrorSubBoxLargeYSize=500 * CLHEP::mm;
const G4double MirrorSubBoxLargeZSize=500 * CLHEP::mm;
const G4double MirrorSubBoxShiftY=  0.5*Box2YSize;

const G4double MirrorSubBoxYPosTop = 0.5*MirrorSubBoxLargeYSize+ MirrorSubBoxShiftY;
const G4double MirrorSubBoxYPosBot = -0.5*MirrorSubBoxLargeYSize - MirrorSubBoxShiftY;


//const G4double MirrorMinExtent=40.0 * CLHEP::mm;
//const G4double MirrorMaxExtent=60.0 * CLHEP::mm;

const G4double MirrorMinExtent=39.5 * CLHEP::mm;
const G4double MirrorMaxExtent=58.2 * CLHEP::mm;

const G4double MirrorMinThetaExtent = MirrorMinExtent/MirrorInnerRadius;
const G4double MirrorMaxThetaExtent = MirrorMaxExtent/MirrorInnerRadius;


const G4double  MirrorPosX =0.0;
const G4double  MirrorPosZ = SphereRadius;
const G4double  MirrorPosY =0.0;

//testbeam upgrade 2015
const G4double MirrorGap15 = 0.0* CLHEP::mm;
const G4double MirrorInnerRadius15 = SphereRadius15 + MirrorGap15;
const G4double MirrorThickness15 = 5.0 * CLHEP::mm;
const G4double MirrorOuterRadius15  = MirrorInnerRadius15+ MirrorThickness15;

const G4double MirrorMinExtent15=33.0 * CLHEP::mm;
const G4double MirrorMaxExtent15=55.0 * CLHEP::mm;
//const G4double MirrorMinThetaExtent15 = MirrorMinExtent/MirrorInnerRadius15;
//const G4double MirrorMaxThetaExtent15 = MirrorMaxExtent/MirrorInnerRadius15;
const G4double MirrorMinThetaExtent15 = MirrorMinExtent15/MirrorInnerRadius15;
const G4double MirrorMaxThetaExtent15 = MirrorMaxExtent15/MirrorInnerRadius15;

const G4double  MirrorPosX15 =0.0;
const G4double  MirrorPosY15 =0.0;
const G4double  MirrorPosZ15 = SphereRadius15;
const G4double  MirrorVolPosZ15 = 0.0;




#endif // INCLUDE_RICHTBMIRRORGEOMETRYPARAMTERS_HH
