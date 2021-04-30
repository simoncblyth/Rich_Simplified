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
  add these lines:  
  `set(X11_Xinerama_INCLUDE_PATH "${workdir}/usr/include")`  
  `list(APPEND glfw_INCLUDE_DIRS "${X11_Xrandr_INCLUDE_PATH}"`  
  `                                "${X11_Xinerama_INCLUDE_PATH}"`  
  `                                "${X11_Xkb_INCLUDE_PATH}"`  
  `                                "${X11_Xcursor_INCLUDE_PATH}"`  
  `                                "${X11_Xi_INCLUDE_PATH}")`  
  `set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_INSTALL_LIBDIR}")`  
   cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=${workdir}/opticks.build/externals .
   make
   make install
   cp -r ${workdir}/opticks.build/externals/lib64/* ${workdir}/opticks.build/externals/lib/
