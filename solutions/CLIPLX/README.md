# [IPL and RCB (CLIPLX)](https://www.codechef.com/problems/CLIPLX)

- **Difficulty Rating**: 1167
- **Solved in**: 2 attempt(s)

## Problem Summary
RCB needs to earn at least $X$ points from $Y$ matches. A win grants 2 points, a tie grants 1 point, and a loss grants 0 points. We need to find the minimum number of wins required to achieve at least $X$ points.

## Intuition & Mathematical Observation
Let $W$ be the number of wins and $T$ be the number of ties. The remaining matches $(Y - W - T)$ result in losses (0 points).
The total points equation is:
$$2W + T = X$$

We want to minimize $W$. To minimize $W$, we should maximize the number of ties $T$. Since the total number of matches is $Y$, the maximum number of ties we can have is limited by the remaining matches after accounting for wins: $T \le Y - W$.

To get the most points with the fewest wins, we assume all remaining matches are ties:
$$2W + (Y - W) = X$$
$$W + Y = X$$
$$W = X - Y$$

If $X \le Y$, we don't need any wins because we can simply tie all $X$ matches (or fewer) to reach the target, so $W = 0$. If $X > Y$, we must win at least $X - Y$ matches to make up the point deficit.

Thus, the formula is:
$$W = \max(0, X - Y)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic subtraction and comparison. Total time complexity is $O(T)$ where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

/**
 * Problem: CLIPLX
 * RCB needs X points from Y matches.
 * Win = 2 pts, Tie = 1 pt, Loss = 0 pts.
 * Let W be the number of wins.
 * Points = 2*W + (number of ties).
 * To minimize W, we maximize ties. We can tie at most (Y - W) matches.
 * Total points = 2*W + (Y - W) = W + Y.
 * We need W + Y >= X, so W >= X - Y.
 * Since W must be at least 0, W = max(0, X - Y).
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        
        // If points needed (x) is less than or equal to matches (y),
        // we can achieve the points via ties alone.
        if (x <= y) {
            std::cout << 0 << "\n";
        } else {
            // Otherwise, we need to win the difference.
            std::cout << (x - y) << "\n";
        }
    }

    return 0;
}
```