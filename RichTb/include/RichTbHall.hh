#ifndef RichTbHall_h
#define RichTbHall_h 1

// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

// local headers
#include "RichTbMaterial.hh"

class RichTbHall {

  public:
    RichTbHall();
    virtual ~ RichTbHall();

    G4LogicalVolume *getRichTbHallLogicalVolume() {
        return RichTbHallLVol;
    }
    G4VPhysicalVolume *getRichTbHallPhysicalVolume() {
        return RichTbHallPVol;
    }

  private:
    G4LogicalVolume*  RichTbHallLVol;
    G4VPhysicalVolume* RichTbHallPVol;
};

#endif                          /*RichTbHall_h */
