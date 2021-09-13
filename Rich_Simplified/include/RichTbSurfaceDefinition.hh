// $Id: $
#ifndef INCLUDE_RICHTBSURFACEDEFINITION_HH 
#define INCLUDE_RICHTBSURFACEDEFINITION_HH 1

// Include files
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4OpticalSurface.hh"
#include "RichTbRunConfig.hh"
#include <vector>

/** @class RichTbSurfaceDefinition RichTbSurfaceDefinition.hh include/RichTbSurfaceDefinition.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-24
 */
class RichTbSurfaceDefinition {
public:

  virtual ~RichTbSurfaceDefinition( ); ///< Destructor

  static RichTbSurfaceDefinition* getRichTbSurfaceDefinitionInstance();
  

  G4OpticalSurface* getRichTbSphMirrorSurface() 
  {
    return  RichTbSphMirrorSurface;
  }
  G4OpticalSurface* getRichTbVesselSurface()
  {
    return RichTbVesselSurface;
  }
  G4OpticalSurface* getRichTbPMTMasterQuartzWSurface()
  {
    return RichTbPMTMasterQuartzWSurface;
  }
  G4OpticalSurface* getRichTbPMTQuartzWPhCathodeSurface()
  {
    return RichTbPMTQuartzWPhCathodeSurface;
  }
  G4OpticalSurface* getRichTbKovarSurface() {
    return RichTbKovarSurface;}
  G4OpticalSurface* getRichTbSiDetSurface() {
    return RichTbSiDetSurface;}

  void createMirrorOpticalSurface();
  void createVesselSurface();
  void createPMTQuartzWSurface();
  void createPMTQuartzWPhCathodeSurface();
  void ReadMirrorReflectivity();
  void createRichTbKovarSurface();
  void createtRichTbSiDetSurface();
  
protected:

private:

  /// Standard constructor
  RichTbSurfaceDefinition( ); 

  static  RichTbSurfaceDefinition*  RichTbSurfaceDefinitionInstance;
  
  G4OpticalSurface* RichTbSphMirrorSurface;
  G4OpticalSurface* RichTbVesselSurface;
  G4OpticalSurface* RichTbPMTMasterQuartzWSurface;
  G4OpticalSurface* RichTbPMTQuartzWPhCathodeSurface;
  G4OpticalSurface* RichTbKovarSurface;
  G4OpticalSurface* RichTbSiDetSurface;  
  std::vector<G4double> MirrorSurfWlen;
  std::vector<G4double> MirrorSurfReflect;

};
#endif // INCLUDE_RICHTBSURFACEDEFINITION_HH
