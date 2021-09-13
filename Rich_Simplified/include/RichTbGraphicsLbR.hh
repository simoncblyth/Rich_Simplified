#ifndef INCLUDE_RICHTBGRAPHICSLBR_HH
#define INCLUDE_RICHTBGRAPHICSLBR_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "RichTbOpticksDetectorConstruction.hh"


/** @class RichTbGraphicsLbR RichTbGraphicsLbR.hh include/RichTbGraphicsLbR.hh
 *
 *
 *  @author Sajan Easo
 *  @date   2021-07-29
 */

class RichTbGraphicsLbR {
public:
  /// Standard constructor
  RichTbGraphicsLbR();
  RichTbGraphicsLbR(RichTbOpticksDetectorConstruction*  );
  virtual ~RichTbGraphicsLbR( ); ///< Destructor


  void setGraphicsLbRAttributes();
protected:

private:

  RichTbOpticksDetectorConstruction* curDetector;

};
#endif // INCLUDE_RICHTBGRAPHICSLBR_HH

