#!/bin/bash

# Check if a valid build type is provided and set BUILD_TYPE
if [ "$1" == "RELEASE" ]; then
    echo "Building in Release mode"
    BUILD_TYPE=Release
elif [ "$1" == "DEBUG" ]; then
    echo "Building in Debug mode"
    BUILD_TYPE=Debug
elif [ "$1" == "TESTS" ]; then
    echo "Building in Test mode"
    BUILD_TYPE=Tests
else
    echo "Invalid or missing build type. Using default: Debug"
    BUILD_TYPE=Debug
fi

# Check if the CLEAN argument is provided
if [ "$2" == "CLEAN" ] || [ "$1" == "CLEAN" ]; then
    echo "Cleaning build directory"
    rm -rf build
fi

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to the build directory
cd build || { echo "Failed to enter build directory"; exit 1; }

# Run cmake to configure the project
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE .. || { echo "CMake configuration failed"; exit 1; }

# Build the project with make using 6 cores
cmake --build . -- -j6 || { echo "Build failed"; exit 1; }

echo -e "\n\n"

# Run the transpiler
if [ "$BUILD_TYPE" == "Tests" ]; then
    # Run tests if in test mode
    ctest --output-on-failure || { echo "Tests failed"; exit 1; }
else
    # Otherwise, run the transpiler
    ./vtc-compiler || { echo "Failed to execute Transpiler"; exit 1; }
fi
