#ifndef INCLUDE_RICHTBUPGRADEPHDETSUPFRAME_HH
#define INCLUDE_RICHTBUPGRADEPHDETSUPFRAME_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbUpgradeCrystalMaster.hh"

/** @class RichTbUpgradePhDetSupFrame RichTbUpgradePhDetSupFrame.hh include/RichTbUpgradePhDetSupFrame.hh
 *
 *
 *  @author Sajan Easo
 *  @date   2014-10-23
 */
class RichTbUpgradePhDetSupFrame {
public:
  /// Standard constructor
  RichTbUpgradePhDetSupFrame(RichTbUpgradeCrystalMaster*  rTbCrystalMaster );

  virtual ~RichTbUpgradePhDetSupFrame( ); ///< Destructor

  void constructRichTbPhotoDetectorSupFrame() ;
  void constructRichTbPhotoDetectorSupFrameWithHpd();
  void constructRichTbPhotoDetectorSupFrame15();
  void constructRichTbPhotoDetectorSupFrame16LT();
  void constructRichTbPhotoDetectorSupFrame17();

  G4LogicalVolume* getRichTbPhDetSupFrameLeftLVol()
  {return RichTbPhDetSupFrameLeftLVol;}
  G4LogicalVolume* getRichTbPhDetSupFrameRightLVol()
  {  return  RichTbPhDetSupFrameRightLVol;}
  G4VPhysicalVolume* getRichTbPhDetSupFrameLeftPVol()
  {  return RichTbPhDetSupFrameLeftPVol ;}
  G4VPhysicalVolume* getRichTbPhDetSupFrameRightPVol()
  {  return RichTbPhDetSupFrameRightPVol ;}

  G4LogicalVolume* getRichTbPhDetSupFrame2017LVol()
  {return RichTbPhDetSupFrame2017LVol;}
  G4VPhysicalVolume* getRichTbPhDetSupFrame2017PVol()
  {  return RichTbPhDetSupFrame2017PVol ;}

  G4LogicalVolume* getRichTbPhDetSupFrameBottomLeftLVol()
  {return RichTbPhDetSupFrameBottomLeftLVol;}
  G4LogicalVolume* getRichTbPhDetSupFrameBottomRightLVol()
  {  return  RichTbPhDetSupFrameBottomRightLVol;}
  G4VPhysicalVolume* getRichTbPhDetSupFrameBottomLeftPVol()
  {  return RichTbPhDetSupFrameBottomLeftPVol ;}
  G4VPhysicalVolume* getRichTbPhDetSupFrameBottomRightPVol()
  {  return RichTbPhDetSupFrameBottomRightPVol ;}

  RichTbUpgradeCrystalMaster* getCrystalMaster()
  {return aRTbCrystalMaster;  }

  
  G4LogicalVolume*  getRichTbPhDetGrandSupFrameLVol(G4int iside) 
  {  return RichTbPhDetSupFrameLVol [iside];}
  
  G4VPhysicalVolume* getRichTbPhDetGrandSupFramePVol (G4int isideA) 
  {  return RichTbPhDetSupFramePVol [isideA];}
  


protected:

private:

  G4LogicalVolume*   RichTbPhDetSupFrame2017LVol;
  G4VPhysicalVolume* RichTbPhDetSupFrame2017PVol ;

  G4LogicalVolume*   RichTbPhDetSupFrameLeftLVol;
  G4LogicalVolume*   RichTbPhDetSupFrameRightLVol;
  G4VPhysicalVolume* RichTbPhDetSupFrameLeftPVol ;
  G4VPhysicalVolume* RichTbPhDetSupFrameRightPVol ;
  G4LogicalVolume*   RichTbPhDetSupFrameBottomLeftLVol;
  G4LogicalVolume*   RichTbPhDetSupFrameBottomRightLVol;
  G4VPhysicalVolume* RichTbPhDetSupFrameBottomLeftPVol;
  G4VPhysicalVolume* RichTbPhDetSupFrameBottomRightPVol;
  RichTbUpgradeCrystalMaster* aRTbCrystalMaster;
  std::vector<G4LogicalVolume*> RichTbPhDetSupFrameLVol;
  std::vector<G4VPhysicalVolume*> RichTbPhDetSupFramePVol;
  

};
#endif // INCLUDE_RICHTBUPGRADEPHDETSUPFRAME_HH
