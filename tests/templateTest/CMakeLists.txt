include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(vtc-tests
        TemplateTest.cpp)

target_link_libraries(vtc-tests gtest gtest_main)
target_link_libraries(vtc-tests vtc)