cmake_minimum_required(VERSION 3.13.5)

project(Test VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_compile_options(-L/usr/local/lib -pthread -lpistache)
#add_link_options(-v -L/usr/local/lib -pthread -lpistache)

execute_process(COMMAND bash -c "uname -r | tr -d '\n'" OUTPUT_VARIABLE KERNEL_VER)

configure_file(test.hxx.in test.hxx)

add_executable(test test.cxx)
link_directories(/usr/local/lib)
target_link_libraries(test pistache)
