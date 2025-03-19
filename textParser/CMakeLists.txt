cmake_minimum_required(VERSION 3.29.1)
project(jsonParser LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED
        include/TextParser.h

        src/TextParser.cpp
        src/Parser/ParseError.h
        src/Parser/Parser.h
        src/Parser/Parser.cpp
        src/Parser/ParserBase.h
        src/Parser/ParserBase.cpp

        src/Scanner/ErrorHandler.cpp
        src/Scanner/ErrorHandler.h
        src/Scanner/Scanner.cpp
        src/Scanner/Scanner.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE VTC_TEXT_PARSER_EXPORTS)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
        ${CMAKE_CURRENT_SOURCE_DIR}/../ast
)

target_link_libraries(${PROJECT_NAME} PRIVATE ast)