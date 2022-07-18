cmake_minimum_required(VERSION 3.16)
project(Leetcode)


add_subdirectory(src)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-fsanitize=address -ggdb3 -Wall -Wextra")
add_definitions(-std=c++17)

set(CXX_FLAGS "-fsanitize=address -ggdb3 -Wall -Wextra")