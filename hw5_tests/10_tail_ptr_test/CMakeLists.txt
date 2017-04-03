include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5TailPointerTest-10 tail_ptr_test.cpp)
target_link_libraries(runHW5TailPointerTest-10 hw5_library gtest gtest_main)