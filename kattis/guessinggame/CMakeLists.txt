set(Flags -g -O2 -std=gnu++17 -static -lrt -lpthread)

add_executable(test_guessinggame guessinggame.cpp
                    test_guessinggame.cpp)
target_include_directories(test_guessinggame PRIVATE ../../doctest/doctest)
target_compile_options(test_guessinggame PRIVATE ${Flags})

add_executable(solution_guessinggame guessinggame.cpp
                            solution.cpp)
target_include_directories(solution_guessinggame PRIVATE ../../doctest/doctest)
target_compile_options(solution_guessinggame PRIVATE -Werror ${Flags})