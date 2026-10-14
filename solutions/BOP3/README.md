# [Min And Operations (BOP3)](https://www.codechef.com/problems/BOP3)

- **Difficulty Rating**: 946
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a set $S = \{0, 1, 2, \dots, N\}$ where $N$ is even. We perform an operation repeatedly until only one element remains: pick two elements $X$ and $Y$ from the set, add $\max(X, Y)$ to our total score, and replace the pair with $(X \& Y)$ if $(X \& Y)$ is not already in the set. The goal is to determine the final score after the set is reduced to a single element.

## Intuition & Mathematical Observation
By tracing the process for small even values of $N$, we can identify a clear pattern:

*   **$N=2$**: Set $\{0, 1, 2\}$. Pick $(1, 2) \to$ score $2$, set $\{0\}$. Final: **2**.
*   **$N=4$**: Set $\{0, 1, 2, 3, 4\}$. Pick $(3, 4) \to$ score $4$, set $\{0, 1, 2\}$. Pick $(1, 2) \to$ score $4+2=6$, set $\{0\}$. Final: **6**.
*   **$N=6$**: Set $\{0, 1, 2, 3, 4, 5, 6\}$. Pick $(5, 6) \to$ score $6$, set $\{0, 1, 2, 3, 4\}$. Pick $(3, 4) \to$ score $6+4=10$, set $\{0, 1, 2\}$. Pick $(1, 2) \to$ score $10+2=12$, set $\{0\}$. Final: **12**.

The sequence of results is $2, 6, 12, 20, \dots$ for $N = 2, 4, 6, 8, \dots$.
Let $k = N/2$. The sequence corresponds to the formula:
$$\text{Score} = k \times (k + 1)$$

**Logic**: By always picking the largest available pair $(2k-1, 2k)$, we add $2k$ to the score. The bitwise AND $(2k-1 \& 2k)$ results in $2k-2$, which is already present in the set. This effectively removes the two largest elements and reduces the problem to $N-2$. Summing these values gives:
$$\sum_{i=1}^{N/2} 2i = 2 \times \frac{(N/2)(N/2 + 1)}{2} = \frac{N}{2} \left( \frac{N}{2} + 1 \right)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a direct mathematical formula.
- **Space Complexity**: $O(1)$, as we only store a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem reduces to a summation of the largest elements in pairs.
 * For N, the result is (N/2) * (N/2 + 1).
 */

void solve() {
    long long N;
    cin >> N;
    // k represents N/2
    long long k = N / 2;
    // The pattern follows k * (k + 1)
    long long ans = k * (k + 1);
    cout << ans << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```