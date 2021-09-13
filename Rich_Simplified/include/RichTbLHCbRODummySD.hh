// $Id: $
#ifndef INCLUDE_RICHTBLHCBRODUMMYSD_HH 
#define INCLUDE_RICHTBLHCBRODUMMYSD_HH 1

// Include files
#include "G4VSensitiveDetector.hh"

/** @class RichTbLHCbRODummySD RichTbLHCbRODummySD.hh include/RichTbLHCbRODummySD.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-12
 *  Mod SE date 2021-08-01
 */
class G4Step;
class RichTbLHCbRODummySD: public G4VSensitiveDetector {
public: 
  /// Standard constructor
  RichTbLHCbRODummySD( ); 

  virtual ~RichTbLHCbRODummySD( ); ///< Destructor
  void Initialize(G4HCofThisEvent* /* HCE */) {};
  G4bool ProcessHits(G4Step* /* aStep */,G4TouchableHistory* /* ROhist */) {return false;}
  void EndOfEvent(G4HCofThisEvent* /* HCE */) {};
  void clear() {};
  void DrawAll() {};
  void PrintAll() {};
};


RichTbLHCbRODummySD::RichTbLHCbRODummySD()
  : G4VSensitiveDetector("RichTbROdummySD") {}
  
RichTbLHCbRODummySD::~RichTbLHCbRODummySD() 
  {  }
#endif // INCLUDE_RICHTBLHCBRODUMMYSD_HH
