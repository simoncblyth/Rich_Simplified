#include "OPTICKS_LOG.hh"
#include "RichTbSimH.hh"

//#define WITH_OPTICKS

int main( int argc, char** argv )
{
    OPTICKS_LOG( argc, argv );

    const char* argforced = "" ; 
    RichTbSimH rich( argc, argv, argforced );
    double time = rich.beamOn(1);

    LOG(info) << time ; 

    return 0;
}
