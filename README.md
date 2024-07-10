# Cpp Template project  
This is a template for basic c++ project using cmake, google test and vcpkg

Note: In future I might want to add a crossplatform.

## Project Structure

```
MyProject
├── Application.cpp        # Main application entry point
├── CMakeLists.txt         # CMake configuration file
├── LICENSE                # Project license
├── README.md              # Project documentation
├── include
│   └── # Header files
├── src
│   └── # Source files
└── tests
    └── # Unit tests
```

## Build Instructions

### Prerequisites

- CMake (version 3.20 or higher)
- vcpkg

### Setup vcpkg

1. Install the required packages using vcpkg:
    ```bash
    ./vcpkg install gtest
    ```

### Build the Project

1. Create a build directory and navigate to it:
    ```bash
    mkdir build
    cd build
    ```

2. Configure the project (replace `<BuildType>` with `Debug`, `Release`, or `Tests`):
    ```bash
    cmake -DCMAKE_BUILD_TYPE=<BuildType> ..
    ```

3. Build the project:
    ```bash
    cmake --build .
    ```

4. Run tests (if `Tests` build type is selected):
    ```bash
    cmake --build . --target run_tests
    ```

## License
Do what you want.
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
