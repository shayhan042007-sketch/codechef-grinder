# [Mirror Swap (MRSWAP)](https://www.codechef.com/problems/MRSWAP)

- **Difficulty Rating**: 667
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array of size $2N$. You are allowed to swap elements at index $i$ and index $2N - i + 1$ (using 1-based indexing) for any $1 \le i \le N$. The goal is to maximize the sum of the elements in the first half of the array (indices $1$ to $N$) after performing any number of these swaps.

## Intuition & Mathematical Observation
The problem allows us to perform independent swaps for each pair $(A[i], A[2N - i + 1])$. Since we want to maximize the sum of the first $N$ elements, we should look at each pair individually:

1. For every index $i$ from $1$ to $N$, we have two values: $A[i]$ and its "mirror" counterpart $A[2N - i + 1]$.
2. Because we can swap these two values, we have the freedom to choose which one ends up in the first half of the array.
3. To maximize the total sum, for every pair, we should greedily choose the larger of the two values to be placed in the first half.
4. Therefore, the maximum sum is simply the sum of $\max(A[i], A[2N - i + 1])$ for all $1 \le i \le N$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the first half of the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array of size $2N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-based indexing).
 * This means for each pair (A[i], A[2N + 1 - i]) where 1 <= i <= N,
 * we can choose to keep them as they are or swap them.
 * To maximize the sum of the first half (A[1] + ... + A[N]),
 * for each pair (A[i], A[2N + 1 - i]), we should place the larger of the two
 * in the first half.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // The array is 0-indexed in C++.
    // A[i] corresponds to the first half (0 to N-1).
    // The mirror of A[i] is A[2N - 1 - i].
    for (int i = 0; i < N; ++i) {
        max_sum += max(A[i], A[2 * N - 1 - i]);
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
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