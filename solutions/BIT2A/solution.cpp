#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sorted list A of size N.
 * For each element A[i], we need to find the number of elements strictly greater than A[i].
 * Since the array is sorted, all elements strictly greater than A[i] must appear after the 
 * last occurrence of A[i] in the array.
 * 
 * Approach:
 * 1. For each index i, we want to find the count of elements > A[i].
 * 2. Since the array is sorted, we can use the upper_bound function or simply 
 *    iterate to find the first index where the value is strictly greater than A[i].
 * 3. If the first index where A[j] > A[i] is 'idx', then the number of elements 
 *    strictly greater than A[i] is (N - idx).
 * 4. Time Complexity: O(N log N) or O(N) per test case. Given N <= 100, O(N^2) is also fine.
 *    Here we use O(N log N) with upper_bound for efficiency.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // upper_bound returns an iterator to the first element strictly greater than A[i]
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        
        // The number of elements strictly greater is the distance from the iterator to the end
        int count = distance(it, A.end());
        
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}