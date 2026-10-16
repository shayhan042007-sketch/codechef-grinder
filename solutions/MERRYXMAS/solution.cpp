#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three activities with durations: 1, 2, and 4 hours.
 * To maximize the number of activities, we should always pick the shortest 
 * available activities first (Greedy approach).
 * 
 * The sorted durations are: 1, 2, 4.
 * - If X < 1: 0 activities
 * - If 1 <= X < 3: 1 activity (the 1-hour one)
 * - If 3 <= X < 7: 2 activities (1 + 2 = 3 hours)
 * - If X >= 7: 3 activities (1 + 2 + 4 = 7 hours)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    int count = 0;
    if (X >= 1) {
        count++;
        X -= 1;
    }
    if (X >= 2) {
        count++;
        X -= 2;
    }
    if (X >= 4) {
        count++;
        X -= 4;
    }

    cout << count << "\n";

    return 0;
}