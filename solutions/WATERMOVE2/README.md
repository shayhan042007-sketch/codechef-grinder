# [Water Moving (Max) (WATERMOVE2)](https://www.codechef.com/problems/WATERMOVE2)

- **Difficulty Rating**: 934
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given $N$ cups, each containing a certain amount of water. In one operation, you can choose two cups and merge their contents into one. You are allowed to perform exactly $K$ such operations. The goal is to maximize the amount of water in a single cup after performing these $K$ operations.

## Intuition & Mathematical Observation
To maximize the water in a single cup, we need to strategically choose which cups to merge:

1.  **Case 1: $K \ge N - 1$**
    If the number of allowed operations is greater than or equal to $N-1$, we have enough operations to merge every single cup into one. Therefore, the maximum amount of water in a single cup will simply be the sum of all water in all $N$ cups.

2.  **Case 2: $K < N - 1$**
    If we have fewer than $N-1$ operations, we cannot merge everything. To maximize the result, we should focus on the largest available amounts. By sorting the cups in descending order, we can take the largest cup and merge the next $K$ largest cups into it. This effectively gives us the sum of the $K+1$ largest values present in the initial array.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step required to identify the $K+1$ largest elements. The summation takes $O(K)$, which is bounded by $O(N)$.
- **Space Complexity**: $O(N)$ to store the amounts of water in the $N$ cups.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the water in a single cup after exactly K operations:
 * 1. If K >= N-1, we can merge all water into one cup. The maximum amount is the total sum.
 * 2. If K < N-1, we perform K merges. To maximize the result, we pick the largest cup 
 *    and merge the K largest other cups into it. This results in the sum of the 
 *    (K+1) largest elements.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (K >= N - 1) {
        // We can merge everything into one cup.
        cout << total_sum << "\n";
    } else {
        // We perform K merges. We start with the largest cup and add the K largest other cups.
        sort(A.rbegin(), A.rend());
        long long max_val = 0;
        for (int i = 0; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
    }
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