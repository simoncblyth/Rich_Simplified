#ifndef RichTbLHCbR1QW_h
#define RichTbLHCbR1QW_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1MagShRegion.hh"

class RichTbLHCbR1QW {
public:
  RichTbLHCbR1QW(RichTbLHCbR1MagShRegion * rTbR1MagShRegion );
  virtual ~RichTbLHCbR1QW();
  G4LogicalVolume * getRichTbLHCbR1QWLogicalVolume(){
     return rTbR1QWLVol;}
  G4VPhysicalVolume* getRichTbLHCbR1QWPhysicalVolume() {
     return rTbR1QWPVol;}
  void constructR1QW();

  private:

  RichTbLHCbR1MagShRegion * mTbR1MagShRegion;

  G4LogicalVolume*  rTbR1QWLVol;
  G4VPhysicalVolume* rTbR1QWPVol;

};


#endif                          /*RichTbLHCbR1QW_h */
