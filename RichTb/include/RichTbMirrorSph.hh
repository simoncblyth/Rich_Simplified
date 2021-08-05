#ifndef INCLUDE_RICHTBMIRRORSPH_HH 
#define INCLUDE_RICHTBMIRRORSPH_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

#include "RichTbContainerVesselBox.hh"

/** @class RichTbMirrorSph RichTbMirrorSph.hh include/RichTbMirrorSph.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-23
 */
class RichTbMirrorSph {
public: 
  /// Standard constructor
  RichTbMirrorSph(RichTbContainerVesselBox* aVessel  ); 

  virtual ~RichTbMirrorSph( ); ///< Destructor

  void constructRichMirrSph();
  
  G4LogicalVolume* getRichTbMirrSphLVol()
  {  return RichTbMirrSphLVol;}
  
  G4VPhysicalVolume * getRichTbMirrSphPVol() 
  {  return RichTbMirrSphPVol;}
  

protected:

private:

  RichTbContainerVesselBox* aCVessel;
  G4LogicalVolume      *  RichTbMirrSphLVol;
  G4VPhysicalVolume    *  RichTbMirrSphPVol;
  

};
#endif // INCLUDE_RICHTBMIRRORSPH_HH
