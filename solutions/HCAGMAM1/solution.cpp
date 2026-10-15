#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef And Salary Pay
 * Approach:
 * 1. Calculate the total number of working days (count of '1's).
 * 2. Calculate the longest streak of consecutive '1's.
 * 3. Salary = (Total '1's * X) + (Longest Streak * Y).
 * 4. Since the string length is fixed at 30, a simple linear scan is O(N) per test case,
 *    which is well within the time limit for 10^4 test cases.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    string s;
    cin >> s;

    long long total_working_days = 0;
    long long max_streak = 0;
    long long current_streak = 0;

    for (char c : s) {
        if (c == '1') {
            total_working_days++;
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 0;
        }
    }
    // Final check in case the string ends with a streak
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }

    long long salary = (total_working_days * X) + (max_streak * Y);
    cout << salary << "\n";
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