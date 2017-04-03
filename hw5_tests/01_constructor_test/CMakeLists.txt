include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHW5ConstructorTest-1 constructor_test.cpp)
target_link_libraries(runHW5ConstructorTest-1 hw5_library gtest gtest_main)