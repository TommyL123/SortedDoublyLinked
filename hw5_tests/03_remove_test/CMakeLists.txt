include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5removeTest-3 remove_test.cpp)
target_link_libraries(runHW5removeTest-3 hw5_library gtest gtest_main)