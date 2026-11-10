#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N marbles with types A_1, A_2, ..., A_N.
 * There are M total possible types (1 to M).
 * We need to find how many types from 1 to M are NOT present in the input array.
 * 
 * Approach:
 * 1. Use a boolean array or a set to keep track of the marble types we have collected.
 * 2. Since M is small (up to 100), a boolean array of size 101 is sufficient.
 * 3. Iterate through the input array and mark the collected types as true.
 * 4. Count how many indices from 1 to M are still false.
 * 
 * Time Complexity: O(T * (N + M))
 * Space Complexity: O(M)
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<bool> collected(M + 1, false);
    for (int i = 0; i < N; ++i) {
        int type;
        cin >> type;
        if (type >= 1 && type <= M) {
            collected[type] = true;
        }
    }
    
    int missing_count = 0;
    for (int i = 1; i <= M; ++i) {
        if (!collected[i]) {
            missing_count++;
        }
    }
    
    cout << missing_count << "\n";
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