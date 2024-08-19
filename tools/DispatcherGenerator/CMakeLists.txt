cmake_minimum_required(VERSION 3.20)

# Set the project name and version
project(MyProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set up vcpkg
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

# Add the include and source directories
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/include/*.h)

# Add the executable for the main application
add_executable(MyProject ${PROJECT_SOURCE_DIR}/Application.cpp ${SOURCES})

# Platform-specific settings
if(WIN32)
    # Windows-specific settings
    message("Building on Windows")
elseif(UNIX)
    # Linux-specific settings
    message("Building on Linux")
endif()

# Check the build type
if(CMAKE_BUILD_TYPE STREQUAL "Tests")
    find_package(GTest CONFIG REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    
    set(TESTS 
        ${PROJECT_SOURCE_DIR}/tests/test_adding.cpp
    )

    add_executable(tests ${TESTS} ${SOURCES} ${HEADERS})

    target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main)

    enable_testing()
    include(GoogleTest)
    gtest_discover_tests(tests)
 
    target_compile_definitions(MyProject PRIVATE gvDEBUG)
    target_compile_definitions(tests PRIVATE gvDEBUG)
    message("Building in Tests mode.")

elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(MyProject PRIVATE gvDEBUG)
    message("Building in Debug mode.")

elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(MyProject PRIVATE gvRELEASE)
    message("Building in Release mode.")

else()
    message(FATAL_ERROR "Unknown build type. Set CMAKE_BUILD_TYPE to Debug, Release, or Tests.")
endif()

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS tests
    COMMENT "Running all tests"
)
