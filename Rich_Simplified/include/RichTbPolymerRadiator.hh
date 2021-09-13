#ifndef INCLUDE_RICHTBPOLYMERRADIATOR_HH 
#define INCLUDE_RICHTBPOLYMERRADIATOR_HH 1

// Include files

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

#include "RichTbContainerVesselBox.hh"

/** @class RichTbPolymerRadiator RichTbPolymerRadiator.hh include/RichTbPolymerRadiator.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-15
 */

class RichTbPolymerRadiator {
public: 
  /// Standard constructor
  RichTbPolymerRadiator( RichTbContainerVesselBox* aVessel); 

  virtual ~RichTbPolymerRadiator( ); ///< Destructor

  void constructPolymerPlusGeometry();
  
  G4LogicalVolume* getRichTbPolymerPlusLVol() 
  {  return RichTbPolymerPlusLVol;}

  G4VPhysicalVolume *  getRichTbPolymerPlusPVol()
  {  return  RichTbPolymerPlusPVol;}
  


protected:

private:


  RichTbContainerVesselBox* aCVessel;
  
  G4LogicalVolume   *   RichTbPolymerPlusLVol;
  G4VPhysicalVolume *   RichTbPolymerPlusPVol;
  

};
#endif // INCLUDE_RICHTBPOLYMERRADIATOR_HH
