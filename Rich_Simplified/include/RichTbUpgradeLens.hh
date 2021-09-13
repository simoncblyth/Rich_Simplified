// $Id: $
#ifndef INCLUDE_RICHTBUPGRADELENS_HH 
#define INCLUDE_RICHTBUPGRADELENS_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystalMaster.hh"

/** @class RichTbVessel RichTbVessel.hh include/RichTbVessel.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbLens {
public:
  /// Standard constructor
  RichTbLens(RichTbUpgradeCrystalMaster* rTbCrystalMaster ); 

  virtual ~RichTbLens( ); ///< Destructor

  void  constructRichTbLens();
  void  constructRichTbLensEnvelope();
  
  G4LogicalVolume* getRichTbLensLVol() 
  {
    return RichTbLensLVol;
  }

  G4VPhysicalVolume* getRichTbLensPVol() 
  {
    return RichTbLensPVol;
  }
 
  RichTbUpgradeCrystalMaster* getaRTbCrystalMaster() 
  { 
    return aRTbCrystalMaster;
  
  }
  
protected:

private:
  RichTbUpgradeCrystalMaster* aRTbCrystalMaster;
  
  G4LogicalVolume* RichTbLensLVol;
 
  G4VPhysicalVolume* RichTbLensPVol;
 
};
#endif 
