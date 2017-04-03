include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5GetFrequencyTest-7 get_frequency_test.cpp)
target_link_libraries(runHW5GetFrequencyTest-7 hw5_library gtest gtest_main)