# [Make Odd (P2P)](https://www.codechef.com/problems/P2P)

- **Difficulty Rating**: 1203
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two binary strings $A$ and $B$ of length $N$, we must select exactly one character from either $A[i]$ or $B[i]$ for each index $i$ (where $0 \le i < N$). Let the resulting sequence be $S$. We need to determine if it is possible to make the sum of the elements in $S$ an odd number.

## Intuition & Mathematical Observation
To determine if the sum can be odd, we categorize the indices based on the pairs $(A[i], B[i])$:

1.  **(0, 0)**: Choosing either value results in $0$. These indices contribute nothing to the total sum.
2.  **(1, 1)**: Choosing either value results in $1$. These indices contribute exactly $1$ to the total sum regardless of the choice. Let `ones` be the count of such indices.
3.  **(0, 1) or (1, 0)**: We have a choice. We can pick $0$ or $1$. This means we can toggle the parity of the total sum by changing our choice at any of these indices. Let `diff` be the count of such indices.

**Logic:**
- If `diff > 0`: We have at least one index where we can choose between $0$ and $1$. If our current sum is even, we can flip the choice at one of these indices to make it odd, and vice versa. Therefore, if `diff > 0`, it is **always possible** to make the sum odd.
- If `diff == 0`: We have no flexibility. The total sum is fixed and equal to the number of `(1, 1)` pairs. We simply check if `ones` is odd. If it is, the answer is **YES**; otherwise, it is **NO**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the strings. We iterate through the strings exactly once.
- **Space Complexity**: $O(N)$ to store the input strings (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each index i, we choose either A[i] or B[i].
 * Score = sum of chosen values. We want Score to be odd.
 * 
 * - (1, 1) pairs contribute 1 to the sum.
 * - (0, 1) or (1, 0) pairs allow us to toggle the parity of the sum.
 * - (0, 0) pairs contribute 0.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int ones = 0;
    int diff = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] == '1' && B[i] == '1') {
            ones++;
        } else if (A[i] != B[i]) {
            diff++;
        }
    }

    // If we have any index where we can choose between 0 and 1,
    // we can always adjust the total sum to be odd.
    if (diff > 0) {
        cout << "YES" << "\n";
    } else {
        // If no flexibility, check if the fixed sum of (1,1) pairs is odd.
        if (ones % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
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