![Version](https://img.shields.io/badge/version-0.9.0-green.svg)
[![License](https://img.shields.io/badge/license-MIT_License-green.svg?style=flat)](LICENSE)
[![Build Status](https://travis-ci.org/karel-burda/cpp-utils.svg?branch=develop)](https://travis-ci.org/karel-burda/cpp-utils)
[![Coverage Status](https://coveralls.io/repos/github/karel-burda/cpp-utils/badge.svg?branch=develop)](https://coveralls.io/github/karel-burda/cpp-utils?branch=develop)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/fd08a5e184a945208324fd7a415428ad)](https://app.codacy.com/app/karel-burda/cpp-utils?utm_source=github.com&utm_medium=referral&utm_content=karel-burda/function-loader&utm_campaign=Badge_Grade_Dashboard)

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
