# [Ada King (ADAKING)](https://www.codechef.com/problems/ADAKING)

- **Difficulty Rating**: 1378
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an $8 \times 8$ chessboard, we are required to place one King ('O') and a set of obstacles ('X') such that the King can reach exactly $K$ cells (including the cell it is currently standing on). The remaining cells should be filled with obstacles.

## Intuition & Mathematical Observation
The key to this problem is realizing that a King can move to any adjacent cell (horizontally, vertically, or diagonally). If we place the King at the top-left corner $(0, 0)$ and fill the board in a row-major order (reading order), the King will always be able to reach every '.' cell placed sequentially.

1. **Placement**: Place the King at `board[0][0]`.
2. **Filling**: We need exactly $K$ reachable cells. Since the King occupies one cell, we need to place $K-1$ additional '.' characters.
3. **Connectivity**: By filling the board row-by-row, we ensure that every '.' cell is adjacent to at least one other '.' cell (or the King), maintaining a connected path for the King to reach all $K$ cells.
4. **Obstacles**: Any remaining cells after the first $K$ are filled with 'X', which effectively blocks the King from moving further.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the board size is fixed at $8 \times 8 = 64$ cells, the nested loops always perform a constant number of operations.
- **Space Complexity**: $O(1)$. We use a fixed-size $8 \times 8$ character array to store the board state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an 8x8 chessboard. We need to place one King ('O') and some obstacles ('X')
 * such that the King can reach exactly K cells.
 * 
 * Strategy:
 * Place the King at (0, 0).
 * Fill the board with '.' for the first K cells in a row-major order.
 * Fill the remaining (64 - K) cells with 'X'.
 */

void solve() {
    int K;
    cin >> K;

    char board[8][8];
    int count = 0;

    // Place the King at (0, 0)
    board[0][0] = 'O';
    count++;

    // Fill the rest of the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == 0 && j == 0) continue;
            
            if (count < K) {
                board[i][j] = '.';
                count++;
            } else {
                board[i][j] = 'X';
            }
        }
    }

    // Print the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
        // Optional: Add a newline between test cases if required by specific output formats
        if (t > 0) cout << "\n";
    }
    return 0;
}
```