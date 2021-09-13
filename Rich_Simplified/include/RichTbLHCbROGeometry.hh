// $Id: $
#ifndef INCLUDE_RICHTBLHCBROGEOMETRY_HH 
#define INCLUDE_RICHTBLHCBROGEOMETRY_HH 1

// Include files
#include "globals.hh"
#include "G4VReadOutGeometry.hh"
#include "G4VPhysicalVolume.hh"


/** @class RichTbLHCbROGeometry RichTbLHCbROGeometry.hh include/RichTbLHCbROGeometry.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-11
 *  Mod SE 2021-08-07
 */
class RichTbOpticksDetectorConstruction;

class RichTbLHCbROGeometry:public G4VReadOutGeometry  {
public: 
  /// Standard constructor
  RichTbLHCbROGeometry(G4String, RichTbOpticksDetectorConstruction* ); 

  virtual ~RichTbLHCbROGeometry( ); ///< Destructor

  G4VPhysicalVolume* Build() override;

  RichTbOpticksDetectorConstruction* getCurDet() 
  {
    return CurDet;
  }
  
protected:

private:
  RichTbOpticksDetectorConstruction* CurDet;
  
};
#endif // INCLUDE_RICHTBLHCBROGEOMETRY_HH
