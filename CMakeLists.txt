cmake_minimum_required(VERSION 3.10)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector main.cpp Vector.cpp Vector.h exceptions.h)