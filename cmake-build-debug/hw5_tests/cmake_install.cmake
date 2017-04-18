# Install script for directory: /Users/tommythemoney/Documents/TommyL123-HW5/hw5_tests

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/lib/gtest-1.7.0/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/00_basic_tests/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/01_constructor_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/02_add_to_list_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/03_remove_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/04_is_empty_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/05_size_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/06_contains_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/07_get_frequency_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/08_copy_constructor_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/09_head_ptr_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/10_tail_ptr_test/cmake_install.cmake")
  include("/Users/tommythemoney/Documents/TommyL123-HW5/cmake-build-debug/hw5_tests/11_mid_ptr_test/cmake_install.cmake")

endif()

