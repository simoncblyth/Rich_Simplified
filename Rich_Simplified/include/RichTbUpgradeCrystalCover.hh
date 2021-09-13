// $Id: $
#ifndef INCLUDE_RICHTBUPGRADECRYSTALCOVER_HH 
#define INCLUDE_RICHTBUPGRADECRYSTALCOVER_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeCrystalMaster.hh"

/** @class (RichTbCrystalMaster (RichTbCrystalMaster.hh include/RichTbCrystalMaster.hh 

 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbCrystalCover {
public:
  /// Standard constructor
  RichTbCrystalCover(RichTbUpgradeCrystalMaster* rTbCrystalMaster ); 

  virtual ~RichTbCrystalCover( ); ///< Destructor

  void  constructRichTbCrystalCover();
  void  constructRichTbCrystalCoverEnvelope();
  
  G4LogicalVolume* getRichTbCrystalCoverLVol() 
  {
    return RichTbCrystalCoverLVol;
  }
  /*
 G4LogicalVolume* getRichTbCrystalCoverEnvelopeBottomLVol()
  {
    return RichTbCrystalCoverEnvelopeBottomLVol;
    
  }
  */
  G4VPhysicalVolume* getRichTbCrystalCoverPVol() 
  {
    return RichTbCrystalCoverPVol;
  }
  /*
  G4VPhysicalVolume* getRichTbCrystalCoverEnvelopeBottomPVol()
  {
    return RichTbVesselEnvelopeBottomPVol;
  }
  */
  RichTbUpgradeCrystalMaster* getaRTbCrystalMaster() 
  { 
    return aRTbCrystalMaster;
  
  }
  
protected:

private:
  RichTbUpgradeCrystalMaster* aRTbCrystalMaster;
  
  G4LogicalVolume* RichTbCrystalCoverLVol;
  // G4LogicalVolume*  RichTbVesselEnvelopeBottomLVol;
  

  G4VPhysicalVolume* RichTbCrystalCoverPVol;
  // G4VPhysicalVolume* RichTbVesselEnvelopeBottomPVol; 

 
};
#endif 
