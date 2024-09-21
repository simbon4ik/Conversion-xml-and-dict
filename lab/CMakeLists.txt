cmake_minimum_required(VERSION 3.16)
project(lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(input input.h input.cpp)
add_library(func library.h library.cpp)

add_executable(prog prog.cpp)

target_link_libraries(prog input func)
