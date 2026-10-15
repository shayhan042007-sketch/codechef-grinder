#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HATTRICK
 * A hattrick is defined as 3 consecutive wickets ('W') in an over of 6 balls.
 * We need to check if any sequence of 3 consecutive balls contains 'W'.
 * 
 * Given balls: A, B, C, D, E, F
 * Possible windows of 3:
 * 1. (A, B, C)
 * 2. (B, C, D)
 * 3. (C, D, E)
 * 4. (D, E, F)
 * 
 * If any of these windows consist entirely of 'W', output YES, else NO.
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check all possible windows of size 3
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}