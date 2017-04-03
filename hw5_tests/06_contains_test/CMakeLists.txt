include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5ContainsTest-6 contains_test.cpp)
target_link_libraries(runHW5ContainsTest-6 hw5_library gtest gtest_main)