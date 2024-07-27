project(graphs)


set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS " -std=c++17 -fsanitize=address -ggdb3 -Wall -Wextra")

set(CXX_FLAGS " -std=c++17 -fsanitize=address -ggdb3 -Wall -Wextra")

#add_executable(clonegraph leetcode/clone_graph.cpp)
#add_executable(shortedpath_visiting_allnodes leetcode/shortest_path_visiting_all_nodes.cpp)
#add_executable(critical_connections_in_a_network src/critical_connections_in_a_network.cpp)
#add_executable(numberof_islands src/number_of_islands.cpp)
#add_executable(flood_fill1 src/flood_fill.cpp)
#add_executable(pacific_atlantic_atlantic_water_flow src/pacific_atlantic_atlantic_water_flow.cpp)
#add_executable(max_area_of_island src/max_area_of_island.cpp)
#add_executable(number_of_closed_islands src/number_of_closed_islands.cpp)
#add_executable(number_of_enclaves src/number_of_enclaves.cpp)
#add_executable(all_paths_from_source_to_target src/all_paths_from_source_to_target.cpp)
#add_executable(number_of_good_paths src/number_of_good_paths.cpp)
#add_executable(satisfiability_of_equality_equations src/satisfiability_of_equality_equations.cpp)
#add_executable(most_stones_removed_with_same_row_or_column src/most_stones_removed_with_same_row_or_column.cpp)
#add_executable(shortest_paths_with_alternating_colors src/shortest_paths_with_alternating_colors.cpp)
#add_executable(shortest_paths_with_alternating_colors src/shortest_paths_with_alternating_colors.cpp)
#add_executable(build_matrix_with_conditions src/build_matrix_with_conditions.cpp)
add_executable(minimum_cost_to_covert_string_1 src/minimum_cost_to_covert_string_1.cpp)
