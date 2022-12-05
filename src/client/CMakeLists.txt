find_package(CURL)

add_library(client
    PuzzleInputFetcher.h PuzzleInputFetcher.cc
)

target_link_libraries(client PRIVATE CURL::libcurl)
target_compile_options(client PRIVATE ${AOC2022_CXXFLAGS})
target_include_directories(client INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
