cmake_minimum_required(VERSION 3.20)

project(DSA_in_CPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCE_FILES
main.cpp
src/pointersAndReferences.cpp
src/arrayAndVectors.cpp
)

add_executable(DSA_in_CPP ${SOURCE_FILES})
