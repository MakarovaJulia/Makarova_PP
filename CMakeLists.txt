cmake_minimum_required(VERSION 3.23)
project(HW1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.cpp)
add_executable(HW1 ${SOURCE_FILES})
