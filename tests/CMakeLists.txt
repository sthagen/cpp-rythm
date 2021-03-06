# add catch
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
    file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.13.3/catch.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
endif()

set(tests
    all_of.cpp
    any_of.cpp
    none_of.cpp
    drop_n.cpp
    take_n.cpp
    drop_nth.cpp
    take_nth.cpp
    drop_n_take_m.cpp
    take_n_drop_m.cpp
    elapsed.cpp
    count_true.cpp
    count_false.cpp
    count_zero.cpp
    count_if.cpp
    count_else.cpp
    schmitt_trigger.cpp
    schmitt_trigger_inverting.cpp)

add_executable(rythm_test test.cpp ${tests})
target_include_directories(rythm_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(rythm_test PROPERTIES CXX_STANDARD 17)

enable_testing()
add_test(NAME test COMMAND rythm_test)
