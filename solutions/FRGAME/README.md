# [Game between friends (FRGAME)](https://www.codechef.com/problems/FRGAME)

- **Difficulty Rating**: 991
- **Solved in**: 1 attempt(s)

## Problem Summary
Nitin starts with $A$ coins and Sobhagya starts with $B$ coins. The game proceeds in two steps:
1. Ritik gives $C$ coins to the player who currently has fewer coins (or to Sobhagya if they have an equal amount).
2. Satyarth gives $D$ coins to the player who currently has fewer coins (or to Sobhagya if they have an equal amount).

We need to determine the final winner. If $A \ge B$, Nitin wins ('N'); otherwise, Sobhagya wins ('S').

## Intuition & Mathematical Observation
The problem describes a simple simulation. We are given the initial state $(A, B)$ and two sequential updates. 

- **Winning Condition**: The problem explicitly states that Sobhagya is winning if $B > A$, and Nitin is winning if $A \ge B$.
- **Update Logic**: In each step, we check the current state. If $B > A$, Nitin is the "losing" player, so we add the coins to $A$. If $A \ge B$, Sobhagya is the "losing" player (or tied), so we add the coins to $B$.
- **Constraints**: Since $A, B, C, D \le 10^6$, the maximum possible value for any variable after two additions is $10^6 + 10^6 + 10^6 = 3 \times 10^6$. This fits well within a standard 32-bit integer, though `long long` is used for safety.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coin counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Nitin has A coins, Sobhagya has B coins.
 * Winning condition:
 * If B > A, Sobhagya is winning.
 * If A >= B, Nitin is winning.
 * 
 * Ritik gives C coins to the player who is not winning.
 * Satyarth gives D coins to the player who is not winning.
 * 
 * We simulate these two steps and determine the final winner.
 */

void solve() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    // First step: Ritik gives C coins
    // If Sobhagya is winning (B > A), Nitin gets C.
    // Otherwise (A >= B), Sobhagya gets C.
    if (B > A) {
        A += C;
    } else {
        B += C;
    }

    // Second step: Satyarth gives D coins
    // If Sobhagya is winning (B > A), Nitin gets D.
    // Otherwise (A >= B), Sobhagya gets D.
    if (B > A) {
        A += D;
    } else {
        B += D;
    }

    // Final check
    if (B > A) {
        cout << "S" << "\n";
    } else {
        cout << "N" << "\n";
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