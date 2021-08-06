// $Id: $
// Include files 
#include "globals.hh"
#include "G4Material.hh"
#include "Randomize.hh"
#include "RichTbMaterialParameters.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMiscNames.hh"
#include "RichTbGeometryParameters.hh"
#include "G4TransportationManager.hh"
#include "G4TouchableHistory.hh"
// local
#include "HpdSiEnergyLoss.hh"
#include "RichTbPhotoElectron.hh"
#include "RichTbPeUserInfoAttach.hh"
//-----------------------------------------------------------------------------
// Implementation file for class : HpdSiEnergyLoss
//
// 2003-12-10 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
HpdSiEnergyLoss::HpdSiEnergyLoss(const G4String& processName )
// :G4VEnergyLoss(processName), 
  : G4VContinuousDiscreteProcess(processName),
    MinKineticEnergy(1.* CLHEP::eV),MipEnergy(30000.0 * CLHEP::eV),finalRangeforStep(0.15* CLHEP::mm)  
 {

  static const G4MaterialTable* theMaterialTable = 
                     G4Material::GetMaterialTable();
  ElossMaterialName=  HpdSiDetMaterialName;
  EkillMaterialName=  HpdEnvelopeMaterialName;
  
  
  G4int numberOfMat= (G4int) ((*theMaterialTable).size()) ;
  //  G4cout<<"Hpd Si Eloss number of Mat "<<numberOfMat<<G4endl;
  G4int iMat=0;
  fMatIndex=-1;

  while(iMat<numberOfMat && fMatIndex < 0  ) {
    if ( ElossMaterialName == (*theMaterialTable)[iMat]->GetName()){
      fMatIndex=(*theMaterialTable)[iMat]->GetIndex();
      //  G4cout<<"Hpd Si energy Loss construct Material "<<ElossMaterialName
      //      <<"   "<< fMatIndex<<G4endl;
    }
    iMat++;
    
  }
  
  G4int iMatK=0;
  fMatIndexK=-1;
  while(iMatK<numberOfMat && fMatIndexK < 0  ) {
    if ( EkillMaterialName == (*theMaterialTable)[iMatK]->GetName()){
      fMatIndexK=(*theMaterialTable)[iMatK]->GetIndex();
      //  G4cout<<"Hpd Si Energy Loss: hpd endcap  Material "
      //    <<EkillMaterialName
      //      <<"   "<< fMatIndexK<<G4endl;
    }
    iMatK++;
    
  }


  if(iMat > numberOfMat ||  iMatK >  numberOfMat ) {
    G4cout<<"Invalid material Name in HpdSiEnergyLoss constructor" <<G4endl;
  }
     G4cout<<GetProcessName() <<" is created "<<G4endl;
  

}
//=============================================================================
// Destructor
//=============================================================================
HpdSiEnergyLoss::~HpdSiEnergyLoss() {} 
G4bool HpdSiEnergyLoss::IsApplicable(const G4ParticleDefinition& 
                                     aParticleType) {
   return(aParticleType.GetPDGCharge()!= 0.);
}

G4double HpdSiEnergyLoss::GetContinuousStepLimit(const G4Track& track,
                                                 G4double /* previousStepSize */,
                                                 G4double /* currentMinimumStep */,
                                                 G4double& /* currentSafety*/){

  G4double  RangeForStep =  finalRangeforStep;

  if( ( fMatIndex != (int) track.GetMaterial() -> GetIndex()) && 
      ( fMatIndexK != (int) track.GetMaterial() -> GetIndex()) ) { 
    RangeForStep = DBL_MAX;
  }
    
   
  return RangeForStep;

}
G4double  HpdSiEnergyLoss::GetMeanFreePath(const G4Track& /* track */,
                         G4double /* previousStepSize */,
                         G4ForceCondition* condition) {
  // return infinity so that it does nothing.
  *condition = NotForced;
  return DBL_MAX;

}
G4VParticleChange*  HpdSiEnergyLoss::PostStepDoIt(const G4Track& aTrack,
                                 const G4Step& aStep) {
  // Do nothing
   aParticleChange.Initialize(aTrack) ;
  return G4VContinuousDiscreteProcess::PostStepDoIt(aTrack,aStep);
   
}
G4VParticleChange* HpdSiEnergyLoss::AlongStepDoIt(const G4Track& aTrack,
                                                  const G4Step& /* aStep */) {

  //  G4cout<<" Now in  HpdSiEnergyLoss alongstep "<<G4endl;
  
  aParticleChange.Initialize(aTrack);
  G4int aMaterialIndex =  (G4int) aTrack.GetMaterial()->GetIndex();
  // G4String aMaterialName =  aTrack.GetMaterial()->GetName();
  // G4cout<<" HpdSiEnergyLoss  fmatindex fmatindexK  material index "<< fMatIndex <<"  "
  //      << fMatIndexK <<"   "<< aMaterialIndex <<"  "<< aMaterialName <<G4endl;
  

  // if( ( fMatIndex != (int) aTrack.GetMaterial()->GetIndex() ) && 
  //     (fMatIndexK != (int) aTrack.GetMaterial()->GetIndex()  ) ) {
  if( ( fMatIndex !=  aMaterialIndex  ) && 
      (fMatIndexK !=  aMaterialIndex    ) ) {
    return &aParticleChange;
  }
  const G4DynamicParticle* aParticle = aTrack.GetDynamicParticle();
   G4double aKinEnergyInitParticle=aParticle->GetKineticEnergy(); 
   G4double aKinEnergyInit = aKinEnergyInitParticle;
    G4String  aCreatorProcessName= "NullProcess";
    const G4VProcess* aProcess = aTrack.GetCreatorProcess();
    if(aProcess) aCreatorProcessName =  aProcess->GetProcessName();
    // if the particle hits the hpd envelope or the endcap
    // return. If it is a photoelectron hitting the
    // endcap or envelope kill the photoelectron.
    if( fMatIndexK ==   (G4int) aTrack.GetMaterial() -> GetIndex()){
      if( aCreatorProcessName ==  HpdPhotElectProc) {
       aParticleChange.ProposeTrackStatus(fStopAndKill);
       aParticleChange.ProposeEnergy(0.0);
       // aParticleChange.SetStatusChange(fStopAndKill);        
      }      
      return &aParticleChange;
    }

    // if( aCreatorProcessName != HpdPhotElectProc )   G4cout<<" Hpd energy loss proc  " << aCreatorProcessName <<G4endl;
    
    RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
  //  G4int aNonOptimalHpdCondition=  rConfig-> getNonOptimalHpdCondition();     
  // G4double aNonOptimalHpdAbsEff = rConfig->getNonOptimalHpdAbsEff();
   
  G4double Eloss, aKinEnergyFinal;
  //     G4cout<<" Now in Hpd Si energy loss with pheln initial energy = "
  //      << aKinEnergyInit<<G4endl;
  
  if(aKinEnergyInit < MinKineticEnergy ) {  Eloss=0.0 ; }
  else if( aKinEnergyInit < MipEnergy ) {Eloss= aKinEnergyInit ;}
  else { Eloss = MipEnergy; }


  // if( aCreatorProcessName != HpdPhotElectProc )G4cout<<" backsca energy loss "<<Eloss <<G4endl;
  

  aKinEnergyFinal=aKinEnergyInit-Eloss;

  //Now implement the back scattering in an ad hoc manner.

  //  G4double Effs = 1.0 -  backscaprob * bckKillFactor;
  G4double Effs = HpdelectronicsDetAbsEff;
  
  //  if( aNonOptimalHpdCondition >= 1 ) 
  //  {
  //    Effs =  aNonOptimalHpdAbsEff;
  //   }

//   G4cout << "Back scattering: " << Effs << G4endl;
  
  //  G4cout<<"Hpd Si energy loss Effs "<< Effs<<G4endl;

  G4double Randbsk =  G4UniformRand();
  //  G4cout<<"Hpd Si energy loss Effs randbsk "<< Effs
  //      <<"   "<< Randbsk<<G4endl;

  if(Randbsk <= Effs && Eloss > 0.0 ) 
    {
      //   G4cout<<"Now deposting energy in Silicon Eloss=  " 
  	  //  <<Eloss<<G4endl;
    
      //aParticleChange.SetLocalEnergyDeposit(Eloss);  
      aParticleChange.ProposeLocalEnergyDeposit(Eloss);

      // Now to create backscattered electrons

      G4double abackScaProb =  rConfig->getHpdpeBackScaProb();
      
      if( abackScaProb > 0.0 ) {

         G4double aBckRnd = G4UniformRand();
         if( aBckRnd < abackScaProb ) {
           
         if( aCreatorProcessName  == HpdPhotElectProc) {

          G4double RandXposition =  G4UniformRand() -0.5;
          G4double RandYposition =  G4UniformRand() -0.5;
          G4ThreeVector LocalElectronDirection( 0,0 ,1 );
          G4ThreeVector LocalElectronOrigin( RandXposition*RichTbHpdSiDetRadiusSize,
                                             RandYposition*RichTbHpdSiDetRadiusSize , -0.5*RichTbHpdSiDetZSize-1.0);
         G4Navigator* theNavigator = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
         G4ThreeVector GlobalElectronOrigin = theNavigator->GetLocalToGlobalTransform().TransformPoint(LocalElectronOrigin);
         const G4ThreeVector GlobalElectronDirection = theNavigator->
                                GetLocalToGlobalTransform().TransformAxis(LocalElectronDirection);

         G4double aPElectronTime= aTrack.GetGlobalTime();

         G4double aElecKineEnergyForTracking=(rConfig ->getHpdPEMomInit() ) * CLHEP::keV;
         
         G4DynamicParticle* aElectron= 
	            new G4DynamicParticle (RichTbPhotoElectron::PhotoElectron() ,
                                 GlobalElectronDirection, aElecKineEnergyForTracking) ;

         G4Track * aSecPETrack =
	             new G4Track(aElectron,aPElectronTime,GlobalElectronOrigin);
         
          aSecPETrack->SetTouchableHandle((G4VTouchable*)0);
          aSecPETrack->SetParentID(aTrack.GetTrackID());
          aSecPETrack->SetGoodForTrackingFlag(true);



          G4Track* aTaggedSecPETrack = RichTbPeBckAttach(aTrack,aSecPETrack );
          // G4cout<<"Created a backsca electron "<<G4endl;
          
          aParticleChange.AddSecondary(aTaggedSecPETrack);
          //kill old pe
          aParticleChange.ProposeTrackStatus(fStopAndKill);
          aParticleChange.ProposeEnergy(0.0);

         }
         
      }
      
         
      }
      



    }
  
  //  if( aCreatorProcessName != HpdPhotElectProc )G4cout<<" Kinnergy final finalke "<<aKinEnergyFinal<<"  "                       
  //   << MinKineticEnergy<<  G4endl;
  
  if (aKinEnergyFinal <= MinKineticEnergy ) 
    {
      //   aParticleChange.SetStatusChange(fStopAndKill);
      aParticleChange.ProposeTrackStatus(fStopAndKill);
      aParticleChange.ProposeEnergy(0.0);
      
    }
  else 
    { 
      aParticleChange.ProposeEnergy(aKinEnergyFinal);
      //    aParticleChange.SetEnergyChange(aKinEnergyFinal);
    }


  

  return &aParticleChange;
}

//=============================================================================
