// $Id: $
#ifndef INCLUDE_RICHTBLHCBUPGRADESD_HH 
#define INCLUDE_RICHTBLHCBUPGRADESD_HH 1

// Include files
#include "globals.hh"
#include "G4VSensitiveDetector.hh"
#include "G4ThreeVector.hh"
#include "RichTbHit.hh"
#include "RichTbGeometryParameters.hh"
#include <iostream>
#include <cstdint>

class G4Step;
class G4HCofThisEvent;

using namespace std;

/** @class RichTbLHCbUpgradeSD RichTbLHCbUpgradeSD.hh include/RichTbLHCbUpgradeSD.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-12
 *  Modif: Claudia Merlassino, Sajan Easo
 *  date  : 2014-08-21 
 *  Modif Sajan Easo 
 *  date: 2021-08-01
 */
class RichTbLHCbUpgradeSD:public G4VSensitiveDetector {
public: 
  /// Standard constructor
  RichTbLHCbUpgradeSD(G4String ); 

  virtual ~RichTbLHCbUpgradeSD( ); ///< Destructor
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

  void ResetPmtSDID ();
  void SetPmtSDIDBit( int aM, int aP, int aPix );
  bool RetrievePmtSDIDBit( int aM, int aP , int aPix ); 
    
protected:

private:
      RichTbHitsCollection * RichTbHitCollection;
      std::vector <std::vector<int64_t> >  RichTbR1PmtSDID;
      G4int HCID;
  G4int  CurrentHitCreationOption;
  G4double CurrentPmtPixelGap;
  G4int RichTbHitG4CollIndex;
  G4int RichTbHitOpticksCollIndex;
  G4String  RichTbLHCbSensDetName;
  G4double RichTbLHCbCurrNominalPixelEff;

};
#endif // INCLUDE_RICHTBLHCBUPGRADESD_HH
