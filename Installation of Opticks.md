# Installation of Opticks
Some instruction about installation of Opticks on UoM GPU machines  
Prerequisite: NVIDIA OptiX 6.5+, cmake 3.12+, gcc 5+
> gcc 5+ is required to support c++14. If you want to build with gcc 4.8.1+ which only supports c++11, please refer to complier.md file.  
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
   line 31:	`opticks-prepend-prefix ${workdir}/opticks.build_externals/clhep_2440`  
   line 32: `opticks-prepend-prefix ${workdir}/opticks.build_externals/xercesc`  
   line 33: `opticks-prepend-prefix ${workdir}/opticks.build_externals/g4_1042`  
   line 34: `opticks-prepend-prefix ${workdir}/opticks.build_externals/boost`  
   > If you want to install Opticks with geant4.10.07.p01, please refer to g4_1071.md file.  
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
   > If you meet a problem related to libXinerama, you can refer to libXinerama.md and install this library by hand.  
8. `source $OPTICKS_PREFIX/bin/opticks-setup.sh`  
   `source ${workdir}/opticks.build_externals/g4_1042/bin/geant4.sh`  
9. You can add these three lines to your ~/.bashrc file, so that every time you log into the sever, the environment will be set up automatically.  
   `source ${workdir}/.opticks_config`  
   `source $OPTICKS_PREFIX/bin/opticks-setup.sh`  
   `source ${workdir}/opticks.build_externals/g4_1042/bin/geant4.sh`  
10. `opticks-t` #perform all the tests in Opticks  
   > If some tests fail, you can refer to failed_tests.md to check the potential reasons.  

You can find more details here: https://simoncblyth.bitbucket.io/opticks/docs/install.html


