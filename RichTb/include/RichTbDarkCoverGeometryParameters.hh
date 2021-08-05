// $Id: $
#ifndef INCLUDE_RICHTBDARKCOVERGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBDARKCOVERGEOMETRYPARAMETERS_HH 1

// Include files
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"

/** @class RichTbVesselGeometryParameters RichTbVesselGeometryParameters.hh include/RichTbVesselGeometryParameters.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */

const G4double RichTbUpgradeDarkCoverXSize=17.0*2.0* CLHEP::mm;

//const G4double RichTbUpgradeDarkCoverXSize=(27.0* CLHEP::mm - 10* CLHEP::mm)*2*0.9;
const G4double RichTbUpgradeDarkCoverYSize=70.0* CLHEP::mm;
//const G4double RichTbUpgradeDarkCoverZSize=1.0* CLHEP::mm;
const G4double RichTbUpgradeDarkCoverZSize=2.0* CLHEP::mm;


const G4double RichTbUpgradeDarkCoverYLocation = 0.0;

const G4double RichTbUpgradeDarkCoverXLocation = 0.0;
//const G4double RichTbUpgradeDarkCoverZLocation =138.4* CLHEP::mm - 26.5* CLHEP::mm + 1* CLHEP::mm;

//const G4double RichTbUpgradeDarkCoverZLocation =-SphereRadius  + RadiatorLensThickness   + 1* CLHEP::mm;

const G4double RichTbUpgradeDarkCoverZLocation =-SphereRadius  + RadiatorLensThickness   +
                               0.5* RichTbUpgradeDarkCoverZSize;



const G4double RichTbUpgradeDarkCoverEnvPlateThickness=0.0* CLHEP::mm;


// now for the darkcover upstream side
const G4double RichTbDarkUpsInnerRadius = MirrorOuterRadius + 2.0* CLHEP::mm;
const G4double RichTbDarkUpsOuterRadius = RichTbDarkUpsInnerRadius + 3.0* CLHEP::mm;

// now for the dark cover on the two sides of the radiator
const G4double RichTbRadiatorC2S= SphereRadius - RadiatorLensThickness;
const G4double RichTbRadiatorLateralHalfSize = std::sqrt(SphereRadius*SphereRadius - RichTbRadiatorC2S*RichTbRadiatorC2S);

//const G4double RichTbDarkSideZSize = RadiatorLensThickness+6.0* CLHEP::mm;
const G4double RichTbDarkSideZSize = RadiatorLensThickness+25.0* CLHEP::mm;
const G4double RichTbDarkSideXSize = 2.0*RichTbRadiatorLateralHalfSize;
const G4double RichTbDarkSideYSize=3.0* CLHEP::mm;


const G4double RichTbDarkSideYTopLocation =  MirrorSubBoxShiftY+2.0* CLHEP::mm;
const G4double RichTbDarkSideYBotLocation =  -1.0*(MirrorSubBoxShiftY+2.0* CLHEP::mm);
const G4double RichTbDarkSideZLocation  = 0.5*RichTbDarkSideZSize;
const G4double RichTbDarkSideXLocation  =0.0* CLHEP::mm;


//testbeam 2015 upgrade
const G4double RichTbUpgradeDarkCoverXSize15 = 17.0*2.0* CLHEP::mm;
const G4double RichTbUpgradeDarkCoverYSize15 = RichTbUpgradeDarkCoverXSize15;
const G4double RichTbUpgradeDarkCoverZSize15 = 2.0* CLHEP::mm;

const G4double RichTbUpgradeDarkCoverYLocation15 = 0.0;
const G4double RichTbUpgradeDarkCoverXLocation15 = 0.0;
const G4double RichTbUpgradeDarkCoverZLocation15 =-SphereRadius15 + RadiatorLensThickness15 +
		0.5*RichTbUpgradeDarkCoverZSize;

//upstream darkcover
const G4double RichTbDarkUpsInnerRadius15 = MirrorOuterRadius15 + 2.0* CLHEP::mm;
const G4double RichTbDarkUpsOuterRadius15 = RichTbDarkUpsInnerRadius15 + 3.0* CLHEP::mm;

//side darkcovers
//const G4double RichTbRadiatorC2S15= SphereRadius15 - RadiatorLensThickness15;
//const G4double RichTbRadiatorLateralHalfSize15 = std::sqrt(SphereRadius15*SphereRadius15 - RichTbRadiatorC2S*RichTbRadiatorC2S);
const G4double RichTbRadiatorLateralHalfSize15 = cylRmax;
//const G4double RichTbDarkSideZSize = RadiatorLensThickness+6.0* CLHEP::mm;
const G4double RichTbDarkSideZSize15 = RadiatorLensThickness15+25.0* CLHEP::mm;
const G4double RichTbDarkSideXSize15 = 2.0*RichTbRadiatorLateralHalfSize15+60.0* CLHEP::mm;
const G4double RichTbDarkSideYSize15 = RichTbDarkSideXSize15;
const G4double BoxInnZSize15 = RichTbDarkSideZSize15+30.0* CLHEP::mm;
const G4double BoxInnXSize15 = RichTbDarkSideXSize15-3.0* CLHEP::mm;
const G4double BoxInnYSize15 = RichTbDarkSideYSize15-3.0* CLHEP::mm;


const G4double RichTbDarkSideYLocation15 =  0.0* CLHEP::mm;//RichTbRadiatorLateralHalfSize15+2.0* CLHEP::mm;
//const G4double RichTbDarkSideYBotLocation15 =  0.0* CLHEP::mm;//-1.0*(RichTbRadiatorLateralHalfSize15+2.0* CLHEP::mm);
const G4double RichTbDarkSideZLocation15  = 0.5*RichTbDarkSideZSize15;
const G4double RichTbDarkSideXLocation15  = 0.0* CLHEP::mm;


// Now for the darkcover on the side with PhC crystals
// It is slightly extended version of the side cover used for testbeam in 2015.

const G4double RichTbDarkSideZSizePhC = 70.0* CLHEP::mm;
const G4double RichTbDarkSideXSizePhC = 360.0* CLHEP::mm;
const G4double RichTbDarkSideYSizePhC =  RichTbDarkSideXSizePhC;
const G4double  RichTbDarkSideBoxInnZSizePhC= RichTbDarkSideZSizePhC + 50.0* CLHEP::mm; 
const G4double  RichTbDarkSideBoxInnXSizePhC = RichTbDarkSideXSizePhC - 3.0* CLHEP::mm;
const G4double  RichTbDarkSideBoxInnYSizePhC = RichTbDarkSideYSizePhC - 3.0* CLHEP::mm;

const G4double RichTbDarkSideZCoverShiftUpstream=20.0* CLHEP::mm;


const G4double RichTbDarkSideZPhCYLocation =  0.0* CLHEP::mm;
const G4double RichTbDarkSideZPhCXLocation =  0.0* CLHEP::mm;
const G4double RichTbDarkSideZPhCZLocation =  0.5*RichTbDarkSideZSizePhC - RichTbDarkSideZCoverShiftUpstream;


// Now for the darkcover on the upstream of  PhC crystals

const G4double RichTbDarkUpsZSizePhC = 5.0* CLHEP::mm;
const G4double RichTbDarkUpsXSizePhC = 370.0* CLHEP::mm;
const G4double RichTbDarkUpsYSizePhC =  RichTbDarkUpsXSizePhC;

const G4double RichTbDarkUpsZPhCZGapWrtSide=1.0* CLHEP::mm;

const G4double RichTbDarkUpsPhCZLocation =  (-1.0*RichTbDarkSideZCoverShiftUpstream)
  -RichTbDarkUpsZPhCZGapWrtSide-(0.5*RichTbDarkSideZPhCZLocation) ;
const G4double RichTbDarkUpsPhCXLocation=0.0* CLHEP::mm;
const G4double RichTbDarkUpsPhCYLocation=0.0* CLHEP::mm;


#endif
