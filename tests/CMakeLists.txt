project(vtc-tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

add_subdirectory(lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(vtc-tests
        LogManagerTests/LoggingValidationTest.cpp
        ParserTests/ParserValidationTest.cpp
        ScannerTests/ScannerValidationTest.cpp
        E2E/tools/E2ETester.cpp
        E2E/tools/E2ETester.h
        E2E/E2Etests.cpp)

target_compile_definitions(vtc-tests PRIVATE DEBUG_MODE)
target_compile_definitions(vtc PRIVATE DEBUG_MODE)

target_link_libraries(vtc-tests gtest gtest_main)
target_link_libraries(vtc-tests vtc)
