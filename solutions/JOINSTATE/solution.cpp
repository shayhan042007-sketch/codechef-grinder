#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and a threshold M.
 * We need to partition the array into the maximum number of contiguous subarrays
 * such that the sum of each subarray is at least M.
 * 
 * Greedy Strategy:
 * Iterate through the array and maintain a running sum.
 * As soon as the running sum reaches or exceeds M, we have formed a valid state.
 * We increment our count of states and reset the running sum to 0.
 * Any remaining elements that do not sum up to M at the end are effectively 
 * absorbed into the last valid state formed (or the only state if no state reached M yet).
 * However, the problem guarantees that the total sum is at least M, so we will
 * always be able to form at least one state.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the input array.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int state_count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        
        // If the current accumulated sum meets the requirement,
        // we finalize this as a state and reset the counter.
        if (current_sum >= M) {
            state_count++;
            current_sum = 0;
        }
    }
    
    cout << state_count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}