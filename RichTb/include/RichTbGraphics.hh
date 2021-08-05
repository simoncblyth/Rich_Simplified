#ifndef RichTbGraphics_h
#define RichTbGraphics_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "RichTbUpgradeDetectorConstruction.hh"
#include "RichTbGraphicsAuxA.hh"

class RichTbGraphics {

  public:

    RichTbGraphics();
    RichTbGraphics(RichTbDetectorConstruction* );
    virtual ~ RichTbGraphics();

   void setAllGraphicsAttributes();
   void setRichTbHallGraphicsAttibutes();
   void setRichTbDetectorGeometryGraphicsAttributes();
   void setRichTbDetectorGeometryPhDetGraphicsAttributes();
  
  
  private:

  RichTbDetectorConstruction* curDetector;
  RichTbGraphicsAuxA* curRichTbGraphicsAuxA;
  
  
};
#endif                          /*RichTbGraphics_h */
