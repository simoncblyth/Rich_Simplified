#include <cassert>

#ifdef WITH_OPTICKS
#include "G4TransportationManager.hh"
#include "G4Opticks.hh"
#endif

#include "RunAction.hh"

RunAction::RunAction(Ctx* ctx_) 
    :   
    G4UserRunAction(),
    ctx(ctx_)
{
}
void RunAction::BeginOfRunAction(const G4Run*)
{
#ifdef WITH_OPTICKS
    G4cout << "\n\n###[ RunAction::BeginOfRunAction G4Opticks.setGeometry\n\n" << G4endl ; 
    G4VPhysicalVolume* world = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking()->GetWorldVolume() ; 
    assert( world ) ; 

    G4Opticks* g4ok = G4Opticks::Get(); 
    bool standardize_geant4_materials = false ;   

    const char* embedded_commandline_extra = "--skipaheadstep 1000" ; // see ~/opticks/notes/issues/raja_repeated_photons.rst 
    g4ok->setEmbeddedCommandLineExtra(embedded_commandline_extra);
    g4ok->setGeometry(world, standardize_geant4_materials );    

    const std::vector<G4PVPlacement*>& sensor_placements = g4ok->getSensorPlacements() ;
    for(unsigned i=0 ; i < sensor_placements.size()  ; i++)
    {
        float efficiency_1 = 0.5f ; 
        float efficiency_2 = 1.0f ; 
        int sensor_cat = -1 ;                   // -1:means no angular efficiency info 
        int sensor_identifier = 0xc0ffee + i ;  // mockup a detector specific identifier
        unsigned sensorIndex = 1+i ;            // 1-based
        g4ok->setSensorData( sensorIndex, efficiency_1, efficiency_2, sensor_cat, sensor_identifier );  
    }

    G4cout << "\n\n###] RunAction::BeginOfRunAction G4Opticks.setGeometry\n\n" << G4endl ; 
#endif
}
void RunAction::EndOfRunAction(const G4Run*)
{
#ifdef WITH_OPTICKS
    G4cout << "\n\n###[ RunAction::EndOfRunAction G4Opticks.Finalize\n\n" << G4endl ; 
    G4Opticks::Finalize();
    G4cout << "\n\n###] RunAction::EndOfRunAction G4Opticks.Finalize\n\n" << G4endl ; 
#endif
}

