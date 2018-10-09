![Version](https://img.shields.io/badge/version-0.9.0-green.svg)
[![License](https://img.shields.io/badge/license-MIT_License-green.svg?style=flat)](LICENSE)
[![Build Status](https://travis-ci.org/karel-burda/cpp-utils.svg?branch=develop)](https://travis-ci.org/karel-burda/cpp-utils)
[![Coverage Status](https://coveralls.io/repos/github/karel-burda/cpp-utils/badge.svg?branch=develop)](https://coveralls.io/github/karel-burda/cpp-utils?branch=develop)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/fd08a5e184a945208324fd7a415428ad)](https://app.codacy.com/app/karel-burda/cpp-utils?utm_source=github.com&utm_medium=referral&utm_content=karel-burda/function-loader&utm_campaign=Badge_Grade_Dashboard)

# Important
This project contains git sub-modules that are needed for building example and tests.

If you just want to use the implementation, you can clone **without** sub-modules. In case you want to build example, tests, or use CMake, please, be sure to clone the repository
with `--recurse-submodules` or `--recursive` on older versions of git. Alternatively, you can clone without sub-modules and initialize these later.

# Introduction
`cpp-utils` features tiny c++ helpers and primitives that are used across my projects.

Implementation is header-only.

See [include/cpp_utils](include/cpp_utils) for main functionality and [tests/unit](tests/unit) for unit tests.

# Usage
In order to use the `cpp-utils`, it's the `include` directory that matters. Just make sure that the header search path is pointing to the [include](include) directory located in the root directory.

You can use the provided CMake package configuration at [cpp-utils-config.cmake.in](cpp-utils-config.cmake.in).

## Examples
For full examples, see implementation of [tests](tests/unit).

### idisable_copy.hpp
```cpp
#include <cpp_utils/primitives/idisable_copy.hpp>

// foo has deleted copy semantics
class foo : private burda::cpp_utils::primitives::idisable_copy
{
};
```

### idisable_move.hpp
```cpp
#include <cpp_utils/primitives/idisable_move.hpp>

// foo has deleted move semantics
class foo : private burda::cpp_utils::primitives::idisable_move
{
};

class crippled : private burda::cpp_utils::primitives::idisable_move
                 private burda::cpp_utils::primitives::idisable_copy
{
}
```

### measure_duration.hpp
```cpp
#include <cpp_utils/time/measure_duration.hpp>

// this should yield around 4 seconds, "duration" is of type "std::chrono<double>"
 const auto duration = burda::cpp_utils::measure_duration([]() { std::this_thread::sleep_for(4s); });
```

# Build Process
For generation of project containing the implementation, run the cmake in the top-level directory like this:

`cmake .`

I personally prefer to specify a separate build directory explicitly:

`cmake -Bbuild -H.`

You can of course specify ordinary cmake options like build type (debug, release with debug info, ...), used generator, etc.

# Unit Tests
For building tests, run cmake with the option `UNIT-TESTS=ON`:

`cmake -Bbuild -H. -DUNIT-TESTS:BOOL=ON`

# Continuous Integration
Continuous Integration is now being run Linux (with GCC 5.x) on Travis: https://travis-ci.org/karel-burda/cpp-utils.

Compilers are set-up to treat warnings as errors and with pedantic warning level. Targets are built in release mode with debug symbols and code coverage measure).

The project is using just one stage (because of the overhead of spawning other stages)
* `tests (C++14)` -- cppcheck, build (linux, gcc5), tests

Project uses [coveralls.io](https://coveralls.io/github/karel-burda/cpp-utils) for code coverage summary and [codacy](https://app.codacy.com/app/karel-burda/cpp-utils/dashboard) for the coding style and additional static analysis.
