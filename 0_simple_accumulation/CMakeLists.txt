cmake_minimum_required(VERSION 3.9)
project(lazy_operations)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)
#set(CMAKE_VERBOSE_MAKEFILE true)

add_executable(lazy final.cpp)

target_compile_options(lazy
    PRIVATE
        -O2 -Wall
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE lazy FUNCTION main)
