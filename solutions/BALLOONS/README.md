# [Coloured Balloons (BALLOONS)](https://www.codechef.com/problems/BALLOONS)

- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ different types of balloons, where the $i$-th type of balloon costs $i$ rupees. You are provided with the quantity $A_i$ for each balloon type. The goal is to calculate the total cost required to purchase all the balloons, which is the sum of the products of the quantity and the cost for each type: $\sum_{i=1}^{N} (A_i \times i)$.

## Intuition & Mathematical Observation
The problem asks for a simple weighted sum. Since the cost of the $i$-th balloon is exactly its index $i$ (1-indexed), we can iterate through the input array and maintain a running total.

- For each input $A_i$ at index $i$ (where $i$ ranges from $1$ to $N$), the contribution to the total cost is $A_i \times i$.
- Given the constraints ($N \le 100$ and $A_i \le 100$), the maximum possible cost is approximately $505,000$. While this fits within a standard 32-bit `int`, using `long long` is a safe practice in competitive programming to avoid potential overflow issues in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ balloon types exactly once. With $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only store the running total and the current input value, requiring constant extra space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N colours of balloons.
 * The i-th colour (1-indexed) costs i rupees.
 * We are given A_i, the number of balloons of the i-th colour.
 * Total cost = sum_{i=1 to N} (A_i * i).
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        long long total_cost = 0;
        for (int i = 1; i <= n; ++i) {
            long long a_i;
            cin >> a_i;
            // The cost of the i-th colour is i.
            // Total cost is sum of (number of balloons * cost per balloon)
            total_cost += (a_i * i);
        }
        
        cout << total_cost << "\n";
    }
    
    return 0;
}
```