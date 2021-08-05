// $Id: $
#ifndef INCLUDE_RICHTBUPGRADERADIATOR_HH
#define INCLUDE_RICHTBUPGRADERADIATOR_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystalMaster.hh"
#include "RichTbUpgradeLTPhC.hh"

/** @class  RichTbUpgradeRadiator  RichTbUpgradeRadiator.hh include/ RichTbUpgradeRadiator.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbUpgradeRadiator{
public:
  /// Standard constructor
  RichTbUpgradeRadiator(RichTbUpgradeCrystalMaster* rTbCrystalMaster );

  virtual ~RichTbUpgradeRadiator( ); ///< Destructor

  void  constructRichTbUpgradeRadiator();
  void  constructRichTbUpgradeRadiator15();
  void  constructRichTbUpgradeRadiatorEnvelope();

  G4LogicalVolume* getRichTbUpgradeRadiatorLVol()
  {
    return RichTbUpgradeRadiatorLVol;
  }
  G4LogicalVolume* getRichTbUpgradeRadiatorEnvelopeBottomLVol()
  {
    return RichTbUpgradeRadiatorEnvelopeBottomLVol;

  }

  G4VPhysicalVolume* getRichTbUpgradeRadiatorPVol()
  {
    return RichTbUpgradeRadiatorPVol;
  }
  G4VPhysicalVolume* getRichTbUpgradeRadiatorEnvelopeBottomPVol()
  {
    return RichTbUpgradeRadiatorEnvelopeBottomPVol;
  }
  RichTbUpgradeCrystalMaster* getaRTbCrystalMaster()
  {
    return aRTbCrystalMaster;

  }
  G4LogicalVolume* getTestLvol()
  {
    return testLvol;
  }
  G4VPhysicalVolume* getTestPvol()
  {
    return testPvol;
  }
  RichTbUpgradeLTPhC* getRichTbUpgradeLTPhC() 
  {
    return  rRichTbUpgradeLTPhC;
  }
  
  

protected:

private:
  RichTbUpgradeCrystalMaster* aRTbCrystalMaster;

  G4LogicalVolume* RichTbUpgradeRadiatorLVol;
  G4LogicalVolume*  RichTbUpgradeRadiatorEnvelopeBottomLVol;


  G4VPhysicalVolume* RichTbUpgradeRadiatorPVol;
  G4VPhysicalVolume* RichTbUpgradeRadiatorEnvelopeBottomPVol;

  G4LogicalVolume * testLvol;
  G4VPhysicalVolume * testPvol;

  RichTbUpgradeLTPhC* rRichTbUpgradeLTPhC;
  

};
#endif
