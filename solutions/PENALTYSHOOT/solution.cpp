#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Team A has 3 turns done, 2 turns remaining. Max goals A can add: 2.
 * Team B has 4 turns done, 1 turn remaining. Max goals B can add: 1.
 * 
 * Let A_final = X + a, where 0 <= a <= 2
 * Let B_final = Y + b, where 0 <= b <= 1
 * We need to check if there exist a and b such that X + a = Y + b.
 * This is equivalent to checking if the range of possible final scores for A
 * overlaps with the range of possible final scores for B.
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