add_executable(waif waif.cpp)
target_compile_options(waif PRIVATE -g -O2 -std=gnu++17 -static -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive)
target_compile_options(waif PRIVATE -Werror -Wall -Wpedantic)