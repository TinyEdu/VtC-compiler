cmake_minimum_required(VERSION 3.29.1)

add_executable(runTests
        JsonParser/test_JsonParser.cpp
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(runTests PRIVATE
        GTest::gmock_main
        GTest::gmock
        GTest::gtest_main
        GTest::gtest
        jsonParser)

target_include_directories(runTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../jsonParser/include
)

include(GoogleTest)
gtest_discover_tests(runTests)
