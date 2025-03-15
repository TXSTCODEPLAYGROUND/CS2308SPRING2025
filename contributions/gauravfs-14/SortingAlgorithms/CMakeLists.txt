cmake_minimum_required(VERSION 3.30)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 20)

# Add source files
set(SOURCES
    main.cpp
    functions/algorithms/bubbleSort.cpp
    functions/algorithms/selectionSort.cpp
    functions/algorithms/insertionSort.cpp
    functions/algorithms/mergeSort.cpp
    functions/algorithms/quickSort.cpp
)

# Add header files
set(HEADERS
    functions/functions.h
)

# Create executable
add_executable(SortingAlgorithms ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(SortingAlgorithms PRIVATE functions)