# [Swish Game (SWISHGAME)](https://www.codechef.com/problems/SWISHGAME)

- **Difficulty Rating**: 1188
- **Solved in**: 1 attempt(s)

## Problem Summary
Toofan plays a game where he throws $N$ rings. A "swish" occurs when a ring lands successfully. The game ends under two conditions:
1. Toofan reaches exactly $K$ swishes.
2. It becomes mathematically impossible for Toofan to reach $K$ swishes with the remaining number of rings.

Given the number of rings thrown so far ($M$), the target number of swishes ($K$), and the sequence of results for the first $M$ rings, determine the total number of rings ($N$) that were thrown in the game.

## Intuition & Mathematical Observation
We analyze the state of the game after $M$ throws:
1. **Case 1: Goal Reached**
   If the number of swishes in the first $M$ throws is $\ge K$, the game must have ended exactly when the $K$-th swish occurred. Since the problem states the game ended at $M$, it implies $N = M$.

2. **Case 2: Goal Impossible**
   If the number of swishes after $M$ throws is less than $K$, the game ends if it is impossible to reach $K$ swishes even if every remaining ring were a swish. 
   Let $S$ be the number of swishes in the first $M$ throws. The number of remaining rings is $(N - M)$. The game becomes impossible when:
   $$S + (N - M) < K$$
   To find the smallest $N$ where the game stops, we look for the point where the condition fails. The game ends at $M$ if, at that exact moment, the maximum possible swishes he could achieve is $K-1$.
   $$S + (N - M) = K - 1$$
   Rearranging for $N$:
   $$N = K - 1 - S + M$$

## Complexity Analysis
- **Time Complexity**: $O(M)$ per test case, where $M$ is the length of the string $S$. We iterate through the string once to count the swishes.
- **Space Complexity**: $O(M)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the string of length M.
 * Let 'swishes' be the count of 'S' in S.
 * 
 * Case 1: The game ended because Toofan reached K swishes.
 * In this case, the game must have ended exactly at move M.
 * This implies N = M.
 * 
 * Case 2: The game ended because it became impossible to reach K swishes.
 * The game ends at move M if the current swishes + remaining rings < K.
 * The threshold for impossibility is: swishes + (N - M) = K - 1.
 * Therefore, N = K - 1 - swishes + M.
 */

void solve() {
    int M, K;
    cin >> M >> K;
    string S;
    cin >> S;

    int swishes = 0;
    for (char c : S) {
        if (c == 'S') {
            swishes++;
        }
    }

    if (swishes >= K) {
        // Game ended because he reached K swishes
        cout << M << "\n";
    } else {
        // Game ended because it became impossible to reach K swishes
        // N = K - 1 - swishes + M
        long long N = (long long)K - 1 - swishes + M;
        cout << N << "\n";
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