# CMake minimum version
cmake_minimum_required(VERSION 3.13.5)

# Project settings
project(Test VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add kernel version to header file
execute_process(COMMAND bash -c "uname -r | tr -d '\n'" OUTPUT_VARIABLE KERNEL_VER)
configure_file(test.hxx.in test.hxx)

# Create executable
add_executable(test test.cxx)

# Link test binary with pistache
link_directories(/usr/local/lib)
target_link_libraries(test pistache)
