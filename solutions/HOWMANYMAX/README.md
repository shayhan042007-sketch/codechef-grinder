# [How Many Maximums (HOWMANYMAX)](https://www.codechef.com/problems/HOWMANYMAX)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N-1$ representing the relationship between adjacent elements of an array $A$ of length $N$:
- $S[i] = '0'$ implies $A[i] < A[i+1]$
- $S[i] = '1'$ implies $A[i] > A[i+1]$

We need to determine the number of local maximums in the array. An element $A[i]$ is a local maximum if it is greater than its immediate neighbors.

## Intuition & Mathematical Observation
To identify a local maximum at index $i$ (1-indexed), we analyze the constraints provided by the string $S$:

1.  **Boundary Case (First Element $A[1]$):** $A[1]$ is a local maximum if it is greater than $A[2]$. This corresponds to $S[0] == '1'$.
2.  **Boundary Case (Last Element $A[N]$):** $A[N]$ is a local maximum if it is greater than $A[N-1]$. This corresponds to $S[N-2] == '0'$.
3.  **Intermediate Elements ($A[i]$ where $1 < i < N$):** $A[i]$ is a local maximum if it is greater than both its predecessor ($A[i-1]$) and its successor ($A[i+1]$).
    - $A[i-1] < A[i]$ corresponds to $S[i-2] == '0'$.
    - $A[i] > A[i+1]$ corresponds to $S[i-1] == '1'$.
    - Thus, we look for the pattern `"01"` in the string $S$.

By checking these three conditions independently, we can count the total number of local maximums.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the array. We iterate through the string $S$ of length $N-1$ exactly once.
- **Space Complexity**: $O(N)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N-1 where:
 * S[i] = '0' means A[i] < A[i+1]
 * S[i] = '1' means A[i] > A[i+1]
 * 
 * An element A[i] can be the maximum if it is a "local peak".
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 1) {
        cout << 1 << "\n";
        return;
    }

    int count = 0;

    // Check A[1]: Needs A[1] > A[2] -> S[0] == '1'
    if (S[0] == '1') {
        count++;
    }

    // Check A[N]: Needs A[N-1] < A[N] -> S[N-2] == '0'
    if (S[N - 2] == '0') {
        count++;
    }

    // Check A[i] for 1 < i < N: Needs A[i-1] < A[i] and A[i] > A[i+1]
    // This corresponds to the pattern "01" in the string S.
    for (int i = 0; i < N - 2; ++i) {
        if (S[i] == '0' && S[i + 1] == '1') {
            count++;
        }
    }

    cout << count << "\n";
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