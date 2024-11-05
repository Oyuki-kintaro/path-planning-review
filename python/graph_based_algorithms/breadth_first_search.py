from collections import deque

def bfs(grid, start, end):
    """
    Perform breadth-first search (BFS) on a 2D grid to find the shortest path from start to end.

    Args:
        grid (List[List[str]]): The 2D grid representing the map.
        start (Tuple[int, int]): Coordinates of the starting point.
        end (Tuple[int, int]): Coordinates of the ending point.

    Returns:
        Tuple[List[List[str]], int]: A tuple containing:
            - The grid with the path marked.
            - The number of steps in the shortest path, or -1 if the end is unreachable.
    """
    # Define possible moves (left, right, down, up)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    non_traversable = {'-', '|'}
    
    # Initialize the BFS queue
    queue = deque([(start, 0)])  # (position, distance)
    visited = {start}            # Track visited cells
    came_from = {start: None}     # Track the path to each cell
    
    # Clone the grid to avoid modifying the original during path marking
    path_grid = [row[:] for row in grid]
    rows, cols = len(grid), len(grid[0])

    def is_traversable(x, y):
        """Check if a cell is within bounds, traversable, and not yet visited."""
        return 0 <= x < rows and 0 <= y < cols and grid[x][y] not in non_traversable and (x, y) not in visited

    # BFS to explore paths
    while queue:
        (x, y), dist = queue.popleft()
        
        # Check if we've reached the end
        if (x, y) == end:
            # Backtrack to mark the path
            current = end
            while current != start:
                cx, cy = current
                path_grid[cx][cy] = '*'  # Mark each cell along the path
                current = came_from[current]
            return path_grid, dist
        
        # Explore neighbors
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if is_traversable(nx, ny):
                visited.add((nx, ny))
                queue.append(((nx, ny), dist + 1))
                came_from[(nx, ny)] = (x, y)  # Record the previous cell

    # If end is unreachable
    return path_grid, -1
