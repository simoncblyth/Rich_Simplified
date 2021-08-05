// $Id: $
#ifndef INCLUDE_RICHTBCRYSTALMASTERGEOMETRYPARAMETERS_HH 
#define INCLUDE_RICHTBCRYSTALMASTERGEOMETRYPARAMETERS_HH 1

// Include files
/** @class RichTbVesselGeometryParameters RichTbVesselGeometryParameters.hh include/RichTbVesselGeometryParameters.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-10-21
 */

const G4double RichTbCrystalMasterXSize=400.0 * CLHEP::mm;
const G4double RichTbCrystalMasterYSize=600.0 * CLHEP::mm;
const G4double RichTbCrystalMasterZSize=1500.0 * CLHEP::mm;

//const G4double RichTbCrystalMasterOriginShiftFromLeftEdgeX=0.0 * CLHEP::mm;  // for now assume middle part. to be verified.
//const G4double RichTbCrystalMasterOriginShiftFromFloorY=0.0 * CLHEP::mm;
//const G4double RichTbCrystalMasterOriginShiftFromLeftZ=300.0 * CLHEP::mm;
//G4double CrystalXRotation = appoConfig ->getSpecialStudyCrystalRotationX();
//const G4double RichTbCrystalXRotation=CrystalXRotation*rad;  
//G4double CrystalYRotation = appoConfig ->getSpecialStudyCrystalRotationY();
//const G4double RichTbCrystalYRotation=CrystalYRotation*rad;
const G4double RichTbCrystalMasterYLocation = 0.0;
//const G4double RichTbCrystalMasterXShiftAlongCrystal = RichTbCrystalMasterOriginShiftFromLeftEdgeX;
//const G4double RichTbCrystalMasterZShiftAlongCrystal = -RichTbCrystalMasterOriginShiftFromLeftZ + 0.5 * RichTbCrystalMasterZSize;

const G4double RichTbCrystalMasterXLocation = 0.0;
const G4double RichTbCrystalMasterZLocation = -250 * CLHEP::mm ;

// now for variables used after creating the geometry in stepaction.

const G4double RichTbCrystalMasterEnvPlateThickness=0.0 * CLHEP::mm;





// the following are not exact values.
//const G4double  RichTbCrystalXNegExtremeAlongCrystal=RichTbCrystalOriginShiftFromLeftEdgeX-RichTbCrystalXSize;
//const G4double  RichTbCrystalXPosExtremeAlongCrystal=RichTbCrystalOriginShiftFromLeftEdgeX;
//const G4double  RichTbCrystalZUpsExtremeAlongCrystal= -RichTbCrystalUpsExternalPartZSize;
//const G4double  RichTbCrystalZDnsExtremeAlongCrystal= -RichTbcrystalUpsExternalPartZSize+RichTbCrystalZSize;
//const G4double  RichTbCrystalXNegExtreme=  RichTbCrystalXNegExtremeAlongCrystal*cos(RichTbCrystalYRotation)+
//                                          RichTbCrystalZDnsExtremeAlongCrystal*sin(RichTbCrystalYRotation);
//const G4double  RichTbCrystalXPosExtreme=  RichTbCrystalXPosExtremeAlongCrystal*cos(RichTbCrystalYRotation)+
//                                          RichTbCrystalZUpsExtremeAlongCrystal*sin(RichTbCrystalYRotation);

//const G4double  RichTbCrystalYNegExtreme= RichTbCrystalYLocation-0.5*RichTbCrystalYSize;
//const G4double  RichTbCrystalYPosExtreme= RichTbCrystalYLocation+0.5*RichTbCrystalYSize;
//const G4double  RichTbCrystalZDnsExtreme = -RichTbCrystalXNegExtremeAlongCrystal*sin(RichTbCrystalYRotation)+
//                                        RichTbCrystalZDnsExtremeAlongCrystal*cos(RichTbCrystalYRotation);
//const G4double  RichTbCrystalDnsZEnd = RichTbCrystalZDnsExtreme;
#endif
