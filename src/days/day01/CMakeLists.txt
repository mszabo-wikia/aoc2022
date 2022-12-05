add_library(day01
    CaloriesStats.h
    day01.h day01.cc
)

target_compile_options(day01 PRIVATE ${AOC2022_CXXFLAGS})
target_include_directories(day01 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
