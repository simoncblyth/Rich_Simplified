// $Id: $
#ifndef INCLUDE_RICHTBRODUMMYSD_HH 
#define INCLUDE_RICHTBRODUMMYSD_HH 1

// Include files
#include "G4VSensitiveDetector.hh"

/** @class RichTbRODummySD RichTbRODummySD.hh include/RichTbRODummySD.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-12
 */
class G4Step;
class RichTbRODummySD: public G4VSensitiveDetector {
public: 
  /// Standard constructor
  RichTbRODummySD( ); 

  virtual ~RichTbRODummySD( ); ///< Destructor
  void Initialize(G4HCofThisEvent* /* HCE */) {};
  G4bool ProcessHits(G4Step* /* aStep */,G4TouchableHistory* /* ROhist */) {return false;}
  void EndOfEvent(G4HCofThisEvent* /* HCE */) {};
  void clear() {};
  void DrawAll() {};
  void PrintAll() {};
};


RichTbRODummySD::RichTbRODummySD()
  : G4VSensitiveDetector("RichTbROdummySD") {}
  
  RichTbRODummySD::~RichTbRODummySD() 
  {  }
#endif // INCLUDE_RICHTBRODUMMYSD_HH
