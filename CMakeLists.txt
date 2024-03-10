cmake_minimum_required(VERSION 3.12.0...3.28.0)
project(OptiTake VERSION 0.1.0)

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.x
)

FetchContent_MakeAvailable(
    googletest
)

add_subdirectory(src)
add_subdirectory(test)

add_executable(OptiTake main.cpp)

target_include_directories(OptiTake PRIVATE src)
target_link_libraries(OptiTake PRIVATE LibOptiTake)