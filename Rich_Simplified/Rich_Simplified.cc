#include "OPTICKS_LOG.hh"
#include "RichTbSimH.hh"

int main( int argc, char** argv, const char* argforced )
{
    OPTICKS_LOG( argc, argv );

    RichTbSimH rich( argc, argv, argforced );
    rich.beamOn(1);

    return 0;
}
