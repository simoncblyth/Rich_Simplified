# Rich Simplified example
An example shows the interface of Opticks with Geant4, based on the Simplified RICH project (https://gitlab.cern.ch/seaso/richgpuopticks/-/tree/master/RichTbLHCbOpticks/cmtuser/RichTbSimH) and CerenkovMinimal example (https://bitbucket.org/simoncblyth/opticks/src/master/examples/Geant4/CerenkovMinimal/).

1. How to use it? 
   You need to change some code in Opticks, please refer to ../Mychanges.cc for more details. 
   Copy the Rich_Simplified directory to opticks/examples/Geant4/, and 
   `source build.sh` or `./build.sh clean` 
   `cd build && ./Rich_Simplified` 

2. The current running results can be found in Rich_Simplified_Sep_13.log. 
   The geometry is set properly, but no hits are collected. 

3. Opticks sets a border surface as is_sensor if it has non-zero efficiency (See https://bitbucket.org/simoncblyth/opticks/src/c0bb0f9dd93d6f53f0aba4ad98e052d022d9a37c/ggeo/GPropertyMap.cc#lines-289)  
   Before, the Sensitive Detector is attached to the PMT Anode, and the hits recorded by Geant4 are actually electrons?  
   Now, the SD is attached to the window, and make a border surface to the window

4. In Opticks, once a photon reaches a sensor surface and is recorded as a hit, will it be destroyed or continue travelling?
