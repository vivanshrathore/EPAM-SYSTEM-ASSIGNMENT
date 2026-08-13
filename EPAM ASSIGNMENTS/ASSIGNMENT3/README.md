## Problem 1: Schlorship Distribution (Greedy)

### Description
Given a set of budget requirements for $N$ students and a total available budget, determine the maximum number of students whose requirements can be fully met.

### Algorithm Overview
This problem uses a **Greedy Approach**:
1. Read the total budget and the individual requirement costs.
2. Sort the requirements in ascending order ($O(N \log N)$).
3. Sequentially allocate budget to the smallest requirement first until the remaining budget is insufficient.

### Complexity
| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N \log N)$ | Dominated by sorting array of length $N$. |
| **Space Complexity** | $O(N)$ | Vector used to store requirements. |

## Problem 2: Maximum Learning Points (Dynamic Programming)

### Problem Description
Given an array of $N$ point values, the goal is to select a subset of elements to maximize the total sum such that **no two selected elements are adjacent** in the array.

### Algorithm Overview
This problem is solved using a 1D **Dynamic Programming (DP)** approach:

- **State Definition:** `dp[i]` stores the maximum points attainable using a valid, non-adjacent subset from indices `0` to `i`.
- **Base Cases:**
  - `dp[0] = points[0]`
  - `dp[1] = max(points[0], points[1])`
- **Transitions:** For index $i \ge 2$:
  $$\text{dp}[i] = \max(\text{dp}[i-1], \text{dp}[i-2] + \text{points}[i])$$

## Complexity
| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | A single linear pass is made through the array of length $N$. |
| **Space Complexity** | $O(N)$ | A DP table (`vector<ll> dp`) of size $N$ is used. |
