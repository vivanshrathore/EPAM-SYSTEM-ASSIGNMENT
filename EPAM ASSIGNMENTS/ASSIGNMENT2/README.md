# Tree & Graph Problems — Medium Level

## Problem 1: Tree of Trusted Servers

### Problem Statement
A multinational organization maintains its communication infrastructure as a tree rooted at Server 1. Each server stores a security key. A server is **trusted** if the XOR of all security keys on the path from the root to that server is **≥ K**. Count all trusted servers (root included).

### Approach
- DFS from root (Server 1) with running XOR value
- At each node, check if current XOR ≥ K before propagating to children
- Root's own key is excluded from XOR (path starts from root's children)

### Time Complexity
**O(N)** — each node visited exactly once

### Space Complexity
**O(N)** — adjacency list + recursion stack

### Input Format
```
N K
key1 key2 ... keyN
u1 v1
u2 v2
...
```

## Problem 2: Emergency Route Validation

### Problem Statement
A country's highway system is modeled as an undirected graph. A city is **efficiently reachable** if the shortest path from City 1 to that city has at most **D roads**. Count all efficiently reachable cities including the capital.

### Approach
- BFS from City 1 with level-by-level traversal
- Track current depth via `level` variable
- Stop when `level > D`
- Count all nodes processed within D levels

### Time Complexity
**O(N + M)** — standard BFS over N nodes and M edges

### Space Complexity
**O(N + M)** — adjacency list + visited array + queue

### Input Format
```
N M D
u1 v1
u2 v2
...
```
---

## File Structure
```
Medium-Level/
├── problem1_trusted_servers.cpp
├── problem2_emergency_route.cpp
└── README.md
```

## How to Compile & Run
```bash
g++ problem1_trusted_servers.cpp -o p1
./p1 < input1.txt

g++ problem2_emergency_route.cpp -o p2
./p2 < input2.txt
```