#ifndef INCLUDE_RICHTBPHCPHOTDETSUPFRAMEGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBPHCPHOTDETSUPFRAMEGEOMETRYPARAMETERS_HH 1

// Include files

#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"



const G4double PhCDetPlaneSegXSize = 50.0 * CLHEP::mm;
const G4double PhCDetPlaneSegYSize = 50.0 * CLHEP::mm;
const G4double PhCDetPlaneSegZSize = 5.0 * CLHEP::mm;


const G4double PhCPhotDetSupFrameXSize = 70.0 * CLHEP::mm;
const G4double PhCPhotDetSupFrameYSize = 70.0 * CLHEP::mm;
const G4double PhCPhotDetSupFrameZSize = 70.0 * CLHEP::mm;


const G4double  PhCDetPlaneShiftFromFrameEdge=10.0 * CLHEP::mm;
const G4double  PhCDetPlaneSurfaceZPos =  0.5*PhCPhotDetSupFrameZSize-PhCDetPlaneShiftFromFrameEdge;
const G4double  PhCDetPlaneSurfaceXPos = 0.0 * CLHEP::mm;
const G4double  PhCDetPlaneSurfaceYPos = 0.0 * CLHEP::mm;

const G4double PhCDetPlaneXPos=PhCDetPlaneSurfaceXPos;
const G4double PhCDetPlaneYPos=PhCDetPlaneSurfaceYPos;
const G4double PhCDetPlaneZPos= PhCDetPlaneSurfaceZPos-0.5*PhCDetPlaneSegZSize;
const G4double PhCDetPlaneInSupFrameRotX =0.0 * CLHEP::rad;
const G4double PhCDetPlaneInSupFrameRotY =0.0 * CLHEP::rad;

const G4double PhCDetPlaneRotX= 0.0 * CLHEP::rad;
const G4double PhCDetPlaneRotY = -0.40 * CLHEP::rad;

const G4double PhCPhotDetSupFrameRotX=PhCDetPlaneRotX;
//const G4double PhCPhotDetSupFrameRotY=2.0*MirrorSphYRotation * CLHEP::rad;
const G4double PhCPhotDetSupFrameRotY=PhCDetPlaneRotY;



//const G4double MirrorParabBegZ = -0.5*RichTbContainerVesselBoxZSize +
//                                  MirrorParabolaGeneralZShift;
//const G4double MirrSphSegmentZPosNoRot=  MirrorParabBegZ + MirrSphShiftWrtParabAlongNominalZ;
//const G4double MirrorSphZLocation = MirrSphSegmentZPosNoRot -  MirrorSphInnerROC * (1.0-cos(MirrorSphYRotation)); 
//const G4double MirrSphSegmentPivotPointZPos = MirrorSphZLocation + MirrorSphInnerROC;
//const G4double MirrSphSegmentNominalFocalPlaneDist= 0.5*MirrorSphInnerROC;

const G4double PhDetPlaneFineTuneXShift=-10.0 * CLHEP::mm;

//const G4double  LMirrorFocalPlaneDistFactor = 1.6;

//const G4double  LMirrorFocalPlaneDistFactor = 1.4;

//const G4double  LMirrorFocalPlaneDistFactor = 1.3;
const G4double  LMirrorFocalPlaneDistFactor = 1.25;

const G4double  LMirrorFocalPlaneDistFactorQW = 0.8;



const G4double PhCDetPlaneInVesselXPos =  MirrSphSegmentPivotPointXPos -
                                  LMirrorFocalPlaneDistFactor*MirrSphSegmentNominalFocalPlaneDist*sin( PhCDetPlaneRotY )+
                                  PhDetPlaneFineTuneXShift;

                   


const G4double PhCDetPlaneInVesselZPos = MirrSphSegmentPivotPointZPos -
                                  LMirrorFocalPlaneDistFactorQW*MirrSphSegmentNominalFocalPlaneDist*cos(PhCDetPlaneRotY);



const G4double PhCDetPlaneInVesselQWXPos =  MirrSphSegmentPivotPointXPos -
                                  LMirrorFocalPlaneDistFactorQW*MirrSphSegmentNominalFocalPlaneDist*sin( PhCDetPlaneRotY )+
                                  PhDetPlaneFineTuneXShift;

                   


const G4double PhCDetPlaneInVesselQWZPos = MirrSphSegmentPivotPointZPos -
                                  LMirrorFocalPlaneDistFactorQW*MirrSphSegmentNominalFocalPlaneDist*cos(PhCDetPlaneRotY);





const G4double PhCDetPlaneInVesselYPos = 0.0 * CLHEP::mm;

const G4double PhCPhotDetSupFrameXPos = PhCDetPlaneInVesselXPos- PhCDetPlaneSurfaceZPos*sin( PhCDetPlaneRotY );
const G4double PhCPhotDetSupFrameZPos = PhCDetPlaneInVesselZPos- PhCDetPlaneSurfaceZPos*cos( PhCDetPlaneRotY );
const G4double PhCPhotDetSupFrameYPos = 0.0 * CLHEP::mm;

const G4double PhCPhotDetSupFrameQWXPos = PhCDetPlaneInVesselQWXPos- PhCDetPlaneSurfaceZPos*sin( PhCDetPlaneRotY );
const G4double PhCPhotDetSupFrameQWZPos = PhCDetPlaneInVesselQWZPos- PhCDetPlaneSurfaceZPos*cos( PhCDetPlaneRotY );


#endif // INCLUDE_RICHTBPHCPHOTDETSUPFRAMEGEOMETRYPARAMETERS_HH
