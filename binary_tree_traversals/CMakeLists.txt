set(Flags -g -O2 -std=gnu++17 -static -lrt -lpthread)

add_executable(binary_tree_traversals binary_tree_traversals.cpp)
target_compile_options(binary_tree_traversals PRIVATE -Werror ${Flags})