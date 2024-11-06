#include "pathfinding_utils.h"

// Directions
const std::vector<std::pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

std::pair<std::pair<int, int>, std::pair<int, int>> findLocations(const std::vector<std::vector<char>>& map) {
    std::pair<int, int> start_pos = {NOT_FOUND, NOT_FOUND}; 
    std::pair<int, int> end_pos = {NOT_FOUND, NOT_FOUND}; 

    for (int i = 0; i < map.size(); ++i) { // rows
        for (int j = 0; j < map[i].size(); ++j) { // columns
            if (map[i][j] == START_CHAR) start_pos = {i, j};
            if (map[i][j] == END_CHAR) end_pos = {i, j};
        }
    }
    return {start_pos, end_pos}; // Return not found positions
}

void markPath(std::vector<std::vector<char>>& grid, std::map<std::pair<int, int>, std::pair<int, int>>& came_from, const std::pair<int, int>& start, const std::pair<int, int>& end) {
    std::pair<int, int> current = end;
    while (current != start) {
        grid[current.first][current.second] = '*';
        current = came_from[current];
    }
}


bool isTraversable(const std::vector<std::vector<char>>& grid, std::set<std::pair<int, int>>& visited, int x, int y) {
    return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && 
            grid[x][y] != '-' && grid[x][y] != '|' && visited.find({x, y}) == visited.end());
}
