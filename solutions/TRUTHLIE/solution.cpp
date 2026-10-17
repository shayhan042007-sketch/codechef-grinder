#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to pick X people such that the number of truth-tellers (T) is 
 * strictly greater than the number of liars (L) in any subset of size X.
 * 
 * Let the subset have k truth-tellers and (X-k) liars.
 * We need k > X - k, which means 2k > X.
 * The worst case is picking the maximum possible number of liars, which is M.
 * If we pick X people, the minimum number of truth-tellers is max(0, X - M).
 * So we need 2 * (X - M) > X  => 2X - 2M > X => X > 2M.
 * The smallest integer X is 2M + 1.
 * We also must have X <= N + M.
 */

void solve() {
    int N, M;
    cin >> N >> M;

    int X = 2 * M + 1;
    if (X <= N + M) {
        cout << X << "\n";
    } else {
        cout << -1 << "\n";
    }
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