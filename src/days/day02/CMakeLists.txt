add_library(day02
    Shape.h Shape.cc
    day02.h day02.cc
)

target_compile_options(day02 PRIVATE ${AOC2022_CXXFLAGS})
target_include_directories(day02 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
