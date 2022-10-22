cmake_minimum_required(VERSION 3.5.0)
project(CPlusPlus_Training)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/build/bin/debug")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files 
"${source_dir}/*.cpp"  
"${source_dir}/private/*.cpp" )

include_directories(${PROJECT_NAME} "${source_dir}/public/*.h")

add_executable(${PROJECT_NAME} ${source_files})