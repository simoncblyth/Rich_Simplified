#ifndef INCLUDE_RICHTBLARGEMIRRORPARABOLA_HH 
#define INCLUDE_RICHTBLARGEMIRRORPARABOLA_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

#include "RichTbContainerVesselBox.hh"

/** @class RichTbLargeMirrorParabola RichTbLargeMirrorParabola.hh include/RichTbLargeMirrorParabola.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-06-06
 */
class RichTbLargeMirrorParabola {
public: 
  /// Standard constructor
  RichTbLargeMirrorParabola( RichTbContainerVesselBox* aVessel ); 

  virtual ~RichTbLargeMirrorParabola( ); ///< Destructor

  void constructRichTbLargeMirrorParabola();
  
  G4LogicalVolume * getRichTbLargeMirrorParabolaLVol()     
  {  return RichTbLargeMirrorParabolaLVol;}
  
  G4VPhysicalVolume * getRichTbLargeMirrorParabolaPVol() 
  {  return RichTbLargeMirrorParabolaPVol; }
  

protected:

private:
 RichTbContainerVesselBox*   aCVessel;
 G4LogicalVolume      *  RichTbLargeMirrorParabolaLVol;
 G4VPhysicalVolume    *  RichTbLargeMirrorParabolaPVol;
  
};
#endif // INCLUDE_RICHTBLARGEMIRRORPARABOLA_HH
