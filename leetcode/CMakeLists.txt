cmake_minimum_required(VERSION 3.15)
project(NoProject)

add_executable(test_shuffle-the-array src/shuffle-the-array.cpp
                                      test/test_shuffle-the-array.cpp)
target_include_directories(test_shuffle-the-array PRIVATE
                            ../doctest/doctest
                            inc)