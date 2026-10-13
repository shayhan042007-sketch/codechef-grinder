# [Reach Weight (REACHWT)](https://www.codechef.com/problems/REACHWT)

- **Difficulty Rating**: 530
- **Solved in**: 1 attempt(s)

## Problem Summary
We are tasked with reaching a target weight $N$ using two types of weights:
1. A 1kg weight that costs 20 units.
2. A 2kg weight that costs 30 units.

The goal is to find the minimum cost to achieve exactly $N$ kg.

## Intuition & Mathematical Observation
Let $x$ be the number of 1kg weights and $y$ be the number of 2kg weights. We have the constraint:
$$x + 2y = N$$
We want to minimize the total cost $C$:
$$C = 20x + 30y$$

Substituting $x = N - 2y$ into the cost equation:
$$C = 20(N - 2y) + 30y$$
$$C = 20N - 40y + 30y$$
$$C = 20N - 10y$$

To minimize $C$, we must **maximize $y$**. Since $x \ge 0$, we know $N - 2y \ge 0$, which implies $y \le \frac{N}{2}$. Thus, the maximum integer value for $y$ is $\lfloor \frac{N}{2} \rfloor$.

- **Case 1: $N$ is even.**
  $y = \frac{N}{2}$.
  $C = 20N - 10(\frac{N}{2}) = 20N - 5N = 15N$.
- **Case 2: $N$ is odd.**
  $y = \frac{N-1}{2}$.
  $C = 20N - 10(\frac{N-1}{2}) = 20N - 5(N-1) = 15N + 5$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a simple mathematical formula. Total time complexity is $O(T)$ where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to reach exactly N kg using 1kg weights (cost 20) and 2kg weights (cost 30).
 * Let x be the number of 1kg weights and y be the number of 2kg weights.
 * We want to minimize Cost = 20x + 30y subject to x + 2y = N, where x, y >= 0.
 * 
 * From x + 2y = N, we get x = N - 2y.
 * Since x >= 0, we must have N - 2y >= 0, so 2y <= N, or y <= N/2.
 * Substituting x into the cost function:
 * Cost = 20(N - 2y) + 30y
 * Cost = 20N - 40y + 30y
 * Cost = 20N - 10y
 * 
 * To minimize the cost, we need to maximize y.
 * Since y must be an integer and y <= N/2, the maximum value for y is floor(N/2).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Using the derived formula:
        // If N is even, cost is 15 * N
        // If N is odd, cost is 15 * N + 5
        long long cost;
        if (n % 2 == 0) {
            cost = 15 * n;
        } else {
            cost = 15 * n + 5;
        }
        
        cout << cost << "\n";
    }
    
    return 0;
}
```