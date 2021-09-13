#ifndef INCLUDE_RICHTBR1QWGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBR1QWGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbR1QWGeometryParameters RichTbR1QWGeometryParameters.hh include/RichTbR1QWGeometryParameters.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2021-07-22
 */
//Parameters for simplified rich1 QW .

const G4double RichTbR1QWHalfXSize = 750.0 * CLHEP::mm;
const G4double RichTbR1QWHalfYSize = 420.0 * CLHEP::mm;
const G4double RichTbR1QWHalfZSize = 3.0 * CLHEP::mm;
const G4double RichTbR1QWShiftFromDetPlane = -250.0 * CLHEP::mm;
const G4double RichTbR1QWShiftAlongDetPlane = -60.0 * CLHEP::mm;
const G4double RichTbR1QWRotX = RichTbR1DetPlaneRotX;
const G4double RichTbR1QWPosX = 0.0 *  CLHEP::mm ;
const G4double RichTbR1QWPosY = RichTbR1DetPlaneCenterY +  RichTbR1QWShiftFromDetPlane * RichTbR1DetPlaneDirCosY + RichTbR1QWShiftAlongDetPlane*RichTbR1DetPlaneDirCosZ -  RichTbR1MagShRegPosY -  RichTbR1SubMasterPosY -  RichTbR1MasterPosY;
const G4double RichTbR1QWPosZ = RichTbR1DetPlaneCenterZ + RichTbR1QWShiftFromDetPlane * RichTbR1DetPlaneDirCosZ + RichTbR1QWShiftAlongDetPlane*RichTbR1DetPlaneDirCosY -RichTbR1MagShRegPosZ - RichTbR1SubMasterPosZ -  RichTbR1MasterPosZ ;

#endif // INCLUDE_RICHTBR1QWGEOMETRYPARAMETERS_HH
