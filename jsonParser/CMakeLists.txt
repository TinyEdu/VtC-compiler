cmake_minimum_required(VERSION 3.29.1)
project(textParser LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED
        JsonParser.cpp
        include/JsonParser.h
)
target_compile_definitions(${PROJECT_NAME} PRIVATE VTC_JSON_PARSER_EXPORTS)

# Include the interface and AST module
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
        ${CMAKE_CURRENT_SOURCE_DIR}/../ast
)

target_link_libraries(${PROJECT_NAME} PRIVATE ast)