#ifndef RichTbLHCbR1PMT_h
#define RichTbLHCbR1PMT_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1EC.hh"
class RichTbLHCbR1Pmt {

public:
  RichTbLHCbR1Pmt(RichTbLHCbR1EC * rTbR1EC );
  virtual ~RichTbLHCbR1Pmt();

  // G4LogicalVolume * getRichTbLbR1PmtLogicalVolume(G4int iP, G4int iEC, G4int iM) 
  //           { return rTbLbR1PmtLVol [iM] [iEC] [iP]   ; }

  G4LogicalVolume * getRichTbLbR1PmtLogicalVolume() {return rTbLbR1PmtLVol ;}

  G4VPhysicalVolume* getRichTbLbR1PmtPhysicalVolume(G4int iP, G4int iEC, G4int iM) 
             { return rTbLbR1PmtPVol [iM] [iEC] [iP]   ; }
  void constructLbR1Pmt();

private:
  RichTbLHCbR1EC * mTbR1EC;
  //  std::vector<std::vector< std::vector<G4LogicalVolume * > > > rTbLbR1PmtLVol;
  G4LogicalVolume * rTbLbR1PmtLVol;
  std::vector<std::vector< std::vector< G4VPhysicalVolume* > > > rTbLbR1PmtPVol;
    
};

#endif                          /*RichTbLHCbR1PMT_h */
