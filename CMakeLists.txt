cmake_minimum_required(VERSION 3.29)
project(VtC_compiler)

set(CMAKE_CXX_STANDARD 20)

add_executable(VtC_compiler main.cpp
        LogManager/LogManager.cpp)
