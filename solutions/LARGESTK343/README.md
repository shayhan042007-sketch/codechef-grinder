# [Largest K (LARGESTK343)](https://www.codechef.com/problems/LARGESTK343)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ zeros and $Y$ ones, we need to arrange them in a sequence such that between any two adjacent zeros, there are at least $K$ ones. We are tasked with finding the maximum possible value of $K$.

## Intuition & Mathematical Observation
To maximize $K$, we must place the $X$ zeros such that they create the minimum number of gaps required to satisfy the condition. 

1. With $X$ zeros, there are exactly $X - 1$ gaps between them that **must** be filled with ones to satisfy the condition "between any two zeros."
2. Let $g_i$ be the number of ones in the $i$-th gap. The problem requires $g_i \ge K$ for all $i \in \{1, 2, \dots, X-1\}$.
3. The total number of ones used in these mandatory gaps is $\sum_{i=1}^{X-1} g_i$.
4. Since we want to satisfy the condition with the available $Y$ ones, the minimum number of ones required is $(X - 1) \times K$.
5. Therefore, the constraint is $(X - 1) \times K \le Y$.
6. Solving for $K$, we get $K \le \frac{Y}{X - 1}$.
7. Since $K$ must be an integer, the largest possible value is $\lfloor \frac{Y}{X - 1} \rfloor$.

*Note: If $X=1$, there are no gaps between zeros, meaning the condition is vacuously true for any $K$. However, based on the problem constraints, we focus on the $X > 1$ case.*

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single division operation. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to arrange them such that between any two zeros, there are at least K ones.
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let g_i be the number of ones in the i-th gap (where i = 1 to X-1).
 * The condition is g_i >= K for all i = 1 to X-1.
 * The total number of ones used in these gaps is sum(g_i) for i=1 to X-1.
 * The total number of ones available is Y.
 * So, sum(g_i) <= Y.
 * Since each g_i >= K, the minimum sum is (X - 1) * K.
 * Therefore, (X - 1) * K <= Y.
 * K <= Y / (X - 1).
 * 
 * The largest integer K is floor(Y / (X - 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // X zeros create (X - 1) gaps that must contain at least K ones.
        // The condition is (X - 1) * K <= Y.
        // Thus, K = Y / (X - 1).
        
        long long K = Y / (X - 1);
        cout << K << "\n";
    }

    return 0;
}
```