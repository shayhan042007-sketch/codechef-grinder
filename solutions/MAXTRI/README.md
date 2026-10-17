# [Max Triangle (MAXTRI)](https://www.codechef.com/problems/MAXTRI)

- **Difficulty Rating**: 664
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a set of sticks with lengths $1, 2, 3, \dots, N$, the goal is to choose three distinct sticks that can form a non-degenerate triangle such that their perimeter ($A + B + C$) is maximized. If no such triangle can be formed, output -1.

## Intuition & Mathematical Observation
To form a non-degenerate triangle with sides $A, B, C$ (where $A \le B \le C$), the triangle inequality theorem states that the sum of the two smaller sides must be strictly greater than the largest side:
$$A + B > C$$

To maximize the perimeter $P = A + B + C$, we should aim to pick the largest available values for $A, B,$ and $C$. Let $C = N$, $B = N-1$, and $A = N-2$. 

1. **Check the condition**:
   $$(N-2) + (N-1) > N$$
   $$2N - 3 > N$$
   $$N > 3$$

2. **Case Analysis**:
   - If **$N < 4$**: The largest possible set is $\{1, 2, 3\}$. Since $1 + 2 = 3$, it fails the triangle inequality. Thus, for $N=1, 2, 3$, no triangle can be formed. Output: `-1`.
   - If **$N \ge 4$**: We can always pick $N, N-1,$ and $N-2$. The perimeter is $N + (N-1) + (N-2) = 3N - 3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation is a simple arithmetic operation. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have sticks of lengths 1, 2, ..., N.
 * To maximize the perimeter A + B + C, we pick the largest possible values:
 * C = N, B = N-1, A = N-2.
 * The condition A + B > C becomes (N-2) + (N-1) > N, which simplifies to N > 3.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        if (n < 4) {
            // For N=1, 2, 3, no combination of 3 sticks satisfies the triangle inequality
            cout << -1 << "\n";
        } else {
            // The maximum perimeter is formed by the three largest sticks: N, N-1, N-2
            // Perimeter = N + (N-1) + (N-2) = 3N - 3
            long long result = 3 * n - 3;
            cout << result << "\n";
        }
    }

    return 0;
}
```