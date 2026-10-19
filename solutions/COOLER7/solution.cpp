#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To drop the temperature from T to T-1, it takes T minutes.
 * To go from N to M, we need to perform the drop (N-M) times.
 * The sequence of times taken is:
 * N -> N-1: N minutes
 * N-1 -> N-2: N-1 minutes
 * ...
 * M+1 -> M: M+1 minutes
 * 
 * Total time = N + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic progression sum.
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * First term = N
 * Last term = M + 1
 * Total time = (N - M) * (N + M + 1) / 2
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Using the arithmetic series sum formula:
        // Sum = (n - m) * (n + m + 1) / 2
        // Since n and m are small (up to 40), this fits in a standard integer,
        // but long long is used for safety.
        long long total_time = (n - m) * (n + m + 1) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}