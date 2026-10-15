# [Ada School (ADASCOOL)](https://www.codechef.com/problems/ADASCOOL)

- **Difficulty Rating**: 1004
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an $N \times M$ grid of students. Each student must move to an adjacent cell (up, down, left, or right) such that every student ends up in a unique cell. Essentially, we need to determine if it is possible to pair every student with an adjacent neighbor, which is equivalent to finding a **perfect matching** in the grid graph.

## Intuition & Mathematical Observation
A grid graph can be viewed as a bipartite graph (like a checkerboard with black and white squares). 
1. In any bipartite graph, a perfect matching can only exist if the number of vertices is even.
2. If both $N$ and $M$ are odd, the total number of cells ($N \times M$) is odd. In a checkerboard coloring of an odd-sized grid, the number of black cells and white cells will differ by 1, making a perfect matching impossible.
3. If at least one of $N$ or $M$ is even, the total number of cells is even. In this case, it is always possible to tile the grid with $1 \times 2$ dominoes (each domino representing a pair of adjacent students), thus satisfying the condition.

**Conclusion**: A perfect matching exists if and only if $(N \times M)$ is even, which is true if at least one of $N$ or $M$ is even.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple parity check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input dimensions.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M grid of students. Each student must move to an adjacent cell.
 * This is equivalent to finding a perfect matching in the grid graph.
 * A grid graph is a bipartite graph. A perfect matching exists if and only if
 * the total number of vertices (N * M) is even.
 * 
 * If N * M is even, it means at least one of N or M must be even.
 * If both N and M are odd, N * M is odd, and a perfect matching is impossible
 * because the number of black and white cells in a checkerboard coloring 
 * will differ by 1.
 * 
 * Therefore, the condition for "YES" is (N * M) % 2 == 0, which simplifies to:
 * (N is even) OR (M is even).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If the total number of cells is even, a perfect matching exists.
        // This happens if at least one dimension is even.
        if ((n * m) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```