#include "graph_based_utils.h"

void bfs(const std::vector<std::vector<char>>& grid)
{
    //std::cout << "\nTESTING" << std::endl;
    // define possible moves
    std::set<char> non_traversable = {'-', '|'};
    std::vector<std::pair<int, int>> directions = {
        {-1, 0}, // Move left
        {1, 0},  // Move right
        {0, -1}, // Move down
        {0, 1}   // Move up
    };

    // get start and end positions
    auto [start, end] = findLocations(grid);
    std::queue<std::pair<std::pair<int, int>, int>> queue; // (position, distance)
    queue.push({start, 0});

    // Track visited cells
    std::set<std::pair<int, int>> visited; 
    visited.insert(start);
}



std::pair<std::pair<int, int>, std::pair<int, int>> findLocations(const std::vector<std::vector<char>>& map) {
    char start = 'S';
    char end = 'E';
    
    // variable to store start and end positions
    std::pair<int, int> start_pos = {-1, -1}; 
    std::pair<int, int> end_pos = {-1, -1}; 

    for (int i = 0; i < map.size(); ++i) { // rows
        for (int j = 0; j < map[i].size(); ++j) { // columns
            if (map[i][j] == start) {
                start_pos = {i, j}; 
            } 
            else if (map[i][j] == end) {
                end_pos = {i, j}; 
            }

            // Break if both locations are found
            if (start_pos.first != -1 && end_pos.first != -1) {
                return {start_pos, end_pos};
            }
        }
    }
    return {start_pos, end_pos};
}
