# [Expensive Buying (BUYING7)](https://www.codechef.com/problems/BUYING7)

- **Difficulty Rating**: 635
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ items with their respective prices $C_i$, we need to select exactly $K$ items such that the total cost is maximized. In other words, we need to find the sum of the $K$ most expensive items available in the list.

## Intuition & Mathematical Observation
To maximize the sum of $K$ elements chosen from a set, the optimal strategy is a **Greedy Approach**:
1. Sort the list of prices in descending order (from largest to smallest).
2. Select the first $K$ elements from the sorted list.
3. Sum these $K$ elements to obtain the maximum possible total cost.

Since the constraints are small ($N \le 100$), sorting the array takes $O(N \log N)$ time, which is highly efficient and well within the time limits for the given constraints.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of items. The sorting operation dominates the per-test-case complexity.
- **Space Complexity**: $O(N)$ to store the prices of the $N$ items.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N items with prices C_i. We need to find the sum of the K most expensive items.
 * To do this, we can sort the array of prices in descending order and sum the first K elements.
 * 
 * Constraints:
 * T <= 100, N <= 100, C_i <= 100.
 * The maximum possible sum is 100 * 100 = 10,000, which fits easily into a standard integer.
 * However, using long long is good practice for competitive programming.
 * Time complexity per test case: O(N log N) due to sorting.
 * Total time complexity: O(T * N log N), which is well within the 1s limit.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    // Sort in descending order to easily pick the K most expensive items
    sort(C.begin(), C.end(), greater<int>());
    
    long long total_cost = 0;
    for (int i = 0; i < K; ++i) {
        total_cost += C[i];
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
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