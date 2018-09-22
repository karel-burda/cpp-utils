cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(cpp-utils VERSION 0.9.0 LANGUAGES NONE)

set(OTHER
    README.md
    .travis.yml)

set(SRCS
    include/primitives/idisable_copy.hpp
    include/primitives/idisable_move.hpp)

add_custom_target(${PROJECT_NAME} SOURCES ${SRCS} ${OTHER})
