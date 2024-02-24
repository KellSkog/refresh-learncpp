cmake_minimum_required(VERSION 3.20)

project(experiment C CXX)

add_executable(exprmt main.cpp algo.cpp)
add_executable(test_exprmt algo.cpp test_exprmt.cpp)
# /home/kellskog/Repositories/refresh-learncpp/doctest/doctest/doctest.h
target_include_directories(test_exprmt PRIVATE ../doctest/doctest)