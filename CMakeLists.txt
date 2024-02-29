cmake_minimum_required(VERSION 3.8)
set(CMAKE_C_COMPILER_WORKS 1)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


project(Leetcode)

add_subdirectory(src)
#add_subdirectory(daily)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS " -std=c++20 -fsanitize=address -ggdb3 -Wall -Wextra")

set(CXX_FLAGS " -std=c++17 -fsanitize=address -ggdb3 -Wall -Wextra")

add_definitions(-DCMAKE_BUILD_TYPE=Debug)