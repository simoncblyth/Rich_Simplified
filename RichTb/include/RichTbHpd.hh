// $Id: $
#ifndef INCLUDE_RICHTBHPD_HH 
#define INCLUDE_RICHTBHPD_HH 1

// Include files
#include "globals.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
//#include "RichTbPhDetSupFrame.hh"
#include <vector>
#include "RichTbUpgradePhDetSupFrame.hh"

/** @class RichTbHpd RichTbHpd.hh include/RichTbHpd.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-19
 */
class  RichTbPhDetSupFrame;

class RichTbHpd {
public:
  /// Standard constructor
  RichTbHpd(G4int aHpdNum, RichTbUpgradePhDetSupFrame* aSupFrame  ); 

  virtual ~RichTbHpd( ); ///< Destructor

  G4LogicalVolume* getRichTbHpdMasterLVol() 
  {
    return RichTbHpdMasterLVol;
  }
  G4LogicalVolume* getRichTbHpdSMasterLVol()
  {
    return  RichTbHpdSMasterLVol;
  }
  G4LogicalVolume* getRichTbHpdEnvelopeTubeLVol() 
  {
    return RichTbHpdEnvelopeTubeLVol;
  }
  G4LogicalVolume* getRichTbHpdEnvelopeEndCapLVol() 
  {
    return RichTbHpdEnvelopeEndCapLVol;
  }
  G4LogicalVolume* getRichTbHpdQuartzWLVol()
  {
    return RichTbHpdQuartzWLVol;
  }
  G4LogicalVolume* getRichTbHpdPhCathodeLVol()
  {
    return RichTbHpdPhCathodeLVol;
  }
  G4LogicalVolume* getRichTbHpdSiDetLVol()
  {
    return RichTbHpdSiDetLVol;
  }
  G4LogicalVolume* getRichTbSiPixelLVol() 
  {
    return RichTbSiPixelLVol;
    
  }
  G4VPhysicalVolume* getSingleRichTbSiPixelPVol(G4int PixelNum) 
  {
    return RichTbSiPixelPVol[ PixelNum];
    
  }
  std::vector<G4VPhysicalVolume*> getRichTbSiPixelPVol()
  {
    return RichTbSiPixelPVol;
  }
  
  G4VPhysicalVolume* getRichTbHpdMasterPVol() 
  {
    return RichTbHpdMasterPVol;
  }
  G4VPhysicalVolume* getRichTbHpdSMasterPVol()
  {
    return RichTbHpdSMasterPVol;
  }
  G4VPhysicalVolume* getRichTbHpdEnvelopeTubePVol()
  {
    return RichTbHpdEnvelopeTubePVol;
  }
  G4VPhysicalVolume* getRichTbHpdEnvelopeEndCapPVol()
  {
    return RichTbHpdEnvelopeEndCapPVol;
  }
  G4VPhysicalVolume* getRichTbHpdQuartzWPVol()
  {
    return RichTbHpdQuartzWPVol; 
  }
  G4VPhysicalVolume* getRichTbHpdPhCathodePVol()
  {
    return RichTbHpdPhCathodePVol;
  }
  G4VPhysicalVolume* getRichTbHpdSiDetPVol()
  {
    return  RichTbHpdSiDetPVol;
  }
  
  G4int getCurHpdNum() 
  {
    return  CurHpdNum;
  }

  void setTrackingSwitch(bool aV ) {
    m_TrackingSwitch = aV;
  }
  bool TrackingSwitch(){
    return  m_TrackingSwitch;
  }
  
  void constructHpdMasterTree();
  void constructHpdComponentsLVol();
  void constructHpdComponentsPVol();
  void constructHpdSiPixel();
  void buildHpdGeometry();
  
  
  
protected:

private:

  RichTbUpgradePhDetSupFrame* MotherOfHpd;
  G4int CurHpdNum;
  
  G4LogicalVolume* RichTbHpdMasterLVol;
  G4LogicalVolume* RichTbHpdSMasterLVol;
  G4LogicalVolume* RichTbHpdEnvelopeTubeLVol;
  G4LogicalVolume* RichTbHpdEnvelopeEndCapLVol;
  G4LogicalVolume* RichTbHpdQuartzWLVol;
  G4LogicalVolume* RichTbHpdPhCathodeLVol;
  G4LogicalVolume* RichTbHpdSiDetLVol;
  G4VPhysicalVolume*  RichTbHpdMasterPVol;
  G4VPhysicalVolume*  RichTbHpdSMasterPVol;
  G4VPhysicalVolume* RichTbHpdEnvelopeTubePVol;  
  G4VPhysicalVolume* RichTbHpdEnvelopeEndCapPVol;  
  G4VPhysicalVolume* RichTbHpdQuartzWPVol;  
  G4VPhysicalVolume* RichTbHpdPhCathodePVol;  
  G4VPhysicalVolume* RichTbHpdSiDetPVol;

    
  G4LogicalVolume* RichTbSiPixelLVol;
 
  std::vector<G4VPhysicalVolume*> RichTbSiPixelPVol;
  bool m_TrackingSwitch;
  
  
  
 

};
#endif // INCLUDE_RICHTBHPD_HH
