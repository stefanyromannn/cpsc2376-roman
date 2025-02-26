cmake_minimum_required(VERSION 3.10)
project(Practice03)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include directories (if any)
include_directories(practice)

# Add executable target


# Link with GoogleTest (if needed)
add_subdirectory(googletest)
target_link_libraries(practice03_test gtest gtest_main)

