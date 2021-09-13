// $Id: $
#ifndef INCLUDE_RICHTBUPGRADECRYSTALMASTER_HH 
#define INCLUDE_RICHTBUPGRADECRYSTALMASTER_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"

/** @class RichTbUpgradeVessel RichTbUpgradeVessel.hh include/RichTbUpgradeVessel.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbUpgradeCrystalMaster {
public:
  /// Standard constructor
  RichTbUpgradeCrystalMaster(RichTbUpgradeVessel* rTbVessel ); 

  virtual ~RichTbUpgradeCrystalMaster( ); ///< Destructor

  void  constructRichTbUpgradeCrystalMaster();
  void  constructRichTbUpgradeCrystalMasterEnvelope();
  
  G4LogicalVolume* getRichTbUpgradeCrystalMasterLVol() 
  {
    return RichTbUpgradeCrystalMasterLVol;
  }
  G4LogicalVolume* getRichTbUpgradeCrystalMasterEnvelopeBottomLVol()
  {
    return RichTbUpgradeCrystalMasterEnvelopeBottomLVol;
    
  }

  G4VPhysicalVolume* getRichTbUpgradeCrystalMasterPVol() 
  {
    return RichTbUpgradeCrystalMasterPVol;
  }
  G4VPhysicalVolume* getRichTbUpgradeCrystalMasterEnvelopeBottomPVol()
  {
    return RichTbUpgradeCrystalMasterEnvelopeBottomPVol;
  }
  RichTbUpgradeVessel* getaRTbVessel() 
  { 
    return aRTbVessel;
  
  }
  
protected:

private:
  RichTbUpgradeVessel * aRTbVessel;
  
  G4LogicalVolume* RichTbUpgradeCrystalMasterLVol;
  G4LogicalVolume*  RichTbUpgradeCrystalMasterEnvelopeBottomLVol;
  

  G4VPhysicalVolume* RichTbUpgradeCrystalMasterPVol;
  G4VPhysicalVolume* RichTbUpgradeCrystalMasterEnvelopeBottomPVol; 

 
};
#endif 
