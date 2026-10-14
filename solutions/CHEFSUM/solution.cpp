#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * prefixSum(i) = A[1] + A[2] + ... + A[i]
 * suffixSum(i) = A[i] + A[i+1] + ... + A[N]
 * 
 * Let f(i) = prefixSum(i) + suffixSum(i)
 * f(i) = (A[1] + ... + A[i]) + (A[i] + ... + A[N])
 * f(i) = (A[1] + ... + A[N]) + A[i]
 * 
 * Since (A[1] + ... + A[N]) is a constant sum of all elements in the array,
 * minimizing f(i) is equivalent to minimizing A[i].
 * 
 * To find the minimum index i for which f(i) is minimum, we simply need to find
 * the index i (1-based) where A[i] is the smallest. If there are multiple such
 * indices, the problem asks for the least index i.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array (or O(1) if processed on the fly).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int min_val = 200000; // Constraint A[i] <= 10^5
    int min_idx = -1;
    
    for (int i = 1; i <= N; ++i) {
        int val;
        cin >> val;
        if (val < min_val) {
            min_val = val;
            min_idx = i;
        }
    }
    
    cout << min_idx << "\n";
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