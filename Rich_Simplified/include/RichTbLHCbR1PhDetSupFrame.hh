#ifndef RichTbLHCbR1PhDetSupFrame_h
#define RichTbLHCbR1PhDetSupFrame_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1MagShRegion.hh"


class RichTbLHCbR1PhDetSupFrame {
public:
  RichTbLHCbR1PhDetSupFrame(RichTbLHCbR1MagShRegion* rMagShRegion);
  virtual ~RichTbLHCbR1PhDetSupFrame();
  G4LogicalVolume * getRichTbLHCbR1PhDetSupFrameLogicalVolume(){
     return rTbR1PhDetSupFrameLVol;}
  G4VPhysicalVolume* getRichTbLHCbR1PhDetSupFramePhysicalVolume() {
     return rTbR1PhDetSupFramePVol;}
  void constructPhDetSupFrame();
  void constructPhDetModuleBackPl();

  G4LogicalVolume * getRichTbLbR1ModuleBackPlLVol () {return rTbLbR1ModuleBackPlLVol ; }
  G4VPhysicalVolume* getRichTbLbR1ModuleBackPlPVol ( )     {return rTbLbR1ModuleBackPlPVol ; }

  private:

  RichTbLHCbR1MagShRegion* mMagShRegion;
  G4LogicalVolume*  rTbR1PhDetSupFrameLVol;
  G4VPhysicalVolume* rTbR1PhDetSupFramePVol;
  G4LogicalVolume * rTbLbR1ModuleBackPlLVol ;
  G4VPhysicalVolume*  rTbLbR1ModuleBackPlPVol;

};


#endif                          /*RichTbLHCbR1PhDetSupFrame_h */
