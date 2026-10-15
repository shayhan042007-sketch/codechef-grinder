#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N coins with values v_1, v_2, ..., v_N.
 * We need to select two distinct coins such that the absolute difference 
 * between their values is minimized.
 * 
 * Approach:
 * 1. If we sort the array of coin values, the minimum difference between any 
 *    two elements must occur between two adjacent elements in the sorted array.
 * 2. Proof: Suppose we have sorted values a_1 <= a_2 <= ... <= a_N.
 *    For any i < j, a_j - a_i = (a_j - a_{j-1}) + (a_{j-1} - a_{j-2}) + ... + (a_{i+1} - a_i).
 *    Since all terms are non-negative, a_j - a_i >= a_{k+1} - a_k for any k in [i, j-1].
 *    Thus, the minimum difference must be found among adjacent pairs.
 * 
 * Complexity:
 * - Sorting takes O(N log N).
 * - A single pass to find the minimum difference takes O(N).
 * - Total time complexity: O(N log N) per test case.
 * - Total space complexity: O(N) to store the coin values.
 * - Given the sum of N <= 5 * 10^5, this approach is well within the 1s time limit.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    
    // Sort the coins to bring values with minimal differences next to each other
    sort(v.begin(), v.end());
    
    // Initialize min_diff with a large value
    long long min_diff = LLONG_MAX;
    
    // Iterate through the sorted array and check adjacent differences
    for (int i = 0; i < N - 1; ++i) {
        long long diff = v[i + 1] - v[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
        // Optimization: if diff is 0, it's the smallest possible absolute difference
        if (min_diff == 0) break;
    }
    
    cout << min_diff << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}