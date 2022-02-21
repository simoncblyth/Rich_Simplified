#ifndef RichTbLHCbR1FlatMirror_h
#define RichTbLHCbR1FlatMirror_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbRich1SubMaster.hh"

class RichTbLHCbR1FlatMirror {
public:
  RichTbLHCbR1FlatMirror(RichTbLHCbRich1SubMaster* rTbLHCbR1SubMaster, bool tinyFlatMirror );

  virtual ~RichTbLHCbR1FlatMirror();
  G4LogicalVolume * getRichTbLHCbR1FlatMirrorLogicalVolume(){
     return rTbR1FlatMirrorLVol;}
  G4VPhysicalVolume* getRichTbLHCbR1FlatMirrorPhysicalVolume() {
     return rTbR1FlatMirrorPVol;}
  void constructLbR1FlatMirror();

  private:
  bool m_tinyFlatMirror;
  RichTbLHCbRich1SubMaster* mTbLHCbR1SubMaster;

  G4LogicalVolume*  rTbR1FlatMirrorLVol;
  G4VPhysicalVolume* rTbR1FlatMirrorPVol;

};


#endif                          /*RichTbLHCbR1FlatMirror_h */
