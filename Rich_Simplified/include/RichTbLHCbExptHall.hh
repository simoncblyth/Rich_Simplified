#ifndef RichTbLHCbExptHall_h
#define RichTbLHCbExptHall_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers    
#include "RichTbMaterial.hh"

class RichTbLHCbExptHall {
public:
  RichTbLHCbExptHall();
  virtual ~RichTbLHCbExptHall();

    G4LogicalVolume *getRichTbLHCbExptHallLogicalVolume() {
        return rTbLHCbExptHallLVol;
    }
    G4VPhysicalVolume *getRichTbLHCbExptHallPhysicalVolume() {
        return rTbLHCbExptHallPVol;
    }

  private:
    G4LogicalVolume*   rTbLHCbExptHallLVol;
    G4VPhysicalVolume* rTbLHCbExptHallPVol;

  
};



#endif                          /*RichTbExptLHCbExptHall_h */
