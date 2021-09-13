// $Id: $
#ifndef INCLUDE_RICHTBUPGRADESD_HH 
#define INCLUDE_RICHTBUPGRADESD_HH 1

// Include files
#include "globals.hh"
#include "G4VSensitiveDetector.hh"
#include "G4ThreeVector.hh"
#include "RichTbHit.hh"
#include "RichTbGeometryParameters.hh"

#include "OpHit.hh"
class G4Step;
class G4HCofThisEvent;


/** @class RichTbUpgradeSD RichTbUpgradeSD.hh include/RichTbUpgradeSD.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-12
 *  Modif: Claudia Merlassino, Sajan Easo
 *  date  : 2014-08-21 
 */
class RichTbUpgradeSD:public G4VSensitiveDetector {
public: 
  /// Standard constructor
  RichTbUpgradeSD(G4String ); 

  virtual ~RichTbUpgradeSD( ); ///< Destructor
      void Initialize(G4HCofThisEvent*HCE) override;

      G4bool ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist) override;
      void EndOfEvent(G4HCofThisEvent*HCE) override;
      void clear()    override ;
      void DrawAll()  override ;
      void PrintAll() override ;

  G4int getCurrentHitCreationOption()
  {
    return  CurrentHitCreationOption;
  }
  
    
protected:

private:
      //RichTbHitsCollection * RichTbHitCollection;
      OpHitCollection * RichTbHitCollection;
      std::vector<G4int> PmtSDID;
      G4int HCID;
  G4int  CurrentHitCreationOption;
  G4double CurrentPmtPixelGap;
  G4int RichTbHitCollIndex;
  G4String  RichTbSensDetName;
  

};
#endif // INCLUDE_RICHTBUPGRADESD_HH
