// $Id: $
#ifndef INCLUDE_RICHTBUPGRADEDARKCOVER_HH
#define INCLUDE_RICHTBUPGRADEDARKCOVER_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeRadiator.hh"
#include "RichTbUpgradeCrystalMaster.hh"

/** @class RichTbDarkCover RichTbDarkCover.hh include/RichTbDarkCover.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbUpgradeDarkCover {
public:
  /// Standard constructor
  RichTbUpgradeDarkCover(RichTbUpgradeRadiator* rTbRadiator );

  virtual ~RichTbUpgradeDarkCover( ); ///< Destructor

  void  constructRichTbUpgradeDarkCover();
  void  constructRichTbUpgradeUpsDarkCoverEnvelope(RichTbUpgradeCrystalMaster* aMaster);
  void  constructRichTbUpgradeSideDarkCoverEnvelope(RichTbUpgradeCrystalMaster* aMasterC);

  //testbeam 2015 upgrade
  void  constructRichTbUpgradeDarkCover15();
  void  constructRichTbUpgradeUpsDarkCoverEnvelope15(RichTbUpgradeCrystalMaster* aMaster);
  void  constructRichTbUpgradeSideDarkCoverEnvelope15(RichTbUpgradeCrystalMaster* aMasterC);
  void  constructRichTbUpgradeSideDarkCoverEnvelopePhC(RichTbUpgradeCrystalMaster* aMasterC);
  void  constructRichTbUpgradeUpsDarkCoverEnvelopePhC(RichTbUpgradeCrystalMaster* aMasterC);

  G4LogicalVolume* getRichTbUpgradeDarkCoverLVol()
  {
    return RichTbUpgradeDarkCoverLVol;
  }
  G4LogicalVolume* getRichTbUpgradeDarkCoverEnvelopeBottomLVol()
  {
    return RichTbUpgradeDarkCoverEnvelopeBottomLVol;

  }

  G4VPhysicalVolume* getRichTbUpgradeDarkCoverPVol()
  {
    return RichTbUpgradeDarkCoverPVol;
  }
  G4VPhysicalVolume* getRichTbUpgradeDarkCoverEnvelopeBottomPVol()
  {
    return RichTbUpgradeDarkCoverEnvelopeBottomPVol;
  }
  RichTbUpgradeRadiator* getaRTbUpgradeRadiator()
  {
    return aRTbUpgradeRadiator;
  }

  G4LogicalVolume* getRichTbUpgradeUpsDarkCoverLVol()
  {  return RichTbUpgradeUpsDarkCoverLVol; }

  G4LogicalVolume* getRichTbUpgradeSideDarkCoverLVol()
  {   return RichTbUpgradeSideDarkCoverLVol ;}

  G4LogicalVolume* getRichTbUpgradeSideDarkCoverEnvPhCLVol() 
  {  return RichTbUpgradeSideDarkCoverEnvPhCLVol;}

  G4VPhysicalVolume* getRichTbUpgradeSideDarkCoverEnvPhCPVol() 
  {    return 	RichTbUpgradeSideDarkCoverEnvPhCPVol;}
  
  G4LogicalVolume* getRichTbUpgradeUpsDarkCoverEnvPhCLVol(){
    return RichTbUpgradeUpsDarkCoverEnvPhCLVol;
  }
  G4VPhysicalVolume* getRichTbUpgradeUpsDarkCoverEnvPhCPVol(){
    return RichTbUpgradeUpsDarkCoverEnvPhCPVol;
  }

  

protected:

private:
  RichTbUpgradeRadiator* aRTbUpgradeRadiator;

  G4LogicalVolume*  RichTbUpgradeDarkCoverLVol;
  G4LogicalVolume*  RichTbUpgradeUpsDarkCoverLVol;
  G4LogicalVolume*  RichTbUpgradeDarkCoverEnvelopeBottomLVol;
  G4LogicalVolume*  RichTbUpgradeSideDarkCoverLVol;
  G4LogicalVolume*  RichTbUpgradeSideDarkCoverEnvPhCLVol;
  G4LogicalVolume*  RichTbUpgradeUpsDarkCoverEnvPhCLVol;
  



  G4VPhysicalVolume* RichTbUpgradeDarkCoverPVol;
  G4VPhysicalVolume* RichTbUpgradeUpsDarkCoverPVol;
  G4VPhysicalVolume* RichTbUpgradeDarkCoverEnvelopeBottomPVol;
  G4VPhysicalVolume* RichTbUpgradeSideTopDarkCoverPVol;
  G4VPhysicalVolume* RichTbUpgradeSideBotDarkCoverPVol;
  G4VPhysicalVolume* RichTbUpgradeSideDarkCoverEnvPhCPVol;
  G4VPhysicalVolume* RichTbUpgradeUpsDarkCoverEnvPhCPVol;
  

  

};
#endif
