cmake_minimum_required(VERSION 3.9)
project(9_composable_lazy_functions)

set(CMAKE_C_COMPILER   /usr/bin/clang   CACHE STRING "Compiler" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0 CACHE STRING "Compiler" FORCE)
#set(CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_CXX_STANDARD 17)

add_executable(9_composable_lazy_functions
        main2.cpp
        scalars.hpp
        range.hpp
        scalar_iterator.hpp
        filter.hpp
        range_expr.hpp
        xforms.hpp
        range_iterator.hpp
        callable.hpp)

add_subdirectory($ENV{HOME}/swim/yap yap)

target_link_libraries(9_composable_lazy_functions yap)

target_compile_options(9_composable_lazy_functions
    PRIVATE
        -O2
)

include($ENV{HOME}/swim/yap/cmake/Disassemble.cmake)
disassemble(show_assembly EXECUTABLE 9_composable_lazy_functions FUNCTION main)
