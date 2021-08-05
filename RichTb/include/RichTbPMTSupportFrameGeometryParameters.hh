#ifndef INCLUDE_RICHTBPMTSUPPORTFRAMEGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBPMTSUPPORTFRAMEGEOMETRYPARAMETERS_HH 1
//size and location of PMTPhDetSupport frames


// Phot det sup frame in Test beam  for 2014
// Looking downstream from the origin of the beam towards +Z axis 

/*
   --------------             -----------------
   |   PhDet 0   |            |    PhDet 1    |
   |             |            |               |
   |  ---------  |            | -----------   |
   |  |  EC 0 |  |      Beam  | |    EC 1  |  |
   |  ---------  |            | -----------   |
   |             |            |               |
   |------------ |            |---------------|

   Inside each EC the PMTs are arranged as follows. This also when looking towards downstream from the origin of beam.


            EC 0                    EC 1

     PMT 3        PMT 2         PMT 7     PMT 6

     PMT 1        PMT 0         PMT 5     PMT 4


  Coordinate system:   Z along beam line
                       Y going upwards
                       X goes left when looking downstream.


   PMT label for efficiency:
   PMT Number   PMT Label
     0            JA
     1            JA
     2            JB
     3            JB
     4            SA
     5            SA
     6            SB
     7            SB




  PMT rotations

     PMT number       rotation wrt postive Z axis in radians

        0                pi
        1                pi
        2                pi/2
        3                pi/2
        4                -pi/2
        5                -pi/2
        6                 0.0
        7                 0.0


    PMT Pixel numbering for PMT 7 as one looks downstream along positive Z axis.
    (Same as Paolo scheme sifted by 1. His scheme starts at 1, whereas here it starts at 0 for C++ arrays).


    63  62  61    .....   56
    55  54  53    .....   48
    47 ...................40
    39 ...................32    => 0 * CLHEP::rad rotation
    31 ...................24
    23 ...................16
    15 ...................8
    7   6   5  4  3  2  1 0


for 2017 configuration : 


Roberta's Convention

    -----------------     Y ^
    |               |       |
    |EC0         EC3|       |
    | -----------   |  <----
    | |PMT0 PMT3 |  |   X
    | |PMT1 PMT2 |  |
    | -----------   |
    |EC1         EC2|
    | -----------   |  
    | |PMT0 PMT3 |  |   
    | |PMT1 PMT2 |  |
    | -----------   | BEAM         
    |EC2         EC1|
    | -----------   |  
    | |PMT0 PMT3 |  |   
    | |PMT1 PMT2 |  |
    | -----------   |              
    |EC3         EC0|
    | -----------   |  
    | |PMT0 PMT3 |  |   
    | |PMT1 PMT2 |  |
    | -----------   |            
    |               |
     ---------------- 
         Saleve


Simulation's convention
    -----------------     Y ^
    |               |       |
    |EC0         EC0|       |
    | -----------   |  <----
    | |PMT14PMT15|  |   X
    | |PMT12PMT13|  |
    | -----------   |
    |EC1         EC1|  
    | -----------   |  
    | |PMT10PMT11|  |   
    | |PMT8 PMT9 |  |
    | -----------   | BEAM         
    |EC2         EC2|
    | -----------   |  
    | |PMT6 PMT7 |  |   
    | |PMT4 PMT5 |  |
    | -----------   |              
    |EC3         EC3|
    | -----------   |  
    | |PMT2 PMT3 |  |   
    | |PMT0 PMT1 |  |
    | -----------   |            
    |               |
     ---------------- 
         Saleve




     PMT number       rotation wrt postive Z axis in radians

        0                pi
        1                -pi/2
        2                pi/2
        3                0.0
        4                pi
        5                -pi/2
        6                pi/2
        7                0.0
        8                pi
        9                -pi/2
        10               pi/2
        11               0.0
        12               pi
        13               -pi/2
        14               pi/2 
        15               0.0


 */

#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"



//#include "RichTbRunConfig.hh" //in order to make geometry changes without recompiling

const G4double ECXShift = -16.3 * CLHEP::mm; // absolute position is 70.6+ECXShift
                                 //usaly : -16.3
                                 //to fit 2017 run 389 : 23


//const G4int NumPhDetSupFrames = 2;
//const G4int NumElementaryCell =2;
//const G4int NumPhDetSupFrames15 = 4;
//const G4int NumElementaryCell15 =4;
//const G4int NumPmtsInEC = 4;

//const G4int RichTbTotNumPmt = NumElementaryCell * NumPmtsInEC;
//const G4int RichTbTotNumPmt15 = NumElementaryCell15 * NumPmtsInEC;


//const G4double PhDetSupFrameXSize = 56.0 * CLHEP::mm;
//const G4double PhDetSupFrameYSize = 60.0 * CLHEP::mm;

//const G4double PhDetSupFrameZSize = 70.0 * CLHEP::mm;





//const G4double ECXSize = 55.4 * CLHEP::mm;
//const G4double ECYSize = 55.4 * CLHEP::mm;
//const G4double ECZSize = 55.4 * CLHEP::mm;

//const G4double ECFrontZSize = 23.55 * CLHEP::mm;
//const G4double ECFrontDistFromPhDetFrameSurface=5.0 * CLHEP::mm;



const G4double ECXLocation  = 0.0 * CLHEP::mm;
const G4double ECYLocation  = 0.0 * CLHEP::mm;

//const G4double ECZLocation  = (-0.5*PhDetSupFrameZSize) + ECFrontDistFromPhDetFrameSurface + 0.5*ECZSize;


//const G4double RichTbPMTAdjacentGap= 1.8 * CLHEP::mm;
//const G4double RichTbPMTPitch = 28.0 * CLHEP::mm;

// PMT Rotation values wrt positive Z.
//The rotations are given to be consistent with Paolo scheme for anodes.
// The information is available only for the central PMTs  ( 0, 2 , 5, 7). So for now the other pmts are
// rotations same as the central PMTS as shown in the list above.

const G4double RichTbPmtRotZInEC[]  =  {CLHEP::pi * CLHEP::rad, -0.5 * CLHEP::pi * CLHEP::rad ,0.5 * CLHEP::pi * CLHEP::rad,0.0 * CLHEP::rad,CLHEP::pi * CLHEP::rad, -0.5 * CLHEP::pi * CLHEP::rad ,0.5 * CLHEP::pi * CLHEP::rad,0.0 * CLHEP::rad, CLHEP::pi * CLHEP::rad, -0.5 * CLHEP::pi * CLHEP::rad ,0.5 * CLHEP::pi * CLHEP::rad,0.0 * CLHEP::rad,CLHEP::pi * CLHEP::rad, -0.5 * CLHEP::pi * CLHEP::rad ,0.5 *CLHEP::pi * CLHEP::rad,0.0 * CLHEP::rad};


//const G4double RichTbPmtRotZInEC[]  =  {CLHEP::pi * CLHEP::rad, CLHEP::pi * CLHEP::rad ,0.5*CLHEP::pi * CLHEP::rad, 0.5*CLHEP::pi * CLHEP::rad, -0.5*CLHEP::pi * CLHEP::rad, -0.5*CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad, 0.0 * CLHEP::rad,
//										CLHEP::pi * CLHEP::rad, CLHEP::pi * CLHEP::rad ,0.5*CLHEP::pi * CLHEP::rad, 0.5*CLHEP::pi * CLHEP::rad, -0.5*CLHEP::pi * CLHEP::rad, -0.5*CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad, 0.0 * CLHEP::rad};


//const G4double RichTbPmtPosXInEC[] = {-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
//									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
//									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
//									-0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch};
//const G4double RichTbPmtPosYInEC[] = {-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
//        							-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
//									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch,
//									-0.5*RichTbPMTPitch, -0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch, 0.5*RichTbPMTPitch};

//const G4double PMTFrontDistFromECSurface = 2.0 * CLHEP::mm;


//const G4double RichTbPmtPosZInEC = (-0.5*ECZSize) + PMTFrontDistFromECSurface + ( 0.5* PMTMasterBoxZSize) ;

//const G4double PhotonDetPlaneGapWrtRadiatorSurface=30.0 * CLHEP::mm;
//testing this change on 04-03-2015 following email discussions.
const G4double PhotonDetPlaneGapWrtRadiatorSurface=25.5 * CLHEP::mm;

// The following numbers are in the Crystal master reference frame.

const G4double PhotonDetectorPlaneX=0.0;
const G4double PhotonDetectorPlaneY=0.0;
const G4double PhotonDetectorPlaneZ= RadiatorLensThickness + PhotonDetPlaneGapWrtRadiatorSurface;
const G4double PhotonDetectorPlaneDirCosX=0.0;
const G4double PhotonDetectorPlaneDirCosY=0.0;
const G4double PhotonDetectorPlaneDirCosZ=1.0;


//const G4double PhotonDetPlaneToPMTMasterSurfaceZ = -1.0 * RichTbPMTEdgeToQuartzInsideEdgeDeltaZ;

//const G4double PhotonDetPlaneToPhDetSupFrameFrontSurface = PhotonDetPlaneToPMTMasterSurfaceZ
//                                                   -PMTFrontDistFromECSurface- ECFrontDistFromPhDetFrameSurface;

const G4double PhDetSupFrameZLocation = PhotonDetectorPlaneZ + PhotonDetPlaneToPhDetSupFrameFrontSurface + 0.5*PhDetSupFrameZSize;
const G4double PhDetSupFrameNominalXPos= 70.0 * CLHEP::mm;
//const G4double PhDetSupFrameFinalXPos = PhDetSupFrameNominalXPos-(0.5*RichTbPMTPitch)+1.5 * CLHEP::mm;
//const G4double PhDetSupFrameFinalXPos = PhDetSupFrameNominalXPos-(0.5*RichTbPMTPitch)+4.0 * CLHEP::mm;
//Sajan
//const G4double PhDetSupFrameFinalXPos = PhDetSupFrameNominalXPos-(0.5*RichTbPMTPitch)+8.0 * CLHEP::mm;
//mio
//const G4double PhDetSupFrameFinalXPos = 70.92;
//modified May6-2015 for test

const G4double PhDetSupFrameFinalXPos = 70.6 * CLHEP::mm;
const G4double PhDetSupFrameFinalXPos15 = 70.6 * CLHEP::mm + ECXShift;
const G4double PhDetSupFrameFinalXPos17 = 1*(70.6 * CLHEP::mm + ECXShift);
//const G4double PhDetSupFrameFinalXPos17 = -54.3 * CLHEP::mm;

//const G4double PhDetSupFrameFinalYPos = 0 * CLHEP::mm/*1.3 * CLHEP::mm*/;
const G4double PhDetSupFrameYGap = 0.3 * CLHEP::mm;
const G4double PhDetSupFrameFinalYPos = 0.0;
const G4double PhDetSupFrameFinalYPos15 = 0.5*ECYSize+PhDetSupFrameYGap;
const G4double PhDetSupFrameFinalYPos17 = 0.0; 
//Sajan
//const G4double PhDetSupFrameXLocation[] =  {  PhDetSupFrameFinalXPos  , -1*PhDetSupFrameFinalXPos };
//const G4double PhDetSupFrameXLocation[] =  {  70.6  , -70.92 };
// Modified May 6-2015 for test
const G4double PhDetSupFrameXLocation[] = {PhDetSupFrameFinalXPos ,-1*PhDetSupFrameFinalXPos};
const G4double PhDetSupFrameXLocation15[] = {PhDetSupFrameFinalXPos15 ,-1*PhDetSupFrameFinalXPos15};

//const G4double PhDetSupFrameYLocation[] =  {    0.0 * CLHEP::mm,  0.0 * CLHEP::mm};
// Moving EC up for test
const G4double PhDetSupFrameYLocation[] =  {PhDetSupFrameFinalYPos, PhDetSupFrameFinalYPos};
const G4double PhDetSupFrameYLocation15[] =  {PhDetSupFrameFinalYPos15, PhDetSupFrameFinalYPos15};

//Upgrade 2015
//const G4double PhDetSupFrameRadius = sqrt(pow(PhDetSupFrameFinalXPos,2) + pow(PhDetSupFrameFinalYPos,2));
//const G4double PhDetSupFrameFinalBottomXPos = PhDetSupFrameRadius/3; //for equidistance of EC's in x
//const G4double PhDetSupFrameFinalBottomYPos = sqrt(pow(PhDetSupFrameRadius,2)-pow(PhDetSupFrameFinalBottomXPos,2)); //for same radius
//test move up and inwards
//const G4double PhDetSupFrameBottomXLocation[] = {0.5*PhDetSupFrameFinalXPos-5 * CLHEP::mm, -0.5*PhDetSupFrameFinalXPos+5 * CLHEP::mm};
//const G4double PhDetSupFrameBottomYLocation[] = {-1*PhDetSupFrameFinalXPos+5 * CLHEP::mm, -1*PhDetSupFrameFinalXPos+5 * CLHEP::mm};
const G4double PhDetSupFrameBottomXLocation[] = {PhDetSupFrameFinalXPos15 ,-1*PhDetSupFrameFinalXPos15};
const G4double PhDetSupFrameBottomYLocation[] = {-1*PhDetSupFrameFinalYPos15, -1*PhDetSupFrameFinalYPos15};

//const G4double ECSupportTolerence = 1.0 * CLHEP::mm;

//const G4double ECSupportXSize = ECXSize-ECSupportTolerence;
//const G4double ECSupportYSize = ECYSize-ECSupportTolerence;
//const G4double ECSupportZSize = 3.0 * CLHEP::mm;
const G4double ECSupportXLocation = ECXLocation;
const G4double ECSupportYLocation = ECYLocation;

//const G4double ECSupportZLocation = ECZLocation+ 0.5*(ECZSize + ECSupportZSize)+2.0 * CLHEP::mm;


//testbeam 2015 upgrade
const G4double ECXLocation15  = 0.0 * CLHEP::mm;
const G4double ECYLocation15  = 0.0 * CLHEP::mm;
const G4double ECZLocation15  = (-0.5*PhDetSupFrameZSize) + ECFrontDistFromPhDetFrameSurface + 0.5*ECZSize;
const G4double ECSupportXLocation15 = ECXLocation15;
const G4double ECSupportYLocation15 = ECYLocation15;
const G4double ECSupportZLocation15 = ECZLocation15+ 0.5*(ECZSize + ECSupportZSize)+2.0 * CLHEP::mm;

const G4double PhotonDetPlaneGapWrtRadiatorSurface15=21.0 * CLHEP::mm;//2017 configuration too
const G4double PhotonDetectorPlaneX15=0.0;
const G4double PhotonDetectorPlaneY15=0.0;
const G4double PhotonDetectorPlaneZ15= RadiatorLensThickness15 + PhotonDetPlaneGapWrtRadiatorSurface15;
const G4double PhotonDetectorPlaneZ17= RadiatorLensThickness15 + PhotonDetPlaneGapWrtRadiatorSurface15;
const G4double PhDetSupFrameZLocation15 = PhotonDetectorPlaneZ15 + 
                     PhotonDetPlaneToPhDetSupFrameFrontSurface + 0.5*PhDetSupFrameZSize;

const G4double PhDetSupFrameZLocation17 = PhotonDetectorPlaneZ17 + 
                     PhotonDetPlaneToPhDetSupFrameFrontSurface + 0.5*PhDetSupFrameZSize;
//testbeam 2017

const G4double ECXLocation17  =  0.0 * CLHEP::mm;
const G4double ECYLocation17  = 0.0 * CLHEP::mm;
const G4double ECZLocation17  = (-0.5*PhDetSupFrameZSize) + ECFrontDistFromPhDetFrameSurface + 0.5*ECZSize;
const G4double ECXSupportLocation17 = ECXLocation17;
const G4double ECYSupportLocation17 = ECYLocation17;
const G4double ECZSupportLocation17 = ECZLocation17+ 0.5*(ECZSize + ECSupportZSize)+2.0 * CLHEP::mm;



// testbeam 2016 with layertec

//const G4double PhotonDetectorPlaneZGapFromLTDnsSurface=30.0 * CLHEP::mm;

//const G4double PhotonDetectorPlaneZWithLTRadiator=  RichTbLTSampleDownstreamSurfaceLocation 
//  + PhotonDetectorPlaneZGapFromLTDnsSurface;

//const G4double PhDetSupFrameZLocationWithLT =  PhotonDetectorPlaneZWithLTRadiator
//      + PhotonDetPlaneToPhDetSupFrameFrontSurface + 0.5*PhDetSupFrameZSize;

//const G4double  PhDetSupFrameNominalXPosWithLT = 35.0 * CLHEP::mm;
//const G4double  PhDetSupFrameFinalXPosWithLT = PhDetSupFrameNominalXPosWithLT +  ECXShiftWithLT;


//const G4double PhDetSupFrameFinalYPosWithLT = 0.0 * CLHEP::mm;

//const G4double PhDetSupFrameXLocationWithLTec[] = {PhDetSupFrameFinalXPosWithLT  ,-1*PhDetSupFrameFinalXPosWithLT };
//const G4double PhDetSupFrameYLocationWithLTec[] =  { PhDetSupFrameFinalYPosWithLT ,PhDetSupFrameFinalYPosWithLT };
//const G4double PhDetSupFrameLTYGap = 0.3 * CLHEP::mm;


#endif // INCLUDE_RICHTBPMTSUPPORTFRAMEGEOMETRYPARAMETERS_HH
