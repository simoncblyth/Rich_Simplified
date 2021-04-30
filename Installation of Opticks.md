# Installation of Opticks
Some instruction about installation of Opticks on UoM GPU machines  
0. Install NVIDIA OptiX  
1. `cd ${workdir}`  # replace ${workdir} with the path where you want to install Opticks  
   `git clone https://bitbucket.org/simoncblyth/opticks`  
   `git remote -v`  # should list bitbucket.org urls  
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
4. `echo "source ${workdir}/.opticks_config" >> ~/.bashrc`  
   start a new bash session  
5. `opticks-info`  
   `bash -lc "opticks-info"`  
6. `opticks-foreign`  
   `opticks-foreign-install`     
7. `source ${workdir}/.opticks_config`  
   `opticks-externals-install`  
   `opticks-full`  
8. `source $OPTICKS_PREFIX/bin/opticks-setup.sh`  
   `source ${workdir}/opticks.build_externals/g4_1042/bin/geant4.sh`  
9. You can add these three lines to your ~/.bashrc file, so that every time you log into the sever, the environment will be set up automatically.  
   `source ${workdir}/.opticks_config`  
   `source $OPTICKS_PREFIX/bin/opticks-setup.sh`  
   `source ${workdir}/opticks.build_externals/g4_1042/bin/geant4.sh`  
10. `opticks-t` #Perform all the tests in Opticks  

You can find more details here: https://simoncblyth.bitbucket.io/opticks/docs/install.html


