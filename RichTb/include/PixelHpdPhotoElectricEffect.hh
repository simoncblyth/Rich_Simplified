// $Id: $
#ifndef INCLUDE_PIXELHPDPHOTOELECTRICEFFECT_HH 
#define INCLUDE_PIXELHPDPHOTOELECTRICEFFECT_HH 1

// Include files
#include "G4ios.hh" 
#include "globals.hh"
#include "Randomize.hh" 
#include "G4VDiscreteProcess.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4DynamicParticle.hh"
#include "G4OpticalPhoton.hh" 
#include "G4Electron.hh"
#include "G4Step.hh"
#include "RichTbMaterialParameters.hh"
#include <vector>
#include "RichTbRunConfig.hh"

/** @class PixelHpdPhotoElectricEffect PixelHpdPhotoElectricEffect.hh include/PixelHpdPhotoElectricEffect.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-09
 */
class PixelHpdPhotoElectricEffect:public G4VDiscreteProcess  {
public: 
  /// Standard constructor
  PixelHpdPhotoElectricEffect(const G4String&) ; 

  virtual ~PixelHpdPhotoElectricEffect( ); ///< Destructor
  G4bool IsApplicable(const G4ParticleDefinition&  );
  // is applicable for optical photon only
  G4double GetMeanFreePath(const G4Track& ,
                                 G4double ,
                                 G4ForceCondition* condition);
  //returns infinity (max integer possible) . This means the process does
  // not limit the step, but sets the Forced condition for the DoIt to be
  // invoked at every step. But only at the boundary between Hpd quartz 
  // window and the Hpd photocathode any action be taken.
  G4VParticleChange* PostStepDoIt(const G4Track& aTrack,
                                       const G4Step&  aStep);
  //The method for implementing the HpdPhotoelectric effect.
  G4double getHpdQEff(G4int, G4double);
  // To interpolate the QE from QE data.
  G4double getHpdPhElectronMomentum() 
  {return HpdPhElectronMomentum; }
  G4double getPhCathodeToSilDetDist()
  {return PhCathodeToSilDetDist; }
  std::vector<G4double> getHpdDemag(G4int hpdnum) 
   {return DemagnificationFactor[hpdnum]; }
  G4double getHpdDemagLinearTerm(G4int hpdnum) 
   {return DemagnificationFactor[hpdnum][1]; }
  G4int getNumHpdTot() 
  {
    return  NumHpdTot;
  }
G4double getHpdPhCathodeRInner()
{return HpdPhCathodeRInner;}

G4int getNumDemagParam()
{
  return  NumDemagParam;
}
G4int getNumQEbins()
{
  return NumQEbins;
}

protected:

private:

  G4int NumHpdTot;
  G4int NumDemagParam;
  G4int NumQEbins;
  G4String PrePhotoElectricVolName;
  G4String PostPhotoElectricVolName;
  G4double HpdPhElectronMomentum;
  G4double PhCathodeToSilDetDist;
  G4double  HpdPhCathodeRInner;
  G4double PSFsigma;
  std::vector<std::vector<G4double> >DemagnificationFactor;
  std::vector<std::vector<G4double> >HpdQE;
  std::vector<std::vector<G4double> >HpdWabin;

};
#endif // INCLUDE_PIXELHPDPHOTOELECTRICEFFECT_HH
