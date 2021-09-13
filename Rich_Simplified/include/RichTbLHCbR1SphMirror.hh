#ifndef RichTbLHCbR1SphMirror_h
#define RichTbLHCbR1SphMirror_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbRich1SubMaster.hh"

class RichTbLHCbR1SphMirror {
public:
  RichTbLHCbR1SphMirror(RichTbLHCbRich1SubMaster* rTbLHCbR1SubMaster  );
  virtual ~RichTbLHCbR1SphMirror();
  G4LogicalVolume * getRichTbLHCbR1SphMirrorLogicalVolume(){
     return rTbR1SphMirrorLVol;}
  G4VPhysicalVolume* getRichTbLHCbR1SphMirrorPhysicalVolume() {
     return rTbR1SphMirrorPVol;}
  void constructLbR1SphMirror();

  private:
  RichTbLHCbRich1SubMaster* mTbLHCbR1SubMaster; 
  G4LogicalVolume*  rTbR1SphMirrorLVol;
  G4VPhysicalVolume* rTbR1SphMirrorPVol;

};


#endif                          /*RichTbLHCbR1SphMirror_h */
