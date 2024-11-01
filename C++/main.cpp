#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

//function prototypes
void Menu();
int ReadCSVFile(std::string filename);


int main()
{
    int choice = 0;
    std::string filename;
    
    do {

        //print menu
        Menu();
        std::cin >> choice;

        // get user input
        switch (choice)
        {
        case 1:
            filename = "../maps/map1.csv";
            break;
        case 2:
            filename = "../maps/map2.csv";
            break;
        case 3:
            filename = "../maps/map3.csv";
            break;
        case 4:
            filename = "../maps/map4.csv";
            break;
        case 5:
            filename = "../maps/map5.csv";
            break;
        case 6:
            break;
        default:
            std::cout << "ERROR: Please enter a number 1 - 6" << std::endl;
            break;
        }

        // take action based on input
        if (choice != 6)
        {
            ReadCSVFile(filename);
        }
               
    } while (choice != 6);
    std::cout << "Exiting..." << std::endl;
    exit(EXIT_SUCCESS);
}

void Menu()//Main Menu layout
{
    std::cout << "\n::::::::::Main Menu::::::::::\n" << std::endl;
    std::cout << "Choose a map:" << std::endl;
    std::cout << "1) Simple" << std::endl;
    std::cout << "2) Moderate" << std::endl;
    std::cout << "3) Intermediate" << std::endl;
    std::cout << "4) Advanced" << std::endl;
    std::cout << "5) Complex" << std::endl;
    std::cout << "6) Exit Program\n" << std::endl;
    std::cout << "Please select an option: ";
}

int ReadCSVFile(std::string filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1; // Return with an error code
    }

    std::string line;
    while (std::getline(file, line)) { // Read each line from the file
        std::stringstream ss(line); // Create a string stream from the line
        std::string value;

        while (std::getline(ss, value, ',')) { // Split the line by commas
            std::cout << value << " "; // Output each value
        }
        std::cout << std::endl; // New line for the next row
    }

    file.close(); // Close the file
    return 0;
}