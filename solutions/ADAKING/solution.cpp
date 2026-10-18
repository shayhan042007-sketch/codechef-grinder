#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an 8x8 chessboard. We need to place one King ('O') and some obstacles ('X')
 * such that the King can reach exactly K cells.
 * 
 * Strategy:
 * Place the King at (0, 0).
 * Fill the board with '.' for the first K cells in a row-major order (reading order).
 * Fill the remaining (64 - K) cells with 'X'.
 * Since the King moves to adjacent cells, if we fill the board in a connected 
 * manner (like a snake or row-by-row), the King will be able to reach all '.' cells.
 * 
 * Example K=1:
 * OXXXXXXX
 * XXXXXXXX
 * ...
 * 
 * Example K=5:
 * O....XXX
 * XXXXXXXX
 * ...
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
        if (t > 0) cout << "\n";
    }
    return 0;
}