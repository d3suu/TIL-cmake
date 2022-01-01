cmake_minimum_required(VERSION 3.10)

project(Test VERSION 1.0)

execute_process(COMMAND bash -c "uname -r | tr -d '\n'" OUTPUT_VARIABLE KERNEL_VER)

configure_file(test.hxx.in test.hxx)

add_executable(test test.cxx)

