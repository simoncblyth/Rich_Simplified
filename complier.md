1. How to build Opticks with gcc 4.8.1+ which only supports c++11.  
  > Edit ${workdir}/opticks/cmake/Modules/OpticksCXXFlags.cmake   
  line 23 and 29: `set(CMAKE_CXX_STANDARD 14)` -> `set(CMAKE_CXX_STANDARD 11)`  

2. How to install libXinerama library.  
  > wget http://mirror.centos.org/centos/8/AppStream/x86_64/os/Packages/libXinerama-devel-1.1.4-1.el8.x86_64.rpm  
  rpm2cpio libXinerama-devel-1.1.4-1.el8.x86_64.rpm |cpio -idvm  
  cd ${workdir}/opticks.build/externals/glfw/glfw-3.3.2/  
  edit CMakeLists.txt  
  comment out these lines below:  
  `# Check for Xinerama (legacy multi-monitor support)`  
  `#if (NOT X11_Xinerama_INCLUDE_PATH)`  
  `#    message("${X11_Xinerama_INCLUDE_PATH}")`  
  `#    message(FATAL_ERROR "Xinerama headers not found; install libxinerama development package")`  
  add this option:  
  `-DX11_Xinerama_INCLUDE_PATH=${workdir}/usr/include`
  to opticks/externals/glfw.bash, then
  opticks-externals-install
   cp -r ${workdir}/opticks.build/externals/lib64/* ${workdir}/opticks.build/externals/lib/

3. Something wrong with gcc or g++ complier.  
  Set it up by adding this line to ~/.bashrc:  
  `source /cvmfs/lhcb.cern.ch/lib/lcg/releases/gcc/4.9.3/x86_64-centos7/setup.sh`  

4. Failure of NPY package compilation.  
  modifying cmake/Modules/OpticksCXXFlags.cmake:  
  `set(CMAKE_CXX_STANDARD 11)` instead of `set(CMAKE_CXX_STANDARD 14)` 
