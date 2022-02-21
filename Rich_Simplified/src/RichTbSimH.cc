#include "G4RunManager.hh"
#include "G4GeometryManager.hh"

#include "RichTbSimH.hh"

#include "RichTbOpticksDetectorConstruction.hh"
//#include "RichTbPhysicsList.hh"
#include "PhysicsList.hh"
#include "L4Cerenkov.hh"
#include "PrimaryGeneratorAction.hh"

#ifdef WITH_OPTICKS
#include "G4TransportationManager.hh"
#include "G4Opticks.hh"
#endif

#include "Ctx.hh"
#include "PLOG.hh"
#include "SSys.hh"
#include "SArgs.hh"

#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalParameters.hh"
#include "G4OpticalPhysics.hh"

#include "RunAction.hh"
#include "EventAction.hh"
#include "TrackingAction.hh"
#include "SteppingAction.hh"


RichTbSimH::RichTbSimH( int argc, char** argv, const char* argforced )
    :
    ctx(new Ctx),
    rm(new G4RunManager),
    dc(new RichTbOpticksDetectorConstruction( argc, argv, argforced )),
    pl(new PhysicsList<L4Cerenkov>( argc, argv, argforced )),
    ga(nullptr),
    ra(nullptr),
    ea(nullptr),
    ta(nullptr),
    sa(nullptr)
{
    init();
}

void RichTbSimH::init()
{
    rm->SetUserInitialization(dc);
    rm->SetUserInitialization(pl);
    //G4VModularPhysicsList* physicsList = new FTFP_BERT;
    //physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());

    //G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
    //auto opticalParams               = G4OpticalParameters::Instance();

    //opticalParams->SetWLSTimeProfile("delta");

    //opticalParams->SetScintYieldFactor(1.0);
    //opticalParams->SetScintExcitationRatio(0.0);
    //opticalParams->SetScintTrackSecondariesFirst(true);
    //opticalParams->SetScintEnhancedTimeConstants(true);

    //opticalParams->SetCerenkovMaxPhotonsPerStep(100);
    //opticalParams->SetCerenkovMaxBetaChange(10.0);
    //opticalParams->SetCerenkovTrackSecondariesFirst(true);

    //physicsList->RegisterPhysics(opticalPhysics);
    //rm->SetUserInitialization(physicsList);

    ga = new PrimaryGeneratorAction(ctx);
    ra = new RunAction(ctx) ; 
    ea = new EventAction(ctx) ; 
    ta = new TrackingAction(ctx) ; 
    sa = new SteppingAction(ctx) ; 

    rm->SetUserAction(ga);
    rm->SetUserAction(ra);
    rm->SetUserAction(ea);
    rm->SetUserAction(ta);
    rm->SetUserAction(sa);

    rm->Initialize(); 
    G4cout << " G4RunManager rm initialized successfully " << G4endl;

#ifdef WITH_OPTICKS
    G4cout << "\n\n###[ G4Opticks.setGeometry\n\n" << G4endl ;
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

    G4cout << "\n\n###] G4Opticks.setGeometry\n\n" << G4endl ;
#endif

}


RichTbSimH::~RichTbSimH()
{
    G4GeometryManager::GetInstance()->OpenGeometry(); 
}

double RichTbSimH::beamOn(int num_ev)
{
    rm->BeamOn(num_ev); 
    return ra->getTime();
}

void RichTbSimH::Finalize()
{
    delete ctx;
    delete rm;
}
