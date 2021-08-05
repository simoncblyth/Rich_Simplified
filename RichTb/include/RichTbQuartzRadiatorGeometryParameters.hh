#ifndef INCLUDE_RICHTBQUARTZRADIATORGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBQUARTZRADIATORGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


const G4double QuartzRadiatorRadius=412.09 * CLHEP::mm;

const G4double QuartzRadiatorZSize=8.0 * CLHEP::mm;
const G4double QuartzRadiatorInnerRadius=0.0 * CLHEP::mm;

const G4double QuartzRadiatorZStartPhi=0.0 * CLHEP::rad;
const G4double QuartzRadiatorZDeltaPhi=2*M_PI;
const G4double QuartzRadiatorZStartTheta=0.0 * CLHEP::rad;
const G4double QuartzRadiatorZDeltaTheta=M_PI;

const G4double QuartzRadiatorXLocation = 0.0 * CLHEP::mm;
const G4double QuartzRadiatorYLocation = 0.0 * CLHEP::mm;
const G4double QuartzRadiatorSubZShift = 2.0*QuartzRadiatorRadius - QuartzRadiatorZSize;


const G4double QuartzRadiatorZSphShift = -1.0*(QuartzRadiatorRadius-0.5*QuartzRadiatorZSize);
//const G4double QuartzRadiatorSystemExtraShift = 5.0 * CLHEP::mm;
//const G4double QuartzRadiatorSystemExtraShift = 2.0 * CLHEP::mm;
//const G4double QuartzRadiatorSystemExtraShift = 3.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = 2.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -1.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -0.7 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -0.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -0.4 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -0.7 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -7.5 * CLHEP::mm;
//const G4double QuartzRadiatorSystemExtraShift = -5.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -1.0 * CLHEP::mm;
//const G4double QuartzRadiatorSystemExtraShift = 0.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = 1.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = 0.0 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -1.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -3.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -4.0 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -4.5 * CLHEP::mm;
//const G4double QuartzRadiatorSystemExtraShift = -5.0 * CLHEP::mm;
//const G4double QuartzRadiatorSystemExtraShift = -4.7 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -4.85 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -4.8 * CLHEP::mm;


//   //const G4double QuartzRadiatorSystemExtraShift = -4.85 * CLHEP::mm;

const G4double QuartzRadiatorSystemExtraShift = -2.9 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -3.5 * CLHEP::mm;

//const G4double QuartzRadiatorSystemExtraShift = -4.0 * CLHEP::mm;


const G4double QuartzRadiatorZExtraShift =QuartzRadiatorZSphShift + QuartzRadiatorSystemExtraShift ;


//const G4double QuartzRadiatorZExtraShift = -10.0 * CLHEP::mm;
const G4double QuartzRadiatorZLocation =  MirrorParabBegZ + MirrorParabFocalShift+QuartzRadiatorZExtraShift ;

const G4double QuartzRadiatorXRotation=0.0 * CLHEP::rad;
const G4double QuartzRadiatorYRotation=0.0 * CLHEP::rad;

const G4double QuartzBlackCoverZSize=0.5 * CLHEP::mm;
const G4double QuartzBlackCoverTolerence=0.0 * CLHEP::mm;
//const G4double QuartzBlackCoverTolerence=0.1 * CLHEP::mm;
const G4double QuartzDnsBlackCoverRadius= 19.0 * CLHEP::mm;
const G4double QuartzUpsBlackCoverRadius= 10.0 * CLHEP::mm;
const G4double  QuartzBlackCoverLocalZShift= 0.5*(QuartzRadiatorZSize+QuartzBlackCoverZSize);

const G4double QuartzBlackCoverDnsZPos= MirrorParabBegZ + MirrorParabFocalShift+ 
                          QuartzRadiatorSystemExtraShift+  QuartzBlackCoverLocalZShift;
const G4double QuartzBlackCoverUpsZPos= MirrorParabBegZ + MirrorParabFocalShift+ 
                          QuartzRadiatorSystemExtraShift    - QuartzBlackCoverLocalZShift;






#endif // INCLUDE_RICHTBQUARTZRADIATORGEOMETRYPARAMETERS_HH
