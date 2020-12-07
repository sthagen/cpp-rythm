cmake_minimum_required(VERSION 3.16)
project(RYTHM VERSION 2020.12)

option(RYTHM_BUILD_TEST "whether or not to build the test" ON)

set(include_dest "include")
set(tool_dest "bin")

# add external libraries (not header-only)
# include(external/external.cmake)

# subdirectories
if (RYTHM_BUILD_TEST)
    add_subdirectory(tests)
endif()
