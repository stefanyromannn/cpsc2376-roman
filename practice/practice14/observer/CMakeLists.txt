cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ObserverPattern)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_executable(ObserverPattern main.cpp gradebook.cpp)

# If you are using any external libraries, link them here
# Example: target_link_libraries(ObserverPattern someLibrary)