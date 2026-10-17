# [Football Ties (FOOTBALLTIES)](https://www.codechef.com/problems/FOOTBALLTIES)

- **Difficulty Rating**: 788
- **Solved in**: 1 attempt(s)

## Problem Summary
In a football league, a win earns 3 points, a loss earns 0 points, and a draw earns 1 point. Given the final scores $X$ and $Y$ of two teams, we need to determine the minimum number of matches that must have ended in a draw. Note that a draw counts as 1 point for both teams involved.

## Intuition & Mathematical Observation
Let $w_A$ and $w_B$ be the number of wins for team A and team B, and $D$ be the number of draws. The scores are calculated as:
- $X = 3 \cdot w_A + D$
- $Y = 3 \cdot w_B + D$

From these equations, we can observe the relationship using modular arithmetic:
- $X \equiv D \pmod{3}$
- $Y \equiv D \pmod{3}$

This implies that the number of draws $D$ must leave the same remainder as the scores when divided by 3. Since we want to find the **minimum** number of draws, we look for the smallest non-negative integer $D$ that satisfies this condition. 

Given that $X \equiv Y \pmod{3}$ is a requirement for any valid set of scores in this system, the smallest non-negative value for $D$ is simply $X \pmod{3}$ (or $Y \pmod{3}$).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single modulo operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A win gives 3 points, a loss gives 0 points, and a draw gives 1 point.
 * Let w_a be the number of wins for team A, and d_a be the number of draws for team A.
 * Let w_b be the number of wins for team B, and d_b be the number of draws for team B.
 * 
 * Since every draw involves both teams, the number of draws for A must equal the number of draws for B.
 * Let D be the number of draws.
 * Score of A: X = 3 * w_a + D
 * Score of B: Y = 3 * w_b + D
 * 
 * We want to minimize D.
 * From the equations:
 * X % 3 = D % 3
 * Y % 3 = D % 3
 * 
 * This implies that D must be a non-negative integer such that D % 3 = X % 3 and D % 3 = Y % 3.
 * Since we want the minimum D, and we know that X = 3*w_a + D and Y = 3*w_b + D,
 * we can observe that D = X % 3 is the smallest non-negative value satisfying the condition.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The minimum number of draws is simply the remainder when the score is divided by 3.
        // Since X % 3 must equal Y % 3 for a valid scenario to exist, 
        // we can output either X % 3 or Y % 3.
        cout << (x % 3) << "\n";
    }

    return 0;
}
```