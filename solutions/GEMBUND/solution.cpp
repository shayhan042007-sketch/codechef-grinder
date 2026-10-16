#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, B blue, and G green gems.
 * Each gem sells for 3 coins individually.
 * A bundle of (1R, 1B, 1G) sells for 10 coins.
 * 
 * Let k be the number of bundles we make.
 * k can range from 0 to min(R, B, G).
 * If we make k bundles, we use k of each gem.
 * Remaining gems: (R-k) red, (B-k) blue, (G-k) green.
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 * Total coins = 10k + 3(R + B + G - 3k)
 * Total coins = 10k + 3(R + B + G) - 9k
 * Total coins = k + 3(R + B + G)
 * 
 * To maximize this, we should maximize k.
 * Since k is the number of bundles, the maximum k is min(R, B, G).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, b, g;
        cin >> r >> b >> g;

        // Maximum number of bundles possible
        long long k = min({r, b, g});

        // Calculate total coins
        // Each bundle adds 10 coins, but consumes 3 gems that would have 
        // otherwise been worth 3 * 3 = 9 coins.
        // So each bundle effectively adds 1 coin over the base value of 3 per gem.
        long long total_coins = (k * 10) + ((r - k) + (b - k) + (g - k)) * 3;

        cout << total_coins << "\n";
    }

    return 0;
}