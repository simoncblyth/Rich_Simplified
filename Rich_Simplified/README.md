# Rich Simplified example
An example shows the interface of Opticks with Geant4, based on the Simplified RICH project (https://gitlab.cern.ch/seaso/richgpuopticks/-/tree/master/RichTbLHCbOpticks/cmtuser/RichTbSimH) and CerenkovMinimal example (https://bitbucket.org/simoncblyth/opticks/src/master/examples/Geant4/CerenkovMinimal/).

1. How to use it? 
   You need to change some code in Opticks, please refer to ../Mychanges.cc for more details. 
   Copy the Rich_Simplified directory to opticks/examples/Geant4/, and 
   `source build.sh` or `./build.sh clean` 
   `cd build && ./Rich_Simplified` 

2. The current running results can be found in Rich_Simplified_Sep_13.log. 
   The geometry is set properly, but no hits are collected. 
