
set(CMAKE_C_COMPILER_WORKS 1)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(SRC)



#add_subdirectory(14days-cracking)
add_subdirectory(linkedlist)
#add_subdirectory(backtracking)
add_subdirectory(arrays)
#add_subdirectory(strings)
#add_subdirectory(graph)
#add_subdirectory(trees)
#add_subdirectory(dp)
#add_subdirectory(stacks_queues)
#add_subdirectory(greedy)
#add_subdirectory(map_n_set)
#add_subdirectory(disjoint_set)
#add_subdirectory(matrix)
#add_subdirectory(bitmanupulations)
#add_subdirectory(math)
#add_subdirectory(practice)
#add_subdirectory(contests)
#add_subdirectory(leetcode75)
#add_subdirectory(recursions)
#add_subdirectory(memorization)
#add_subdirectory(2023)


#add_executable(app main.cpp "math/src/maximum_odd_binary_number.cpp")