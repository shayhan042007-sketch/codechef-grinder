#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * The game proceeds by dividing both TS and JS by 2 as long as both are even.
 * This is equivalent to removing all factors of 2 from both numbers.
 * Let TS' = TS / 2^k = m (which is odd).
 * Let JS = 2^p * n, where n is odd.
 * 
 * The game continues until one of them becomes odd.
 * If we divide both by 2^min(k, p), the new values are:
 * TS_new = TS / 2^min(k, p)
 * JS_new = JS / 2^min(k, p)
 * 
 * Jerry wins if the final state is (TS_new is odd, JS_new is even).
 * Since TS_new = TS / 2^k = m (odd), the condition "TS_new is odd" is always satisfied.
 * Thus, Jerry wins if JS_new is even.
 * 
 * JS_new = (2^p * n) / 2^min(k, p).
 * For JS_new to be even, we need the power of 2 in JS_new to be at least 1.
 * This happens if p > k.
 * 
 * So, we need to count how many JS in [1, TS] satisfy:
 * 1. JS is a multiple of 2^(k+1)
 * 2. JS <= TS
 * 
 * Let X = 2^(k+1). We need to count multiples of X up to TS.
 * The number of such values is floor(TS / X).
 */

void solve() {
    long long ts;
    cin >> ts;

    // Find the power of 2 that divides TS
    long long temp_ts = ts;
    long long power_of_2 = 1;
    while (temp_ts % 2 == 0) {
        power_of_2 *= 2;
        temp_ts /= 2;
    }

    // We need JS to be a multiple of (power_of_2 * 2)
    // such that JS <= TS.
    long long divisor = power_of_2 * 2;
    long long ans = ts / divisor;

    cout << ans << "\n";
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