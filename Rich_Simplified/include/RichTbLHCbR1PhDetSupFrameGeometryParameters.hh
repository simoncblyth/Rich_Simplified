#ifndef INCLUDE_RICHTBR1PHDETSUPFRAMEGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBR1PHDETSUPFRAMEGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbR1PhDetSupFrameGeometryParameters RichTbR1PhDetSupFrameGeometryParameters.hh include    /RichTbR1PhDetSupFrameParameters.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2021-07-22
 */
//Parameters for simplified rich1 Phdetsupframe
const G4double RichTbR1PhDetSupFrameHalfSizeX =  800  *  CLHEP::mm ;
const G4double RichTbR1PhDetSupFrameHalfSizeY =  550  *  CLHEP::mm ;
const G4double RichTbR1PhDetSupFrameHalfSizeZ =  40  *  CLHEP::mm ;
const G4double RichTbR1DetPlaneDirCosY = 0.846193;
const G4double RichTbR1DetPlaneDirCosZ = 0.532877;
const G4double RichTbR1DetPlaneDirCosX = 0.0;
const G4double RichTbR1DetPlaneRotX = -1.0 * acos(RichTbR1DetPlaneDirCosZ) * CLHEP::rad ;
const G4double RichTbR1DetPlaneCenterX = 0.0 *  CLHEP::mm ;
const G4double RichTbR1DetPlaneCenterY = 1407.72 * CLHEP::mm ;
const G4double RichTbR1DetPlaneCenterZ = 1641.42 * CLHEP::mm ;
const G4double RichTbR1PhDetSupFrameTolerence = 1.0 * CLHEP::mm ;



const G4double RichTbR1PhDetSupFrameRotX = RichTbR1DetPlaneRotX;
const G4double RichTbR1PhDetSupFramePosX = 0.0 * CLHEP::mm ;

const G4double RichTbLbModuleZPos = -RichTbR1PhDetSupFrameHalfSizeZ + 
                                    0.5 * RichTbLbModuleZSize + RichTbR1PhDetSupFrameTolerence; 
const G4double RichTbR1MagShRegSubBoxRotX = RichTbR1DetPlaneRotX ;

//==========================================================
const G4double RichTbLbModuleBackPlZTolerence = 3.0*CLHEP::mm;
const G4double RichTbLbModuleBackPlXSize= 1350.0 * CLHEP::mm;
const G4double RichTbLbModuleBackPlYSize= 620.0 * CLHEP::mm;
const G4double RichTbLbModuleBackPlZSize= 3.0*CLHEP::mm;

const G4double RichTbLbModuleBackPlXPos = 0.0 * CLHEP::mm;
const G4double RichTbLbModuleBackPlYPos = 0.0 * CLHEP::mm;
const G4double RichTbLbModuleBackPlZPos = RichTbLbModuleZPos +
  0.5 * (RichTbLbModuleZSize + RichTbLbModuleBackPlZSize) + RichTbLbModuleBackPlZTolerence;

//====================================================

const G4double RichTbR1DetPlaneInPhDetSup=  RichTbLbModuleZPos + RichTbLbECZPos + RichLbPmtMasterInECZPos - RichLbPMTQuartzPosZ + 0.5 * RichLbPMTQuartzZSize ;
const G4double  RichTbR1PhDetSupShiftAlongPmtAxis = -1.0* RichTbR1DetPlaneInPhDetSup ;
const G4double RichTbR1PhDetSupFramePosY =  RichTbR1DetPlaneCenterY + RichTbR1PhDetSupShiftAlongPmtAxis * RichTbR1DetPlaneDirCosY -  RichTbR1MagShRegPosY - RichTbR1SubMasterPosY -  RichTbR1MasterPosY  ;
const G4double RichTbR1PhDetSupFramePosZ = RichTbR1DetPlaneCenterZ + RichTbR1PhDetSupShiftAlongPmtAxis * RichTbR1DetPlaneDirCosZ -  RichTbR1MagShRegPosZ - RichTbR1SubMasterPosZ -  RichTbR1MasterPosZ ;

 


#endif // INCLUDE_RICHTBR1PHDETSUPFRAMEGEOMETRYPARAMETERS_HH
