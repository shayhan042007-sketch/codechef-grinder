# [Chess Pairing (CHESS_PAIR)](https://www.codechef.com/problems/CHESS_PAIR)

- **Difficulty Rating**: 892
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $2N$ total players, where $X$ players are rated and the remaining $(2N - X)$ players are unrated. We need to pair all $2N$ players into $N$ pairs such that the number of pairs consisting of two rated players is minimized. We are asked to output the number of rated players who end up being paired with another rated player.

## Intuition & Mathematical Observation
To minimize the number of rated-rated pairs, we should prioritize pairing rated players with unrated players as much as possible.

1. Let $R = X$ (number of rated players).
2. Let $U = 2N - X$ (number of unrated players).
3. Each pair consisting of one rated and one unrated player "neutralizes" one rated player. We can form at most $\min(R, U)$ such pairs.
4. After forming these pairs, the remaining rated players must be paired with each other.
   - If $R \le U$, we can pair every rated player with an unrated player. The number of rated-rated pairs is $0$.
   - If $R > U$, we use all $U$ unrated players to pair with $U$ rated players. The remaining rated players are $R - U$. Since these remaining players must be paired with each other, the number of rated players left without an unrated partner is $R - U$.

Thus, the number of rated players paired with other rated players is $\max(0, R - U)$. Substituting $U = 2N - X$:
$$\text{Result} = \max(0, X - (2N - X)) = \max(0, 2X - 2N)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 2N total players, X of whom are rated.
 * We want to minimize the number of rated players paired with other rated players.
 * 
 * Let R = X (rated players)
 * Let U = 2N - X (unrated players)
 * 
 * We want to maximize the number of (Rated, Unrated) pairs.
 * The maximum number of such pairs is min(R, U).
 * The remaining rated players who must be paired with each other is R - min(R, U).
 * This simplifies to max(0, R - U).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long unrated = 2 * n - x;
        long long result = 0;
        
        // If rated players exceed unrated, the excess must pair with each other
        if (x > unrated) {
            result = x - unrated;
        } else {
            result = 0;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
```