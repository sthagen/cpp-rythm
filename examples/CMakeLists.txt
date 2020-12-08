set(examples
    drop_n.cpp)

add_executable(rythm_drop_n drop_n.cpp)
target_include_directories(rythm_drop_n PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(rythm_drop_n PROPERTIES CXX_STANDARD 17)

enable_testing()
add_test(NAME examples COMMAND rythm_drop_n)
