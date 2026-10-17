# [Gotta Catch Em All (GCEA)](https://www.codechef.com/problems/GCEA)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ Pekómons, each with a specific difficulty level $A_i$. To catch a Pekómon, you can either:
1. Use **Normal Pekóballs**: The cost is $A_i \times X$.
2. Use a **Master Pekóball**: The cost is a flat rate of $Y$.

The goal is to calculate the minimum total cost required to catch all $N$ Pekómons.

## Intuition & Mathematical Observation
For each individual Pekómon $i$, we have two independent options. To minimize the total cost, we must minimize the cost for each Pekómon individually. 

For any given Pekómon with difficulty $A_i$:
- The cost using normal balls is $A_i \times X$.
- The cost using a master ball is $Y$.

By applying the greedy approach, we choose the cheaper option for each Pekómon:
$$\text{min\_cost}_i = \min(A_i \times X, Y)$$

The total cost is simply the summation of these minimum costs:
$$\text{Total Cost} = \sum_{i=1}^{N} \min(A_i \times X, Y)$$

Since the constraints are small ($N, X, Y, A_i \le 100$), this approach is highly efficient and avoids any overflow issues by using `long long`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of Pekómons exactly once.
- **Space Complexity**: $O(1)$ (excluding the input storage), as we only need a few variables to keep track of the running total.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon with difficulty A_i, we have two choices:
 * 1. Use Normal Pekóballs: Cost = A_i * X
 * 2. Use a Master Pekóball: Cost = Y
 * 
 * To minimize the total cost, for each Pekómon, we should choose the minimum of these two:
 * min_cost_i = min(A_i * X, Y)
 * 
 * The total minimum cost is the sum of min_cost_i for all i from 1 to N.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        
        // Calculate cost for this specific Pekómon
        long long normal_cost = (long long)A_i * X;
        total_cost += min(normal_cost, Y);
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
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