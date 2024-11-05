#include <iostream>
#include <vector>
#include <utility> 
#include <set> 
#include <queue>
#include <map>


/**
 * @brief Performs breadth-first search on the given map.
 * 
 * @param map A reference to a 2D vector representing the map.
 * @return int The distance in steps from the start position to the end position.
 */
int bfs(std::vector<std::vector<char>>& map); // Replace with your actual function signature

/**
 * @brief Finds start and end locations within the given map.
 * 
 * @param map A constant reference to a 2D vector representing the map.
 * @return std::pair<std::pair<int, int>, std::pair<int, int>> The found locations as pairs of coordinates.
 */
std::pair<std::pair<int, int>, std::pair<int, int>> findLocations(const std::vector<std::vector<char>>& map);

