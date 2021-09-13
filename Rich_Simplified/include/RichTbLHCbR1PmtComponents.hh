#ifndef RichTbLHCbR1PMTCOMPONENTS_h
#define RichTbLHCbR1PMTCOMPONENTS_h 1
// Geant 4 headers
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
// local headers
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1Pmt.hh"
class RichTbLHCbR1PmtComponents {
public:
  RichTbLHCbR1PmtComponents(RichTbLHCbR1Pmt* rTbR1Pmt );
  virtual ~RichTbLHCbR1PmtComponents();
  G4LogicalVolume * getRichTbLbR1PmtSubMasterLogicalVolume() {return rTbR1PmtSubMasterLVol; }
  G4LogicalVolume * getRichTbLbR1PmtAnodeLogicalVolume() {return rTbR1PmtAnodeLVol; }
  G4LogicalVolume * getRichTbLbR1PmtQuartzLogicalVolume() {return rTbR1PmtQuartzLVol; }
  G4LogicalVolume * getRichTbLbR1PmtPhCathLogicalVolume() {return rTbR1PmtPhCathLVol; }
  G4LogicalVolume * getRichTbLbR1PmtSideEnvelopeLogicalVolume() {return rTbR1PmtSideEnvelopeLVol; }
  G4LogicalVolume * getRichTbLbR1PmtFrontRingLogicalVolume() {return rTbR1PmtFrontRingLVol; }
  G4VPhysicalVolume* getRichTbLbR1PmtSubMasterPhysicalVolume () {return rTbR1PmtSubMasterPVol ;}

  //  G4VPhysicalVolume* getRichTbLbR1PmtSubMasterPhysicalVolume(G4int ip, G4int iec, G4int iM ) 
  // {return rTbR1PmtSubMasterPVol [iM] [iec] [ip] ; }
  G4VPhysicalVolume* getRichTbLbR1PmtAnodePhysicalVolume() {return rTbR1PmtAnodePVol; }
  G4VPhysicalVolume* getRichTbLbR1PmtQuartzPhysicalVolume() {return rTbR1PmtQuartzPVol; }
  G4VPhysicalVolume* getRichTbLbR1PmtPhCathPhysicalVolume() {return rTbR1PmtPhCathPVol; }
  G4VPhysicalVolume* getRichTbLbR1PmtPmtSideEnvelopePhysicalVolume() {return rTbR1PmtSideEnvelopePVol; }
  G4VPhysicalVolume* getRichTbLbR1PmtPmtFrontRingPhysicalVolume() {return rTbR1PmtFrontRingPVol; }
  void constructR1PmtSubMaster();
  void constructR1PmtAnode();
  void constructR1PmtComp();
  void constructR1PmtAnodePixel();




private:
  RichTbLHCbR1Pmt* mTbR1Pmt;
  G4LogicalVolume * rTbR1PmtSubMasterLVol;
  G4LogicalVolume * rTbR1PmtAnodeLVol;
  G4LogicalVolume * rTbR1PmtQuartzLVol;
  G4LogicalVolume * rTbR1PmtPhCathLVol;
  G4LogicalVolume * rTbR1PmtSideEnvelopeLVol;
  G4LogicalVolume * rTbR1PmtFrontRingLVol;
  G4LogicalVolume * rTbR1PmtPixelLVol;


  //  std::vector<std::vector< std::vector< G4VPhysicalVolume* > > > rTbR1PmtSubMasterPVol;
  G4VPhysicalVolume* rTbR1PmtSubMasterPVol;
  G4VPhysicalVolume* rTbR1PmtAnodePVol;
  G4VPhysicalVolume* rTbR1PmtQuartzPVol;
  G4VPhysicalVolume* rTbR1PmtPhCathPVol;
  G4VPhysicalVolume* rTbR1PmtSideEnvelopePVol;
  G4VPhysicalVolume* rTbR1PmtFrontRingPVol;
  std::vector< G4VPhysicalVolume* > rTbR1PmtPixelPVol;

};

#endif                          /*RichTbLHCbR1PMTCOMPONENTS_h */
