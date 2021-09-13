#ifndef RichTbLHCbRich1SubMaster_h
#define RichTbLHCbRich1SubMaster_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers    
#include "RichTbMaterial.hh"
#include "RichTbLHCbRich1Master.hh"


class RichTbLHCbRich1SubMaster {
public:
  RichTbLHCbRich1SubMaster(RichTbLHCbRich1Master* rTbLHCbR1Master );
  virtual ~RichTbLHCbRich1SubMaster();
  G4LogicalVolume * getRichTbLHCbRich1SubMasterLogicalVolume(){ 
     return rTbRich1SubMasterLVol;}
  G4VPhysicalVolume* getRichTbLHCbRich1SubMasterPhysicalVolume() {
     return rTbRich1SubMasterPVol;}
  void constructLbR1SubMaster();

  private:

  RichTbLHCbRich1Master* mTbLHCbR1Master;

  G4LogicalVolume*  rTbRich1SubMasterLVol;
  G4VPhysicalVolume* rTbRich1SubMasterPVol;
 
};


#endif                          /*RichTbLHCbRich1SubMaster_h */
