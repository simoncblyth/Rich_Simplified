# Install script for directory: /afs/hep.man.ac.uk/u/liyu/liyu/opticks/examples/Geant4/RichTb

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/afs/hep.man.ac.uk/u/liyu/liyu/opticks.build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/RichTb" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/RichTb")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/RichTb"
         RPATH "/hepgpu6-data1/liyu/opticks.build/lib64:/hepgpu6-data1/liyu/opticks.build/externals/lib:/hepgpu6-data1/liyu/opticks.build/externals/lib64:/hepgpu6-data1/liyu/opticks.build/externals/OptiX/lib64")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE EXECUTABLE FILES "/afs/hep.man.ac.uk/u/liyu/liyu/opticks/examples/Geant4/RichTb/build/RichTb")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/RichTb" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/RichTb")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/RichTb"
         OLD_RPATH "/afs/hep.man.ac.uk/u/liyu/liyu/opticks.build/lib64:/afs/hep.man.ac.uk/u/liyu/liyu/opticks.build_externals/g4_1071/lib64:/hepgpu6-data1/liyu/opticks.build_externals/xercesc/lib:/afs/hep.man.ac.uk/u/liyu/liyu/opticks.build_externals/clhep_2440/lib:/afs/hep.man.ac.uk/u/liyu/liyu/opticks.build_externals/boost/lib:/usr/local/cuda/lib64:/afs/hep.man.ac.uk/u/liyu/liyu/NVIDIA-OptiX-SDK-6.5.0-linux64/lib64:"
         NEW_RPATH "/hepgpu6-data1/liyu/opticks.build/lib64:/hepgpu6-data1/liyu/opticks.build/externals/lib:/hepgpu6-data1/liyu/opticks.build/externals/lib64:/hepgpu6-data1/liyu/opticks.build/externals/OptiX/lib64")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/RichTb")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/afs/hep.man.ac.uk/u/liyu/liyu/opticks/examples/Geant4/RichTb/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
