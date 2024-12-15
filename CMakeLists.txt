cmake_minimum_required(VERSION 3.29)
project(vtc-compiler)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-std=gnu++20)

set(SOURCE_FILES
main.cpp
vtc/LogManager/LogManager.cpp)
add_executable(vtc-compiler ${SOURCE_FILES})

include_directories(vtc)

add_subdirectory(vtc)
add_subdirectory(tests)

target_compile_definitions(vtc-compiler PRIVATE ENABLE_ANSI_COLOR)
target_compile_definitions(vtc-compiler PRIVATE DEBUG_MODE)
target_link_libraries(vtc-compiler vtc)