#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N colours of balloons.
 * The i-th colour (1-indexed) costs i rupees.
 * We are given A_i, the number of balloons of the i-th colour.
 * Total cost = sum_{i=1 to N} (A_i * i).
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i <= 100.
 * Maximum possible cost per test case = sum_{i=1 to 100} (100 * i)
 * = 100 * (100 * 101 / 2) = 100 * 5050 = 505,000.
 * This fits comfortably within a standard 32-bit integer, but using long long
 * is good practice to prevent overflow in competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        long long total_cost = 0;
        for (int i = 1; i <= n; ++i) {
            long long a_i;
            cin >> a_i;
            // The cost of the i-th colour is i.
            // Total cost is sum of (number of balloons * cost per balloon)
            total_cost += (a_i * i);
        }
        
        cout << total_cost << "\n";
    }
    
    return 0;
}