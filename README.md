![Version](https://img.shields.io/badge/version-0.9.0-green.svg)
[![License](https://img.shields.io/badge/license-MIT_License-green.svg?style=flat)](LICENSE)

# Introduction
`cpp-utils` features tiny c++ helper and primitives that are used across my projects.

See [include](include) for main functionality and [tests](tests) for tests.

# Build Process
For generation of project containing the implementation and tests, run the cmake in the top-level directory like this:

`cmake .`

I personally prefer to specify a separate build directory explicitly:

`cmake -Bbuild -H.`

You can of course specify ordinary cmake options like build type (debug, release with debug info, ...), used generator, etc.

# Tests
For running unit and integration tests, execute

`cmake . -DUNIT_TESTS:BOOL=ON`

Tests are being run in the Continuous Integration environment.
