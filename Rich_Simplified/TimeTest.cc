#include "OPTICKS_LOG.hh"
#include "RichTbSimH.hh"
#include <iostream>
#define DEBUG

#ifdef WITH_OPTICKS
#include "G4TransportationManager.hh"
#include "G4Opticks.hh"
#endif

int main( int argc, char** argv )
{
    OPTICKS_LOG( argc, argv );
    const char* argforced = "" ; 

#ifdef WITH_OPTICKS
    std::cout << "WITH_OPTICKS" << std::endl ; 
#else
    std::cout << "not WITH_OPTICKS" << std::endl ; 
#endif


    //RichTbSimH rich1( argc, argv, argforced );
    
    //int events[] = {1, 10, 50, 200, 1000};
    int events[] = {1, 10, 1, 1, 1};
    double g4_time[] = {0,0,0,0,0};

    //for(int i=0; i<5; i++)  g4_time[i] = rich1.beamOn(events[i]);
    //for(int i=0; i<5; i++) std::cout << events[i] << "\t" << g4_time[i] << "\t";
    //std::cout << std::endl;
    //rich1.Finalize();

    RichTbSimH rich2( argc, argv, argforced );

    double total_time[] = {0,0,0,0,0};

    //for(int i=0; i<5; i++) total_time[i] = rich2.beamOn(events[i]);

    for(int i=0; i<5; i++) std::cout << events[i] << "\t" << total_time[i]-g4_time[i] << "\t";
    std::cout << std::endl;

#ifdef WITH_OPTICKS
    std::cout << "\n\n###[ G4Opticks.Finalize\n\n" << std::endl ;
    G4Opticks::Finalize();
    std::cout << "\n\n###] G4Opticks.Finalize\n\n" << std::endl ;
#endif
    rich2.Finalize();
    return 0;
}
