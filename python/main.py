import csv
import sys
import os
import time
from graph_based_algorithms import breadth_first_search, depth_first_search

# Constants
MAPS_PATH = os.path.join(os.path.dirname(__file__), '../maps/')
MAP_CHOICES = {
    1: "map1.csv",
    2: "map2.csv",
    3: "map3.csv",
    4: "map4.csv",
    5: "map5.csv"
}

def load_map_as_2D_arr(filename):
    """
    Reads a CSV file and creates a 2D map array.
    
    Args:
        filename (str): Path to the CSV file containing the map.
    
    Returns:
        tuple: A tuple containing:
            - map_array (list of lists): 2D array representation of the map.
            - start_pos (tuple of int): Coordinates of the starting position.
            - end_pos (tuple of int): Coordinates of the ending position.
    """
    map_array = []
    start_pos = None
    end_pos = None

    with open(filename, 'r') as file:
        reader = csv.reader(file)
        for x, row in enumerate(reader):
            map_row = [char for char in row[0]]
            map_array.append(map_row)
            
            # Locate start and end positions
            for y, char in enumerate(map_row):
                if char == 'S':
                    start_pos = (x, y)
                elif char == 'E':
                    end_pos = (x, y)
    
    return map_array, start_pos, end_pos

def print_map(map_array):
    """Prints the map to the console for visual verification."""
    for row in map_array:
        print(''.join(row))

def display_menu():
    """
    Displays a menu for selecting a map difficulty level.
    
    Returns:
        str: File path of the selected map.
    """
    print("Choose a map:")
    for option, map_name in MAP_CHOICES.items():
        print(f"\t{option}: {map_name.replace('.csv', '').capitalize()}")
    print("\t6: Exit")
    
    while True:
        try:
            choice = int(input("Please select an option: "))
            if choice == 6:
                print("Exiting...")
                sys.exit()
            if choice in MAP_CHOICES:
                return os.path.join(MAPS_PATH, MAP_CHOICES[choice])
            else:
                print("ERROR: You must select a number between 1 - 6.")
        except ValueError:
            print("ERROR: Please enter a valid number between 1 - 6.")

def choose_algorithm():
    """Prompt the user to choose a pathfinding algorithm ."""
    
    print("\nChoose a pathfinding algorithm:")
    print("\t1: Breadth-First Search (BFS)")
    print("\t2: Depth-First Search (DFS)")
    print("\t3: Exit")
    
    while True:
        try:
            choice = int(input("Please select an option: "))
            if choice == 1:
                return "bfs"
            elif choice == 2:
                return "dfs"
            elif choice == 3:
                print("Exiting...")
                sys.exit()
            else:
                print("ERROR: You must select either 1, 2 or 3.")
        except ValueError:
            print("ERROR: Please enter a valid number (1, 2 or 3).")


def main():
    """Main function to execute the map loading and pathfinding algorithm."""
    
    while True:
        file_path = display_menu()
        map_2D_array, start_pos, end_pos = load_map_as_2D_arr(file_path)

        # Ask the user to select a pathfinding algorithm
        algorithm_choice = choose_algorithm()
        
        start_time = time.perf_counter()
        if algorithm_choice == "bfs":
            final_map, result = breadth_first_search.bfs(map_2D_array, start_pos, end_pos)
        elif algorithm_choice == "dfs":
            final_map, result = depth_first_search.dfs(map_2D_array, start_pos, end_pos)
        end_time = time.perf_counter()

        # Print the results
        print("\nStarting Map:")
        print_map(map_2D_array)
        print(f"\nFinal Map:")
        print_map(final_map)
        print(f"\nPathfinding algorithm: {algorithm_choice.upper()}\tTime taken: {end_time - start_time:.8f} seconds")
        print(f"Result: {result} steps\n")  



if __name__ == "__main__":
    main()
