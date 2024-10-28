# Path Planning Maps

This repository contains a collection of progressively complex maps designed for path-planning algorithm testing and development. Each map is structured to provide increasing challenges, from simple layouts to complex mazes, allowing for evaluation of various pathfinding techniques.

**Map Key**
    "S" - Starting point of the map.  
    "E" - Endpoint of the map.  
    "*" - Non-traversable space (obstacle or wall).  
    " " - Traversable space (open path).  

## Maps Overview

The maps are saved as `.csv` files and can be read into both Python and C++ environments. Each map file is numbered according to its complexity level.

**Map Descriptions**

    Map 1: Simple
        File: map1.csv
        Description: This map is straightforward, with a direct path between the starting and ending points, interrupted by a few obstacles. It is ideal for initial testing of basic pathfinding algorithms, ensuring they can handle a simple layout with minimal hindrances.

    Map 2: Moderate
        File: map2.csv
        Description: This map introduces more obstacles that require slight detours, offering more of a challenge than Map 1. It is suitable for testing algorithms that need to navigate around a few isolated obstacles.

    Map 3: Intermediate
        File: map3.csv
        Description: The intermediate map has a mix of clustered obstacles and open spaces, requiring more sophisticated pathfinding strategies. This map tests the algorithm's ability to find less direct paths while avoiding multiple obstacles.

    Map 4: Advanced
        File: map4.csv
        Description: This map increases the difficulty by adding denser and more complex obstacle patterns, pushing the path-planning algorithm to find more circuitous routes. It is useful for evaluating the efficiency and robustness of algorithms in semi-maze-like environments.

    Map 5: Complex Maze
        File: map5.csv
        Description: The final map is a complex maze with numerous obstacles and narrow paths, representing a challenging scenario where the algorithm must make more deliberate choices to reach the endpoint. This map is intended for advanced testing of pathfinding methods in constrained, maze-like environments.

## Purpose of Use

These maps are designed for the following purposes:  
**Algorithm Testing:** Evaluate various path-planning algorithms, such as A*, Dijkstra, BFS, and DFS, by observing their effectiveness in different levels of complexity.  
**Performance Analysis:** Measure the efficiency of algorithms by analyzing the computational time and memory usage required to find the optimal path in each map.  
**Heuristic Development:** Fine-tune heuristics and optimization parameters to handle both simple and complex environments, potentially improving the algorithm's performance in real-world applications.  