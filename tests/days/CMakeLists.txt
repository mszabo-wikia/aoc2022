find_package(GTest)

enable_testing()

add_executable(
  days_tests
  day01_test.cc
  day02_test.cc
)
target_link_libraries(days_tests PRIVATE
  GTest::gtest_main client
  day01 day02
)
target_compile_options(days_tests PRIVATE ${AOC2022_CXXFLAGS})

include(GoogleTest)
gtest_discover_tests(days_tests)

# Copy over the fixture directory to the build directory to make fixtures easily usable by tests.
add_custom_command(
  TARGET days_tests POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/tests/days/fixtures
    ${CMAKE_CURRENT_BINARY_DIR}/fixtures
)
