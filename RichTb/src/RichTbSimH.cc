#include "G4RunManager.hh"
#include "G4GeometryManager.hh"

#include "RichTbSimH.hh"

#include "RichTbUpgradeDetectorConstruction.hh"
//#include "RichTbPhysicsList.hh"
#include "PhysicsList.hh"
#include "L4Cerenkov.hh"
#include "PrimaryGeneratorAction.hh"


#include "Ctx.hh"
#include "PLOG.hh"
#include "SSys.hh"

#include "RunAction.hh"
#include "EventAction.hh"
#include "TrackingAction.hh"
#include "SteppingAction.hh"


RichTbSimH::RichTbSimH()
    :
    ctx(new Ctx),
    rm(new G4RunManager),
    dc(new RichTbDetectorConstruction()),
    pl(new PhysicsList<L4Cerenkov>()),
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

}


RichTbSimH::~RichTbSimH()
{
    G4GeometryManager::GetInstance()->OpenGeometry(); 
}

void RichTbSimH::beamOn(int num_ev)
{
    rm->BeamOn(num_ev); 
}

