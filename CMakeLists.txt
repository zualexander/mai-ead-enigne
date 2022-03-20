cmake_minimum_required(VERSION 3.21)
project(Enigne VERSION 1.0.0)

add_subdirectory(Enigne)
add_subdirectory(Sandbox)

target_compile_features(Enigne PUBLIC cxx_std_20)