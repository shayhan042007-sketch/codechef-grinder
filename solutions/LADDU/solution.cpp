#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Calculate total laddus based on activity rules:
 *    - CONTEST_WON: 300 + max(0, 20 - rank)
 *    - TOP_CONTRIBUTOR: 300
 *    - BUG_FOUND: severity
 *    - CONTEST_HOSTED: 50
 * 2. Determine redemption threshold based on origin:
 *    - INDIAN: 200
 *    - NON_INDIAN: 400
 * 3. Calculate max months: total_laddus / threshold
 * 
 * Time Complexity: O(T * activities)
 * Space Complexity: O(1)
 */

void solve() {
    int activities;
    string origin;
    cin >> activities >> origin;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    cout << (total_laddus / threshold) << "\n";
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