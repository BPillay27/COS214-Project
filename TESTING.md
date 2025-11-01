# Testing Guide for COS 214 Project

This document provides instructions on how to build the project and run the unit tests.

## Building the Project for Testing

The project uses CMake to manage the build process. The unit tests are built as part of the default build configuration.

### Prerequisites

- A C++ compiler that supports C++17 (e.g., GCC, Clang, MSVC)
- CMake (version 3.16 or higher)
- NB use wsl for easy use 

### Build Steps

1.  **Create a build directory:**
    To keep the source directory clean, all build artifacts will be placed in a separate `build` directory.

    ```bash
    cd build
    ```

2.  **Configure the project with CMake:**
    From the `build` directory, run CMake to generate the build system.

    ```bash
    cmake ..
    ```

3.  **Compile the code:**
    Use `make` to compile the project, including the `unit_tests` executable.

    ```bash
    make
    ```

## Running the Unit Tests

The project's unit tests are built using the Google Test framework.

### Executing the Test Suite

After a successful build, the test executable `unit_tests` will be located in the `build` directory.

To run all the tests, execute the following command from within the `build` directory:

```bash
./unit_tests
```

The output will show the results of all the test cases.