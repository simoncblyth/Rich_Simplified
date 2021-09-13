// $Id: $
#ifndef INCLUDE_PMTPHOTOELECTRICEFFECT_HH
#define INCLUDE_PMTPHOTOELECTRICEFFECT_HH 1

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

/** @class PmtPhotoElectricEffect PmtPhotoElectricEffect.hh include/PmtPhotoElectricEffect.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2003-12-09
 */
class PmtPhotoElectricEffect:public G4VDiscreteProcess  {
public:
  /// Standard constructor
  PmtPhotoElectricEffect(const G4String&) ;

  virtual ~PmtPhotoElectricEffect( ); ///< Destructor
  G4bool IsApplicable(const G4ParticleDefinition&  ) override;
  // is applicable for optical photon only
  G4double GetMeanFreePath(const G4Track& ,
                                 G4double ,
                                 G4ForceCondition* condition) override;
  //returns infinity (max integer possible) . This means the process does
  // not limit the step, but sets the Forced condition for the DoIt to be
  // invoked at every step. But only at the boundary between Hpd quartz
  // window and the Hpd photocathode any action be taken.
  G4VParticleChange* PostStepDoIt(const G4Track& aTrack,
                                       const G4Step&  aStep) override;
  //The method for implementing the PmtPhotoelectric effect.
  G4double getPmtQEff(G4int, G4double);
  // To interpolate the QE from QE data.
  G4double getPmtPhElectronMomentum()
  {return PmtPhElectronMomentum; }
  G4double getPhCathodeToSilDetDist()
  {return PhCathodeToSilDetDist; }

  G4int getNumPmtTot()
  {
    return  NumPmtTot;
  }


G4int getNumQEbins()
{
  return NumQEbins;
}

protected:

private:

	G4int NumPmts_; // TESTnumPmts

  G4int NumPmtTot;

  G4int NumQEbins;
  G4String PrePhotoElectricVolName;
  G4String PostPhotoElectricVolName;
  G4double PmtPhElectronMomentum;
  G4double PhCathodeToSilDetDist;


  std::vector<std::vector<G4double> >PmtQE;
  std::vector<std::vector<G4double> >PmtWabin;

};
#endif // INCLUDE_PMTPHOTOELECTRICEFFECT_HH
