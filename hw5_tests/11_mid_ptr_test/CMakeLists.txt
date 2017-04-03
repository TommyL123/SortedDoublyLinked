include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5MidPointerTest-11 mid_ptr_test.cpp)
target_link_libraries(runHW5MidPointerTest-11 hw5_library gtest gtest_main)