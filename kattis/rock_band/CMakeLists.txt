add_executable(rock_band rock_band.cpp)
target_compile_options(rock_band PRIVATE -g -O2 -std=gnu++17 -static -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive)# {files})