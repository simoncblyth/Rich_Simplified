// $Id: $
#ifndef INCLUDE_RICHTBUPGRADEPHDFRAME_HH 
#define INCLUDE_RICHTBUPGRADEPHDFRAME_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeCrystalMaster.hh"

/** @class RichTbVessel RichTbVessel.hh include/RichTbVessel.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbPhDFrame {
public:
  /// Standard constructor
  RichTbPhDFrame(RichTbUpgradeCrystalMaster* rTbCrystalMaster ); 

  virtual ~RichTbPhDFrame( ); ///< Destructor

  void  constructRichTbPhDFrame();
  void  constructRichTbPhDFrameEnvelope();
  
  G4LogicalVolume* getRichTbPhDFrameLVol() 
  {
    return RichTbPhDFrameLVol;
  }
  G4LogicalVolume* getRichTbPhDFrameEnvelopeBottomLVol()
  {
    return RichTbPhDFrameEnvelopeBottomLVol;
    
  }

  G4VPhysicalVolume* getRichTbPhDFramePVol() 
  {
    return RichTbPhDFramePVol;
  }
  G4VPhysicalVolume* getRichTbPhDFrameEnvelopeBottomPVol()
  {
    return RichTbPhDFrameEnvelopeBottomPVol;
  }
  RichTbUpgradeCrystalMaster* getRTbCrystalMaster() 
  { 
    return aRTbCrystalMaster;
  
  }
  
protected:

private:
  RichTbUpgradeCrystalMaster* aRTbCrystalMaster;
  
  G4LogicalVolume* RichTbPhDFrameLVol;
  G4LogicalVolume*  RichTbPhDFrameEnvelopeBottomLVol;
  

  G4VPhysicalVolume* RichTbPhDFramePVol;
  G4VPhysicalVolume* RichTbPhDFrameEnvelopeBottomPVol; 

 
};
#endif 
