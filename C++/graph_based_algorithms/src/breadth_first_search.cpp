#include "graph_based_utils.h"

// Constants for start and end markers
const char START_CHAR = 'S';
const char END_CHAR = 'E';
const int NOT_FOUND = -1;

int bfs(std::vector<std::vector<char>>& grid)
{
    // define possible moves
    std::vector<std::pair<int, int>> directions = {
        {-1, 0}, // Move left
        {1, 0},  // Move right
        {0, -1}, // Move down
        {0, 1}   // Move up
    };

    // get start and end positions
    std::pair<std::pair<int, int>, std::pair<int, int>> positions = findLocations(grid); // {start position, end position}
    std::queue<std::pair<std::pair<int, int>, int>> queue; // (position, distance)
    queue.push({positions.first, 0});

    // Track visited cells
    std::set<std::pair<int, int>> visited; 
    visited.insert(positions.first);
    std::map<std::pair<int, int>, std::pair<int, int>> came_from; // slower than unsing std::unordered_map
    came_from[positions.first] = {-1, -1};
    
    std::pair<std::pair<int, int>, int> currentPosition;
    std::pair<int, int> current;
    int distance = NOT_FOUND;

    while (!queue.empty()) {
        currentPosition = queue.front();
        queue.pop();

        // check if end is reached
        distance = currentPosition.second;
        if (currentPosition.first == positions.second) {
            
            current = positions.second;
            while (current != positions.first) {
                grid[current.first][current.second] = '*'; // Mark the path
                current = came_from[current];  
            }
            return distance; // Return the distance to the end position
        }

        // Explore neighbors
        for (std::pair<int, int>& direction: directions) {
            int dx = direction.first;
            int dy = direction.second;
            
            int x = currentPosition.first.first + dx;
            int y = currentPosition.first.second + dy;

            if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] != '-' && grid[x][y] != '|' && visited.find({x, y}) == visited.end()) {
                visited.insert({x, y});
                queue.push({{x, y}, distance + 1});
                came_from[{x, y}] = {currentPosition.first.first, currentPosition.first.second};
            }
        }
    }
    return distance; // End is unreachable
}



std::pair<std::pair<int, int>, std::pair<int, int>> findLocations(const std::vector<std::vector<char>>& map) {
    std::pair<int, int> start_pos = {NOT_FOUND, NOT_FOUND}; 
    std::pair<int, int> end_pos = {NOT_FOUND, NOT_FOUND}; 

    for (size_t i = 0; i < map.size(); ++i) { // rows
        for (size_t j = 0; j < map[i].size(); ++j) { // columns
            if (map[i][j] == START_CHAR) {
                start_pos = {static_cast<int>(i), static_cast<int>(j)};
            } 
            else if (map[i][j] == END_CHAR) {
                end_pos = {static_cast<int>(i), static_cast<int>(j)};
            }

            // Break if both locations are found
            if (start_pos.first != NOT_FOUND && end_pos.first != NOT_FOUND) {
                return {start_pos, end_pos};
            }
        }
    }
    return {start_pos, end_pos}; // Return not found positions
}
