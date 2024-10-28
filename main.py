import csv


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




#### MAIN ####
file_path = 'maps/map1.csv'
map, start_pos, end_pos = load_map_as_2D_arr(file_path)
print_map(map)
