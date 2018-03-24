cmake_minimum_required(VERSION 3.7)
project(ranges)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)

add_subdirectory($ENV{HOME}/swim/yap yap)

add_executable(ranges
        main.cpp
        scalar_iterator.hpp
        range.hpp
        scalars.hpp
        map.hpp
        filter.hpp
        xforms.hpp
        take.hpp
        drop.hpp
        callable.hpp
        fold.hpp
)
target_link_libraries(ranges yap)

target_compile_options(ranges
    PRIVATE
        -O2 -Wall
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE ranges FUNCTION main)
