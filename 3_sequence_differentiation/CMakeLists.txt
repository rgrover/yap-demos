cmake_minimum_required(VERSION 3.9)
project(3_sequence_differentiation)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)
#set(CMAKE_VERBOSE_MAKEFILE true)

add_executable(differentiation
        main.cpp
        expose.hpp
        discrete_sequence.hpp
        differentiator.hpp
)

target_compile_options(differentiation
    PRIVATE
        -O2 -Wall
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE differentiation FUNCTION main)
