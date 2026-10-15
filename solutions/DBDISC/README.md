# [Double Discount (DBDISC)](https://www.codechef.com/problems/DBDISC)

- **Difficulty Rating**: 994
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given $N$ items, each with a cost $A_i$ and a tastiness $B_i$. You must select exactly two distinct items $(i, j)$ such that their total cost after applying a discount is less than or equal to $K$. The discount is applied only to the more expensive of the two items, calculated as $\min(\text{cost}_{\text{max}} / 2, 100)$. The goal is to maximize the sum of the tastiness values $(B_i + B_j)$ of the two selected items. If no such pair exists, output 0.

## Intuition & Mathematical Observation
Given the constraints $N \le 100$, an $O(N^2)$ approach is perfectly efficient. 

1. **Brute Force**: Since we only need to pick two items, we can iterate through all possible pairs $(i, j)$ where $i < j$.
2. **Discount Logic**: For every pair, identify the item with the higher cost. Apply the discount rule: `discount = min(expensive / 2, 100)`.
3. **Validation**: Calculate the `total_cost = (A[i] + A[j]) - discount`. If `total_cost <= K`, the pair is valid.
4. **Maximization**: Keep track of the maximum `B[i] + B[j]` encountered among all valid pairs.
5. **Edge Case**: If no pairs satisfy the condition, the problem implies we cannot select any items, so we return 0.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, where $N$ is the number of items. With $N=100$, $N^2 = 10,000$, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the cost and tastiness arrays.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to select exactly two items (i, j) where i != j.
 * The more expensive item gets a discount: discount = min(A_max / 2, 100)
 * Final cost = (A[i] + A[j]) - discount
 * We maximize (B[i] + B[j]) such that Final cost <= K.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int max_tastiness = 0;
    bool found = false;

    // Iterate through all unique pairs (i, j)
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int cost_i = A[i];
            int cost_j = A[j];
            
            // Identify the more expensive item
            int expensive = max(cost_i, cost_j);
            int cheaper = min(cost_i, cost_j);
            
            // Calculate discount: 50% of expensive or 100, whichever is smaller
            int discount = min(expensive / 2, 100);
            
            // Total cost calculation
            int total_cost = (expensive + cheaper) - discount;
            
            if (total_cost <= K) {
                found = true;
                int current_tastiness = B[i] + B[j];
                if (current_tastiness > max_tastiness) {
                    max_tastiness = current_tastiness;
                }
            }
        }
    }

    if (!found) {
        cout << 0 << "\n";
    } else {
        cout << max_tastiness << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```