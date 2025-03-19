cmake_minimum_required(VERSION 3.29.1)
project(interpreter LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED
        Interpreter.cpp
        include/Interpreter.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE VTC_INTERPRETER_EXPORTS)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
)