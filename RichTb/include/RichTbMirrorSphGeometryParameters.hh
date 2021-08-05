#ifndef INCLUDE_RICHTBMIRRORSPHGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBMIRRORSPHGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbMirrorSphGeometryParameters RichTbMirrorSphGeometryParameters.hh include/RichTbMirrorSphGeometryParameters.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-21
 */

const G4double MirrorSphThickness= 2.0 * CLHEP::mm;

//const G4double MirrorSphInnerROC = 800.0 * CLHEP::mm;

const G4double MirrorSphInnerROC = 609.6*2.0 * CLHEP::mm;

const G4double MirrorSphOuterROC = MirrorSphInnerROC+MirrorSphThickness;

//const G4double MirrorSphLateralRadius = 180.0 * CLHEP::mm;

const G4double MirrorSphLateralRadius = 203.2/2.0 * CLHEP::mm;

//const G4double MirrorSphLateralRadius = 150.0 * CLHEP::mm;


const G4double MirrorSphPhiSize= 2*M_PI;

const G4double MirrorSphThetaSize =  MirrorSphLateralRadius/MirrorSphInnerROC;
const G4double MirrSphPhiStart =  0.0 * CLHEP::rad;
const G4double MirrSphThetaStart = 0.0 * CLHEP::rad;
 
//const G4double MirrSphShiftWrtParabAlongNominalZ= -100.0 * CLHEP::mm;

//const G4double MirrSphShiftWrtParabAlongNominalZ= -200.0 * CLHEP::mm;

//const G4double MirrSphShiftWrtParabAlongNominalZ= -250.0 * CLHEP::mm;

const G4double MirrSphShiftWrtParabAlongNominalZ= -230.0 * CLHEP::mm;

const G4double MirrorSphXRotation=0.0 * CLHEP::rad;
const G4double MirrorSphYRotation=-0.20 * CLHEP::rad;

const G4double MirrSphSegmentZPosNoRot=  MirrorParabBegZ + MirrSphShiftWrtParabAlongNominalZ;



const G4double MirrorSphXLocation = -1.0*MirrorSphInnerROC * sin(MirrorSphYRotation);

//const G4double MirrorSphXLocation = 0.0 * CLHEP::mm;


const G4double MirrorSphYLocation = 0.0 * CLHEP::mm;

const G4double MirrorSphZLocation = MirrSphSegmentZPosNoRot -  MirrorSphInnerROC * (1.0-cos(MirrorSphYRotation)); 
//const G4double MirrorSphZLocation = MirrSphSegmentZPosNoRot;

// The following used for defining the ph det plane

const G4double MirrSphSegmentPivotPointZPos = MirrorSphZLocation + MirrorSphInnerROC;
const G4double MirrSphSegmentPivotPointXPos = 0.0 * CLHEP::mm;
const G4double MirrSphSegmentPivotPointYPos = 0.0 * CLHEP::mm;



const G4double MirrSphSegmentNominalFocalPlaneDist= 0.5*MirrorSphInnerROC;





#endif // INCLUDE_RICHTBMIRRORSPHGEOMETRYPARAMETERS_HH
