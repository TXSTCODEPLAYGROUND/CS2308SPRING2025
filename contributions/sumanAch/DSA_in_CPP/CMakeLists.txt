# Minimum required CMake version
cmake_minimum_required(VERSION 3.30)

project(DSA_in_CPP)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files (Ensure filenames match exactly)
set(SOURCE_FILES 
    index.cpp
    pointersAndReferences.cpp
    sumOfN.cpp  # Ensure correct filename case
    uniqueNum.cpp
    vectors.cpp
)

# Create an executable 
add_executable(DSA_in_CPP ${SOURCE_FILES})

