#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to minimize LCM(1+A_1, 2+A_2, ..., N+A_N) where A is a permutation of 1 to N.
 * Let B_i = i + A_i. We want to minimize LCM(B_1, B_2, ..., B_N).
 * 
 * Consider the values 1+A_1, 2+A_2, ..., N+A_N.
 * If we choose A_i such that i + A_i is constant or small, we minimize the LCM.
 * A simple strategy is to reverse the permutation: A = [N, N-1, ..., 1].
 * Then i + A_i = i + (N - i + 1) = N + 1 for all i.
 * The LCM becomes LCM(N+1, N+1, ..., N+1) = N+1.
 * 
 * Since the sum of each pair is N+1, the LCM is N+1.
 * This is the smallest possible value because the maximum value in the set {i + A_i}
 * must be at least N+1 (by the Pigeonhole Principle or simple observation),
 * and if all values are N+1, the LCM is N+1.
 */

void solve() {
    int N;
    cin >> N;
    
    // Output the permutation [N, N-1, ..., 1]
    for (int i = N; i >= 1; --i) {
        cout << i << (i == 1 ? "" : " ");
    }
    cout << "\n";
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