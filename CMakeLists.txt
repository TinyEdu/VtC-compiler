cmake_minimum_required(VERSION 3.20)

# Set the project name and version
project(vtc-compiler VERSION 1.0)

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
add_executable(vtc-compiler ${PROJECT_SOURCE_DIR}/Application.cpp ${SOURCES})

# Platform-specific settings
if(WIN32)
    # Windows-specific settings
    message("Building on Windows")
elseif(UNIX)
    # Linux-specific settings
    message("Building on Linux")
endif()

# Build types configuration
if(CMAKE_BUILD_TYPE STREQUAL "Tests")
    # Test configuration
    message("Building in Tests mode.")
    find_package(GTest CONFIG REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # Gather test sources, excluding the main application
    file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

    # Add the test executable
    add_executable(tests ${TEST_SOURCES} ${SOURCES})

    # Link GTest libraries
    target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main)

    enable_testing()
    include(GoogleTest)
    gtest_discover_tests(tests)

    # Define preprocessor macros
    target_compile_definitions(vtc-compiler PRIVATE DEBUG_MODE TESTS_MODE)
    target_compile_definitions(tests PRIVATE DEBUG_MODE)

elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Debug configuration
    message("Building in Debug mode.")
    target_compile_definitions(vtc-compiler PRIVATE DEBUG_MODE)

elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Release configuration
    message("Building in Release mode.")
    target_compile_definitions(vtc-compiler PRIVATE RELEASE_MODE)

else()
    # Unknown configuration
    message(FATAL_ERROR "Unknown build type. Set CMAKE_BUILD_TYPE to Debug, Release, or Tests.")
endif()

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS tests
    COMMENT "Running all tests"
)
