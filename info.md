1.  How to create a new geocache from your own gdml file
    geocache-              # run precursor function which defines the others
    type geocache-create   # take a look at geocache-create
    OKX4Test --deletegeocache --gdmlpath /hepgpu6-data1/liyu/LXe_1071/build/LXe.gdml
    OKX4Test --deletegeocache --gdmlpath /hepgpu6-data1/liyu/Final/build/Final.gdml
    OKX4Test --deletegeocache --gdmlpath /hepgpu6-data1/liyu/LXe_1071/build/G4Opticks_50000.gdml
    OTracerTest  # just viz, fast start as does no simulation
    OKTest       # does Opticks simulation before viz
    OKG4Test     # does both Geant4 and Opticks simulations before viz
    OKG4Test --g4ppe 100 --multievent 100

2. How to build G4OpticksTest developed by Hans: https://github.com/hanswenzel/G4OpticksTest 
  git clone https://github.com/hanswenzel/G4OpticksTest.git
  cd G4OpticksTest/
  vi set_env_lq.sh
  `export WORK_DIR=/hepgpu6-data1/liyu/opticks`
  `export OptiX_INSTALL_DIR=/hepgpu6-data1/liyu/NVIDIA-OptiX-SDK-6.5.0-linux64`
  `export OPTICKS_COMPUTE_CAPABILITY=70`
  `export CUDA_INSTALL_DIR=/usr/local/cuda`
  `#export CUDA_SAMPLES=/home/wenzel/NVIDIA_CUDA-10.1_Samples`
  cp set_env_lq.sh set_env.sh
  #source setup_opticks.sh   
  cd ../
  mkdir G4OpticksTest-build
  cd G4OpticksTest-build
  source ../root/bin/thisroot.sh
  edit CMakeFiles.txt
  cmake -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="/hepgpu6-data1/liyu/opticks/externals;/hepgpu6-data1/liyu/opticks;/afs/hep.man.ac.uk/u/liyu/liyu/opticks.build/externals/plog/include" \
  -DOPTICKS_PREFIX=/hepgpu6-data1/liyu/opticks \
  -DCMAKE_MODULE_PATH=$(opticks-home)/cmake/Modules \
  -DCMAKE_INSTALL_PREFIX=../G4OpticksTest-install \
  ../G4OpticksTest
  cmake -DCMAKE_CXX_FLAGS='-fPIC -shared' -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH="/afs/hep.man.ac.uk/u/liyu/liyu/opticks.build/externals/plog/include" -DCMAKE_MODULE_PATH=$(opticks-home)/cmake/Modules -DCMAKE_INSTALL_PREFIX=../G4OpticksTest-install  ../G4OpticksTest
  make install
  cd ../G4OpticksTest-install/bin
  export OPTICKS_EMBEDDED_COMMANDLINE_EXTRA="--rngmax 10"
  time ./G4OpticksTest -gdml G4Opticks_50000.gdml -pl 'FTFP_BERT+OPTICAL'  -macro muon_IO.mac
