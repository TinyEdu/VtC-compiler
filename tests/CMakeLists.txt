project(vtc-tests)

add_subdirectory(lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(vtc-tests
        LogManager/LoggingValidationTest.cpp
        templateTest/TemplateTest.cpp)

target_compile_definitions(vtc-tests PRIVATE DEBUG_MODE)
target_compile_definitions(vtc PRIVATE DEBUG_MODE)

target_link_libraries(vtc-tests gtest gtest_main)
target_link_libraries(vtc-tests vtc)
