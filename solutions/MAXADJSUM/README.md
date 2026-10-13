# [Maximise Adjacent Sum (MAXADJSUM)](https://www.codechef.com/problems/MAXADJSUM)

- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we need to rearrange its elements to maximize the sum of adjacent elements:
$$f(A) = \sum_{i=1}^{N-1} (A_i + A_{i+1})$$

## Intuition & Mathematical Observation
Expanding the summation formula:
$$f(A) = (A_1 + A_2) + (A_2 + A_3) + (A_3 + A_4) + \dots + (A_{N-1} + A_N)$$
$$f(A) = A_1 + 2A_2 + 2A_3 + \dots + 2A_{N-1} + A_N$$

From this expansion, we observe that:
1. The elements at the ends of the array ($A_1$ and $A_N$) are added exactly **once**.
2. All other $N-2$ elements are added **twice**.

To maximize the total sum, we want the largest elements to be multiplied by 2. Conversely, we should place the two smallest elements at the ends of the array so that they contribute the least to the total sum.

If we sort the array such that $S_1 \le S_2 \le \dots \le S_N$, the optimal sum is:
$$f(A) = S_1 + S_2 + 2 \sum_{i=3}^{N} S_i$$

This can be simplified using the total sum of the array ($T = \sum_{i=1}^{N} S_i$):
$$f(A) = 2 \left( \sum_{i=1}^{N} S_i \right) - (S_1 + S_2)$$

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The summation and calculation steps are $O(N)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * To maximize this, we place the two smallest elements at the ends.
 * Result = 2 * (Sum of all elements) - (Smallest + Second Smallest)
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    // Sort to easily identify the two smallest elements
    sort(A.begin(), A.end());
    
    // The two smallest elements are A[0] and A[1].
    // Formula: 2 * total_sum - (A[0] + A[1])
    long long result = 2 * total_sum - (A[0] + A[1]);
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```