cmake_minimum_required(VERSION 3.9)
project(5_yap_intro)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)
#set(CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_CXX_STANDARD 17)

add_executable(yap_intro main.cpp)

add_subdirectory($ENV{HOME}/swim/yap yap)

target_link_libraries(yap_intro yap)

target_compile_options(yap_intro
    PRIVATE
        -O2
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE yap_intro FUNCTION main)
