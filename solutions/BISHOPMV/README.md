# [Bishop Moves (BISHOPMV)](https://www.codechef.com/problems/BISHOPMV)

- **Difficulty Rating**: 914
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two coordinates $(x_1, y_1)$ and $(x_2, y_2)$ on an $8 \times 8$ chessboard, determine the minimum number of moves a bishop requires to travel from the starting square to the target square. If it is impossible, output -1.

## Intuition & Mathematical Observation
A bishop moves diagonally. We can categorize the possible outcomes based on the properties of the chessboard:

1.  **0 Moves**: If $(x_1, y_1) = (x_2, y_2)$, the bishop is already there. (Though the problem constraints typically imply distinct squares).
2.  **1 Move**: A bishop can reach any square on the same diagonal. Two squares are on the same diagonal if the absolute difference of their coordinates is equal: $|x_1 - x_2| = |y_1 - y_2|$.
3.  **Impossible (-1)**: A bishop is restricted to squares of a single color. The color of a square $(x, y)$ can be determined by the parity of the sum of its coordinates $(x + y) \pmod 2$. If the parity of the start and end squares differ, the bishop can never reach the target.
4.  **2 Moves**: If the squares are the same color but not on the same diagonal, the bishop can always reach the target in exactly 2 moves by moving to the intersection point of the two diagonals passing through the start and end squares.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A bishop moves along diagonals.
 * Two cells (x1, y1) and (x2, y2) are on the same diagonal if:
 * 1. x1 + y1 == x2 + y2 (anti-diagonal)
 * 2. x1 - y1 == x2 - y2 (main diagonal)
 * 
 * If the cells are the same, 0 moves.
 * If they are on the same diagonal, 1 move.
 * If they are not on the same diagonal, we check the color of the squares.
 * A bishop can only move between squares of the same color.
 * The color of a square (x, y) is determined by (x + y) % 2.
 * If (x1 + y1) % 2 != (x2 + y2) % 2, it is impossible (-1).
 * If they are same color but not on the same diagonal, it takes 2 moves.
 */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if they are on the same diagonal
    if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << 1 << "\n";
    } 
    // Check if they are different colors (impossible)
    else if ((x1 + y1) % 2 != (x2 + y2) % 2) {
        cout << -1 << "\n";
    } 
    // If same color but not same diagonal, it takes 2 moves
    else {
        cout << 2 << "\n";
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