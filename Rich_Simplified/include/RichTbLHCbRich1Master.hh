#ifndef RichTbLHCbRich1Master_h
#define RichTbLHCbRich1Master_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers    
#include "RichTbMaterial.hh"
#include "RichTbLHCbExptHall.hh"

class RichTbLHCbRich1Master {
public:
  RichTbLHCbRich1Master(RichTbLHCbExptHall* rTbLHCbExptHall);
  virtual ~RichTbLHCbRich1Master();
  G4LogicalVolume * getRichTbLHCbRich1MasterLogicalVolume(){ 
     return rTbRich1MasterLVol;}
  G4VPhysicalVolume* getRichTbLHCbRich1MasterPhysicalVolume() {
     return rTbRich1MasterPVol;}
  void constructLbR1Master();
  private:

  RichTbLHCbExptHall* mTbLHCbExptHall;
  G4LogicalVolume*  rTbRich1MasterLVol;
  G4VPhysicalVolume* rTbRich1MasterPVol;
 
};


#endif                          /*RichTbLHCbRich1Master_h */
