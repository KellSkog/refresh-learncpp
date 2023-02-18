set(Flags -g -O2 -std=gnu++17 -static -lrt -lpthread)

add_executable(welcomeeasy welcomeeasy.cpp)
target_compile_options(welcomeeasy PRIVATE -Werror ${Flags})