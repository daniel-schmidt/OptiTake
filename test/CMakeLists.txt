add_executable(
  Tests 
  BoardTests.cpp
)

target_include_directories(Tests PRIVATE ../src)

target_link_libraries(
  Tests
  GTest::gtest_main
  LibOptiTake
)

include(GoogleTest)
gtest_discover_tests(Tests)