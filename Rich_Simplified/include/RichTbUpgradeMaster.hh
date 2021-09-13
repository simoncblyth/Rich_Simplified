// $Id: $
#ifndef INCLUDE_RICHTBUPGRADEMASTER_HH 
#define INCLUDE_RICHTBUPGRADEMASTER_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradePhDFrame.hh"

/** @class RichTbVessel RichTbVessel.hh include/RichTbVessel.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbMaster {
public:
  /// Standard constructor
  RichTbMaster(RichTbPhDFrame* rTbPhDFrame, int MasterNum ); 

  virtual ~RichTbMaster( ); ///< Destructor

  void  constructRichTbMaster1();
  void  constructRichTbMasterEnvelope1();
  
  void  constructRichTbMaster2();
  void  constructRichTbMasterEnvelope2();

  void  constructRichTbMaster3();
  void  constructRichTbMasterEnvelope3();

  void  constructRichTbMaster4();
  void  constructRichTbMasterEnvelope4();

  G4LogicalVolume* getRichTbMasterLVol() 
  {
    return RichTbMasterLVol;
  }
  G4LogicalVolume* getRichTbMasterEnvelopeBottomLVol()
  {
    return RichTbMasterEnvelopeBottomLVol;
  }

  G4VPhysicalVolume* getRichTbMasterPVol() 
  {
    return RichTbMasterPVol;
  }
  G4VPhysicalVolume* getRichTbMasterEnvelopeBottomPVol()
  {
    return RichTbMasterEnvelopeBottomPVol;
  }

  RichTbPhDFrame* getaRTbPhDFrame() 
  { 
    return aRTbPhDFrame;
  
  }
  int getaMasterNum() 
  { 
    return aMasterNum;
  
  }
protected:

private:
  RichTbPhDFrame* aRTbPhDFrame;
  int aMasterNum;
  
  G4LogicalVolume* RichTbMasterLVol;
  G4LogicalVolume*  RichTbMasterEnvelopeBottomLVol;
  

  G4VPhysicalVolume* RichTbMasterPVol;
  G4VPhysicalVolume* RichTbMasterEnvelopeBottomPVol; 

 
};
#endif 
