#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-based indexing).
 * This means for each pair (A[i], A[2N + 1 - i]) where 1 <= i <= N,
 * we can choose to keep them as they are or swap them.
 * To maximize the sum of the first half (A[1] + ... + A[N]),
 * for each pair (A[i], A[2N + 1 - i]), we should place the larger of the two
 * in the first half.
 * 
 * Specifically, for each i from 1 to N:
 * The first half element is A[i] and its mirror is A[2N - i + 1].
 * We want to maximize the sum, so we take max(A[i], A[2N - i + 1]) for each i.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // The array is 0-indexed in C++.
    // A[i] corresponds to the first half (0 to N-1).
    // The mirror of A[i] is A[2N - 1 - i].
    for (int i = 0; i < N; ++i) {
        max_sum += max(A[i], A[2 * N - 1 - i]);
    }

    cout << max_sum << "\n";
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