// $Id: $
#ifndef INCLUDE_RICHTBUPGRADEPMT_HH
#define INCLUDE_RICHTBUPGRADEPMT_HH 1

// Include files
#include "globals.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbUpgradeEC.hh"
#include "RichTbUpgradeMaster.hh"
#include <vector>

/** @class RichTbPMT RichTbPMT.hh include/RichTbPMT.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2003-11-19
 */
class  RichTbMaster;

class RichTbPMT {
public:
  /// Standard constructor
  RichTbPMT(RichTbUpgradeEC* aECMaster  );

  virtual ~RichTbPMT( ); ///< Destructor

  void setTrackingSwitch(bool aSw)
  {m_TrackingSwitch = aSw;}
  void buildPMTGeometry();
  void constructPMTComponentsLVol();
  void constructPMTComponentsPVol(int CurPMTNum) ;
  void constructPMTMasterTree(int CurPMTNum);

  void constructPMTAnode();


  std::vector<G4LogicalVolume*> getRichTbPMTMasterLVol()
  {    return RichTbPMTMasterLVol;}

  std::vector<G4LogicalVolume*> getRichTbPMTSMasterLVol()
  {    return  RichTbPMTSMasterLVol;}


  G4LogicalVolume* getRichTbPMTEnvelopeLVol()
  {    return RichTbPMTEnvelopeLVol;}


  /*
  G4LogicalVolume* getRichTbPMTEnvelopeEndCapLVol()
  {
    return RichTbPMTEnvelopeEndCapLVol;
  }
  */
  G4LogicalVolume* getRichTbPMTQuartzWLVol()
  {
    return RichTbPMTQuartzWLVol;
  }
  G4LogicalVolume* getRichTbPMTPhCathodeLVol()
  {
    return RichTbPMTPhCathodeLVol;
  }

  std::vector<G4LogicalVolume*> getRichTbPMTAnodeLVol()
  {
    return RichTbPMTAnodeLVol;
  }



  std::vector<G4VPhysicalVolume*> getRichTbPMTQuartzWPVol()
  {
    return RichTbPMTQuartzWPVol;
  }
  std::vector<G4VPhysicalVolume*> getRichTbPMTPhCathodePVol()
  {
    return RichTbPMTPhCathodePVol;
  }

  std::vector<G4VPhysicalVolume*> getRichTbPMTAnodePVol()
  {
    return RichTbPMTAnodePVol;
  }
   G4LogicalVolume* getRichTbPMTFrontRingLVol()
  {  return   RichTbPMTFrontRingLVol; }

  std::vector<G4VPhysicalVolume*> getRichTbPMTFrontRingPVol ()
  {
    return   RichTbPMTFrontRingPVol;

  }

  std::string getPMTQwLogVolName()
  {
    return m_PMTQwLogVolName;
  }
  std::string getPMTPhCathLogVolName()
  {
    return m_PMTPhCathLogVolName;
  }
  std::string getPMTAnodeLogVolName()
  {
    return m_PMTAnodeLogVolName;
  }

  G4int getCurNumPmts()
  {  return CurNumPmts;}






protected:

private:
  RichTbUpgradeEC* PmtECFrame;
  bool m_TrackingSwitch;
  G4int CurNumPmts;

  G4LogicalVolume* RichTbPMTEnvelopeLVol;
  G4LogicalVolume* RichTbPMTQuartzWLVol;
  G4LogicalVolume*  RichTbPMTPhCathodeLVol;
  G4LogicalVolume* RichTbPMTFrontRingLVol;

  std::vector<G4VPhysicalVolume*> RichTbPMTEnvelopePVol;
  std::vector<G4VPhysicalVolume*>  RichTbPMTQuartzWPVol;
  std::vector<G4VPhysicalVolume*> RichTbPMTPhCathodePVol;
  std::vector<G4VPhysicalVolume*>  RichTbPMTFrontRingPVol;

  std::vector<G4LogicalVolume*>  RichTbPMTMasterLVol;
  std::vector<G4LogicalVolume*> RichTbPMTSMasterLVol;
  std::vector<G4LogicalVolume*> RichTbPMTAnodeLVol;
  std::vector<G4VPhysicalVolume*>  RichTbPMTMasterPVol;
  std::vector<G4VPhysicalVolume*>  RichTbPMTSMasterPVol;
  std::vector<G4VPhysicalVolume*> RichTbPMTAnodePVol;

  std::string m_PMTQwLogVolName;
  std::string m_PMTPhCathLogVolName;
  std::string m_PMTAnodeLogVolName;

  G4LogicalVolume* RichTbAnodePxLVol;
  std::vector<std::vector<G4VPhysicalVolume*> > RichTbAnodePxPVol;


};
#endif // INCLUDE_RICHTBHPD_HH
