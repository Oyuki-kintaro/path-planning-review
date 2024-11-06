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
make
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

# Depth-First Search (DFS) Overview

Depth-First Search (DFS) is a traversal algorithm that explores a structure by going as deep as possible along each path before backtracking. Here's an overview of how it works, its benefits, limitations, and when to use or avoid it.

## How DFS Works

1. **Start at the root node** 
2. **Mark the current node as visited.**
3. **Recursively visit an unvisited adjacent node.**
4. **If no unvisited adjacent nodes are available, backtrack.**
5. **Repeat steps 2-4 until all reachable nodes are visited.**

## Benefits

- **Memory Efficiency:** DFS requires less memory compared to Breadth-First Search (BFS), as it only needs to store a stack of nodes on the current path.
- **Solution Finding:** It can be faster at finding a solution if the solution is deep in the graph.
- **Time Efficiency:** For graphs with many nodes or edges, DFS may be faster than BFS.
- **Cycle Detection:** Useful for detecting cycles in graphs.
- **Topological Sorting:** Effective for topological ordering of nodes in a directed acyclic graph.

## Limitations

- **Not Optimal for Shortest Paths:** DFS doesn't guarantee finding the shortest path in unweighted graphs.
- **Incompleteness:** In infinite graphs, DFS may not find a solution that exists.
- **Memory Usage in Worst Case:** In the worst case (e.g., a completely connected graph), DFS can consume as much memory as BFS.
- **Potential for Getting Stuck:** Without proper constraints, DFS might go down very deep paths in large or infinite graphs.

## When to Use DFS

- **Maze Solving:** Excellent for solving mazes or puzzles with a single solution.
- **Path Finding:** When you need to find any path (not necessarily the shortest) between two nodes.
- **Tree/Graph Traversal:** For exploring all nodes in a graph, especially when the graph is deep rather than wide.
- **Cycle Detection:** In scenarios where you need to detect cycles in a graph.
- **Topological Sorting:** For ordering tasks with dependencies.

## When Not to Use DFS

- **Shortest Path Problems:** When finding the shortest path is crucial, BFS or Dijkstra's algorithm is preferable.
- **Level-wise Exploration:** If you need to explore nodes level by level, BFS is more suitable.
- **Very Large or Infinite Graphs:** Without proper depth limiting, DFS can get stuck in deep paths.
- **Memory-Constrained Environments:** In cases where the recursion stack might overflow due to deep graphs.
- **Weighted Graphs:** For finding optimal paths in weighted graphs, algorithms like Dijkstra's or A* are more appropriate.
