1. How to install Opticks with geant4.10.07.p01  
  > edit ${workdir}/opticks/externals/g4.bash  
  add `1071) echo geant4.10.07.p01 ;;` to g4-nom  
  add `geant4.10.07.p01) echo http://cern.ch/geant4-data/releases/geant4.10.07.p01.tar.gz ;;` to g4-url  
  add `1071) echo Geant4 10.7 patch-01, released 5 February 2021 ;;` to g4-title  
  edir ${workdir}/.opticks_config  
  change `export OPTICKS_GEANT4_VER=1042` to `export OPTICKS_GEANT4_VER=1071`  
  change `opticks-prepend-prefix ${workdir}/opticks.build_externals/g4_1042` to `opticks-prepend-prefix ${workdir}/opticks.build_externals/g4_1071`'  

2. How to install Geant4 by hand
 >  cd ${workdir}/opticks.build_externals/g4_1042  
   wget http://geant4-data.web.cern.ch/geant4-data/releases/geant4.10.04.p02.tar.gz  
   tar -zxvf geant4.10.04.p02.tar.gz
   mkdir geant4.10.04.p02.build
   cd geant4.10.04.p02.build
   cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_USE_SYSTEM_CLHEP=ON -DGEANT4_INSTALL_DATA=ON -DGEANT4_USE_GDML=ON -DGEANT4_INSTALL_DATA_TIMEOUT=100000  -DXERCESC_LIBRARY=${workdir}/opticks.build_externals/xercesc/lib/libxerces-c.so -DXERCESC_INCLUDE_DIR=${workdir}/opticks.build_externals/xercesc/include -DCMAKE_INSTALL_PREFIX=${workdir}/opticks.build_externals/g4_1042/ ${workdir}/opticks.build_externals/g4_1042.build/geant4.10.04.p02    
   make -jN
   make install
