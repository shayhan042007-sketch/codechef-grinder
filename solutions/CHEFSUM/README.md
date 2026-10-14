# [Little Chef and Sums (CHEFSUM)](https://www.codechef.com/problems/CHEFSUM)

- **Difficulty Rating**: 1252
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we define two functions:
1. `prefixSum(i)` = $\sum_{j=1}^{i} A[j]$
2. `suffixSum(i)` = $\sum_{j=i}^{N} A[j]$

We need to find the index $i$ (1-based) that minimizes the value of $f(i) = \text{prefixSum}(i) + \text{suffixSum}(i)$. If there are multiple such indices, we must return the smallest one.

## Intuition & Mathematical Observation
Let's expand the expression for $f(i)$:
$$f(i) = \left( \sum_{j=1}^{i} A[j] \right) + \left( \sum_{j=i}^{N} A[j] \right)$$

Notice that the term $A[i]$ is included in both the prefix sum and the suffix sum. We can rewrite the expression as:
$$f(i) = \left( \sum_{j=1}^{N} A[j] \right) + A[i]$$

Since $\sum_{j=1}^{N} A[j]$ is the total sum of the array and remains constant regardless of the choice of $i$, minimizing $f(i)$ is mathematically equivalent to minimizing $A[i]$. 

Therefore, the problem reduces to finding the index of the smallest element in the array. If there are multiple occurrences of the minimum value, the problem requires the smallest index, which is naturally handled by iterating from $1$ to $N$ and only updating the index when a strictly smaller value is found.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to perform a single pass through the array to find the minimum element.
- **Space Complexity**: $O(1)$, as we do not need to store the entire array; we can process the elements on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(i) = prefixSum(i) + suffixSum(i)
 * f(i) = (A[1] + ... + A[i]) + (A[i] + ... + A[N])
 * f(i) = (A[1] + ... + A[N]) + A[i]
 * 
 * Minimizing f(i) is equivalent to minimizing A[i].
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Initialize min_val with a value larger than any possible A[i] (max 10^5)
    int min_val = 200000; 
    int min_idx = -1;
    
    for (int i = 1; i <= N; ++i) {
        int val;
        cin >> val;
        // Update only if we find a strictly smaller value to keep the smallest index
        if (val < min_val) {
            min_val = val;
            min_idx = i;
        }
    }
    
    cout << min_idx << "\n";
}

int main() {
    // Fast I/O for performance
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