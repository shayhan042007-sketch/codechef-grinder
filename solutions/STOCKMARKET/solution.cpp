#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - (A_i skipped).
 * To maximize this, we need to minimize the value of the skipped day (A_i).
 * 
 * Algorithm:
 * 1. Calculate the sum of all elements in the array.
 * 2. Find the minimum element in the array.
 * 3. The result is (Sum - Minimum Element).
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the number of days.
 * Space: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    long long total_sum = 0;
    long long min_val = 101; // Since max A_i is 100
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }
    
    // We skip the day with the minimum profit (or maximum loss)
    cout << (total_sum - min_val) << "\n";
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