cmake_minimum_required(VERSION 3.16)
project(Leetcode)


add_subdirectory(src)
add_subdirectory(daily)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS " -std=c++20 -fsanitize=address -ggdb3 -Wall -Wextra")

set(CXX_FLAGS " -std=c++17 -fsanitize=address -ggdb3 -Wall -Wextra")

add_definitions(-DCMAKE_BUILD_TYPE=Debug)