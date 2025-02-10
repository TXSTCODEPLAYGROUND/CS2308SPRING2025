cmake_minimum_required(VERSION 3.30)
project(PokerLike)

set(CMAKE_CXX_STANDARD 20)

add_executable(PokerLike main.cpp
        src/cards.cpp
        header/cards.h)
