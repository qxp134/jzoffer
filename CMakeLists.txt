cmake_minimum_required(VERSION 2.8.16)

project(jzoffer)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_library(16 16.cpp)
add_library(17 17.cpp)
add_library(18 18.cpp)
add_library(19 19.cpp)
add_library(22 22.cpp)
add_library(23_1 23_1.cpp)
add_library(23_2 23_2.cpp)
