# [Sale (FINALSALE)](https://www.codechef.com/problems/FINALSALE)

- **Difficulty Rating**: 1180
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has projected sales for $N$ days, represented by an array $A$. If Chef decides to close the shop on day $k$ (where $1 \le k \le N$), the total sales are calculated as the sum of all sales from day $1$ to $k-1$, plus twice the sales of day $k$. The goal is to choose the optimal day $k$ to close the shop such that the total sales are maximized.

## Intuition & Mathematical Observation
Let $S_k$ be the prefix sum of the sales up to day $k$, i.e., $S_k = \sum_{i=1}^{k} A_i$.
The problem states that if we close on day $k$, the total sales $T_k$ are:
$$T_k = \left( \sum_{i=1}^{k-1} A_i \right) + 2 \cdot A_k$$

We can rewrite this expression by splitting the $2 \cdot A_k$ term:
$$T_k = \left( \sum_{i=1}^{k-1} A_i \right) + A_k + A_k$$
$$T_k = S_k + A_k$$

To find the maximum total sales, we iterate through every possible day $k$ from $1$ to $N$, maintain a running prefix sum, and calculate $S_k + A_k$ at each step. We keep track of the maximum value encountered. Since $A_i$ can be up to $10^9$ and $N$ up to $3 \cdot 10^5$, the total sum can exceed the capacity of a 32-bit integer, so we must use `long long` in C++.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single pass through the array to calculate prefix sums and identify the maximum.
- **Space Complexity**: $O(N)$ to store the input array. (Note: This could be optimized to $O(1)$ by calculating the sum on the fly, but $O(N)$ is well within the memory limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N days with projected sales A_1, A_2, ..., A_N.
 * If Chef closes the shop on day k (1 <= k <= N), the total sales will be:
 * Total = (A_1 + A_2 + ... + A_{k-1}) + (2 * A_k)
 * Total = (A_1 + A_2 + ... + A_k) + A_k
 * 
 * To maximize this, we need to calculate the prefix sum of the array and for each day k,
 * compute (PrefixSum[k] + A_k). We then take the maximum over all k.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long current_prefix_sum = 0;
    long long max_sales = -1; // Initialize with a value smaller than any possible result
    
    for (int i = 0; i < N; ++i) {
        current_prefix_sum += A[i];
        // Total sales if we close on day i+1:
        // Sum of all days up to i + A[i] (since A[i] is doubled)
        long long current_total = current_prefix_sum + A[i];
        
        if (i == 0) {
            max_sales = current_total;
        } else {
            max_sales = max(max_sales, current_total);
        }
    }
    
    cout << max_sales << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```