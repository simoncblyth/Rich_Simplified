#ifndef INCLUDE_RICHTBMIRRORPARAGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBMIRRORPARAGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbMirrorParaGeometryParameters RichTbMirrorParaGeometryParameters.hh include/RichTbMirrorParaGeometryParameters.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-16
 */
const G4double MirrorParabThickness=2.0 * CLHEP::mm;

//const  G4double MirrorParabLength = 2.699 * 2.54  * CLHEP::mm;
//const  G4double MirrorParabCenterHoleDiameter = 2.5*2.54  * CLHEP::mm;
//const G4double MirrorParbDnsDiameter= 4.85 * 2.54  * CLHEP::mm;


//const G4double MirrorParabLength = 47.0 * CLHEP::mm;
//const G4double MirrorParabCenterHoleDiameter=35.0 * CLHEP::mm;
//const G4double MirrorParbDnsDiameter=152.0 * CLHEP::mm;
//const G4double MirrorParabLength = 32.0 * CLHEP::mm;
//const G4double MirrorParabCenterHoleDiameter=30.0 * CLHEP::mm;
//const G4double MirrorParbDnsDiameter=100.0 * CLHEP::mm;


const G4double MirrorParabLength = 79.0 * CLHEP::mm;
const G4double MirrorParabCenterHoleDiameter=30.0 * CLHEP::mm;
const G4double MirrorParbDnsDiameter=152.0 * CLHEP::mm;


//const G4double MirrorParabolaGeneralZShift = 100.0  * CLHEP::mm;

const G4double MirrorParabolaGeneralZShift = 200.0  * CLHEP::mm;

const G4double MirrorParabOuterLength = MirrorParabLength +  MirrorParabThickness;
const G4double MirrorParbDnsOuterDiameter=MirrorParbDnsDiameter + MirrorParabThickness;
const G4double MirrorParbDnsOuterCentralHoleDiameter=MirrorParabCenterHoleDiameter;


//const G4double MirrorParabRadGapZ = 1.0 * CLHEP::mm;
//const G4double MirrorParabPosZ = PolymerPlusRadiatorZLocation  + 
//                                 0.5*PolymerPlusRadiatorZSize+ MirrorParabRadGapZ + 0.5* MirrorParabLength;


const G4double MirrorParabBegZ = -0.5*RichTbContainerVesselBoxZSize +  
                                  MirrorParabolaGeneralZShift;

const G4double MirrorParabPosZ = MirrorParabBegZ +  0.5* MirrorParabOuterLength;

const G4double MirrorParabPosX =0.0 * CLHEP::mm;
const G4double MirrorParabPosY =0.0 * CLHEP::mm;

const G4double MirrorParabRotX=0.0 * CLHEP::rad;
const G4double MirrorParabRotY=0.0 * CLHEP::rad;

const G4double MirrorParabHoleLargeZSize = 200.0 * CLHEP::mm;
const G4double MirrParabCylSPhi = 0.0;
const G4double MirrParabCylDPhi = 2*M_PI;

//const  G4double MirrParabFocalLengh  = 10.2  * CLHEP::mm;

//const  G4double MirrParabFocalLengh  = 19.0 * CLHEP::mm;

const  G4double MirrParabFocalLengh  = 17.0 * CLHEP::mm;

//const G4double MirrParabFocalLengh = 30.0 * CLHEP::mm ;

//const G4double MirrParabFocalShiftFactor=0.5;
const G4double MirrParabFocalShiftFactor=0.8;


const G4double MirrorParabFocalShift =  MirrorParabThickness + MirrParabFocalShiftFactor*MirrParabFocalLengh;



#endif // INCLUDE_RICHTBMIRRORPARAGEOMETRYPARAMETERS_HH
