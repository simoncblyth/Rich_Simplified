#ifndef INCLUDE_RICHTBMIRRORPARABOLA_HH 
#define INCLUDE_RICHTBMIRRORPARABOLA_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

#include "RichTbContainerVesselBox.hh"

/** @class RichTbMirrorParabola RichTbMirrorParabola.hh include/RichTbMirrorParabola.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-17
 */

class RichTbMirrorParabola {
public: 
  /// Standard constructor
  RichTbMirrorParabola(RichTbContainerVesselBox* aBox ); 

  virtual ~RichTbMirrorParabola( ); ///< Destructor


  void constructRichMirrParabola();
  
  G4LogicalVolume* getRichTbMirrParabolaLVol(){
     return  RichTbMirrParabolaLVol;
  }
  G4VPhysicalVolume * getRichTbMirrParabolaPVol() 
  {  return  RichTbMirrParabolaPVol;}
  


protected:

private:

  RichTbContainerVesselBox* aCVessel;
  G4LogicalVolume      *  RichTbMirrParabolaLVol;
  G4VPhysicalVolume    *  RichTbMirrParabolaPVol;
  

};
#endif // INCLUDE_RICHTBMIRRORPARABOLA_HH
