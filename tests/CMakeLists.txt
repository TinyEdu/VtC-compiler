cmake_minimum_required(VERSION 3.29.1)
project(runTests VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME}
        JsonParser/test_JsonParser.cpp

        TextParser/ParserValidationTest.cpp
        TextParser/ScannerValidationTest.cpp

        LogManager/LoggingValidationTest.cpp

        E2E/E2Etests.cpp
        E2E/tools/E2ETester.h
        E2E/tools/E2ETester.cpp
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
        GTest::gmock_main
        GTest::gmock
        GTest::gtest_main
        GTest::gtest
        jsonParser
        textParser
        interpreter
        ast)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../jsonParser/include
)

include(GoogleTest)
gtest_discover_tests(runTests)
