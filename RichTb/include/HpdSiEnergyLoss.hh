// $Id: $
#ifndef INCLUDE_HPDSIENERGYLOSS_HH 
#define INCLUDE_HPDSIENERGYLOSS_HH 1

// Include files

#include "globals.hh"
#include "G4VContinuousDiscreteProcess.hh"
#include "G4VParticleChange.hh"
#include "G4DynamicParticle.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"

/** @class HpdSiEnergyLoss HpdSiEnergyLoss.hh include/HpdSiEnergyLoss.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-10
 */
//class HpdSiEnergyLoss : public G4VEnergyLoss {

class HpdSiEnergyLoss : public G4VContinuousDiscreteProcess {
public: 
  /// Standard constructor
  HpdSiEnergyLoss(const G4String& processName); 

  virtual ~HpdSiEnergyLoss( ); ///< Destructor
  G4bool IsApplicable(const G4ParticleDefinition&);
  // true for all charged particles
  G4double GetContinuousStepLimit(const G4Track& track,
                                G4double previousStepSize,
                                G4double currentMinimumStep,
                                G4double& currentSafety);

 G4VParticleChange* AlongStepDoIt(const G4Track& aTrack,
                                     const G4Step& aStep) ;
 G4double GetMeanFreePath(const G4Track& track,
                          G4double previousStepSize,
                          G4ForceCondition* condition);
 G4VParticleChange* PostStepDoIt(const G4Track& aTrack,
                                            const G4Step& aStep);

  G4String getElossMaterialName()  
  {
    return ElossMaterialName;
  }
  G4String getkillMaterialName()  
  {
    return EkillMaterialName;
  }
   
private:

   // hide  assignment and copy operators
     HpdSiEnergyLoss ( HpdSiEnergyLoss &); 
     HpdSiEnergyLoss & operator=(const  HpdSiEnergyLoss &right);
 
 
protected:

private:
  //now the data members
    G4int fMatIndex;
    G4int fMatIndexK;
    G4double MinKineticEnergy ;
    G4double MipEnergy;
    G4double finalRangeforStep;   
    G4String ElossMaterialName;
    G4String EkillMaterialName;

};
#endif // INCLUDE_HPDSIENERGYLOSS_HH
