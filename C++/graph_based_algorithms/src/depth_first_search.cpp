#include "pathfinding_utils.h"

// Recursive helper function
bool dfs_recursive(std::vector<std::vector<char>>& grid, std::pair<int, int> current, 
                   const std::pair<int, int>& end, std::set<std::pair<int, int>>& visited,
                   std::map<std::pair<int, int>, std::pair<int, int>>& came_from) 
{
    if (current == end) {
        return true; // Found the end position
    }

    for (const std::pair<int, int>& direction : directions) {
        
        int x = current.first + direction.first;
        int y = current.second + direction.second;
        std::pair<int, int> next = {x, y};

        // Check boundaries and traversability
        if (isTraversable(grid, visited, x, y)) 
        {
            visited.insert(next);
            came_from[next] = current;

            // Recursive call
            if (dfs_recursive(grid, next, end, visited, came_from)) {
                return true;
            }
        }
    }
    return false;
}

int dfs(std::vector<std::vector<char>>& grid) 
{
    // get start and end positions
    std::pair<int, int> start, end;
    std::tie(start, end) = findLocations(grid);
    
    // Initialize the stack
    std::stack<std::pair<std::pair<int, int>, int>> stack;
    stack.push({start, 0});

    // Track visited cells
    std::set<std::pair<int, int>> visited; 
    visited.insert(start);

    std::map<std::pair<int, int>, std::pair<int, int>> came_from; // slower than unsing std::unordered_map
    came_from[start] = {-1, -1};
    
    // Call the recursive DFS function
    if (dfs_recursive(grid, start, end, visited, came_from)) {
        // Backtrack to mark the path
        std::pair<int, int> current = end;
        int distance = 0;

        while (current != start) {
            grid[current.first][current.second] = '*'; // Mark the path
            current = came_from[current];
            ++distance;
        }
        return distance; // Return the path length
    }

    return -1; // End is unreachable
}