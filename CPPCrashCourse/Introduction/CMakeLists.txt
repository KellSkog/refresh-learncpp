add_executable(ark main.cpp)
add_library(enstone STATIC misty.c)
set_target_properties(enstone PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(ark enstone)