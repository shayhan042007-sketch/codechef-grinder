# [Chef and Eid (EID)](https://www.codechef.com/problems/EID)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ coins with various values, we need to select two distinct coins such that the absolute difference between their values is minimized. We are required to output this minimum absolute difference.

## Intuition & Mathematical Observation
To minimize the difference between any two elements in a set, the most efficient strategy is to sort the elements first. 

1. **Sorting**: Once the array is sorted such that $v_1 \le v_2 \le \dots \le v_N$, the minimum difference between any two elements $v_i$ and $v_j$ (where $i < j$) must occur between two **adjacent** elements.
2. **Proof**: For any $i < j$, the difference $v_j - v_i$ can be expressed as the sum of differences of adjacent elements:
   $v_j - v_i = (v_j - v_{j-1}) + (v_{j-1} - v_{j-2}) + \dots + (v_{i+1} - v_i)$.
   Since all individual differences $(v_{k+1} - v_k)$ are non-negative, the total difference $v_j - v_i$ will always be greater than or equal to any single adjacent difference in that range. Therefore, we only need to check $v_{i+1} - v_i$ for all $i$ from $0$ to $N-2$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent linear scan takes $O(N)$. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the coin values in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N coins with values v_1, v_2, ..., v_N.
 * We need to select two distinct coins such that the absolute difference 
 * between their values is minimized.
 * 
 * Approach:
 * 1. If we sort the array of coin values, the minimum difference between any 
 *    two elements must occur between two adjacent elements in the sorted array.
 * 2. Proof: Suppose we have sorted values a_1 <= a_2 <= ... <= a_N.
 *    For any i < j, a_j - a_i = (a_j - a_{j-1}) + (a_{j-1} - a_{j-2}) + ... + (a_{i+1} - a_i).
 *    Since all terms are non-negative, a_j - a_i >= a_{k+1} - a_k for any k in [i, j-1].
 *    Thus, the minimum difference must be found among adjacent pairs.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    
    // Sort the coins to bring values with minimal differences next to each other
    sort(v.begin(), v.end());
    
    // Initialize min_diff with a large value
    long long min_diff = LLONG_MAX;
    
    // Iterate through the sorted array and check adjacent differences
    for (int i = 0; i < N - 1; ++i) {
        long long diff = v[i + 1] - v[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
        // Optimization: if diff is 0, it's the smallest possible absolute difference
        if (min_diff == 0) break;
    }
    
    cout << min_diff << "\n";
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