//This is the definition of the LHCb RICH Testbeam Detector Construction
// To use with testing for Opticks
//Author SE  1-3-2021
//
#ifndef RichTbOpticksDetectorConstruction_h
#define RichTbOpticksDetectorConstruction_h 1
#include "globals.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbExptHall.hh"
#include "RichTbLHCbRich1Master.hh"
#include "RichTbLHCbRich1SubMaster.hh"
#include "RichTbLHCbR1SphMirror.hh"
#include "RichTbLHCbR1FlatMirror.hh"
#include "RichTbLHCbR1QW.hh"
#include "RichTbLHCbR1PhDetSupFrame.hh"
#include "RichTbLHCbR1MagShRegion.hh"
#include "RichTbLHCbR1Module.hh"
#include "RichTbLHCbR1EC.hh"
#include "RichTbLHCbR1Pmt.hh"
#include "RichTbLHCbR1PmtComponents.hh"
#include "RichTbLHCbSurface.hh"

#include "RichTbLHCbROGeometry.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "RichTbRunConfig.hh"
#include "G4SDManager.hh"
#include "RichTbGraphics.hh"

class RichTbOpticksDetectorConstruction:public G4VUserDetectorConstruction {
 
 public:

    RichTbOpticksDetectorConstruction();
    virtual ~RichTbOpticksDetectorConstruction();
    G4VPhysicalVolume *Construct() override;

    RichTbLHCbExptHall* getRichTbLHCbExptHall () {return rTbLHCbExptHall; }
    RichTbLHCbRich1Master* getRichTbLHCbRich1Master () {return rTbRich1Master; }
    RichTbLHCbRich1SubMaster* getRichTbLHCbRich1SubMaster() {return rTbRich1SubMaster; }
    RichTbLHCbR1SphMirror* getRichTbLHCbR1SphMirror() {return rTbR1SphMirror; }
    RichTbLHCbR1FlatMirror* getRichTbLHCbR1FlatMirror() {return rTbR1FlatMirror; }
    RichTbLHCbR1QW* getRichTbLHCbR1QW() {return rTbR1QW; }
    RichTbLHCbR1PhDetSupFrame* getRichTbLHCbR1PhDetSupFrame() {return rTbR1PhDetSupFrame; }
    RichTbLHCbR1MagShRegion* getRichTbLHCbR1MagShRegion() {return rTbR1MagShRegion ;}
  RichTbLHCbR1Module * getRichTbLHCbR1Module() {return rTbR1Module; }
  RichTbLHCbR1EC * getRichTbLHCbR1EC() {return rTbR1EC; }
  RichTbLHCbR1Pmt * getRichTbLHCbR1Pmt() {return rTbR1Pmt; }
  RichTbLHCbR1PmtComponents* getRichTbLHCbR1PmtComponents()
                     {return rTbR1PmtComponents;}

    void ResetStdVol();

  private:
  RichTbLHCbExptHall*  rTbLHCbExptHall;
  RichTbLHCbRich1Master* rTbRich1Master;
  RichTbLHCbRich1SubMaster* rTbRich1SubMaster;
  RichTbLHCbR1SphMirror* rTbR1SphMirror;
  RichTbLHCbR1FlatMirror* rTbR1FlatMirror;
  
  RichTbLHCbR1QW* rTbR1QW;
  RichTbLHCbR1PhDetSupFrame* rTbR1PhDetSupFrame; 
  RichTbLHCbR1MagShRegion* rTbR1MagShRegion;
  RichTbLHCbR1Module * rTbR1Module;
  RichTbLHCbR1EC * rTbR1EC;
  RichTbLHCbR1Pmt * rTbR1Pmt;
  RichTbLHCbR1PmtComponents* rTbR1PmtComponents;
  RichTbLHCbSurface * rTbR1Surface;
  RichTbLHCbROGeometry * rTbR1ROGeometry;

};
#endif                          /*RichTbOpticksDetectorConstruction_h */
