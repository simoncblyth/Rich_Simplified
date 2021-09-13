#ifndef INCLUDE_RICHTBROGEOMETRYHPD_HH 
#define INCLUDE_RICHTBROGEOMETRYHPD_HH 1

// Include files
#include "globals.hh"
#include "G4VReadOutGeometry.hh"
#include "G4VPhysicalVolume.hh"

class RichTbDetectorConstruction;


/** @class RichTbROGeometryHpd RichTbROGeometryHpd.hh include/RichTbROGeometryHpd.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2015-05-16
 */
class RichTbROGeometryHpd:public G4VReadOutGeometry  {
public: 
  /// Standard constructor
  RichTbROGeometryHpd(G4String, RichTbDetectorConstruction* ); 

  virtual ~RichTbROGeometryHpd( ); ///< Destructor

  G4VPhysicalVolume* Build() override;
  RichTbDetectorConstruction* getCurDet()
  {
    return CurDet;
  }


protected:

private:
  RichTbDetectorConstruction* CurDet;
};
#endif // INCLUDE_RICHTBROGEOMETRYHPD_HH
