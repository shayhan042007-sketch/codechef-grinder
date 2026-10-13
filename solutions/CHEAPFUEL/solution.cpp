#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial price of petrol: X
 * Initial price of diesel: Y
 * Monthly increase for petrol: A
 * Monthly increase for diesel: B
 * Number of months: K
 * 
 * Price of petrol after K months: X + (A * K)
 * Price of diesel after K months: Y + (B * K)
 * 
 * We need to compare these two values.
 * Constraints: X, Y, A, B, K <= 1000.
 * Maximum possible value: 1000 + (1000 * 1000) = 1,001,000.
 * This fits comfortably within a standard 32-bit signed integer, 
 * but using long long is safer practice in competitive programming.
 */

void solve() {
    long long X, Y, A, B, K;
    if (!(cin >> X >> Y >> A >> B >> K)) return;

    long long final_petrol = X + (A * K);
    long long final_diesel = Y + (B * K);

    if (final_petrol < final_diesel) {
        cout << "PETROL" << "\n";
    } else if (final_diesel < final_petrol) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "SAME PRICE" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}