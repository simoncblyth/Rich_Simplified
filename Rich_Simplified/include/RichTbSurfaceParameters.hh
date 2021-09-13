// $Id: $
#ifndef INCLUDE_RICHTBSURFACEPARAMETERS_HH 
#define INCLUDE_RICHTBSURFACEPARAMETERS_HH 1

// Include files

#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"



static G4int NumPhotMirrorReflectBins=403;

// in the above 401 is from the file and 2 bins added at the ends.
// depending upon the wavelength range of measurements.
// this is redefined while reading the file. 


const G4double PhotonMirrReflWavelengthUnits= 1.0 * CLHEP::nanometer;
// for testbem in 2004 a file is read with mirror reflectivity values.

//const G4double  PhotonWavelengthMirrRefl[] =
//
//
//  {140.0,145.0,150.0,155.0,160.0,165.0,170.0,
//   175.0,180.0,185.0,190.0,195.0,200.0,205.0,
//   210.0,215.0,220.0,225.0,230.0,235.0,240.0,
//   245.0,250.0,255.0,260.0,265.0,270.0,275.0,
//   280.0,285.0,290.0,295.0,300.0,305.0,310.0,
//   315.0,320.0,325.0,330.0,335.0,340.0,345.0,
//   350.0,355.0,360.0,400.0,900.0,1000.0,1200.0
//  };
//
//const G4double MirrorReflectivity[]=
//  {51.34108,53.09734,50.90585,49.3188,66.75388,
//   68.24143,70.30895,72.34739,73.85167,75.23763,
//   77.33105,79.52776,81.00301,82.8635,84.10011,
//   85.58822,86.15829,86.95603,87.50696,88.2192,
//   87.25798,87.49368,87.3097,87.02457,87.04436,
//   85.82494,86.69911,85.34895,85.38953,85.26953,
//   85.40186,84.80862,84.66154,84.55714,84.52075,
//   84.50029,83.35554,83.39278,84.26382,84.4191,
//   84.8813,85.16248,85.06534,86.16501,86.36691,
//   86.36691,86.36691,86.36691,86.36691
//  };



   
#endif // INCLUDE_RICHTBSURFACEPARAMETERS_HH
