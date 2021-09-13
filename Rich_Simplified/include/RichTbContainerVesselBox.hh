#ifndef INCLUDE_RICHTBCONTAINERVESSELBOX_HH 
#define INCLUDE_RICHTBCONTAINERVESSELBOX_HH 1

// Include files
// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"

/** @class RichTbContainerVesselBox RichTbContainerVesselBox.hh include/RichTbContainerVesselBox.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-14
 */
class RichTbContainerVesselBox {
public: 
  /// Standard constructor
  RichTbContainerVesselBox(RichTbHall* rTbHall ); 

  virtual ~RichTbContainerVesselBox( ); ///< Destructor

  void constructRichTbContainerVesselBox();
  
  G4LogicalVolume* getRichTbContainerVesselBoxLVol() 
  {    return  RichTbContainerVesselBoxLVol;}
  
  G4VPhysicalVolume* getRichTbContainerVesselBoxPVol() 
  {  return RichTbContainerVesselBoxPVol;}
  


protected:

private:

  RichTbHall* aRTbHall;
  G4LogicalVolume* RichTbContainerVesselBoxLVol;
  G4VPhysicalVolume* RichTbContainerVesselBoxPVol; 
 
 
};
#endif // INCLUDE_RICHTBCONTAINERVESSELBOX_HH
