#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To convert an array A into a permutation of size N (containing 1 to N),
 * we need to map each element A[i] to a unique value in {1, 2, ..., N}.
 * Since we can only increase elements, an element A[i] can be transformed into 
 * a target value T if and only if A[i] <= T.
 * 
 * To minimize the total operations (sum of (T_i - A[i])), we should sort the 
 * array A in non-decreasing order and match the sorted elements with the 
 * sorted target permutation {1, 2, ..., N}.
 * 
 * If at any point after sorting, A[i] > (i + 1), it is impossible to transform 
 * A[i] into (i + 1) because we can only increase values. Thus, we output -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to greedily match the smallest available A[i] 
    // with the smallest available target value (1, 2, ..., N).
    sort(A.begin(), A.end());

    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        long long target = i + 1;
        if (A[i] > target) {
            // Cannot decrease A[i] to reach target
            cout << -1 << "\n";
            return;
        }
        operations += (target - A[i]);
    }

    cout << operations << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}