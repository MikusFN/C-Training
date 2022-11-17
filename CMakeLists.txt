cmake_minimum_required(VERSION 3.5.0)

set(PROJ_NAME CPlusPlus_Training )

project(${PROJ_NAME} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/build/bin/debug")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pedantic")


file(GLOB source_files 
"${source_dir}/*.cpp" 
"${source_dir}/private/*.cpp" )

include_directories(${PROJECT_NAME} "${source_dir}/public/*.h")



add_executable(${PROJECT_NAME} ${source_files})


# Functions Cmake
#Print to console -> message()
function(print)
    message("Printing")
        foreach(var ${ARGN})
            message("${var} = ${${var}}")
            #message("${var} = $ENV{${var}}") -> Environment variables from shell
        endforeach()
endfunction()
#"${ARGN}" = Args passed to print
#"${ARGC}" = Number args passed to print
#"${ARGV0-N}" = values of the args 

print(PROJ_NAME)


#Libs 
#add_library(Name [Static|Shared|Module]) -> Static by default
#add_library(Name [Static|Shared|Module] Imported) -> Outside libs
#object files are created obj files without being linked

#Target link
#target_link_libraries( libName [INTERFACE|PRIVATE|PUBLIC] sourcelibs) -> the propagation level of the libs being linked 
#Interface -> all the libs that will use this lib will have the propagation 
#Private -> Only this link will have acess to the next src
#Public -> This link and all that use them will have acess to the libs linked here (Interface + Private)

#include link
#target_link_directories( Name [Acess[like the other on top] source) -> compiling translation units to the target

#find_package
#find_package(NAME VERSION [OPTIONAL|REQUIRE]) -> will lool for the packger config in file packageNameConfig.cmake
