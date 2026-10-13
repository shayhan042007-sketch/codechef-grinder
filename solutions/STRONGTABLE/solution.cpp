#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Suppose we choose a subset of k legs with strengths W_1, W_2, ..., W_k.
 * Let the minimum strength in this subset be W_min.
 * The weight W that the table can bear must satisfy:
 * W / k <= W_min  =>  W <= k * W_min.
 * To maximize W for a fixed subset, we should set W = k * W_min.
 * 
 * To maximize this over all possible subsets:
 * 1. Sort the given leg strengths in non-decreasing order: W_1 <= W_2 <= ... <= W_N.
 * 2. If we decide that the minimum strength in our subset is W_i, then to maximize
 *    the total weight, we should include all legs with strength >= W_i.
 * 3. If we pick all legs from index i to N-1 (0-indexed), the number of legs is (N - i).
 * 4. The minimum strength in this subset is W_i.
 * 5. The maximum weight for this specific subset is (N - i) * W_i.
 * 6. We iterate through all possible i from 0 to N-1 and find the maximum value.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the strengths to easily pick subsets where W_i is the minimum
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    for (int i = 0; i < n; ++i) {
        // Number of legs with strength >= w[i] is (n - i)
        // The minimum strength is w[i]
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
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