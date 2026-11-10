# [Marble Collector (MARBCOLL)](https://www.codechef.com/problems/MARBCOLL)

- **Difficulty Rating**: 860
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ marbles, each belonging to a specific type ranging from $1$ to $M$. Our goal is to determine how many distinct marble types (from the set $\{1, 2, \dots, M\}$) are **not** present in the collection provided.

## Intuition & Mathematical Observation
The problem asks us to identify the "missing" elements from a range $[1, M]$. 
1. Since the range of $M$ is small, we can use a frequency array or a boolean array of size $M+1$ to keep track of which types have been encountered.
2. We initialize all positions in our tracking array to `false`.
3. As we iterate through the input array of $N$ marbles, we mark the index corresponding to the marble's type as `true`.
4. After processing all $N$ marbles, we simply iterate from $1$ to $M$ and count how many indices remain `false`. This count represents the number of missing marble types.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N + M))$, where $T$ is the number of test cases, $N$ is the number of marbles, and $M$ is the range of types. We iterate through the input once ($N$) and then through the tracking array once ($M$).
- **Space Complexity**: $O(M)$, as we use a boolean vector of size $M+1$ to store the presence of each marble type.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N marbles with types A_1, A_2, ..., A_N.
 * There are M total possible types (1 to M).
 * We need to find how many types from 1 to M are NOT present in the input array.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    // Use a boolean array to track which types have been collected
    vector<bool> collected(M + 1, false);
    for (int i = 0; i < N; ++i) {
        int type;
        cin >> type;
        if (type >= 1 && type <= M) {
            collected[type] = true;
        }
    }
    
    // Count how many types were never marked as collected
    int missing_count = 0;
    for (int i = 1; i <= M; ++i) {
        if (!collected[i]) {
            missing_count++;
        }
    }
    
    cout << missing_count << "\n";
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