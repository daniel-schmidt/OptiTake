add_executable(
  Tests 
  BoardTests.cpp
  OptimalSolutionPlayerTests.cpp
)

target_include_directories(Tests PRIVATE ../src)

target_link_libraries(
  Tests
  gmock_main
  LibOptiTake
)

include(GoogleTest)
gtest_discover_tests(Tests)