# [Golf (LKDNGOLF)](https://www.codechef.com/problems/LKDNGOLF)

- **Difficulty Rating**: 1256
- **Solved in**: 1 attempt(s)

## Problem Summary
The golf course consists of tiles numbered from $0$ to $N+1$, where $0$ and $N+1$ are the holes. A ball is hit with a jump length of $k$. 
- During the **forward journey**, the ball lands on tiles $0, k, 2k, \dots$ until it reaches or passes $N+1$.
- During the **backward journey**, the ball starts from $N+1$ and lands on tiles $(N+1), (N+1)-k, (N+1)-2k, \dots$ until it reaches or passes $0$.

Given the target tile $x$, determine if the ball lands on $x$ during either the forward or backward journey.

## Intuition & Mathematical Observation
The problem can be broken down into two modular arithmetic conditions:

1.  **Forward Journey**: The ball lands on tile $x$ if $x$ is a multiple of $k$.
    *   Condition: `x % k == 0`

2.  **Backward Journey**: The ball starts at $N+1$ and moves backwards by $k$. This means the ball lands on tile $x$ if the distance between the start ($N+1$) and $x$ is a multiple of $k$.
    *   Condition: `(N + 1 - x) % k == 0`

If either of these conditions is true, the ball lands on the target tile $x$. Since $N$ can be up to $10^9$, we use `long long` to prevent potential overflow during calculations, although standard `int` would technically suffice for these specific operations.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. With $T$ test cases, the total time complexity is $O(T)$, which easily passes within the time limit for $T \le 10^5$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the check.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The hallway has tiles 0 to N+1.
 * Forward journey: The ball lands on tiles {0, k, 2k, ..., m*k} such that m*k <= N+1.
 * This means the ball lands on tile x if x % k == 0.
 * 
 * Backward journey: The ball starts at N+1 and lands on tiles {(N+1), (N+1)-k, (N+1)-2k, ...}.
 * This means the ball lands on tile x if (N+1 - x) is a multiple of k.
 * 
 * Combining these:
 * The ball enters the hole if:
 * 1. x % k == 0
 * OR
 * 2. (N + 1 - x) % k == 0
 */

void solve() {
    long long N, x, k;
    if (!(cin >> N >> x >> k)) return;

    // Check forward journey: x is a multiple of k
    bool forward = (x % k == 0);
    
    // Check backward journey: (N + 1 - x) is a multiple of k
    bool backward = ((N + 1 - x) % k == 0);

    if (forward || backward) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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