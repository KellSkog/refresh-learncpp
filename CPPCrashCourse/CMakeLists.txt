cmake_minimum_required(VERSION 3.20)

project(CPPCrashCourse C CXX)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Wconversion -Werror)
endif()

include_directories(../doctest/doctest)
add_subdirectory(ForDanielle)
add_subdirectory(Introduction)
add_subdirectory(Part_1)