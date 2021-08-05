#include "OPTICKS_LOG.hh"
#include "RichTbSimH.hh"

int main( int argc, char** argv )
{
    OPTICKS_LOG( argc, argv );

    RichTbSimH rich;
    rich.beamOn(3);

    return 0;
}
