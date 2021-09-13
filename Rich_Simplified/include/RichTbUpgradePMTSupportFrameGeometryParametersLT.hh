#ifndef INCLUDE_RICHTBUPGRADEPMTSUPPORTFRAMEGEOMETRYPARAMETERSLT_HH 
#define INCLUDE_RICHTBUPGRADEPMTSUPPORTFRAMEGEOMETRYPARAMETERSLT_HH 1
//  test beam in 2016 photon det arrangement with LTec radiator.

/*
   Looking down stream along the positive Z axis.

   --------------             -----------------     Y ^
   |   PhDet 0   |            |    PhDet 1    |       |
   |             |            |               |       |
   |  ---------  |            | -----------   |  <----
   |  |  EC 0 |  |            | |    EC 4  |  |   X
   |  ---------  |            | -----------   |
   |             |            |               |
   |------------ |            |---------------|
   |   gap       |            |   gap         | 
   |-------------|            |---------------|  
   |             |            |               |
   | ---------   |            | ---------     |
   | | EC 1   |  |            | | EC 5   |    |
   | ----------  |            | ----------    |
   |             |            |               |
   |-----gap ----|   beam     |---gap -------- 
 Jura|           |            |               |Saleve
   |             |            |               |
   |   PhDet 0   |            |    PhDet 1    |
   |             |            |               |
   |  ---------  |            | -----------   |
   |  |  EC 2 |  |            | |    EC 6  |  |
   |  ---------  |            | -----------   |
   |             |            |               |
   |------------ |            |---------------|
   |   gap       |            |   gap         | 
   |-------------|            |---------------|  
   |             |            |               |
   | ---------   |            | ---------     |
   | | EC 3   |  |            | | EC 7   |    |
   | ----------  |            | ----------    |
   |             |            |               |
   |-------------|            |---------------- 
      Jura                       Saleve

  EC5 is an ECH which is not implemented yet.
 All the ECs on the left (EC0, EC1, EC2, EC3 are non-existant in real data).
-------------------------------------------------------------------------------------------------------------- 
For RUN1 of testbeam in Oct2016

            EC 0                                   EC 4        ( online-scheme: 2016-LT data)

     PMT 3        PMT 2         PMT 19  (B04-PMT1)     PMT 18     (B03-PMT2)

     PMT 1        PMT 0         PMT 17  (B04-PMT2)      PMT 16    (B03-PMT1)

 -------------------------------------------------------------------------------------------------------------
For RUN2 of testbeam in Nov2016

            EC 0                                   EC 4        ( online-scheme: 2016-LT data)

     PMT 3        PMT 2         PMT 19  (B04-PMT1)     PMT 18     (B03-PMT2-NonExistanct)

     PMT 1        PMT 0         PMT 17  (B04-PMT2)      PMT 16    (B03-PMT1-NonExistant)


--------------------------------------------------------------------------------------------------------------


            EC 1                    EC 5

     PMT 7        PMT 6         PMT 23 (B02-PMT1)    PMT 22   (B06-PMT2)

     PMT 5        PMT 4          PMT 21 (B02-PMT2)    PMT 20   (B06-PMT1)

 

            EC 2                    EC 6

     PMT 11        PMT 10         PMT 27  (B05-PMT1)    PMT 26 (B01-PMT2)

     PMT 9        PMT 8           PMT 25   (B05-PMT2)   PMT 24  (B01-PMT1)


------------------------------------------------------------------------------
For RUN1 of testbeam in Oct2016
            EC 3                    EC 7

     PMT 15        PMT 14         PMT 31     PMT 30   (B07-PMT2)

     PMT 13        PMT 12          PMT 29     PMT 28   (B07-PMT1)


------------------------------------------------------------------------------
For RUN2 of testbeam in Nov2016 
   
            EC 3                    EC 7

     PMT 15        PMT 14         PMT 31 (B03-PMT1)     PMT 30   (B07-PMT2-Nonexistant)

     PMT 13        PMT 12          PMT 29(B03-PMT2)      PMT 28   (B07-PMT1-NonExistant)
-----------------------------------------------




     If EC7 is an EC-H which is not implemented yet. So for now using 4 EC-R



  PMT label for efficiency:
   PMT Number   PMT Label
     0            JA
     1            JA
     2            JB
     3            JB
     4            JA
     5            JA
     6            JB
     7            JB
     8            SA
     9            SA
     10           SB
     11           SB
     12            SA
     13            SA
     14            SB
     15            SB

     16            SA
     17            SA
     18            SB
     19            SB
     20            SA
     21            SA
     22            SB
     23            SB

     24            JA
     25            JA
     26            JB
     27            JB
     28            JA
     29            JA
     30            JB
     31            JB


  PMT rotations

     PMT number       rotation wrt postive Z axis in radians

        0                pi
        1                -pi/2
        2                pi/2
        3                0.0
        4                pi
        5                -pi/2
        6                p/2
        7                 0.0
        8                pi
        9                -pi/2
        10                pi/2
        11                0.0
        12                pi
        13                -pi/2
        14                pi/2 
        15                 0.0
        16                pi
        17                -pi/2
        18                pi/2
        19                0
        20                pi
        21                -pi/2
        22                pi/2
        23                 0.0
        24                pi
        25                -pi/2
        26                pi/2
        27                0
        28                pi
        29                -pi/2
        30                 pi/2
        31                 0.0


    PMT Pixel numbering for PMT 7 as one looks downstream along positive Z axis.
    (Same as Paolo scheme sifted by 1. His scheme starts at 1, whereas here it starts at 0 for C++ arrays).


    63  62  61    .....   56
    55  54  53    .....   48
    47 ...................40
    39 ...................32
    31 ...................24
    23 ...................16
    15 ...................8
    7   6   5  4  3  2  1 0








 */






// testbeam 2016 with layertec samples
#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"



const G4double ECXShiftWithLT = 0.0; // absolute position is NominalXPosition+ECXShift


// The following are in RichTbLTPhCGeometryParameters.hh

//const G4double PhotonDetectorPlaneZGapFromLTDnsSurface=62.0 * CLHEP::mm;

//const G4double PhotonDetectorPlaneZGapFromLTDnsSurface=30.0 * CLHEP::mm;

//const G4double PhotonDetectorPlaneZGapSampleAFromLTDnsSurface=PhotonDetectorPlaneZGapFromLTDnsSurface;
//const G4double PhotonDetectorPlaneZGapSampleBFromLTDnsSurface=62.0 * CLHEP::mm;

//const G4double PhotonDetectorPlaneZWithLTRadiator=  RichTbLTSampleDownstreamSurfaceLocation 
//  + PhotonDetectorPlaneZGapFromLTDnsSurface;


//const G4double PhotonDetectorPlaneZWithLTRadiator= 45.0 * CLHEP::mm;

const G4double PhotonDetectorPlaneZWithLTRadiator= 45.93 * CLHEP::mm;



const G4double PhotonDetectorPlaneXWithLTRadiator=0.0;
const G4double PhotonDetectorPlaneYWithLTRadiator=0.0;



const G4double PhDetSupFrameZLocationWithLT =  PhotonDetectorPlaneZWithLTRadiator
      + PhotonDetPlaneToPhDetSupFrameFrontSurface + 0.5*PhDetSupFrameZSize;



//const G4double  PhDetSupFrameNominalXPosWithLT = 35.0 * CLHEP::mm;
//const G4double  PhDetSupFrameNominalXPosWithLT = 43.0 * CLHEP::mm;

//const G4double  PhDetSupFrameNominalXPosWithLT = 63.0 * CLHEP::mm;

const G4double  PhDetSupFrameNominalXPosWithLT = 80.3 * CLHEP::mm;

const G4double  PhDetSupFrameNominalXPosWithLTRun2 = 53.4 * CLHEP::mm;

const G4double  PhDetSupFrameFinalXPosWithLT = PhDetSupFrameNominalXPosWithLT +  ECXShiftWithLT;
const G4double  PhDetSupFrameFinalXPosWithLTRun2 = PhDetSupFrameNominalXPosWithLTRun2 +  ECXShiftWithLT;

const G4double PhDetSupFrameFinalYPosWithLT = 0.0 * CLHEP::mm;

const G4double PhDetSupFrameXLocationWithLTec[] = {PhDetSupFrameFinalXPosWithLT  ,-1*PhDetSupFrameFinalXPosWithLT };

const G4double PhDetSupFrameXLocationWithLTecRun2[] = {PhDetSupFrameFinalXPosWithLTRun2  ,-1*PhDetSupFrameFinalXPosWithLTRun2 };

const G4double PhDetSupFrameYLocationWithLTec[] =  { PhDetSupFrameFinalYPosWithLT ,PhDetSupFrameFinalYPosWithLT };





// Now for EC locations in PhDetSupFrame with LT configuration
const G4double ECLTYGap = 0.3 * CLHEP::mm;
const G4double ECYLocationShiftSingle = 0.5*ECLTYGap + 0.5*ECYSize;
const G4double ECYLocationShiftDouble = 1.5*ECLTYGap + 1.5*ECYSize;

const G4double  ECXLocationInSupFrame16LT[] =  {  0.0 * CLHEP::mm, 0.0 * CLHEP::mm, 0.0 * CLHEP::mm, 0.0 * CLHEP::mm};
const G4double  ECYLocationInSupFrame16LT[] ={ ECYLocationShiftDouble, ECYLocationShiftSingle,
                                              -1.0*ECYLocationShiftSingle, -1.0*ECYLocationShiftDouble   };




const G4double ECSupportXLocationInSupFrame16LT []={  0.0 * CLHEP::mm, 0.0 * CLHEP::mm,0.0 * CLHEP::mm, 0.0 * CLHEP::mm };
const G4double ECSupportYLocationInSupFrame16LT []={ ECYLocationShiftDouble, ECYLocationShiftSingle,
                                                     -1.0*ECYLocationShiftSingle, -1.0*ECYLocationShiftDouble   };


    


//Now for PMT rotations in EC in 2016 with LT configuration

const G4double RichTbPmtRotZInEC16LT[]  =  
   { CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad,  CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad,  
     CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad,  CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad, 
     CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad,  CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad,  
     CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad,  CLHEP::pi * CLHEP::rad, -0.5* CLHEP::pi * CLHEP::rad ,0.5* CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad
   };

  


const G4int RichTbEcNumFromPmtNum [] = {0,0,0,0, 1,1,1,1, 2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7  };


#endif // INCLUDE_RICHTBUPGRADEPMTSUPPORTFRAMEGEOMETRYPARAMETERSLT_HH
