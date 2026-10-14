#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to arrange them such that between any two zeros, there are at least K ones.
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let g_i be the number of ones in the i-th gap (where i = 1 to X-1).
 * The condition is g_i >= K for all i = 1 to X-1.
 * The total number of ones used in these gaps is sum(g_i) for i=1 to X-1.
 * The total number of ones available is Y.
 * So, sum(g_i) <= Y.
 * Since each g_i >= K, the minimum sum is (X - 1) * K.
 * Therefore, (X - 1) * K <= Y.
 * K <= Y / (X - 1).
 * 
 * The largest integer K is floor(Y / (X - 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // X zeros create (X - 1) gaps that must contain at least K ones.
        // The condition is (X - 1) * K <= Y.
        // Thus, K = Y / (X - 1).
        
        long long K = Y / (X - 1);
        cout << K << "\n";
    }

    return 0;
}