#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a set S = {0, 1, 2, ..., N} where N is even.
 * We perform operations until only one element remains.
 * In each operation, we pick X, Y, add max(X, Y) to score, and add (X & Y) if not present.
 * 
 * Let's trace small values:
 * N=2: {0, 1, 2}. Pick (1, 2) -> score 2, set {0}. Final: 2.
 * N=4: {0, 1, 2, 3, 4}. 
 *      Pick (3, 4) -> score 4, set {0, 1, 2}.
 *      Pick (1, 2) -> score 4+2=6, set {0}. Final: 6.
 * N=6: {0, 1, 2, 3, 4, 5, 6}.
 *      Pick (5, 6) -> score 6, set {0, 1, 2, 3, 4}.
 *      Pick (3, 4) -> score 6+4=10, set {0, 1, 2}.
 *      Pick (1, 2) -> score 10+2=12, set {0}. Final: 12.
 * 
 * Pattern observed:
 * N=2: 2
 * N=4: 6
 * N=6: 12
 * N=8: 20
 * 
 * The sequence is 2, 6, 12, 20, ...
 * These are values of the form k*(k+1) where k = N/2.
 * Let's check N=50: k=25. 25 * 26 = 650. Matches sample output.
 * 
 * The logic:
 * We want to minimize the sum of max(X, Y).
 * By always picking the largest available pair (2k-1, 2k), we add 2k to the score
 * and the result of (2k-1 & 2k) is 2k-2, which is already in the set.
 * This effectively removes the two largest elements and leaves the rest of the set
 * unchanged, reducing the problem to N-2.
 * Total score = sum_{k=1}^{N/2} 2k = 2 * (N/2 * (N/2 + 1) / 2) = (N/2) * (N/2 + 1).
 */

void solve() {
    long long N;
    cin >> N;
    long long k = N / 2;
    long long ans = k * (k + 1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}