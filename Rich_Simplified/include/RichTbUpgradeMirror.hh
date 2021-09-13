// $Id: $
#ifndef INCLUDE_RICHTBUPGRADEMIRROR_HH
#define INCLUDE_RICHTBUPFRADEMIRROR_HH 1

// Include files

#include "RichTbUpgradeCrystalMaster.hh"

#include "RichTbUpgradeRadiator.hh"

/** @class RichTbUpgradeMirror RichTbUpgradeMirror.hh include/RichTbUpgradeMirror.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2003-11-07
 */
class RichTbUpgradeMirror {
public:
  /// Standard constructor
  RichTbUpgradeMirror( RichTbUpgradeCrystalMaster* aMaster, RichTbUpgradeRadiator* aRadiator);

  virtual ~RichTbUpgradeMirror( ); ///< Destructor


  G4LogicalVolume* getRichTbUpgradeMirrorLVol()
  {
   return RichTbUpgradeMirrorLVol;

  }
  G4VPhysicalVolume* getRichTbUpgradeMirrorPVol()
  {
    return RichTbUpgradeMirrorPVol;
  }

  void constructRichTbUpgradeMirror();
  void constructRichTbUpgradeMirror15(); //testbeam 2015 upgrade

  RichTbUpgradeRadiator* getaRTbUpgradeRadiator()
  {
    return aRTbUpgradeRadiator;
  }

protected:

private:

  /// Standard constructor
  //RichTbUpgradeMirror( RichTbCrystalMaster* aMaster );


  //static RichTbUpgradeMirror* RichTbUpgradeMirrorInstance;
  G4ThreeVector MirrorCoC;



  RichTbUpgradeCrystalMaster* motherMaster;

  RichTbUpgradeRadiator* aRTbUpgradeRadiator;

  G4LogicalVolume* RichTbUpgradeMirrorLVol;
  G4VPhysicalVolume* RichTbUpgradeMirrorPVol;

};
#endif // INCLUDE_RICHTBUPGRADEMIRROR_HH
