cmake_minimum_required(VERSION 3.10)
project(Task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(task2 main.cpp calc.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(task2 PUBLIC -g)
endif()
