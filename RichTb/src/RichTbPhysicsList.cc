#include "G4ios.hh"

#include "globals.hh"
#include "RichTbPhysicsList.hh"
#include "RichTbPhotoElectron.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleWithCuts.hh"
#include "G4ParticleTable.hh"
#include "G4VUserPhysicsList.hh"
#include "G4ParticleTable.hh"
#include "G4UserPhysicsListMessenger.hh"
#include "G4UImanager.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"

#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4UnitsTable.hh"

RichTbPhysicsList::RichTbPhysicsList():G4VUserPhysicsList()
{

  // G4cout << " Now define the physics List" << std::endl;

    // default cut value  (1.0mm)
    //     defaultCutValue = 1.0* CLHEP::mm;
  defaultCutValue = 0.1 * CLHEP::mm;
    // defaultCutValue = 10.0* CLHEP::mm;

    // set energy range for SetCut calculation
    // G4ParticleWithCuts::SetEnergyRange(0.99* CLHEP::keV, 100* CLHEP::TeV);

    // pointer to the particle table
    theParticleTable = G4ParticleTable::GetParticleTable();
    theParticleIterator = theParticleTable->GetIterator();

    // UI Messenger
    //  theMessenger = new G4UserPhysicsListMessenger(this);

    //  G4cout << " End of RichTbPhyslist constructor" <<  std::endl;

}


RichTbPhysicsList::~RichTbPhysicsList()
{
}


void RichTbPhysicsList::ConstructParticle()
{
    // In this method, static member functions should be called
    // for all particles which you want to use.
    // This ensures that objects of these particle types will be
    // created in the program.

    ConstructBosons();
    ConstructLeptons();
    ConstructMesons();
    ConstructBaryons();


}


void RichTbPhysicsList::ConstructBosons()
{
    // pseudo-particles
    G4Geantino::GeantinoDefinition();
    G4ChargedGeantino::ChargedGeantinoDefinition();

    // gamma
    G4Gamma::GammaDefinition();

    // optical photon
    G4OpticalPhoton::OpticalPhotonDefinition();
}


void RichTbPhysicsList::ConstructLeptons()
{
    // leptons
    G4Electron::ElectronDefinition();
    G4Positron::PositronDefinition();
    G4NeutrinoE::NeutrinoEDefinition();
    G4AntiNeutrinoE::AntiNeutrinoEDefinition();
    G4MuonPlus::MuonPlusDefinition();
    G4MuonMinus::MuonMinusDefinition();
    G4NeutrinoMu::NeutrinoMuDefinition();
    G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();

    RichTbPhotoElectron::PhotoElectronDefinition();

}


void RichTbPhysicsList::ConstructMesons()
{
    //  mesons
    G4PionPlus::PionPlusDefinition();
    G4PionMinus::PionMinusDefinition();
    G4PionZero::PionZeroDefinition();
    G4KaonPlus::KaonPlusDefinition();
    G4KaonMinus::KaonMinusDefinition();
}


void RichTbPhysicsList::ConstructBaryons()
{
    //  barions
    G4Proton::ProtonDefinition();
    G4AntiProton::AntiProtonDefinition();
    G4Neutron::NeutronDefinition();
    G4AntiNeutron::AntiNeutronDefinition();
}


void RichTbPhysicsList::ConstructProcess()
{
    AddTransportation();
    ConstructGeneral();
    ConstructEM();
    ConstructOp();
}


#include "G4Decay.hh"

void RichTbPhysicsList::ConstructGeneral()
{
    G4Decay *theDecayProcess = new G4Decay();
    //  theParticleTable = G4ParticleTable::GetParticleTable();

    // theParticleTable-> DumpTable("ALL");
    // G4cout << "part iter " << theParticleTable-> GetIterator() <<  std::endl;
    theParticleIterator->reset();

    while ((*theParticleIterator) ()) {
        G4ParticleDefinition *particle = theParticleIterator->value();
        G4ProcessManager *pmanager = particle->GetProcessManager();
        if (theDecayProcess->IsApplicable(*particle)) {
            pmanager->AddDiscreteProcess(theDecayProcess);
            pmanager->SetProcessOrdering(theDecayProcess, idxPostStep);
              pmanager->SetProcessOrdering(theDecayProcess, idxAtRest);

        }
    }
}



#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4PhotoElectricEffect.hh"


#include "G4eMultipleScattering.hh"
#include "G4hMultipleScattering.hh"
#include "G4MuMultipleScattering.hh"


#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hIonisation.hh"

void RichTbPhysicsList::ConstructEM()
{
  G4cout << " Now creating EM processes" << G4endl;

  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
    if (particleName == "gamma") {
    // gamma
      // Construct processes for gamma
       pmanager->AddDiscreteProcess(new G4GammaConversion("conv"));
       pmanager->AddDiscreteProcess(new G4ComptonScattering("compt"));
//      pmanager->AddDiscreteProcess(new G4PhotoElectricEffect());

    } else if (particleName == "e-") {
    //electron
      // Construct processes for electron
      pmanager->AddProcess(new G4eMultipleScattering(),-1, 1, 1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2, 2);
      pmanager->AddProcess(new G4eBremsstrahlung(),   -1,-1, 3);

    } else if (particleName == "e+") {
    //positron
      // Construct processes for positron
      pmanager->AddProcess(new G4eMultipleScattering(),-1, 1, 1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2, 2);
      pmanager->AddProcess(new G4eBremsstrahlung(),   -1,-1, 3);
      pmanager->AddProcess(new G4eplusAnnihilation("annihil"),  0,-1, 4);
    } else if( particleName == "mu+" ||
               particleName == "mu-"    ) {
    //muon
     // Construct processes for muon
     pmanager->AddProcess(new G4MuMultipleScattering(),-1, 1, 1);
     pmanager->AddProcess(new G4MuIonisation(),      -1, 2, 2);
     pmanager->AddProcess(new G4MuBremsstrahlung(),  -1,-1, 3);
     pmanager->AddProcess(new G4MuPairProduction(),  -1,-1, 4);

    } else {
      if ((particle->GetPDGCharge() != 0.0) &&
          (particle->GetParticleName() != "chargedgeantino") &&
          (particle->GetParticleName() != "pe-" )) {
     // all others charged particles except geantino
       pmanager->AddProcess(new G4hMultipleScattering(),-1,1,1);
       pmanager->AddProcess(new G4hIonisation(),       -1,2,2);

      }
    }
  }

  // G4cout << " End of creating EM processes" << G4endl;

}
#include "RichTbMiscNames.hh"
#include "RichTbRunConfig.hh"

#include "RichTbG4Cerenkov.hh"
#include "G4Scintillation.hh"
#include "RichTbG4OpAbsorption.hh"
#include "RichTbG4OpRayleigh.hh"
#include "RichTbG4OpBoundaryProcess.hh"
#include "PmtPhotoElectricEffect.hh"
#include "PmtAnodeEnergyLoss.hh"
#include "PixelHpdPhotoElectricEffect.hh"
#include  "HpdSiEnergyLoss.hh"


void RichTbPhysicsList::ConstructOp()
 {
   //   G4cout << " Now creating Optical processes" << G4endl;

   // G4cout << " Now creating Cherenkov process" << G4endl;
   RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
   G4int aRadiatorConfiguration = rConfig ->getRadiatorConfiguration();


   RichTbG4Cerenkov*  theCerenkovProcess = new RichTbG4Cerenkov("RichTbCerenkov");
   PmtAnodeEnergyLoss* thePmtAnodeEnergyLossProcess = new PmtAnodeEnergyLoss("PmtAnodeEnergyLoss");

   HpdSiEnergyLoss * theHpdSiEnergyLossProcess = (aRadiatorConfiguration == 2 ) ?
     new  HpdSiEnergyLoss("HpdSiEnergyLoss") : 0;


   // G4Scintillation* theScintillationProcess =
   //                     new G4Scintillation("Scintillation");
   // G4cout << " Now creating Absorption process" << G4endl;
   RichTbG4OpAbsorption* theAbsorptionProcess     =
              new RichTbG4OpAbsorption();
   // used even in 2004 testbeam, although only neglibible effect expected.
   //  G4cout << " Now creating Rayleigh process" <<G4endl;
   //
   RichTbG4OpRayleigh*  theRayleighScatteringProcess =
              new RichTbG4OpRayleigh("RichTbG4OpRayleigh");
   // G4cout << " Now creating Boundary process" << G4endl;
   RichTbG4OpBoundaryProcess* theBoundaryProcess =
              new RichTbG4OpBoundaryProcess("RichTbG4BoundaryProcess");

   //  G4cout << " Now creating PmtPhotoElectric process" << G4endl;
   PmtPhotoElectricEffect*   thePmtPhotoElectricProcess=
      new   PmtPhotoElectricEffect(PmtPhotElectProc);

   PixelHpdPhotoElectricEffect * theHpdPhotoElectricProcess= (aRadiatorConfiguration == 2 ) ?
       new PixelHpdPhotoElectricEffect(HpdPhotElectProc) : 0;



  //   theCerenkovProcess->SetMaxNumPhotonsPerStep(300);
   theCerenkovProcess->SetMaxNumPhotonsPerStep(2000);
   theCerenkovProcess->SetTrackSecondariesFirst(true);
   // theScintillationProcess->SetScintillationYieldFactor(1.);
   // theScintillationProcess->SetTrackSecondariesFirst(true);

   //   G4OpticalSurfaceModel themodel = unified;
      G4OpticalSurfaceModel themodel = glisur;
      theBoundaryProcess->SetModel(themodel);
//
//there  seems to be a problem with the definition of
// sigma_c++ particle. Until that is solved, avoid
// creating the Cherekov process for this particle and
// avoid make tests on its process manager.
// this is to avoid a crash from the process index check.
// SE 12-1-04.

    theParticleIterator->reset();
   while( (*theParticleIterator)() ){
     G4ParticleDefinition* particle = theParticleIterator->value();
     G4ProcessManager* pmanager = particle->GetProcessManager();
     //  pmanager->DumpInfo();
     G4String particleName = particle->GetParticleName();
     if(particleName != "sigma_c++") {
       //G4ProcessVector* aList= pmanager-> GetProcessList();
       //
     //   G4cout<<" Particle name numproc Procvectsize "<<particleName
     //      <<"   "<<pmanager-> GetProcessListLength()
     //      <<"  "<< aList->size()  <<G4endl;
       // for(G4int ii=0; ii< (int) aList->size() ;ii++) {

       //   G4cout<<"Proc num name Indexes  "<<ii<< "   "
       //  << ( *aList ) [ii]->GetProcessName()
       //      << "  "<<G4endl;

       //    }


       if (theCerenkovProcess->IsApplicable(*particle)) {
              pmanager->AddContinuousProcess(theCerenkovProcess);
       }

	      //              pmanager->AddProcess(theCerenkovProcess,-1,2,-1);
              if( thePmtAnodeEnergyLossProcess-> IsApplicable(*particle)){
                pmanager-> AddProcess(thePmtAnodeEnergyLossProcess,-1,2,2);
              }

                if(theHpdSiEnergyLossProcess) {
                  if(theHpdSiEnergyLossProcess -> IsApplicable(*particle)){
                     pmanager-> AddProcess(theHpdSiEnergyLossProcess,-1,2,2);
                  }

                }








       //    G4cout<<" End of adding Cherenkov process "<<G4endl;

     //  if (theScintillationProcess->IsApplicable(*particle)) {
       //  pmanager->AddProcess(theScintillationProcess);
       //      pmanager->SetProcessOrderingToLast(theScintillationProcess, idxAtRest);
       // pmanager->SetProcessOrderingToLast(theScintillationProcess, idxPostStep);
     //  }
     if (particleName == "opticalphoton") {
       //  G4cout << " AddDiscreteProcess to OpticalPhoton " << G4endl;
       pmanager->AddDiscreteProcess(theAbsorptionProcess);
       pmanager->AddDiscreteProcess(theRayleighScatteringProcess);
       pmanager->AddDiscreteProcess(theBoundaryProcess);
       pmanager->AddDiscreteProcess(thePmtPhotoElectricProcess);
       if(theHpdPhotoElectricProcess) pmanager->AddDiscreteProcess(theHpdPhotoElectricProcess);


     }

     }





     // G4cout << " End of creating Optical processes" << G4endl;

 }

 }


void RichTbPhysicsList::SetCuts()
{
    if (verboseLevel > 1) {
        G4cout << "RichTbPhysicsList::SetCuts:";
    }
    //  " G4VUserPhysicsList::SetCutsWithDefault" method sets
    //   the default cut value for all particle types
    SetCutsWithDefault();
  if (verboseLevel>0) DumpCutValuesTable();

}
