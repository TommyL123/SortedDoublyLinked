include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5isEmptyTest-4 is_empty_test.cpp.cpp)
target_link_libraries(runHW5isEmptyTest-4 hw5_library gtest gtest_main)