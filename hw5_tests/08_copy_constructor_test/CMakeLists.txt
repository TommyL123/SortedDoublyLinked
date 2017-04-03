include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5CopyConstructorTest-8 copy_constructor_test.cpp)
target_link_libraries(runHW5CopyConstructorTest-8 hw5_library gtest gtest_main)