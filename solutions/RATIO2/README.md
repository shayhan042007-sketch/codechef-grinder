# [Ratio By 2 (RATIO2)](https://www.codechef.com/problems/RATIO2)

- **Difficulty Rating**: 1035
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two positive integers $X$ and $Y$, we want to reach a state where either $X \ge 2Y$ or $Y \ge 2X$. In one operation, we can increment or decrement either $X$ or $Y$ by 1. We need to find the minimum number of operations required to satisfy the condition.

## Intuition & Mathematical Observation
The problem constraints are very small ($2 \le X, Y \le 10$). Because the target state is not far from the initial values, we can treat this as a search problem. 

1. **Check Initial State**: First, verify if the condition $X \ge 2Y$ or $Y \ge 2X$ is already satisfied. If so, the answer is $0$.
2. **Brute Force Search**: Since the input values are small, we can iterate through a reasonable range of possible values for $X'$ and $Y'$ (e.g., from $0$ to $30$). 
3. **Calculate Operations**: For every pair $(i, j)$ in this range that satisfies the condition ($i \ge 2j$ or $j \ge 2i$), we calculate the total operations required: $|X - i| + |Y - j|$.
4. **Minimize**: The answer is the minimum value of these operations across all valid pairs.

This approach is efficient and robust given the small search space.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the range of the search space (in this case, $30 \times 30 = 900$ iterations per test case). This is well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current state and the minimum operations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: RATIO2
 * Goal: Find minimum operations (increment/decrement) to satisfy X >= 2Y or Y >= 2X.
 * Constraints: 2 <= X, Y <= 10.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // If condition already met
    if (X >= 2 * Y || Y >= 2 * X) {
        cout << 0 << "\n";
        return;
    }

    long long min_ops = 1e18;

    // Since X, Y <= 10, the target values won't be very far from the current values.
    // We check a range of values from 0 to 30 to cover all potential optimal targets.
    for (long long i = 0; i <= 30; ++i) {
        for (long long j = 0; j <= 30; ++j) {
            if (i == 0 && j == 0) continue; // Problem constraints imply positive integers
            
            if (i >= 2 * j || j >= 2 * i) {
                long long ops = abs(X - i) + abs(Y - j);
                if (ops < min_ops) {
                    min_ops = ops;
                }
            }
        }
    }
    cout << min_ops << "\n";
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