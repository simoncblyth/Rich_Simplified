#include "PrimaryGeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleGun.hh"

#ifdef WITH_OPTICKS
#include "G4Opticks.hh"
#endif





using CLHEP::MeV ; 

PrimaryGeneratorAction::PrimaryGeneratorAction(Ctx* ctx_)
    :
    G4VUserPrimaryGeneratorAction(),
    ctx(ctx_),
    fParticleGun(new G4ParticleGun(1))
{
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("e+");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleTime(0.0*CLHEP::ns);
    fParticleGun->SetParticlePosition(G4ThreeVector(0.0*CLHEP::cm,0.0*CLHEP::cm,0.0*CLHEP::mm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.1,1.));
    fParticleGun->SetParticleEnergy(4000.*MeV);   // few photons at ~0.7*MeV loads from ~ 0.8*MeV
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    fParticleGun->GeneratePrimaryVertex(anEvent);

#ifdef WITH_OPTICKS
    // not strictly required by Opticks, but useful for debugging + visualization of non-opticals
    //G4Opticks::Get()->collectPrimaries(anEvent) ;  
#endif

}


 
