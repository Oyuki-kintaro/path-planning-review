# Intro

This repository contains implementations of various path planning algorithms in both Python and C++. The project is organized into two main directories: python and C++. Each directory includes scripts to demonstrate and run path planning algorithms on simulated maps. The repository’s goal is to provide a comparative study of algorithms in different languages and their efficiency in pathfinding tasks.
Directory Structure

    python/ - Contains Python implementations of path planning algorithms.
    C++/ - Contains C++ implementations of path planning algorithms.

# Running the Main Scripts

## Python
```
cd python
python3 main.py
```

## C++
```
cd C++
g++ main.cpp -o main
./main
```

Each main script will execute the available path planning algorithms on sample maps. Additional instructions for each algorithm can be found in the respective directories.

# Breadth-First Search (BFS) Overview

Breadth-First Search (BFS) is a method used to explore graphs or trees, moving through nodes level by level. Here’s a simplified look at how BFS works, its benefits, limitations, and when to use it.

## How BFS Works
1. **Start at the Root**: BFS begins at a starting point or "root" node.
2. **Explore Level by Level**: It explores all neighbors of the current node before moving deeper, level by level.
3. **Uses a Queue**: BFS relies on a queue to manage nodes in the order they should be visited.

This structure makes BFS suitable for finding the shortest path in simple, unweighted graphs.

## Key Benefits of BFS
- **Shortest Path**: In an unweighted graph, BFS finds the shortest route from the start node to any other node.
- **Guaranteed Solution**: If a path exists, BFS will find it.
- **Level-by-Level Exploration**: Useful for analyzing structures layer by layer (e.g., social network connections).
  
## Limitations of BFS
- **High Memory Use**: BFS requires storing many nodes at once, which can become inefficient in large graphs.
- **Not Ideal for Deep Graphs**: In very deep structures, other methods like depth-first search may perform better.
- **Time-Consuming in Large Graphs**: BFS can be slow when there are many nodes to examine.

## When to Use BFS
- **Unweighted Shortest Path Problems**: Ideal for finding the shortest path when edges have no weight.
- **Layer-by-Layer Exploration**: Suitable for tasks requiring level-specific data, such as analyzing a tree structure.
- **Connectivity Analysis**: Use BFS to determine if different parts of a graph are connected.

## When Not to Use BFS
- **Memory Constraints**: Avoid BFS for very large graphs if memory is limited.
- **Weighted Graphs**: For graphs with weighted edges, use Dijkstra’s algorithm.
- **Deep Search Needs**: If the solution is likely to be far from the start, depth-first search may be faster.
- **Negative Edge Weights**: BFS does not handle negative weights well; use Bellman-Ford instead.

In summary, BFS is effective for finding the shortest path and exploring graphs level by level but can be limited by memory needs and deep structures. Consider these factors when choosing BFS for your task.