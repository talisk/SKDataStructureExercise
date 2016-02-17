cmake_minimum_required(VERSION 3.3)
project(ex004)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ex004 ${SOURCE_FILES})