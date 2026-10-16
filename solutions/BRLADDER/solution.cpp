#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The cities are structured as follows:
 * 1. Horizontal roads: (2i+1) - (2i+2) for i >= 0.
 *    This means (1,2), (3,4), (5,6), ... are connected.
 *    Condition: |a - b| == 1 AND (min(a, b) is odd).
 * 
 * 2. Vertical roads (Odd): (2i+1) - (2i+3) for i >= 0.
 *    This means (1,3), (3,5), (5,7), ... are connected.
 *    Condition: |a - b| == 2 AND (a is odd AND b is odd).
 * 
 * 3. Vertical roads (Even): (2i) - (2i+2) for i >= 1.
 *    This means (2,4), (4,6), (6,8), ... are connected.
 *    Condition: |a - b| == 2 AND (a is even AND b is even).
 * 
 * Combined logic:
 * - If |a - b| == 1:
 *     Check if the smaller number is odd. Since (2i+1, 2i+2) are connected,
 *     if min(a, b) is odd, they are connected.
 * - If |a - b| == 2:
 *     Check if both are odd or both are even.
 * - Otherwise:
 *     No road exists.
 */

void solve() {
    long long a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    // Case 1: Horizontal road (e.g., 1-2, 3-4)
    // Condition: b - a == 1 and a is odd
    if (b - a == 1) {
        if (a % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    // Case 2: Vertical road (e.g., 1-3, 2-4)
    // Condition: b - a == 2 and both have same parity
    else if (b - a == 2) {
        if (a % 2 == b % 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    // Case 3: No road
    else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        solve();
    }
    return 0;
}