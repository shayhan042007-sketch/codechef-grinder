#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: CHEFSLP
 * Logic:
 * 1. Total slippers = N
 * 2. Left slippers = L
 * 3. Right slippers = N - L
 * 4. Max pairs = min(L, N - L)
 * 5. Total revenue = Max pairs * X
 */

void solve() {
    int n, l, x;
    if (!(cin >> n >> l >> x)) return;
    
    int r = n - l;
    int max_pairs = min(l, r);
    
    cout << (long long)max_pairs * x << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}