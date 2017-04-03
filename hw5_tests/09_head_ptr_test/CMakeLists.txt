include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5HeadPointerTest-9 head_ptr_test.cpp)
target_link_libraries(runHW5HeadPointerTest-9 hw5_library gtest gtest_main)