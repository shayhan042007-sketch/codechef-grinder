#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We want all '1's to form a single contiguous block.
 * We can only change '0' to '1'.
 * 
 * If there are no '1's, the condition is already satisfied (0 changes).
 * If there are '1's, let the first occurrence of '1' be at index 'first'
 * and the last occurrence of '1' be at index 'last'.
 * To make all '1's contiguous, every '0' between 'first' and 'last'
 * must be changed to '1'.
 * 
 * The number of changes required is the count of '0's in the range [first, last].
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int first = -1;
    int last = -1;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // If no '1's exist, 0 changes needed.
    if (first == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count '0's between first and last index
    int changes = 0;
    for (int i = first; i <= last; ++i) {
        if (S[i] == '0') {
            changes++;
        }
    }

    cout << changes << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}