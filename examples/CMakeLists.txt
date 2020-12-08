set(examples
    drop_n.cpp
    take_n.cpp)

add_executable(rythm_drop_n drop_n.cpp)
target_include_directories(rythm_drop_n PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(rythm_drop_n PROPERTIES CXX_STANDARD 17)

add_executable(rythm_take_n take_n.cpp)
target_include_directories(rythm_take_n PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(rythm_take_n PROPERTIES CXX_STANDARD 17)

enable_testing()
add_test(NAME examples_drop_n COMMAND rythm_drop_n)
add_test(NAME examples_take_n COMMAND rythm_take_n)
