// $Id: $
// Include files

#include "G4Material.hh"
#include "Randomize.hh"
#include "RichTbMaterialParameters.hh"
#include "RichTbRunConfig.hh"

#include "G4TouchableHistory.hh" //test

// local
#include "PmtAnodeEnergyLoss.hh"

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
PmtAnodeEnergyLoss::PmtAnodeEnergyLoss(const G4String& processName )
  // :G4VEnergyLoss(processName),
 :G4VContinuousDiscreteProcess(processName),
  MinKineticEnergy(1.* CLHEP::eV),MipEnergy(30000.0* CLHEP::eV),finalRangeforStep(0.15* CLHEP::mm)
 {

  static const G4MaterialTable* theMaterialTable =
                     G4Material::GetMaterialTable();
  ElossMaterialName=  PMTAnodeMaterialName;
  EkillMaterialName=  PMTEnvelopeMaterialName;

   G4int numberOfMat= (G4int) ((*theMaterialTable).size()) ;
   // G4cout<<"Pmt Anode Eloss number of Mat "<<numberOfMat<<G4endl;
  G4int iMat=0;
  fMatIndex=-1;

  while(iMat<numberOfMat && fMatIndex < 0  ) {
    if ( ElossMaterialName == (*theMaterialTable)[iMat]->GetName()){
      fMatIndex=(*theMaterialTable)[iMat]->GetIndex();
      // G4cout<<"PMT anode energy Loss construct Material "<<ElossMaterialName
      //     <<"   "<< fMatIndex<<G4endl;
    }
    iMat++;

  }

  G4int iMatK=0;
  fMatIndexK=-1;
  while(iMatK<numberOfMat && fMatIndexK < 0  ) {
    if ( EkillMaterialName == (*theMaterialTable)[iMatK]->GetName()){
      fMatIndexK=(*theMaterialTable)[iMatK]->GetIndex();
      // G4cout<<"Pmt Anode Energy Loss: pmt envelope  Material "
      //   <<EkillMaterialName
      //    <<"   "<< fMatIndexK<<G4endl;
    }
    iMatK++;

  }

  if(iMat > numberOfMat ||  iMatK >  numberOfMat ) {
    // G4cout << "Invalid material Name in PmtAnodeEnergyLoss constructor" <<G4endl ;
  }
  //  G4cout<<GetProcessName() <<" is created "<<G4endl;


 }


PmtAnodeEnergyLoss::~PmtAnodeEnergyLoss() {}


G4bool PmtAnodeEnergyLoss::IsApplicable(const G4ParticleDefinition&
                                     aParticleType) {
   return(aParticleType.GetPDGCharge()!= 0.);
}
G4VParticleChange* PmtAnodeEnergyLoss::AlongStepDoIt(const G4Track& aTrack,const G4Step& /* aStep */ ) {
	//                                 const G4Step& ) {

  aParticleChange.Initialize(aTrack);
  // G4int aMaterialIndex = aTrack.GetMaterial()->GetIndex();
  if( ( fMatIndex != (int) aTrack.GetMaterial()->GetIndex() ) &&
      (fMatIndexK != (int) aTrack.GetMaterial()->GetIndex()  ) ) {
    return &aParticleChange;
  }
  RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();

  //G4cout << "pmt anode energy loss   " << aTrack.GetMaterial()->GetName()<< G4endl;
  const G4DynamicParticle* aParticle = aTrack.GetDynamicParticle();
   G4double aKinEnergyInitParticle=aParticle->GetKineticEnergy();
   G4double aKinEnergyInit = aKinEnergyInitParticle;
    G4String  aCreatorProcessName= "NullProcess";
    const G4VProcess* aProcess = aTrack.GetCreatorProcess();
    if(aProcess) aCreatorProcessName =  aProcess->GetProcessName();
    //G4cout << "pmt anode energy loss particle creator process name "<<  aCreatorProcessName<<G4endl;

    if( aCreatorProcessName ==  PmtPhotElectProc) {
      aKinEnergyInit = aKinEnergyInitParticle/100000;

      if( fMatIndexK ==   (G4int) aTrack.GetMaterial() -> GetIndex()){

       aParticleChange.ProposeTrackStatus(fStopAndKill);
       aParticleChange.ProposeEnergy(0.0);
       // aParticleChange.SetStatusChange(fStopAndKill);
      return &aParticleChange;
      }

    }

    //begin test
    //	G4StepPoint* pPreStepPoint  = aStep.GetPreStepPoint();
  //	G4StepPoint* pPostStepPoint = aStep.GetPostStepPoint();
//
//    G4TouchableHistory* CurTT =
//    			(G4TouchableHistory*)(pPreStepPoint->GetTouchable());
//
//    	// CurTT -> MoveUpHistory(2);
//    	G4int currentPmtNumber= CurTT -> GetReplicaNumber(2);
//
	//	G4cout<<"current Energy Loss PMT number "<<currentPmtNumber<<G4endl;
    //end test


    G4double Eloss, aKinEnergyFinal;
   if(aKinEnergyInit < MinKineticEnergy ) {  Eloss=0.0 ; }
    else if( aKinEnergyInit < MipEnergy ) { Eloss= aKinEnergyInit ;}
    else { Eloss = MipEnergy; }


   // G4cout<< "Eloss = "<<Eloss<<G4endl;
  aKinEnergyFinal=aKinEnergyInit-Eloss;

  // Now apply the detection efficiency. When pixel efficiency is applied, this
  // detection efficiency is not applied.

  G4double EnergyTransfer = Eloss;

  if( ! (rConfig -> ApplyPixelEff()) ) {
     G4double Effrandom =  G4UniformRand();
     if( Effrandom > ( rConfig -> getMapmtDetectionEfficiency() ) )
     { EnergyTransfer =0.0; }
     //    G4cout<<" Overall eff "<<Effrandom<<"  "<< rConfig -> getMapmtDetectionEfficiency()
     //    <<"   "<<EnergyTransfer<<G4endl;

  }




  if(EnergyTransfer > 0.0 )
    {
      //  G4cout<<"Now deposting energy in Pmt Anode Eloss=  " <<Eloss<<G4endl;

      //aParticleChange.SetLocalEnergyDeposit(Eloss);
      aParticleChange.ProposeLocalEnergyDeposit(EnergyTransfer  );
    }else if ( aKinEnergyInit >  MipEnergy )  {
     aParticleChange.ProposeLocalEnergyDeposit(Eloss);
    }


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

G4VParticleChange*  PmtAnodeEnergyLoss::PostStepDoIt(const G4Track& aTrack,
                                 const G4Step& aStep) {
  // Do nothing
   aParticleChange.Initialize(aTrack) ;
  return G4VContinuousDiscreteProcess::PostStepDoIt(aTrack,aStep);

}

G4double  PmtAnodeEnergyLoss::GetMeanFreePath(const G4Track& /*atrack */ ,
                         G4double /* previousStepSize */,
                         G4ForceCondition* condition) {
  // return infinity so that it does nothing.
  *condition = NotForced;
  return DBL_MAX;

}
G4double PmtAnodeEnergyLoss::GetContinuousStepLimit(const G4Track& track,
                                                     G4double /* previousStepSize */,
                                                     G4double /* currentMinimumStep */,
                                                     G4double& /* currentSafety */ ){

  G4double  RangeForStep =  finalRangeforStep;

  if( ( fMatIndex != (int) track.GetMaterial() -> GetIndex()) &&
      ( fMatIndexK != (int) track.GetMaterial() -> GetIndex()) ) {
    RangeForStep = DBL_MAX;
  }


  return RangeForStep;

}
