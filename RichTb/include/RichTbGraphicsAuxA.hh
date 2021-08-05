#ifndef INCLUDE_RICHTBGRAPHICSAUXA_HH 
#define INCLUDE_RICHTBGRAPHICSAUXA_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "RichTbUpgradeDetectorConstruction.hh"

/** @class RichTbGraphicsAuxA RichTbGraphicsAuxA.hh include/RichTbGraphicsAuxA.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-14
 */
class RichTbGraphicsAuxA {
public: 
  /// Standard constructor
  RichTbGraphicsAuxA(RichTbDetectorConstruction*  ); 

  void setGraphicsAuxAttributes();
  

  virtual ~RichTbGraphicsAuxA( ); ///< Destructor

protected:

private:

  RichTbDetectorConstruction* curDetector;
 

};
#endif // INCLUDE_RICHTBGRAPHICSAUXA_HH
