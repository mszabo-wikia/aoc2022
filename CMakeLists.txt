cmake_minimum_required(VERSION 3.19)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(AOC2022_CXXFLAGS
    -Wall
    -Wextra
    -Werror
    -pedantic-errors
    -Wconversion
    -Wextra-semi
    -Wnull-dereference
    -Wold-style-cast
    -Wunused
    -Wundef
    -Wsign-conversion
    -Wnon-virtual-dtor
    -Woverloaded-virtual
    -Wdouble-promotion 
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

project(aoc2022 LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(tests)
