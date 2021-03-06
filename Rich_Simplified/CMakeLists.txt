cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(name Rich_Simplified)
project(${name} VERSION 0.1.0)
include(OpticksBuildOptions)

find_package( G4OK CONFIG REQUIRED )

file(GLOB sources src/*.cc)
file(GLOB headers include/*.hh)

set(TESTS TimeTest.cc)

add_executable(${name} ${name}.cc ${sources} ${headers} )
target_link_libraries( ${name} Opticks::G4OK )
target_include_directories( ${name} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> )
target_compile_definitions( ${name} PRIVATE WITH_OPTICKS G4USE_STD11 )

install(TARGETS ${name} DESTINATION lib)

foreach(SRC ${TESTS})
    get_filename_component(TGT ${SRC} NAME_WE)
    add_executable(${TGT} ${SRC} ${sources} ${headers} )
    add_test( ${name}.${TGT}  ${TGT} )
    target_link_libraries( ${TGT} Opticks::G4OK )
    target_include_directories( ${TGT} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> )
    target_compile_definitions( ${TGT} PRIVATE WITH_OPTICKS G4USE_STD11 )
    #target_compile_definitions( ${TGT} PRIVATE G4USE_STD11 )

    install(TARGETS ${TGT} DESTINATION lib)
endforeach()
