// $Id: $
#ifndef INCLUDE_RICHTBLHCBSURFACE_HH 
#define INCLUDE_RICHTBLHCBSURFACE_HH 1

// Include files
#include "RichTbSurfaceDefinition.hh"


/** @class RichTbLHCbSurface RichTbLHCbSurface.hh include/RichTbLHCbSurface.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-25
 *  Mod     2021-08-10
 */

class RichTbOpticksDetectorConstruction;

class RichTbLHCbSurface {
public:
  /// Standard constructor
  RichTbLHCbSurface(RichTbOpticksDetectorConstruction*  ); 

  virtual ~RichTbLHCbSurface( ); ///< Destructor

  RichTbOpticksDetectorConstruction* getcurDet()
  {    return curDet; }

  void createLHCbBorderSurfaces();
  
    
protected:

private:

  RichTbOpticksDetectorConstruction* curDet;
  

};
#endif // INCLUDE_RICHTBLHCBSURFACE_HH
