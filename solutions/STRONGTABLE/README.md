# [Table Strength (STRONGTABLE)](https://www.codechef.com/problems/STRONGTABLE)

- **Difficulty Rating**: 1211
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ table legs, each with a specific strength $W_i$. You need to choose a subset of these legs to support a table. If you choose $k$ legs with strengths $S_1, S_2, \dots, S_k$, the table can bear a maximum weight $W$ such that $W \le k \times \min(S_1, S_2, \dots, S_k)$. Your goal is to select a subset of legs that maximizes this weight $W$.

## Intuition & Mathematical Observation
To maximize the weight $W = k \times W_{min}$, we need to consider the relationship between the number of legs chosen ($k$) and the minimum strength in that subset ($W_{min}$):

1. **Sorting**: If we sort the leg strengths in non-decreasing order ($W_0 \le W_1 \le \dots \le W_{N-1}$), it becomes easier to determine the minimum strength of a subset.
2. **Subset Selection**: If we decide that a specific leg $W_i$ will be the *minimum* strength in our subset, we should include all legs that have a strength greater than or equal to $W_i$ to maximize the count $k$.
3. **Calculation**: In the sorted array, if we pick $W_i$ as the minimum, all legs from index $i$ to $N-1$ are $\ge W_i$. The number of such legs is $(N - i)$.
4. **Optimization**: The maximum weight for a subset where $W_i$ is the minimum is simply $W_i \times (N - i)$. By iterating through all possible indices $i$ from $0$ to $N-1$, we can calculate this value for every possible "minimum" and keep track of the global maximum.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the strengths of the $N$ legs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Suppose we choose a subset of k legs with strengths W_1, W_2, ..., W_k.
 * Let the minimum strength in this subset be W_min.
 * The weight W that the table can bear must satisfy:
 * W / k <= W_min  =>  W <= k * W_min.
 * To maximize W for a fixed subset, we should set W = k * W_min.
 * 
 * To maximize this over all possible subsets:
 * 1. Sort the given leg strengths in non-decreasing order: W_1 <= W_2 <= ... <= W_N.
 * 2. If we decide that the minimum strength in our subset is W_i, then to maximize
 *    the total weight, we should include all legs with strength >= W_i.
 * 3. If we pick all legs from index i to N-1 (0-indexed), the number of legs is (N - i).
 * 4. The minimum strength in this subset is W_i.
 * 5. The maximum weight for this specific subset is (N - i) * W_i.
 * 6. We iterate through all possible i from 0 to N-1 and find the maximum value.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the strengths to easily pick subsets where W_i is the minimum
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    for (int i = 0; i < n; ++i) {
        // Number of legs with strength >= w[i] is (n - i)
        // The minimum strength is w[i]
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
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