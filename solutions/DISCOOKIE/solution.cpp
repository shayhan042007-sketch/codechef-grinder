#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N kids and M cookies. We want to reach a number of cookies K such that:
 * 1. K is a multiple of N (K % N == 0).
 * 2. K >= N (since each kid must receive at least 1 cookie).
 * 3. We want to minimize |M - K|.
 * 
 * Case 1: M < N
 * The smallest multiple of N that is >= N is N itself.
 * So, K = N. The time taken is N - M.
 * 
 * Case 2: M >= N
 * Let r = M % N.
 * We have two main candidates for the nearest multiple of N:
 * Option A: Round down to M - r. The cost is r.
 * Option B: Round up to M + (N - r). The cost is N - r.
 * 
 * Since we need the minimum time, we take min(r, N - r).
 */

void solve() {
    long long N, M;
    cin >> N >> M;

    if (M < N) {
        // Must reach at least N cookies.
        cout << (N - M) << "\n";
    } else {
        long long r = M % N;
        if (r == 0) {
            // Already divisible
            cout << 0 << "\n";
        } else {
            // Either destroy r cookies or make (N - r) cookies
            cout << min(r, N - r) << "\n";
        }
    }
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