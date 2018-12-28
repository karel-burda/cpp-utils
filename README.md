![Version](https://img.shields.io/badge/version-1.0.4-green.svg)
[![License](https://img.shields.io/badge/license-MIT_License-green.svg?style=flat)](LICENSE)
[![Build Status](https://travis-ci.org/karel-burda/cpp-utils.svg?branch=master)](https://travis-ci.org/karel-burda/cpp-utils)
[![Codecov Status](https://codecov.io/gh/karel-burda/cpp-utils/branch/master/graph/badge.svg)](https://codecov.io/gh/karel-burda/cpp-utils/branch/master)

## Important
This project contains git sub-modules that are needed for building tests.

If you just want to use the implementation, you can clone without sub-modules. In case you want to build the tests, be sure to clone the repository
with `--recurse-submodules` or `--recursive` on older versions of git. Alternatively, you can clone without sub-modules and initialize these later.

## Introduction
`cpp-utils` features tiny C++ helpers and primitives that are used across my projects.

Implementation is header-only and written in C++ 14 and tested on Windows, Linux and OS X.

See [include/cpp_utils](include/cpp_utils) for main functionality and [tests/unit](tests/unit) for unit tests.

## Usage
Few files in the `cpp-utils` are used directly within my projects -- e.g. using the full copy of the files (thus these files have own short header description regarding its origin).

There are basically these options when it comes to build system integration:

### 1. CMake Way
Recommended option.

There are essentially these ways of how to use this package depending on your preferences our build architecture:

#### A) Generate directly

Call `add_subdirectory(...)` directly in your CMakeLists.txt:

```cmake
add_executable(my-project main.cpp)

add_subdirectory(<path-to-cpp-utils>)
# Example: add_subdirectory(cpp-utils ${CMAKE_BINARY_DIR}/cpp-utils)

# Query of package version
message(STATUS "Current version of cpp-utils is: ${cpp-utils_VERSION}")

add_library(burda::cpp-utils ALIAS cpp-utils)

# This will import search paths, compile definitions and other dependencies of the cpp-utils as well
target_link_libraries(my-project cpp-utils)
# Or with private visibility: target_link_libraries(my-project PRIVATE cpp-utils)
```

#### B) Generate separately

Generation phase on the cpp-utils is run separately, that means that you run:
```cmake
cmake <path-to-cpp-utils>
# Example: cmake -Bbuild/cpp-utils -Hcpp-utils in the root of your project 
```

This will create automatically generated package configuration file `cpp-utils-config.cmake` that contains exported target and all important information.

Then you can do this in your CMakeLists.txt:

```cmake
add_executable(my-project main.cpp)

find_package(cpp-utils CONFIG PATHS <path-to-binary-dir-of-cpp-utils>)
# Alternatively assuming that the "cpp-utils_DIR" variable is set: find_package(cpp-utils CONFIG)

# You can also query (or force specific version during the previous "find_package()" call)
message(STATUS "Found version of cpp-utils is: ${cpp-utils_VERSION}")

# This will import search paths, compile definitions and other dependencies of the cpp-utils as well
target_link_libraries(my-project burda::cpp-utils)
# Or with public visibility: target_link_libraries(my-project PUBLIC burda::cpp-utils)
```

### 2. Manual Way
Not recommended.

Make sure that the `include` directory is in the search paths.

You also have to set C++ 14 standard and potentially other settings as well.

## Examples
For full examples, see implementation of [tests](tests/unit).

### [idisable_copy.hpp](include/cpp_utils/primitives/idisable_copy.hpp)
Test implemented at: [idisable_copy_test.cpp](tests/unit/src/primitives/idisable_copy_test.cpp)
```cpp
#include <cpp_utils/primitives/idisable_copy.hpp>

// foo has deleted copy semantics
class foo : private burda::cpp_utils::primitives::idisable_copy
{
};
```

### [idisable_move.hpp](include/cpp_utils/primitives/idisable_move.hpp)
Test implemented at: [idisable_move_test.cpp](tests/unit/src/primitives/idisable_move_test.cpp)
```cpp
#include <cpp_utils/primitives/idisable_move.hpp>

// foo has deleted move semantics
class foo : private burda::cpp_utils::primitives::idisable_move
{
};

class disabled : private burda::cpp_utils::primitives::idisable_move
                 private burda::cpp_utils::primitives::idisable_copy
{
}
```

### [measure_duration.hpp](include/cpp_utils/time/measure_duration.hpp)
Test implemented at: [measure_duration_test.cpp](tests/unit/src/time/measure_duration_test.cpp)
```cpp
#include <cpp_utils/time/measure_duration.hpp>

// this should yield around 4 seconds, "duration" is of type "std::chrono<double>"
// just the example:
 const auto duration = burda::cpp_utils::measure_duration([]() { std::this_thread::sleep_for(4s); });
```

## Unit Tests
Tests require sub-module [cmake-helpers](https://github.com/karel-burda/cmake-helpers) and [test-utils](https://github.com/karel-burda/test-utils).

For building tests, run CMake in the source directory [tests/unit](tests/unit):

```cmake
cmake -Bbuild -H.
# You can also add coverage by appending "-DCOVERAGE:BOOL=ON"
cmake -Bbuild/tests/unit -Htests/unit -Dcpp-utils_DIR:PATH=$(pwd)/build -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo
cmake --build build/tests/unit --config RelWithDebInfo
# This runs target "run-all-tests-verbose" that will also run the tests with timeout, etc.:
cmake --build build/tests/unit --target run-all-tests-verbose --config RelWithDebInfo
# Or you can execute tests manually
```

For more info, see [.travis.yml](.travis.yml).

## Continuous Integration
Continuous Integration is now being run Linux, OS X and Windows on Travis: https://travis-ci.org/karel-burda/cpp-utils.

Compilers are set-up to treat warnings as errors and with pedantic warning level.

The project is using these jobs:
  * `cpp-utils, tests -- linux, debug, cppcheck, coverage, g++, 64-bit`
  * `cpp-utils, tests -- osx, release with debug info, clang++, 64-bit`
  * `cpp-utils, tests -- windows, release, msvc, 32-bit`

Project uses [codecov.io](https://codecov.io/gh/karel-burda/cpp-utils) for code coverage summary.
