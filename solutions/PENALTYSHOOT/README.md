# [Penalty Shoot-out (PENALTYSHOOT)](https://www.codechef.com/problems/PENALTYSHOOT)

- **Difficulty Rating**: 869
- **Solved in**: 1 attempt(s)

## Problem Summary
In a penalty shootout, Team A has taken 3 shots and has 2 remaining. Team B has taken 4 shots and has 1 remaining. Given the current scores $X$ (for Team A) and $Y$ (for Team B), determine if it is possible for the two teams to finish with the same total score after all their remaining shots are taken.

## Intuition & Mathematical Observation
The problem asks if there exists a scenario where the final scores of both teams are equal. 

1. **Define the ranges:**
   - Team A currently has $X$ goals and can score between $0$ and $2$ additional goals. Thus, their final score will be in the range $[X, X + 2]$.
   - Team B currently has $Y$ goals and can score between $0$ and $1$ additional goal. Thus, their final score will be in the range $[Y, Y + 1]$.

2. **Check for overlap:**
   Two intervals $[L_1, R_1]$ and $[L_2, R_2]$ overlap if and only if:
   $$\max(L_1, L_2) \le \min(R_1, R_2)$$
   
   By applying this logic to our ranges $[X, X+2]$ and $[Y, Y+1]$, we can determine if there is any common score that both teams can achieve. If the condition holds, it is possible for the scores to be equal; otherwise, it is impossible.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic and comparison operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the scores and ranges.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Team A has 3 turns done, 2 turns remaining. Max goals A can add: 2.
 * Team B has 4 turns done, 1 turn remaining. Max goals B can add: 1.
 * 
 * Range for A: [X, X + 2]
 * Range for B: [Y, Y + 1]
 * 
 * Two intervals [L1, R1] and [L2, R2] overlap if max(L1, L2) <= min(R1, R2).
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    int minA = X, maxA = X + 2;
    int minB = Y, maxB = Y + 1;

    // Check if the intervals [minA, maxA] and [minB, maxB] overlap
    if (max(minA, minB) <= min(maxA, maxB)) {
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```