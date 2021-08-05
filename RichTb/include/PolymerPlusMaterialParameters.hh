#ifndef INCLUDE_POLYMERPLUSMATERIALPARAMETERS_HH 
#define INCLUDE_POLYMERPLUSMATERIALPARAMETERS_HH 1

// Include files

#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"


/** @class PolymerPlusMaterialParameters PolymerPlusMaterialParameters.hh include/PolymerPlusMaterialParameters.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-15
 */

const G4int PolymerPlusMatRefIndNumBins= 30;
const G4int PolymerPlusMatProdRefIndNumBins= 15;
const G4double PolymerPlusWavelengthUnits = 1.0 * CLHEP::nanometer ;

const G4double PolymerPlusMatWavelengthValues[]=
{200,300,344,388,432,476,520,564,608,652,696,
		740,784,828,872,916,960,1004,1048,1092,1136,
 1180,1224,1268,1312,1356,1400,1444,1488,1532};


const G4double PolymerPlusMatProdRefIndWavelengthValues[]=
  {200,300,344,388,432,476,520,564,608,652,696, 740,784,828, 872};


//const G4double PolymerPlusMatRefIndexValues [] =
//  {1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,
//   1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,
//   1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,
//   1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978 };

  
//const G4double PolymerPlusMatProdRefIndexValues [] =
//  {1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,
//   1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978, 1.4921978,1.4921978};


// for now using the nitrogen values for the RefIndex (used for refraction etc. Using the bigger values for the
// chenrekov production.

const G4double PolymerPlusMatRefIndexValues [] =
  { 1.00029, 1.00029,  1.00029, 1.00029, 1.00029, 1.00029,  1.00029, 1.00029, 1.00029, 1.00029,
    1.00029, 1.00029,  1.00029, 1.00029, 1.00029, 1.00029,  1.00029, 1.00029, 1.00029, 1.00029,
    1.00029, 1.00029,  1.00029, 1.00029, 1.00029, 1.00029,  1.00029, 1.00029, 1.00029, 1.00029 
  };

  


const G4double PolymerPlusMatProdRefIndexValues [] =
  { 2.973, 2.973,  2.973, 2.973,2.973, 2.973,  2.973, 2.973,2.973, 2.973, 2.973, 2.973,
    2.973, 2.973,  2.973  };

  

const G4double PolymerPlusMatAbsorptionValues[]=
  {1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,
		1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,
    1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32,1.E32 };

// 


#endif // INCLUDE_POLYMERPLUSMATERIALPARAMETERS_HH
