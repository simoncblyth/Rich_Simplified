#pragma once

class G4RunManager;
class G4VPhysicalVolume;

struct Ctx;

struct RunAction;
struct EventAction;
struct TrackingAction;
struct SteppingAction;

class RichTbOpticksDetectorConstruction;
class L4Cerenkov;
template <typename T> struct PhysicsList;
//struct RichTbPhysicsList;
class RichScintillation;

//struct RichTbPhysicsList;
struct PrimaryGeneratorAction;

struct RichTbSimH
{
    RichTbSimH( int argc, char** argv, const char* argforced );
    ~RichTbSimH();

    void init();
    double beamOn(int num_ev); 
    void Finalize();

    Ctx*	ctx;
    G4RunManager*	rm;
    RichTbOpticksDetectorConstruction*	dc;
    //RichTbPhysicsList*	pl;
    PhysicsList<L4Cerenkov>*	pl;
    PrimaryGeneratorAction*	ga;

    RunAction*   ra;
    EventAction* ea;
    TrackingAction* ta;
    SteppingAction*  sa;

};
