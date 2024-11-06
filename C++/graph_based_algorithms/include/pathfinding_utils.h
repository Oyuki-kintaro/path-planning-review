#ifndef PATHFINDING_UTILS_H
#define PATHFINDING_UTILS_H


#include <iostream>
#include <vector>
#include <utility> 
#include <set> 
#include <queue>
#include <map>
#include <stack>

// Constants for start and end markers
const char START_CHAR = 'S';
const char END_CHAR = 'E';
const int NOT_FOUND = -1;

// Directions (defined elsewhere in the file)
extern const std::vector<std::pair<int, int>> directions;

/**
 * @brief Performs breadth-first search on the given map.
 * 
 * @param map A reference to a 2D vector representing the map.
 * @return int The distance in steps from the start position to the end position.
 */
int bfs(std::vector<std::vector<char>>& map);

/**
 * @brief Performs depth-first search on the given map.
 * 
 * @param map A reference to a 2D vector representing the map.
 * @return int The distance in steps from the start position to the end position.
 */
int dfs(std::vector<std::vector<char>>& map);

/**
 * @brief Recursive helper function for depth-first search.
 * 
 * @param grid A reference to a 2D vector representing the map.
 * @param current The current position in the search.
 * @param end The end position in the search.
 * @param visited A set of visited positions in the search.
 * @param came_from A map recording the preceding position for each visited position.
 * @return bool True if the end position is found, false otherwise.
 */
bool dfs_recursive(std::vector<std::vector<char>>& grid, std::pair<int, int> current, 
                   const std::pair<int, int>& end, std::set<std::pair<int, int>>& visited,
                   std::map<std::pair<int, int>, std::pair<int, int>>& came_from);

/**
 * @brief Finds start and end locations within the given map.
 * 
 * @param map A constant reference to a 2D vector representing the map.
 * @return std::pair<std::pair<int, int>, std::pair<int, int>> The found locations as pairs of coordinates.
 */
std::pair<std::pair<int, int>, std::pair<int, int>> findLocations(const std::vector<std::vector<char>>& map);

/**
 * @brief Marks the path from the end position to the start position in the grid.
 * 
 * This function traces back from the end position to the start position using 
 * the `came_from` map, marking each cell along the path with a specific character (e.g., '*').
 * 
 * @param grid The 2D grid representing the map, where the path will be marked.
 * @param came_from A map that records the preceding cell for each cell visited, used to trace the path.
 * @param start The starting position coordinates in the grid.
 * @param end The ending position coordinates in the grid.
 */
void markPath(std::vector<std::vector<char>>& grid, std::map<std::pair<int, int>, std::pair<int, int>>& came_from, const std::pair<int, int>& start, const std::pair<int, int>& end);


/**
 * @brief Checks if a cell in the grid is traversable.
 * 
 * Determines whether a cell at position (x, y) in the grid is traversable, based on 
 * boundaries and whether it has been visited before.
 * 
 * @param grid The 2D grid representing the map.
 * @param visited A set containing the coordinates of cells that have already been visited.
 * @param x The x-coordinate of the cell to check.
 * @param y The y-coordinate of the cell to check.
 * @return True if the cell is within bounds, is not a wall or obstacle, and has not been visited; false otherwise.
 */
bool isTraversable(const std::vector<std::vector<char>>& grid, std::set<std::pair<int, int>>& visited, int x, int y);

#endif // PATHFINDING_UTILS_H