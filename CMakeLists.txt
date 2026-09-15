cmake_minimum_required(VERSION 4.3)
project(SimpleSnakeGam)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED) # ask CMAKE to find raylib

add_executable(SimpleSnakeGam main.cpp)

target_link_libraries(SimpleSnakeGam raylib) # ask CMAKE to link raylib