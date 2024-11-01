import csv
import sys
import os


# Read CSV and create 2D array
def load_map_as_2D_arr(filename):
    map_array = []
    start_pos = None
    end_pos = None

    with open(filename, 'r') as file:
        reader = csv.reader(file)
        for x, row in enumerate(reader):
            map_row = [char for char in row[0]]
            map_array.append(map_row)
            
            # locate & assign start and end positions
            for y, char in enumerate(map_row):
                if char == 'S':
                    start_pos = (x, y)
                elif char == 'E':
                    end_pos = (x, y)
    
    return map_array, start_pos, end_pos

# Print map to verify
def print_map(map_array):
    for row in map_array:
        print(''.join(row))

def menu():
    path = "../maps/"

    choice = input("""\tChoose a map:
            1: Simple
            2: Moderate
            3: Intermediate
            4: Advanced
            5: Complex Maze
            6: Exit
        
        Please select an option: """)
    
    try: 
        num_choice = int(choice)
        
        if num_choice == 1:
            filename = "map1.csv"
        elif num_choice == 2:
            filename = "map2.csv"
        elif num_choice == 3:
            filename = "map3.csv"
        elif num_choice == 4:
            filename = "map4.csv"
        elif num_choice == 5:
            filename = "map5.csv"
        elif num_choice == 6:
            sys.exit()
        else:
            print("ERROR: You must only select a number 1 - 6")
            print("Please try again")
            menu()

        return os.path.join(path, filename)
    
    except SystemExit:
        print("Exiting...")
        sys.exit()
    except:
        print("ERROR: Please enter a number 1 - 6")
        menu()



#### MAIN ####
file_path = menu() 
map_2D_array, start_pos, end_pos = load_map_as_2D_arr(file_path)
print_map(map)
