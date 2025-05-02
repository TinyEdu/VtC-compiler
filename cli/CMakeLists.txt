cmake_minimum_required(VERSION 3.29.1)
project(cli LANGUAGES CXX)

find_package(Qt6 CONFIG REQUIRED COMPONENTS Core)

add_library(${PROJECT_NAME} SHARED
        src/moduleA.cpp
        #    moduleA.h  # If it's private, keep it commented
        src/CommandLineUserInterface.cpp
        include/CommandLineUserInterface.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE VTC_CLI_EXPORTS)

# Correct way to include interface headers
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
