#ifndef INCLUDE_RICHTBLARGEMIRRORPARABOLAGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBLARGEMIRRORPARABOLAGEOMETRYPARAMETERS_HH 1

// Include files

#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


const G4double LargeMirrorParabolaThickness= 2.0 * CLHEP::mm;

const G4double LargeMirrorParabLength = 33.0 * CLHEP::mm;
const G4double LargeMirrorParabCenterHoleDiameter=0.0 * CLHEP::mm;
const G4double LargeMirrorParbDnsDiameter=220.0 * CLHEP::mm;


const G4double LargeMirrorParabolaZLocationWrtSmallParabola = 600.0 * CLHEP::mm;

const G4double LargeMirrorParabolaOrientation= M_PI * CLHEP::rad;

const G4double LargeMirrorParabolaYRotation= LargeMirrorParabolaOrientation-0.20 * CLHEP::rad;
const G4double LargeMirrorParabolaXRotation= 0.0 * CLHEP::rad;


const G4double LargeMirrorParabolaZLocation = LargeMirrorParabolaZLocationWrtSmallParabola + MirrorParabBegZ ;
const G4double LargeMirrorParabolaXLocation=  0.0 * CLHEP::mm;
const G4double LargeMirrorParabolaYLocation=  0.0 * CLHEP::mm;


const G4double LargeMirrorParabolaHoleLargeZSize=400 * CLHEP::mm;
const G4double LargeMirrParabCylSPhi = 0.0;
const G4double LargeMirrParabCylDPhi = 2*M_PI;

const G4double LargeMirrParabFocalLength= 100.0 * CLHEP::mm;

const G4double LargeMirrorParabolaOuterLength= LargeMirrorParabLength + LargeMirrorParabolaThickness;
const G4double LargeMirrorParabolaDnsOuterDiameter = LargeMirrorParbDnsDiameter + LargeMirrorParabolaThickness;
const G4double  LargeMirrorParabDnsOuterCenterHoleDiameter  = LargeMirrorParabCenterHoleDiameter;




#endif // INCLUDE_RICHTBLARGEMIRRORPARABOLAGEOMETRYPARAMETERS_HH
