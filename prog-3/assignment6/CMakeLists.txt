cmake_minimum_required(VERSION 3.29)
project(assignment6)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment6 main.cpp
        ulib/String.h
        ulib/String.cpp)

add_subdirectory(tests)
