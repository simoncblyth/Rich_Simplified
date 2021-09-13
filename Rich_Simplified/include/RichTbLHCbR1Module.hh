#ifndef RichTbLHCbR1Module_h
#define RichTbLHCbR1Module_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1PhDetSupFrame.hh"

class RichTbLHCbR1Module {

public:
  RichTbLHCbR1Module(RichTbLHCbR1PhDetSupFrame * rPhDetSupFrame );
  virtual ~RichTbLHCbR1Module();
  G4LogicalVolume * getRichTbLbR1ModuleLogicalVolume(G4int aModuleNum ) { return rTbLbR1ModuleLVol[aModuleNum] ;}
  G4VPhysicalVolume* getRichTbLbR1ModulePhysicalVolume(G4int aModuleNum) { return rTbLbR1ModulePVol[aModuleNum]; }
  G4int GetModuleNumRC ( G4int aMCol, G4int aMRow );

  G4VPhysicalVolume* getRichTbLbR1ModulePhysVolRC (G4int aMCol, G4int aMRow) {
    return rTbLbR1ModulePVol[  GetModuleNumRC (aMCol,aMRow)] ;}
  void constructR1Module();
 


private:

  RichTbLHCbR1PhDetSupFrame * mPhDetSupFrame ;
  std::vector<G4LogicalVolume *>  rTbLbR1ModuleLVol ;
  //  G4LogicalVolume * rTbLbR1ModuleLVol;
  std::vector< G4VPhysicalVolume* > rTbLbR1ModulePVol;
 


  
};



#endif                          /*RichTbLHCbR1Module_h */
