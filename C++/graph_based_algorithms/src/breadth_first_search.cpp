#include "pathfinding_utils.h"

int bfs(std::vector<std::vector<char>>& grid)
{
    // get start and end positions
    std::pair<int, int> start, end;
    std::tie(start, end) = findLocations(grid);
    
    // Initialize the queue
    std::queue<std::pair<std::pair<int, int>, int>> queue; // (position, distance)
    queue.push({start, 0});

    // Track visited cells
    std::set<std::pair<int, int>> visited; 
    visited.insert(start);
    
    std::map<std::pair<int, int>, std::pair<int, int>> came_from; // slower than unsing std::unordered_map
    came_from[start] = {-1, -1};

    while (!queue.empty()) {
        std::pair<std::pair<int, int>, int> currentPosition = queue.front();
        queue.pop();

        // check if end is reached
        int distance = currentPosition.second;
        if (currentPosition.first == end) {
            
            markPath(grid, came_from, start, end);
            return distance; // Return the distance to the end position
        }

        // Explore neighbors
        for (const std::pair<int, int>& direction: directions) {

            int x = currentPosition.first.first + direction.first;
            int y = currentPosition.first.second + direction.second;

            // Check if the next cell is traversable    
            if (isTraversable(grid, visited, x, y)) {
                visited.insert({x, y});
                queue.push({{x, y}, distance + 1});
                came_from[{x, y}] = currentPosition.first;
            }
        }
    }
    return -1; // End is unreachable
}
