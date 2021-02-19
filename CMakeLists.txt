cmake_minimum_required(VERSION 3.17)
project(my_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_cpp recur/combination.cpp recur/hanoi.cpp vect/vect.cpp)