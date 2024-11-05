# Define possible moves (left, right, down, up)
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
non_traversable = {'-', '|'}

def is_traversable(grid, visited, rows, cols, x, y):
        """Check if a cell is within bounds, traversable, and not yet visited."""
        return 0 <= x < rows and 0 <= y < cols and grid[x][y] not in non_traversable and (x, y) not in visited

def dfs(grid, start, end):
    """
    Perform depth-first search (DFS) on a 2D grid to find the shortest path from start to end.

    Args:
        grid (List[List[str]]): The 2D grid representing the map.
        start (Tuple[int, int]): Coordinates of the starting point.
        end (Tuple[int, int]): Coordinates of the ending point.

    Returns:
        Tuple[List[List[str]], int]: A tuple containing:
            - The grid with the path marked.
            - The number of steps in the shortest path, or -1 if the end is unreachable.
    """
    # Initialize visited set and came_from dictionary
    visited = set()
    came_from = {}

    # Clone the grid to avoid modifying the original during path marking
    path_grid = [row[:] for row in grid]

    rows, cols = len(grid), len(grid[0])

    def dfs_recursive(x, y):
        if (x, y) == end:
            return True

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if is_traversable(grid, visited, rows, cols, nx, ny):
                visited.add((nx, ny))
                came_from[(nx, ny)] = (x, y)  # Record the previous cell
                if dfs_recursive(nx, ny):
                    return True
        return False

    # Start the DFS from the start position
    visited.add(start)
    if dfs_recursive(start[0], start[1]):
        # Backtrack to mark the path
        current = end
        while current != start:
            cx, cy = current
            path_grid[cx][cy] = '*'  # Mark each cell along the path
            current = came_from[current]
        
        # Calculate the distance (number of steps) from the start to the end
        dist = 0
        current = end
        while current != start:
            dist += 1
            current = came_from[current]
        
        return path_grid, dist
    
    # If end is unreachable
    return path_grid, -1