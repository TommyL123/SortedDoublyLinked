include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5SizeTest-5 size_test.cpp)
target_link_libraries(runHW5SizeTest-5 hw5_library gtest gtest_main)