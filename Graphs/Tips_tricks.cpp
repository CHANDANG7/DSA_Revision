1. Graph Traversals
Technique	When to Use	Key Tips & Tricks
BFS (Breadth-First Search)	- Shortest path in unweighted graph
- Level-by-level exploration
- Checking bipartiteness	- Use queue
- Distance array is handy for shortest path
- For bipartite: alternate colors for each level
DFS (Depth-First Search)	- Detect cycles
- Connected components
- Topological sort (with post-order)
- Path existence check	- Use recursion or stack
- Good for problems with backtracking in graphs
Topological Sort (DFS/Kahn)	- Ordering tasks with dependencies
- Course scheduling	- Works only on DAG
- Kahn’s algorithm uses BFS with in-degree array
0-1 BFS	- Shortest path where edge weights are only 0 or 1	- Use deque: push front for 0-weight edges, back for 1-weight edges
Bidirectional BFS	- Shortest path in huge graphs	- Search from source and target simultaneously

2. Shortest Path Algorithms
Algorithm	When to Use	Tips
Dijkstra	- Non-negative weighted graphs	- Use priority queue (min-heap)
- O((V+E)logV)
Bellman-Ford	- Graph with negative edges (but no negative cycles)	- Runs in O(VE)
- Also detects negative cycles
Floyd–Warshall	- All-pairs shortest path for small graphs (n ≤ ~400)	- O(n³)
- Good for dense graphs
A*	- Shortest path with heuristics (game maps)	- Needs admissible heuristic (never overestimate)

3. Minimum Spanning Tree (MST)
Algorithm	When to Use	Tips
Kruskal	- Sparse graphs
- Edge list is available	- Sort edges
- Uses Disjoint Set (Union-Find)
Prim	- Dense graphs
- Adjacency matrix given	- Use priority queue for adjacency list
Borůvka	- Parallel MST construction	- Useful for special parallelized problems

4. Cycle Detection
Graph Type	Algorithm
Undirected	DFS or Disjoint Set
Directed	DFS (with recursion stack)

5. Disjoint Set (Union-Find)
When to Use:

Detect cycles (Kruskal’s MST)

Connected components in dynamic graphs

Grouping problems (e.g., “friend circles”)

Checking if adding an edge connects two already connected nodes

Percolation, network connectivity

Tips:

Always use path compression + union by rank/size

For “offline” queries (connectivity after multiple unions) → Union-Find is better than BFS/DFS

6. Special Problems & Matching
Problem Type	Algorithm
Max flow / Min cut	Ford–Fulkerson / Edmonds–Karp / Dinic
Bipartite matching	Hopcroft–Karp
Strongly Connected Components	Kosaraju / Tarjan

Quick Decision Flow
Is it unweighted? → BFS

Weighted (positive)? → Dijkstra

Negative edges? → Bellman-Ford

All-pairs shortest path? → Floyd–Warshall

Need MST? → Kruskal (sparse) / Prim (dense)

Dynamic connectivity / grouping? → Disjoint Set

Cycle detection? → DFS / Disjoint Set

