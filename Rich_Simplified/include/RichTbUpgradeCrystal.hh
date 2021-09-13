// $Id: $
#ifndef INCLUDE_RICHTBUPGRADECRYSTAL_HH 
#define INCLUDE_RICHTBUPGRADECRYSTAL_HH 1

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
class RichTbCrystal {
public:
  /// Standard constructor
  RichTbCrystal(RichTbUpgradeCrystalMaster* rTbCrystalMaster ); 

  virtual ~RichTbCrystal( ); ///< Destructor

  void  constructRichTbCrystal();
  void  constructRichTbCrystalEnvelope();
  
  G4LogicalVolume* getRichTbCrystalLVol() 
  {
    return RichTbCrystalLVol;
  }
  G4LogicalVolume* getRichTbCrystalEnvelopeBottomLVol()
  {
    return RichTbCrystalEnvelopeBottomLVol;
    
  }

  G4VPhysicalVolume* getRichTbCrystalPVol() 
  {
    return RichTbCrystalPVol;
  }
  G4VPhysicalVolume* getRichTbCrystalEnvelopeBottomPVol()
  {
    return RichTbCrystalEnvelopeBottomPVol;
  }
  RichTbUpgradeCrystalMaster* getaRTbCrystalMaster() 
  { 
    return aRTbCrystalMaster;
  
  }
  
protected:

private:
  RichTbUpgradeCrystalMaster* aRTbCrystalMaster;
  
  G4LogicalVolume* RichTbCrystalLVol;
  G4LogicalVolume*  RichTbCrystalEnvelopeBottomLVol;
  

  G4VPhysicalVolume* RichTbCrystalPVol;
  G4VPhysicalVolume* RichTbCrystalEnvelopeBottomPVol; 

 
};
#endif 
