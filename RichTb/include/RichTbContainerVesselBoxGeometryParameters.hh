#ifndef INCLUDE_RICHTBCONTAINERVESSELBOXGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBCONTAINERVESSELBOXGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


/** @class RichTbContainerVesselBoxGeometryParameters RichTbContainerVesselBoxGeometryParameters.hh include/RichTbContainerVesselBoxGeometryParameters.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-14
 */

//  overall containerVesselBox size

//const G4double RichTbContainerVesselBoxXSize=700.0* CLHEP::mm;
const G4double RichTbContainerVesselBoxXSize=800.0* CLHEP::mm;
const G4double RichTbContainerVesselBoxYSize=700.0* CLHEP::mm;
const G4double RichTbContainerVesselBoxZSize=1200.0* CLHEP::mm;

const G4double RichTbContainerVesselBoxXLocation=0.0* CLHEP::mm;
const G4double RichTbContainerVesselBoxYLocation=0.0* CLHEP::mm;
const G4double RichTbContainerVesselBoxZLocation=0.0* CLHEP::mm;

const G4double RichTbContainerVesselBoxXRotation=0.0* CLHEP::rad;
const G4double RichTbContainerVesselBoxYRotation=0.0* CLHEP::rad;


const G4double RichTbContainerVesselBoxXNegExtremeAlongVessel = -0.5*RichTbContainerVesselBoxXSize;
const G4double RichTbContainerVesselBoxXPosExtremeAlongVessel = 0.5*RichTbContainerVesselBoxXSize;
const G4double RichTbContainerVesselBoxYNegExtremeAlongVessel = -0.5*RichTbContainerVesselBoxYSize;
const G4double RichTbContainerVesselBoxYPosExtremeAlongVessel = 0.5*RichTbContainerVesselBoxYSize;
const G4double RichTbContainerVesselBoxYUpsExtremeAlongVessel = -0.5*RichTbContainerVesselBoxZSize;
const G4double RichTbContainerVesselBoxYDnsExtremeAlongVessel = 0.5*RichTbContainerVesselBoxZSize;

const G4double RichTbContainerVesselBoxXNegExtreme =   RichTbContainerVesselBoxXLocation +
                                              RichTbContainerVesselBoxXNegExtremeAlongVessel*cos(RichTbVesselYRotation)+
                                              RichTbContainerVesselBoxYDnsExtremeAlongVessel*sin(RichTbVesselYRotation);

const G4double RichTbContainerVesselBoxXPosExtreme = -1.0* RichTbContainerVesselBoxXNegExtreme;

// The X Vessel rotation is ignored for now. 
const G4double RichTbContainerVesselBoxYNegExtreme = RichTbContainerVesselBoxYLocation + RichTbContainerVesselBoxYNegExtremeAlongVessel;
const G4double RichTbContainerVesselBoxYPosExtreme = -1.0* RichTbContainerVesselBoxYNegExtreme;

const G4double RichTbContainerVesselBoxZDnsExtreme =  RichTbContainerVesselBoxZLocation-
                                              RichTbContainerVesselBoxXNegExtremeAlongVessel*sin(RichTbVesselYRotation)+
                                              RichTbContainerVesselBoxYDnsExtremeAlongVessel*cos(RichTbVesselYRotation);
                                            
const G4double RichTbContainerVesselBoxZUpsExtreme = -1.0 * RichTbContainerVesselBoxZDnsExtreme;
const G4double RichTbContainerVesselBoxZDnsEnd=   RichTbContainerVesselBoxZDnsExtreme;


#endif // INCLUDE_RICHTBCONTAINERVESSELBOXGEOMETRYPARAMETERS_HH
