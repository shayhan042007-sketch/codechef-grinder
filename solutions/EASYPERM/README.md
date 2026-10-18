# [Easy Permutation (EASYPERM)](https://www.codechef.com/problems/EASYPERM)

- **Difficulty Rating**: 1057
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find a permutation $A$ of the numbers $\{1, 2, \dots, N\}$ such that the Least Common Multiple (LCM) of the sequence $S = \{1+A_1, 2+A_2, \dots, N+A_N\}$ is minimized.

## Intuition & Mathematical Observation
Let $B_i = i + A_i$. We want to minimize $\text{LCM}(B_1, B_2, \dots, B_N)$. 

Consider the sum of all elements in the set $S$:
$$\sum_{i=1}^{N} (i + A_i) = \sum_{i=1}^{N} i + \sum_{i=1}^{N} A_i = 2 \times \sum_{i=1}^{N} i = N(N+1)$$

If we can make every $B_i$ equal to the same value, the LCM will simply be that value. By setting $A_i = N - i + 1$, we get:
$$B_i = i + (N - i + 1) = N + 1$$
For all $i \in \{1, \dots, N\}$, $B_i = N + 1$. Therefore, the LCM of the set is $\text{LCM}(N+1, N+1, \dots, N+1) = N+1$.

Since the maximum value in the set $\{i + A_i\}$ must be at least $N+1$ (because the average value is $N+1$), and the LCM of a set is at least as large as its maximum element, $N+1$ is the theoretical minimum possible LCM. Thus, the permutation $A = [N, N-1, \dots, 1]$ is an optimal solution.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from $N$ down to $1$ to print the permutation.
- **Space Complexity**: $O(1)$, as we do not store the permutation in an array and print the values directly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to minimize LCM(1+A_1, 2+A_2, ..., N+A_N) where A is a permutation of 1 to N.
 * By setting A_i = N - i + 1, we ensure that i + A_i = N + 1 for all i.
 * This results in an LCM of N + 1, which is the minimum possible value.
 */

void solve() {
    int N;
    cin >> N;
    
    // Output the permutation [N, N-1, ..., 1]
    for (int i = N; i >= 1; --i) {
        cout << i << (i == 1 ? "" : " ");
    }
    cout << "\n";
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