cmake_minimum_required(VERSION 3.9)
project(0_simple_accumulation)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)

add_executable(simple_accumulation main.cpp)

target_compile_options(simple_accumulation
    PRIVATE
        -O2 -Wall
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE simple_accumulation FUNCTION main)
