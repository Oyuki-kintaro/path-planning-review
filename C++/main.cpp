#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graph_based_algorithms/include/graph_based_utils.h"

// Function prototypes
void DisplayMenu();
void DisplayMap(const std::vector<std::vector<char>>& map);
std::vector<std::vector<char>> LoadCSVFile(const std::string& filename);

int main() {
    int choice;
    std::string filename;
    std::vector<std::vector<char>> map;
    
    do {
        DisplayMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag on cin
            std::cin.ignore(); // Discard invalid input
            std::cerr << "\nERROR: Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue; // Restart the loop to display the menu again
        }

        // Validate user input and select corresponding file
        switch (choice) {
            case 1: filename = "../maps/map1.csv"; break;
            case 2: filename = "../maps/map2.csv"; break;
            case 3: filename = "../maps/map3.csv"; break;
            case 4: filename = "../maps/map4.csv"; break;
            case 5: filename = "../maps/map5.csv"; break;
            case 6: 
                std::cout << "Exiting..." << std::endl;
                return EXIT_SUCCESS;
            default:
                std::cerr << "\nERROR: Please enter a number between 1 and 6." << std::endl;
                continue;
        }

        // Read and display the selected map
        map = LoadCSVFile(filename);
        std::cout << "\nStarting Map: \n";
        DisplayMap(map);
        bfs(map);
        

    } while (true);
}

// Displays the main menu
void DisplayMenu() {
    std::cout << "\n:::::::::: Main Menu ::::::::::\n"
              << "Choose a map:\n"
              << "\t1) Simple\n"
              << "\t2) Moderate\n"
              << "\t3) Intermediate\n"
              << "\t4) Advanced\n"
              << "\t5) Complex\n"
              << "\t6) Exit Program\n"
              << "\tPlease select an option: ";
}

// Displays the map
void DisplayMap(const std::vector<std::vector<char>>& map) {
    for (const auto& row : map) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}

// Reads a CSV file and stores its contents in a 2D char vector
std::vector<std::vector<char>> LoadCSVFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<char>> grid;

    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open the file: " << filename << std::endl;
        return {}; // Return an empty grid if file cannot be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<char> row;
        for (char ch : line) {
            if (ch != ',') { // Skip commas
                row.push_back(ch);
            }
        }
        grid.push_back(row); // Add the row to the 2D array
    }

    return grid;
}
