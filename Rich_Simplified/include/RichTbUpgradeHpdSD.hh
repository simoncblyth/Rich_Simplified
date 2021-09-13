#ifndef INCLUDE_RICHTBUPGRADEHPDSD_HH 
#define INCLUDE_RICHTBUPGRADEHPDSD_HH 1

// Include files
#include "globals.hh"
#include "G4VSensitiveDetector.hh"
#include "G4ThreeVector.hh"
#include "RichTbHit.hh"
#include "RichTbGeometryParameters.hh"
class G4Step;
class G4HCofThisEvent;

/** @class RichTbUpgradeHpdSD RichTbUpgradeHpdSD.hh include/RichTbUpgradeHpdSD.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2015-05-15
 */
class RichTbUpgradeHpdSD:public G4VSensitiveDetector {
public: 
  /// Standard constructor
  RichTbUpgradeHpdSD(G4String ); 

  virtual ~RichTbUpgradeHpdSD( ); ///< Destructor
      void Initialize(G4HCofThisEvent*HCE);

      G4bool ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist);
      void EndOfEvent(G4HCofThisEvent*HCE);
      void clear();
      void DrawAll();
      void PrintAll();
      G4int getCurrentHitCreationOption(){
        return  CurrentHitCreationOption;
      }

protected:

private:
      RichTbHitsCollection * RichTbHitCollectionHpd;
      std::vector<G4int> HpdSDID;
      G4int HCID;
  G4int  CurrentHitCreationOption;
  G4int RichTbHitCollIndex;
  G4String RichTbSDHpdName;
  
};
#endif // INCLUDE_RICHTBUPGRADEHPDSD_HH
