#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N-1 where:
 * S[i] = '0' means A[i] < A[i+1]
 * S[i] = '1' means A[i] > A[i+1]
 * 
 * An element A[i] can be the maximum if it is a "local peak".
 * Specifically:
 * - A[1] can be the maximum if S[0] == '1' (A[1] > A[2]).
 * - A[N] can be the maximum if S[N-2] == '0' (A[N-1] < A[N]).
 * - For 1 < i < N, A[i] can be the maximum if S[i-2] == '0' and S[i-1] == '1'.
 *   (i.e., A[i-1] < A[i] and A[i] > A[i+1]).
 * 
 * We need to count how many such indices exist.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 1) {
        cout << 1 << "\n";
        return;
    }

    int count = 0;

    // Check A[1]
    if (S[0] == '1') {
        count++;
    }

    // Check A[N]
    if (S[N - 2] == '0') {
        count++;
    }

    // Check A[i] for 1 < i < N (indices 1 to N-2 in 0-based string S)
    // A[i] is index i+1 in 1-based array.
    // Condition: S[i-1] == '0' and S[i] == '1'
    for (int i = 0; i < N - 2; ++i) {
        if (S[i] == '0' && S[i + 1] == '1') {
            count++;
        }
    }

    cout << count << "\n";
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