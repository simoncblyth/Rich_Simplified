# Installation of Opticks
Some instruction about installation of Opticks on UoM GPU machines  
Prerequisite: NVIDIA OptiX 6.5+, cmake 3.12+, gcc 5+
> Opticks v0.1.6 (https://bitbucket.org/simoncblyth/opticks/commits/tag/v0.1.6)
> source /cvmfs/lhcb.cern.ch/lib/LbEnv
> source /cvmfs/lhcb.cern.ch/lib/lcg/releases/gcc/10.1.0/x86_64-centos7/setup.sh 
1. `cd ${workdir}`  #replace ${workdir} with the path where you want to install Opticks  
   `git clone https://bitbucket.org/simoncblyth/opticks`  
   `git remote -v`  #should list bitbucket.org urls  
   `git status`  
   `git pull`  
2. `cp opticks/example.opticks_config .opticks_config`  
3. edit .opticks_config  
   line 5: `export OPTICKS_HOME=${workdir}/opticks`  
   line 22: `export OPTICKS_PREFIX=${workdir}/opticks.build`  
   line 23: `export OPTICKS_CUDA_PREFIX=/usr/local/cuda`  
   line 24: `export OPTICKS_OPTIX_PREFIX=${workdir}/NVIDIA-OptiX-SDK-6.5.0-linux64`  
   line 31:	`opticks-prepend-prefix ${workdir}/opticks.build_externals/clhep_2440` or `opticks-prepend-prefix /cvmfs/sft.cern.ch/lcg/releases/LCG_100/clhep/2.4.4.0/x86_64-centos7-gcc10-opt/`  
   line 32: `opticks-prepend-prefix ${workdir}/opticks.build_externals/xercesc` or `opticks-prepend-prefix /cvmfs/sft.cern.ch/lcg/releases/LCG_100/XercesC/3.2.3/x86_64-centos7-gcc10-opt/`   
   line 33: `opticks-prepend-prefix ${workdir}/opticks.build_externals/g4_1042` or `opticks-prepend-prefix /cvmfs/sft.cern.ch/lcg/releases/LCG_100/Geant4/10.07.p01/x86_64-centos7-gcc10-opt/`    
   line 34: `opticks-prepend-prefix ${workdir}/opticks.build_externals/boost` or `opticks-prepend-prefix /cvmfs/sft.cern.ch/lcg/releases/LCG_100/Boost/1.75.0/x86_64-centos7-gcc10-opt/`    
   > If you want to install Opticks with geant4.10.07.p01, please refer to geant4.md file.  
4. `echo "source ${workdir}/.opticks_config" >> ~/.bashrc`  
   start a new bash session  
5. `opticks-info`  
   `bash -lc "opticks-info"`  
6. `opticks-foreign`  
   `opticks-foreign-install`     
   > If you meet a problem related to the installation of Geant4, you can refer to geant4.md and install it by hand.  
7. `source ${workdir}/.opticks_config`  
   `opticks-externals-install`  
   `opticks-full`  
   > If you meet a problem related to libXinerama, you can refer to complier.md and install this library by hand.  
8. `source $OPTICKS_PREFIX/bin/opticks-setup.sh`  
   `source ${workdir}/opticks.build_externals/g4_1042/bin/geant4.sh`  
9. You can add these three lines to your ~/.bashrc file, so that every time you log into the sever, the environment will be set up automatically.  
   `source ${workdir}/.opticks_config`  
   `source $OPTICKS_PREFIX/bin/opticks-setup.sh`  
   `source ${workdir}/opticks.build_externals/g4_1042/bin/geant4.sh`  
10. `opticks-t` #perform all the tests in Opticks  
   > If some tests fail, you can refer to failed_tests.md to check the potential reasons.  

You can find more details here: https://simoncblyth.bitbucket.io/opticks/docs/install.html  

# Todo list
1. Check the difference between the latest version of Opticks with current commit (7af12e3606f5b76cc27af4b9bbe63a3a3b7d4765) in usage: what cause the num_gs=0 error in the CerenkovMinimal example and CG4Test fail.  
   opticks/cfg4/CCtx.cc:104: unsigned int CCtx::step_limit() const: Assertion `_ok_event_init' failed.  
2. Rich1_new.gdml visualization with photon tracks.  
3. RichTb example: Gensteps not collected correctly: use G4Opticks::Get()->collectGenstep_G4Cerenkov_1042 in L4Cerenkov.cc or *SD.cc?
4. The place to implement this is in X4Solid::convertPolycone
using X4Solid::intersectWithPhiSegment as other shapes do already.
The phi segment shape is a prism described by a set of planes
to form the convex polyhedron.

My recent commits implement this  but it is currently disabled as
it needs debugging, and as your geometry seems to have numerous
other problems with the translation.

Note that the performance and correctness of shapes using
intersectWithPhiSegment for such phi segmented shapes has not been well tested.

So if it is essential for you, then you will need work on
validation and comparison with Geant4.
Also the performance would need to be measured as the segment that
is intersected with is implemented using a CSG convexpolyhedron
implemented with a set of planes.

If performance/correctness is poor the next thing I would try
is to intersect with a segment formed from some other shape
that does not use the plane defined convex polyhedron.
5. Simplified_RICH geometry visualization, input particle position
