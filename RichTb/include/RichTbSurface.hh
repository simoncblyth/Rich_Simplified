// $Id: $
#ifndef INCLUDE_RICHTBSURFACE_HH 
#define INCLUDE_RICHTBSURFACE_HH 1

// Include files
#include "RichTbSurfaceDefinition.hh"


/** @class RichTbSurface RichTbSurface.hh include/RichTbSurface.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-25
 */
class RichTbDetectorConstruction;

class RichTbSurface {
public:
  /// Standard constructor
  RichTbSurface(RichTbDetectorConstruction*  ); 

  virtual ~RichTbSurface( ); ///< Destructor

  RichTbDetectorConstruction* getcurDet()
  {    return curDet; }

  void createBorderSurfaces();
  
    
protected:

private:

  RichTbDetectorConstruction* curDet;
  

};
#endif // INCLUDE_RICHTBSURFACE_HH
