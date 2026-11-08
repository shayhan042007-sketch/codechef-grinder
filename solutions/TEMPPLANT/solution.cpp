#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days with temperatures A_1, A_2, ..., A_N.
 * We need to choose two consecutive days (i, i+1) to plant the seed.
 * The height of the tree is min(A_i, A_{i+1}).
 * We want to maximize this value over all possible i from 1 to N-1.
 * 
 * Complexity:
 * Time: O(N) per test case, where N <= 100. Total time O(T * N) = 10^4 operations.
 * Space: O(N) to store the temperatures.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int max_height = 0;
    // Iterate through all pairs of consecutive days (i, i+1)
    // There are N-1 such pairs.
    for (int i = 0; i < N - 1; ++i) {
        int current_height = min(A[i], A[i + 1]);
        if (current_height > max_height) {
            max_height = current_height;
        }
    }
    
    cout << max_height << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}