cmake_minimum_required(VERSION 3.9)
project(7_filter)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)
#set(CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_CXX_STANDARD 17)

add_executable(filter
        main.cpp
        scalars.hpp
        range.hpp
        scalar_iterator.hpp
        filter.hpp
        filter2.hpp
        range_expr.hpp
        filter3.hpp
        xforms.hpp
        xforms2.hpp
        xforms3.hpp
        xforms4.hpp
        xforms5.hpp
        range_iterator.hpp)

add_subdirectory($ENV{HOME}/swim/yap yap)

target_link_libraries(filter yap)

target_compile_options(filter
    PRIVATE
        -O2
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE filter FUNCTION main)
