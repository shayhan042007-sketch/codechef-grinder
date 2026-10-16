#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains only 1s and 2s.
 * Let 'c' be the count of 2s in the array.
 * The product of all elements is 1^(N-c) * 2^c = 2^c.
 * We need to check if 2^c = k^8 for some integer k.
 * Since 2^c = k^8, k must be a power of 2, say k = 2^x.
 * Then 2^c = (2^x)^8 = 2^(8x).
 * This implies c = 8x, meaning c must be a multiple of 8.
 * 
 * Special case: If c = 0, the product is 1. 1 = 1^8, which is valid.
 * 0 is a multiple of 8 (0 = 8 * 0).
 * Thus, the condition is simply: count of 2s must be a multiple of 8.
 */

void solve() {
    int n;
    cin >> n;
    int count_twos = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 2) {
            count_twos++;
        }
    }

    if (count_twos % 8 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}