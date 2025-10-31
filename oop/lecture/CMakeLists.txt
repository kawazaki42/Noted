cmake_minimum_required(VERSION 3.16)

project(Lecture)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(except except.cpp)
add_executable(lecture_struct lecture_struct.cpp Lecture.cpp)