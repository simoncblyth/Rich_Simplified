#pragma once

class G4RunManager;
class G4VPhysicalVolume;

struct Ctx;

struct RunAction;
struct EventAction;
struct TrackingAction;
struct SteppingAction;

struct SensitiveDetector;
struct RichTbDetectorConstruction;
class L4Cerenkov;
class RichScintillation;

template <typename C> struct PhysicsList;
struct PrimaryGeneratorAction;

struct RichTbSimH
{
    RichTbSimH();
    ~RichTbSimH();

    void init();
    void beamOn(int num_ev); 

    Ctx*	ctx;
    G4RunManager*	rm;
    const char* 	sdn;
    SensitiveDetector*	sd;
    RichTbDetectorConstruction*	dc;
    PhysicsList<L4Cerenkov>*	pl;
    PrimaryGeneratorAction*	ga;

    RunAction*   ra;
    EventAction* ea;
    TrackingAction* ta;
    SteppingAction*  sa;

};
