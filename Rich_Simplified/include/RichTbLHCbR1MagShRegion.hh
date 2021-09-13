#ifndef RichTbLHCbR1MagShRegion_h
#define RichTbLHCbR1MagShRegion_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbRich1SubMaster.hh"

class RichTbLHCbR1MagShRegion {
 public:

  RichTbLHCbR1MagShRegion(RichTbLHCbRich1SubMaster* rTbLHCbR1SubMaster );

  virtual ~RichTbLHCbR1MagShRegion();

  G4LogicalVolume * getRichTbLHCbR1MagShRegionLogicalVolume(){
     return rTbR1MagShRegionLVol;}
  G4VPhysicalVolume* getRichTbLHCbR1MagShRegionPhysicalVolume() {
     return rTbR1MagShRegionPVol;}
  void constructLbR1MagShReg();

 private:
  
  RichTbLHCbRich1SubMaster* mTbLHCbR1SubMaster;  
  G4LogicalVolume*  rTbR1MagShRegionLVol;
  G4VPhysicalVolume* rTbR1MagShRegionPVol;
 
};


#endif                          /*RichTbLHCbR1MagShRegion_h */
