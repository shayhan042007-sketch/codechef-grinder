#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the water in a single cup after exactly K operations:
 * 1. If K >= N-1, we can merge all water into one cup. The maximum amount is the total sum.
 * 2. If K < N-1, we perform K merges. To maximize the result, we pick the largest cup 
 *    and merge the K largest other cups into it. This results in the sum of the 
 *    (K+1) largest elements.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (K >= N - 1) {
        // We can merge everything into one cup.
        cout << total_sum << "\n";
    } else {
        // We perform K merges. We start with the largest cup and add the K largest other cups.
        sort(A.rbegin(), A.rend());
        long long max_val = 0;
        for (int i = 0; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
    }
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