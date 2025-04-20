cmake_minimum_required(VERSION 3.10)
project(SudokuProject)

set(CMAKE_CXX_STANDARD 17)

# This tells the compiler to look in the "include/" folder when resolving #includes
include_directories(include)

# Add the main and all your .cpp source files from "src/"
add_executable(SudokuProject
        main.cpp
        src/sudoku.cpp
        src/sudoku_io.cpp
        src/generator.cpp
        src/utils.cpp
)
