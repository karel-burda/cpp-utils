cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(tests LANGUAGES CXX)

_print_status_message("building with unit tests")

include("${CMAKE_SOURCE_DIR}/cmake-helpers/cmake-helpers/code-coverage.cmake")
include("${CMAKE_SOURCE_DIR}/cmake-helpers/cmake-helpers/gtest.cmake")
include("${CMAKE_SOURCE_DIR}/cmake-helpers/cmake-helpers/threads.cmake")
include("${CMAKE_SOURCE_DIR}/cmake-helpers/cmake-helpers/warnings.cmake")

_gtest_download_and_build("gtest-build" "Release" "gtest-src" "0957cce368316577aae5ddfffcb67f24621d69e7")

add_executable(${PROJECT_NAME} "")

target_sources(
    ${PROJECT_NAME}
        PUBLIC
            src/primitives/idisable_copy_test.cpp
            src/primitives/idisable_move_test.cpp
            src/time/measure_duration_test.cpp)

add_dependencies(${PROJECT_NAME} gtest-build)

_gtest_resolve_build_options(${PROJECT_NAME})

find_package(cpp-utils REQUIRED CONFIG PATHS ${CMAKE_BINARY_DIR} NO_DEFAULT_PATH)
target_include_directories(${PROJECT_NAME} PUBLIC ${cpp-utils_INCLUDE_DIRS})

find_package(test-utils REQUIRED CONFIG PATHS ${CMAKE_BINARY_DIR} NO_DEFAULT_PATH)
target_include_directories(${PROJECT_NAME} PUBLIC ${test-utils_INCLUDE_DIRS})

if (COVERAGE)
    _print_status_message("building unit tests with code coverage")

    _coverage_add_build_options(${PROJECT_NAME})
endif()

enable_testing()

add_test(NAME all-unit-tests
         WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
         COMMAND $<TARGET_FILE:${PROJECT_NAME}> --gtest_color=yes --gtest_shuffle)

add_custom_target(run-all-tests-verbose
                    COMMAND ${CMAKE_CTEST_COMMAND} -V -C ${CMAKE_BUILD_TYPE} --build-run-dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} --timeout 300
                    DEPENDS ${PROJECT_NAME})

_add_pedantic_warning_level(${PROJECT_NAME})
_supress_cxx_compiler_warning(${PROJECT_NAME} "keyword-macro")
