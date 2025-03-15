cmake_minimum_required(VERSION 3.30)
project(PrimeNumbers)

set(CMAKE_CXX_STANDARD 20)

# Add source files
set(SOURCES
    main.cpp
    functions/utils.cpp
)

# Add header files
set(HEADERS
    functions/utils.h
)

# Create executable
add_executable(PrimeNumbers ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(PrimeNumbers PRIVATE functions)