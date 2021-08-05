//This is the declaration of the LHCb RICH Testbeam Material description.
//Author SE  1-3-2001
//
#ifndef RichTbMaterial_h
#define RichTbMaterial_h 1
#include "globals.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4OpticalSurface.hh"
#include <vector>

class RichTbMaterial {

  public:

    virtual ~ RichTbMaterial();
  static RichTbMaterial* getRichTbMaterialInstance();
  
    G4Material *getAir() {
        return RichTbAmbientAir;
    }

    G4Material *getTAir() {
        return RichTbTubeAir;
    }

    G4Material *getTAirA() {
        return RichTbAirA;
    }
   G4Material* getNitrogenGas() {return RichTbNitrogenGas;}
   G4Material* getc4f10Gas() {return RichTbc4f10Gas;}
   G4Material* getMirrorQuartz() {return RichTbMirrorQuartz;}
   G4Material* getRichTbVaccum() {return RichTbVaccum;}
   G4Material* getAluminium() {return RichTbAluminium; }
   G4Material* getCarbon() {return  RichTbCarbon;}
  
  
  
  G4Material* getPMTTubeEnvelopeMaterial() 
  {
    return PMTTubeEnvelopeMaterial;
  }
  G4Material* getPMTAnodeMaterial()
  {
    return PMTAnodeMaterial;
    
  }
  G4Material* getPMTPhCathodeMaterial() 
  {
    return PMTPhCathodeMaterial;
    
  }
  G4Material* getPMTQuartzWindowMaterial() 
  {
    return PMTQuartzWindowMaterial;
  }
  
 G4Material* getCrystalMaterial() 
  {
    return CrystalMaterial;
  }

  G4Material*   getRichTbGasWinQuartz() {return RichTbGasWinQuartz;}   
  G4Material* getHpdTubeEnvelopeMaterial (){    return HpdTubeEnvelopeMaterial;}
  G4Material* getHpdQuartzWindowMaterial ()  {  return HPDQuartzWindowMaterial;}
  G4Material* getHpdPhCathodeMaterial  ()  {  return HPDPhCathodeMaterial;}
  G4Material* getHpdSiDetMaterial ()  {  return HpdSiDetMaterial;}
  G4Material* getLTSubstrateMaterial ()  {  return LTSubstrateMaterial;}
  G4Material* getLTPhCSampleAMaterial ()  {  return LTPhCSampleAMaterial;}
  G4Material* getLTPhCSampleBMaterial ()  {  return LTPhCSampleBMaterial;}
  
  G4Material* getLTFilterSampleAMaterial()  {  return LTFilterSampleAMaterial;}
  G4Material* getLTFilterSampleBMaterial()  {  return LTFilterSampleBMaterial;}
  
  G4Material* getPolymerPlusMaterial ()  {  return PolymerPlusMaterial;}
  
  G4Material* getQuartzRadiatorMaterial() {  return QuartzRadiatorMaterial;}
  
  
  
  private:
    RichTbMaterial();
  static RichTbMaterial* RichTbMaterialInstance;
  
    G4Material * RichTbAmbientAir;
    G4Material *RichTbTubeAir;
    G4Material *RichTbAirA;

    G4Material* RichTbNitrogenGas;
    G4Material* RichTbc4f10Gas;
    G4Material* RichTbMirrorQuartz;
    G4Material* RichTbVaccum;
    G4Material* RichTbAluminium;
    G4Material*  RichTbCarbon;
    G4Material* PMTTubeEnvelopeMaterial;
    G4Material* PMTAnodeMaterial;
    G4Material* PMTQuartzWindowMaterial;
    G4Material* CrystalMaterial;
    G4Material* PMTPhCathodeMaterial;
    G4Material*   RichTbGasWinQuartz;
    G4Material* HpdTubeEnvelopeMaterial;
    G4Material* HpdQuartzWindowMaterial;
    G4Material* HpdPhCathodeMaterial;
    G4Material* HpdSiDetMaterial;
    G4Material* HPDQuartzWindowMaterial;
    G4Material* HPDPhCathodeMaterial;
    G4Material* LTSubstrateMaterial;
    G4Material* LTPhCSampleAMaterial;
    G4Material* LTPhCSampleBMaterial;
    G4Material* LTFilterSampleAMaterial;
    G4Material* LTFilterSampleBMaterial;

    G4Material* PolymerPlusMaterial;
    G4Material* QuartzRadiatorMaterial;
  


};



#endif                          /*RichTbMaterial_h */
