#target_sources(PUBLIC main.cpp)
add_library(lambdas98 STATIC lambdas98.cpp)
target_compile_options(lambdas98 PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++98>)

add_library(lambdas11 STATIC lambdas11.cpp)
target_compile_options(lambdas11 PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++11>)

add_executable(PrintFunc main.cpp )
target_compile_options(PrintFunc PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++23>)

target_link_libraries(PrintFunc lambdas98 lambdas11)
# target_compile_features(PrintFunc PUBLIC cxx_std_11)

# When using cmake --build, you can pass additional arguments to the underlying build tool 
# (Ninja, in this case) by adding them after --. 
# So, to get verbose output with Ninja when using cmake --build, you can use the following command
# cmake --build build -- -v
