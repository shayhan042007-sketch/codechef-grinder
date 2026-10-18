#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Nitin has A coins, Sobhagya has B coins.
 * Winning condition:
 * If B > A, Sobhagya is winning.
 * If A >= B, Nitin is winning.
 * 
 * Ritik gives C coins to the player who is not winning.
 * Satyarth gives D coins to the player who is not winning.
 * 
 * We need to simulate these two steps and determine the final winner.
 * Since A, B, C, D are up to 10^6, the sum will not exceed 3*10^6,
 * which fits comfortably in a standard 32-bit integer, but using 
 * long long is safer and good practice.
 */

void solve() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    // First step: Ritik gives C coins
    // If Sobhagya is winning (B > A), Nitin gets C.
    // Otherwise (A >= B), Sobhagya gets C.
    if (B > A) {
        A += C;
    } else {
        B += C;
    }

    // Second step: Satyarth gives D coins
    // If Sobhagya is winning (B > A), Nitin gets D.
    // Otherwise (A >= B), Sobhagya gets D.
    if (B > A) {
        A += D;
    } else {
        B += D;
    }

    // Final check
    if (B > A) {
        cout << "S" << "\n";
    } else {
        cout << "N" << "\n";
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