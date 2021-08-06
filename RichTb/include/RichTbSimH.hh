#pragma once

class G4RunManager;
class G4VPhysicalVolume;

struct Ctx;

struct RunAction;
struct EventAction;
struct TrackingAction;
struct SteppingAction;

struct RichTbDetectorConstruction;
class L4Cerenkov;
template <typename T> struct PhysicsList;
//struct RichTbPhysicsList;
class RichScintillation;

//struct RichTbPhysicsList;
struct PrimaryGeneratorAction;

struct RichTbSimH
{
    RichTbSimH();
    ~RichTbSimH();

    void init();
    void beamOn(int num_ev); 

    Ctx*	ctx;
    G4RunManager*	rm;
    RichTbDetectorConstruction*	dc;
    //RichTbPhysicsList*	pl;
    PhysicsList<L4Cerenkov>*	pl;
    PrimaryGeneratorAction*	ga;

    RunAction*   ra;
    EventAction* ea;
    TrackingAction* ta;
    SteppingAction*  sa;

};
