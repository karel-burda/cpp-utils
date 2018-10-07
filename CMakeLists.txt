cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(cpp-utils VERSION 0.9.0 LANGUAGES CXX)

include("cmake-helpers/cmake-helpers/messages.cmake")
include("cmake-helpers/cmake-helpers/standard-settings.cmake")

option(UNIT-TESTS "Build with unit tests" OFF)

_print_project_version()

_set_standards("11" "14")
_set_default_build_type("Debug")

set(HEADERS
    include/cpp_utils/primitives/idisable_copy.hpp
    include/cpp_utils/primitives/idisable_move.hpp)

set(OTHER
    README.md
    .travis.yml
    ${PROJECT_NAME}-config.cmake.in)

add_custom_target(${PROJECT_NAME} SOURCES ${HEADERS} ${OTHER})

configure_file(${PROJECT_NAME}-config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" @ONLY)

if (UNIT-TESTS)
    # TODO: remove this dirty hack
    unset(UNIT-TESTS CACHE)
    add_subdirectory(test-utils)

    add_subdirectory(tests/unit)
endif()
