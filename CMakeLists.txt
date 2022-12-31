cmake_minimum_required(VERSION 3.0.0)
project(OptiTake VERSION 0.1.0)

add_executable(OptiTake main.cpp)

target_compile_features(OptiTake PUBLIC cxx_std_20)
target_compile_options(OptiTake PRIVATE -Wall)