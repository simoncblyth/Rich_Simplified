#ifndef INCLUDE_RICHTBUPGRADELTPHC_H 
#define INCLUDE_RICHTBUPGRADELTPHC_H 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystalMaster.hh"




/** @class RichTbUpgradeLTPhC RichTbUpgradeLTPhC.hh include/RichTbUpgradeLTPhC.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2016-10-07
 */
class RichTbUpgradeLTPhC {
public: 
  /// Standard constructor
  RichTbUpgradeLTPhC(RichTbUpgradeCrystalMaster* rTbCrystalMaster ); 

  virtual ~RichTbUpgradeLTPhC( ); ///< Destructor
  void constructRichTbUpgradeLTSampleTypeA();
  void constructRichTbUpgradeLTSampleTypeB();
  void constructRichTbUpgradeLTFilterTypeA();
  void constructRichTbUpgradeLTFilterTypeB();

  void constructRichTbUpgradeLTFilterTypeATestForMapfile();

  void constructRichTbUpgradeLTSampleTypeAMaster();
  void constructRichTbUpgradeLTSampleTypeBMaster();


  G4LogicalVolume*  getRichTbUpgradeLTPhCSampleALVol() 
  {  return  RichTbUpgradeLTPhCSampleALVol;}
  G4LogicalVolume*  getRichTbUpgradeLTPhCSampleBLVol() 
  {  return  RichTbUpgradeLTPhCSampleBLVol;}
  
  
  G4LogicalVolume*  getRichTbUpgradeLTPhCLayerALVol() 
  {    return  RichTbUpgradeLTPhCLayerALVol;}

  G4LogicalVolume*  getRichTbUpgradeLTPhCLayerBLVol() 
  {    return  RichTbUpgradeLTPhCLayerBLVol;}
  
  G4VPhysicalVolume* getRichTbUpgradeLTPhCSampleAPVol() 
  {    return  RichTbUpgradeLTPhCSampleAPVol;}
  G4VPhysicalVolume* getRichTbUpgradeLTPhCSampleBPVol() 
  {    return  RichTbUpgradeLTPhCSampleBPVol;}
  

  G4VPhysicalVolume* getRichTbUpgradeLTPhCLayerAPVol()
  {    return RichTbUpgradeLTPhCLayerAPVol;}
  G4VPhysicalVolume* getRichTbUpgradeLTPhCLayerBPVol()
  {    return RichTbUpgradeLTPhCLayerBPVol;}
  

  G4LogicalVolume*  getRichTbUpgradeLTFilterALVol()
  {  return  RichTbUpgradeLTFilterALVol;}
  G4LogicalVolume*  getRichTbUpgradeLTFilterBLVol()
  {  return  RichTbUpgradeLTFilterBLVol;}
  
  G4VPhysicalVolume* getRichTbUpgradeLTFilterAPVol()
  {  return RichTbUpgradeLTFilterAPVol;}
  G4VPhysicalVolume* getRichTbUpgradeLTFilterBPVol()
  {  return RichTbUpgradeLTFilterBPVol;}
  

  G4LogicalVolume* getRichTbUpgradeLTSampleAMasterLVol() 
  {return RichTbUpgradeLTSampleAMasterLVol;}
  
  G4LogicalVolume* getRichTbUpgradeLTSampleBMasterLVol() 
  {return RichTbUpgradeLTSampleBMasterLVol;}
 
  G4VPhysicalVolume* getRichTbUpgradeLTSampleAMasterPVol()
  { return RichTbUpgradeLTSampleAMasterPVol;}
  
  G4VPhysicalVolume* getRichTbUpgradeLTSampleBMasterPVol()
  { return RichTbUpgradeLTSampleBMasterPVol;}

  G4LogicalVolume* getRichTbUpgradeLTFilterGlassALVol() 
  {return RichTbUpgradeLTFilterGlassALVol;}

  G4LogicalVolume* getRichTbUpgradeLTFilterGlassBLVol() 
  {return RichTbUpgradeLTFilterGlassBLVol;}
  
  G4VPhysicalVolume* getRichTbUpgradeLTFilterGlassAPVol()
  {  return RichTbUpgradeLTFilterGlassAPVol;}

  G4VPhysicalVolume* getRichTbUpgradeLTFilterGlassBPVol()
  {  return RichTbUpgradeLTFilterGlassBPVol;}
  

protected:

private:

 RichTbUpgradeCrystalMaster* aRTbCrystalMaster;

 G4LogicalVolume*  RichTbUpgradeLTPhCSampleALVol;
 G4VPhysicalVolume*  RichTbUpgradeLTPhCSampleAPVol;

 G4LogicalVolume*  RichTbUpgradeLTPhCLayerALVol;
 G4VPhysicalVolume*  RichTbUpgradeLTPhCLayerAPVol;


 G4LogicalVolume*  RichTbUpgradeLTPhCSampleBLVol;
 G4VPhysicalVolume*  RichTbUpgradeLTPhCSampleBPVol;

 G4LogicalVolume*  RichTbUpgradeLTPhCLayerBLVol;
 G4VPhysicalVolume*  RichTbUpgradeLTPhCLayerBPVol;



 G4LogicalVolume*  RichTbUpgradeLTFilterALVol;
 G4LogicalVolume*  RichTbUpgradeLTFilterBLVol;

 G4VPhysicalVolume* RichTbUpgradeLTFilterAPVol;
 G4VPhysicalVolume* RichTbUpgradeLTFilterBPVol;

 G4LogicalVolume*  RichTbUpgradeLTSampleAMasterLVol;
 G4VPhysicalVolume* RichTbUpgradeLTSampleAMasterPVol;
 
 G4LogicalVolume*  RichTbUpgradeLTSampleBMasterLVol;
 G4VPhysicalVolume* RichTbUpgradeLTSampleBMasterPVol;
  

  G4LogicalVolume* RichTbUpgradeLTFilterGlassALVol;
  G4LogicalVolume* RichTbUpgradeLTFilterGlassBLVol;
  G4VPhysicalVolume* RichTbUpgradeLTFilterGlassAPVol;
  G4VPhysicalVolume* RichTbUpgradeLTFilterGlassBPVol;
  

};
#endif // INCLUDE_RICHTBUPGRADELTPHC_H
