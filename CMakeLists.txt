cmake_minimum_required(VERSION 3.6)
project(solar_system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Star.hpp solar_system.hpp Star.cpp)
add_executable(solar_system ${SOURCE_FILES})