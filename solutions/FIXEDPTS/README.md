# [Fixed Points (FIXEDPTS)](https://www.codechef.com/problems/FIXEDPTS)

- **Difficulty Rating**: 884
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$ (the size of a permutation) and an integer $K$, determine if it is possible to construct a permutation of length $N$ such that there are exactly $K$ fixed points. A fixed point is defined as an index $i$ such that $P[i] = i$ (using 1-based indexing).

## Intuition & Mathematical Observation
To have exactly $K$ fixed points, we must choose $K$ indices to satisfy $P[i] = i$. This leaves us with $M = N - K$ elements that must be placed in the remaining $N - K$ positions such that **none** of them are fixed points. This is the definition of a **derangement**.

*   **Case $M = 0$**: We have 0 elements left to arrange. This is valid (0 derangements of 0 elements is 1).
*   **Case $M = 1$**: We have 1 element left. Since there is only one position available for it, it **must** be a fixed point. This would result in $K+1$ fixed points instead of $K$. Therefore, this case is **impossible**.
*   **Case $M \ge 2$**: It is mathematically proven that a derangement exists for any set of size $M \ge 2$. Thus, we can always arrange the remaining elements to avoid fixed points.

**Conclusion**: A permutation with exactly $K$ fixed points is possible if and only if $N - K \neq 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple subtraction and comparison. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * A fixed point is P[i] = i.
 * If we choose K indices to be fixed points, we are left with (N - K) elements 
 * that must be deranged (i.e., none of them can be a fixed point).
 * 
 * A derangement of size M exists if and only if M != 1.
 * - If M = 0, there is 1 derangement (the empty set).
 * - If M = 1, there are 0 derangements (a single element must be a fixed point).
 * - If M >= 2, there is always at least one derangement.
 * 
 * Therefore, we can have exactly K fixed points if and only if (N - K) != 1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // The number of elements that are NOT fixed points is (n - k).
        // If n - k == 1, we have one element left that must be placed in its own position,
        // which would create an additional fixed point, making the total count K + 1.
        // Thus, n - k == 1 is the only impossible case.
        if (n - k == 1) {
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
        }
    }

    return 0;
}
```