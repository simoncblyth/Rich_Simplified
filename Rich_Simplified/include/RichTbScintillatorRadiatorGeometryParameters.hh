#ifndef INCLUDE_RICHTBSCINTILLATORRADIATORGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBSCINTILLATORRADIATORGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


/** @class RichTbScintillatorRadiatorGeometryParameters RichTbScintillatorRadiatorGeometryParameters.hh include/RichTbScintillatorRadiatorGeometryParameters.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-07-31
 */



const G4double  ScintillatorRadiatorRadius=21.0 * CLHEP::mm;

const G4double  ScintillatorRadiatorThickness= 2.0 * CLHEP::mm;


const G4double  ScintillatorRadiatorDnsCoverRadius=18.0 * CLHEP::mm;
const G4double  ScintillatorRadiatorUpsCoverRadius=18.0 * CLHEP::mm;

const G4double  ScintillatorRadiatorCoverThickness=1.0 * CLHEP::mm;
const G4double  ScintillatorRadiatorGap=0.15 * CLHEP::mm;




//const G4double  ScintillatorRadiatorMasterThickness= 
//    ScintillatorRadiatorThickness+2.0* (ScintillatorRadiatorThickness+ScintillatorRadiatorGap);
const G4double  ScintillatorRadiatorMasterThickness= ScintillatorRadiatorThickness;


const G4double  ScintillatorRadiatorSPhi= 0.0 * CLHEP::rad;

const G4double  ScintillatorRadiatorDPhi= 2*M_PI * CLHEP::rad;


const G4double ScintRadiatorSystemExtraShift = 6.0 * CLHEP::mm;



const G4double ScintRadiatorZLocation = MirrorParabBegZ + MirrorParabFocalShift+ScintRadiatorSystemExtraShift;

const G4double  ScintillatorRadiatorShift =  0.5*(ScintillatorRadiatorThickness+ScintillatorRadiatorThickness)+
                                                  ScintillatorRadiatorGap;


const G4double  ScintillatorRadiatorDnsCoverZPos= ScintRadiatorZLocation + ScintillatorRadiatorShift;

const G4double  ScintillatorRadiatorUpsCoverZPos= ScintRadiatorZLocation - ScintillatorRadiatorShift;


const G4double ScintRadiatorXPos=0.0 * CLHEP::mm;
const G4double ScintRadiatorYPos=0.0 * CLHEP::mm;

const G4double ScintRadiatorCoverXPos=0.0 * CLHEP::mm;
const G4double ScintRadiatorCoverYPos=0.0 * CLHEP::mm;


const G4double ScintRadiatorXRotation= 0.0 * CLHEP::rad;
const G4double ScintRadiatorYRotation= 0.0 * CLHEP::rad;

const G4double ScintRadiatorCoverXRotation= 0.0 * CLHEP::rad;
const G4double ScintRadiatorCoverYRotation= 0.0 * CLHEP::rad;


#endif // INCLUDE_RICHTBSCINTILLATORRADIATORGEOMETRYPARAMETERS_HH
