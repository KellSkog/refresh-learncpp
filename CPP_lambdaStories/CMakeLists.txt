cmake_minimum_required(VERSION 3.20)

project(CPPlambda CXX)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Wconversion -Werror)
endif()

add_subdirectory(CPP98_03)