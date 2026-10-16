#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef lives for L years. We are given a string S of length L where S[i] is '1' (good) or '0' (bad).
 * Chef goes to heaven if there exists some L' (1 <= L' <= L) such that the number of good years
 * in the first L' years is at least 50% of L'.
 * 
 * Let 'good' be the count of '1's in the prefix of length L'.
 * The condition is: good / L' >= 0.5
 * This is equivalent to: 2 * good >= L'
 * 
 * We can iterate through the string, maintaining a running count of 'good' years,
 * and check the condition at each year i (1-indexed).
 * 
 * Time Complexity: O(L) per test case, O(sum of L) total.
 * Space Complexity: O(L) to store the string.
 */

void solve() {
    int L;
    cin >> L;
    string S;
    cin >> S;

    int good_count = 0;
    bool possible = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_count++;
        }
        
        // Current year is i + 1
        // Condition: good_count / (i + 1) >= 0.5
        // Which is: 2 * good_count >= i + 1
        if (2 * good_count >= (i + 1)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}