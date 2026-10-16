# [Drawing Chances (DRAWCH)](https://www.codechef.com/problems/DRAWCH)

- **Difficulty Rating**: 945
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ total matches to be played, with $M$ matches already completed. We know the results of the $M$ matches (represented by a string where '1' denotes an Alice win and '0' denotes a Bob win). We need to determine if it is possible for Alice and Bob to finish with an equal number of total wins after all $N$ matches are played.

## Intuition & Mathematical Observation
Let:
- $A$ be the number of wins Alice currently has.
- $B$ be the number of wins Bob currently has ($B = M - A$).
- $K$ be the number of remaining matches ($K = N - M$).
- $x$ be the number of matches Alice wins out of the remaining $K$ matches.

For a tie to occur, the final win counts must be equal:
$$\text{Total Alice Wins} = \text{Total Bob Wins}$$
$$A + x = B + (K - x)$$

Substituting $B = M - A$ and $K = N - M$:
$$A + x = (M - A) + (N - M) - x$$
$$A + x = N - A - x$$
$$2x = N - 2A$$
$$x = \frac{N - 2A}{2}$$

For a valid scenario, $x$ must satisfy:
1. **Integrity**: $N - 2A$ must be divisible by 2 (i.e., $N - 2A$ must be even).
2. **Non-negativity**: $x \ge 0$, which implies $N \ge 2A$.
3. **Feasibility**: $x \le K$, meaning Alice cannot win more than the remaining matches.

If these conditions are met, a tie is possible.

## Complexity Analysis
- **Time Complexity**: $O(M)$ per test case, where $M$ is the length of the string $S$, to count Alice's current wins. Given $T$ test cases, the total time complexity is $O(T \times M)$.
- **Space Complexity**: $O(M)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if there exists an integer x (0 <= x <= K) 
 * such that Alice's final wins equal Bob's final wins.
 * Derived formula: 2x = N - 2A
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int A = 0;
    for (char c : S) {
        if (c == '1') A++;
    }

    int K = N - M;
    int diff = N - 2 * A;
    
    // Check if a valid x exists
    if (diff >= 0 && diff % 2 == 0) {
        int x = diff / 2;
        if (x <= K) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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