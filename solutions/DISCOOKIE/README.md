# [Distribute Cookies (DISCOOKIE)](https://www.codechef.com/problems/DISCOOKIE)

- **Difficulty Rating**: 932
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ kids and $M$ cookies. We need to reach a total number of cookies $K$ such that $K$ is a multiple of $N$ and $K \ge N$. The goal is to find the minimum number of operations (adding or removing cookies) required to transform $M$ into $K$, where each operation changes the count by 1.

## Intuition & Mathematical Observation
To solve this, we consider two scenarios based on the relationship between $M$ and $N$:

1.  **Case $M < N$**:
    Since each kid must receive at least one cookie, the smallest valid multiple of $N$ is $N$ itself. Since we only have $M$ cookies, we must add $N - M$ cookies.

2.  **Case $M \ge N$**:
    We look for the nearest multiple of $N$ to $M$. Let $r = M \pmod N$.
    *   **Option A (Rounding down)**: We remove $r$ cookies to reach the multiple $M - r$.
    *   **Option B (Rounding up)**: We add $N - r$ cookies to reach the next multiple $M + (N - r)$.
    *   We compare these two options and choose the minimum: $\min(r, N - r)$.
    *   If $r = 0$, $M$ is already a multiple of $N$, so the cost is $0$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N kids and M cookies. We want to reach a number of cookies K such that:
 * 1. K is a multiple of N (K % N == 0).
 * 2. K >= N (since each kid must receive at least 1 cookie).
 * 3. We want to minimize |M - K|.
 */

void solve() {
    long long N, M;
    cin >> N >> M;

    if (M < N) {
        // Must reach at least N cookies.
        cout << (N - M) << "\n";
    } else {
        long long r = M % N;
        if (r == 0) {
            // Already divisible
            cout << 0 << "\n";
        } else {
            // Either destroy r cookies or make (N - r) cookies
            cout << min(r, N - r) << "\n";
        }
    }
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