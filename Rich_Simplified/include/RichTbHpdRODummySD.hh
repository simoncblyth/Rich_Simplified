#ifndef INCLUDE_RICHTBHPDRODUMMYSD_HH 
#define INCLUDE_RICHTBHPDRODUMMYSD_HH 1

// Include files
#include "G4VSensitiveDetector.hh"
/** @class RichTbHpdRODummySD RichTbHpdRODummySD.hh include/RichTbHpdRODummySD.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2015-05-06
 */
class RichTbHpdRODummySD: public G4VSensitiveDetector {
public: 
  /// Standard constructor
  RichTbHpdRODummySD(); 

  virtual ~RichTbHpdRODummySD(); ///< Destructor
  void Initialize(G4HCofThisEvent* /* HCE */) override {};
  G4bool ProcessHits(G4Step* /* aStep */,G4TouchableHistory* /* ROhist */) override {return false;}
  void EndOfEvent(G4HCofThisEvent* /* HCE */) override {};
  void clear() override {};
  void DrawAll() override {};
  void PrintAll() override {};

protected:

private:


};

RichTbHpdRODummySD::RichTbHpdRODummySD(): G4VSensitiveDetector("RichTbHpdROdummySD") {}

RichTbHpdRODummySD::~RichTbHpdRODummySD(){  }



#endif // INCLUDE_RICHTBHPDRODUMMYSD_HH
