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

# Add the executable for the main application
add_executable(MyProject ${PROJECT_SOURCE_DIR}/Application.cpp)

# Platform-specific settings
if(WIN32)
    # Windows-specific settings
    message("Building on Windows")
elseif(UNIX)
    # Linux-specific settings
    message("Building on Linux")
endif()

# Check the build type
target_compile_definitions(MyProject PRIVATE gvDEBUG)
message("Building in Debug mode.")
