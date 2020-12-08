cmake_minimum_required(VERSION 3.16)
project(RYTHM VERSION 2020.12)

option(RYTHM_BUILD_EXAMPLES "whether or not to build the examples" ON)
option(RYTHM_BUILD_TESTS "whether or not to build the tests" ON)

set(include_dest "include")
set(tool_dest "bin")

# add external libraries (not header-only)
# include(external/external.cmake)

# subdirectories
if (RYTHM_BUILD_TESTS)
    add_subdirectory(tests)
endif()
if (RYTHM_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
