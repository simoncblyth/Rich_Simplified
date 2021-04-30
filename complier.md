1. How to build Opticks with gcc 4.8.1+ which only supports c++11.
> Edit ${workdir}/opticks/cmake/Modules/OpticksCXXFlags.cmake  
line 23 and 29: `set(CMAKE_CXX_STANDARD 14)` -> `set(CMAKE_CXX_STANDARD 11)`
