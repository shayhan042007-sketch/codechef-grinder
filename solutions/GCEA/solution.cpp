#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon with difficulty A_i, we have two choices:
 * 1. Use Normal Pekóballs: Cost = A_i * X
 * 2. Use a Master Pekóball: Cost = Y
 * 
 * To minimize the total cost, for each Pekómon, we should choose the minimum of these two:
 * min_cost_i = min(A_i * X, Y)
 * 
 * The total minimum cost is the sum of min_cost_i for all i from 1 to N.
 * 
 * Constraints:
 * N, X, Y, A_i are all <= 100.
 * The maximum possible cost would be 100 * 100 * 100 = 1,000,000, 
 * which fits comfortably within a standard 32-bit integer, 
 * but using long long is safer practice in competitive programming.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    vector<int> A(N);
    long long total_cost = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // For each Pekómon, decide whether to use Normal or Master balls
        long long normal_cost = (long long)A[i] * X;
        total_cost += min(normal_cost, Y);
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}