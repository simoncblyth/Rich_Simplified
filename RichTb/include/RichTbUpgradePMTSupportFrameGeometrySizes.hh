#ifndef INCLUDE_RICHTBUPGRADEPMTSUPPORTFRAMEGEOMETRYSIZES_HH 
#define INCLUDE_RICHTBUPGRADEPMTSUPPORTFRAMEGEOMETRYSIZES_HH 1

// Include files

#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


const G4double PhDetSupFrame16XSize = 56.0 * CLHEP::mm;
const G4double PhDetSupFrame16YSize = 240.0 * CLHEP::mm;

const G4double PhDetSupFrame16ZSize = 60.0 * CLHEP::mm;


const G4double PhDetSupFrameYSize2017 = 240.0 * CLHEP::mm;

const G4double PhDetSupFrameXSize = 56.0 * CLHEP::mm;
const G4double PhDetSupFrameYSize = 60.0 * CLHEP::mm;
const G4double PhDetSupFrameZSize = 70.0 * CLHEP::mm;

//const G4double ECXSize = 55.4 * CLHEP::mm;
//const G4double ECYSize = 55.4 * CLHEP::mm;
//const G4double ECZSize = 55.4 * CLHEP::mm;
//const G4double ECZSize = 45.4 * CLHEP::mm;

//2017 upgrade
const G4double ECXSize = 55.4 * CLHEP::mm;
const G4double ECYSize = 55.4 * CLHEP::mm;
const G4double ECZSize = 45.4 * CLHEP::mm;


const G4double ECFrontZSize = 23.55 * CLHEP::mm;
const G4double ECFrontDistFromPhDetFrameSurface=5.0 * CLHEP::mm;


const G4double ECZLocation  = (-0.5*PhDetSupFrameZSize) + ECFrontDistFromPhDetFrameSurface + 0.5*ECZSize;


const G4double RichTbPMTAdjacentGap= 1.8 * CLHEP::mm;
const G4double RichTbPMTPitch = 28.0 * CLHEP::mm;


const G4double PMTFrontDistFromECSurface = 2.0 * CLHEP::mm;
const G4double RichTbPmtPosZInEC = (-0.5*ECZSize) + PMTFrontDistFromECSurface + ( 0.5* PMTMasterBoxZSize) ;

const G4double PhotonDetPlaneToPMTMasterSurfaceZ = -1.0 * RichTbPMTEdgeToQuartzInsideEdgeDeltaZ;

const G4double PhotonDetPlaneToPhDetSupFrameFrontSurface = PhotonDetPlaneToPMTMasterSurfaceZ
                                                   -PMTFrontDistFromECSurface- ECFrontDistFromPhDetFrameSurface;


const G4double RichTbPmtPosXInEC[] = {-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch};


const G4double RichTbPmtPosYInEC[] = {-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
        							-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch};





const G4double ECSupportTolerence = 1.0 * CLHEP::mm;

const G4double ECSupportXSize = ECXSize-ECSupportTolerence;
const G4double ECSupportYSize = ECYSize-ECSupportTolerence;
const G4double ECSupportZSize = 3.0 * CLHEP::mm;

const G4double ECSupportZLocation = ECZLocation+ 0.5*(ECZSize + ECSupportZSize)+2.0 * CLHEP::mm;

const G4String ECLogName[] =
  {"ECLog00", "ECLog01", "ECLog02", "ECLog03","ECLog04", "ECLog05", "ECLog06", "ECLog07" };
const G4String ECSupportLogName[] =
  {"ECSupportLog00", "ECSupportLog01", "ECSupportLog02", "ECSupportLog03","ECSupportLog04", "ECSupportLog05", "ECSupportLog06", "ECSupportLog07" };

const G4String ECPhysName[] =
  {"ECPhys00", "ECPhys01", "ECPhys02", "ECPhys03","ECPhys04", "ECPhys05", "ECPhys06", "ECPhys07" };
const G4String ECSupportPhysName[] =
  {"ECSupportPhys00", "ECSupportPhys01", "ECSupportPhys02", "ECSupportPhys03","ECSupportPhys04", "ECSupportPhys05", "ECSupportPhys06", "ECSupportPhys07" };

const G4String PhSupLogname []= {"PhSupLeftLog","PhSupRightLog"};

const G4String PhSupPhysname []= {"PhSupLeftPhys","PhSupRightPhys"};
  
    

#endif // INCLUDE_RICHTBUPGRADEPMTSUPPORTFRAMEGEOMETRYSIZES_HH
