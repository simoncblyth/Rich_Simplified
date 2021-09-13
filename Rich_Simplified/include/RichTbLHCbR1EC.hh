#ifndef RichTbLHCbR1EC_h
#define RichTbLHCbR1EC_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1Module.hh"

class RichTbLHCbR1EC {
public:
  RichTbLHCbR1EC(RichTbLHCbR1Module * rTbR1Module );
  virtual ~RichTbLHCbR1EC();
  G4LogicalVolume * getRichTbLbR1ECLogicalVolume(G4int aENum, G4int aMNum  ) 
                      {return rTbLbR1ECLVol[aMNum] [aENum]     ; }
  G4VPhysicalVolume* getRichTbLbR1ECPhysicalVolume(G4int aENum, G4int aMNum )
                      {return rTbLbR1ECPVol [aMNum] [aENum];}
  void constructR1LbEC();
  

private:
 RichTbLHCbR1Module * mTbR1Module;
 std::vector< std::vector<G4LogicalVolume *> > rTbLbR1ECLVol;
 std::vector< std::vector< G4VPhysicalVolume* > > rTbLbR1ECPVol;


};






#endif                          /*RichTbLHCbR1EC_h */
