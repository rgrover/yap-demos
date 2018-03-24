cmake_minimum_required(VERSION 3.9)
project(7_scalars)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)
#set(CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_CXX_STANDARD 17)

add_executable(7_scalars main.cpp scalars.hpp range.hpp scalar_iterator.hpp)

add_subdirectory($ENV{HOME}/swim/yap yap)

target_link_libraries(7_scalars yap)

target_compile_options(7_scalars
    PRIVATE
        -O2
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE 7_scalars FUNCTION main)
