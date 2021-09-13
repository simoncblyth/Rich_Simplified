// $Id: $
#ifndef INCLUDE_RICHTBROGEOMETRY_HH 
#define INCLUDE_RICHTBROGEOMETRY_HH 1

// Include files
#include "globals.hh"
#include "G4VReadOutGeometry.hh"
#include "G4VPhysicalVolume.hh"


/** @class RichTbROGeometry RichTbROGeometry.hh include/RichTbROGeometry.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-11
 */
class RichTbDetectorConstruction;

class RichTbROGeometry:public G4VReadOutGeometry  {
public: 
  /// Standard constructor
  RichTbROGeometry(G4String, RichTbDetectorConstruction* ); 

  virtual ~RichTbROGeometry( ); ///< Destructor

  G4VPhysicalVolume* Build() override;

  RichTbDetectorConstruction* getCurDet() 
  {
    return CurDet;
  }
  
protected:

private:
  RichTbDetectorConstruction* CurDet;
  
};
#endif // INCLUDE_RICHTBROGEOMETRY_HH
