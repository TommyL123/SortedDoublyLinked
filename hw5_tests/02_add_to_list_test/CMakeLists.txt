include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5AddToListTest-2 add_to_list_test.cpp)
target_link_libraries(runHW5AddToListTest-2 hw5_library gtest gtest_main)