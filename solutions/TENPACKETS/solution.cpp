#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * We need to represent 10 as a sum of 2s and 4s.
 * Possible combinations (number of 4-packs, number of 2-packs):
 * 1. (0, 5): 0 * Y + 5 * X = 5X
 * 2. (1, 3): 1 * Y + 3 * X = Y + 3X
 * 3. (2, 1): 2 * Y + 1 * X = 2Y + X
 * 
 * We need to find the minimum of {5X, Y + 3X, 2Y + X}.
 * Given constraints: X < Y <= 2X.
 * Since Y <= 2X, buying a 4-pack is always more efficient or equal to buying two 2-packs.
 * Therefore, we should maximize the number of 4-packs used.
 * The combinations are limited to these three because we must reach exactly 10.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Calculate the three possible costs
        long long option1 = 5 * x;
        long long option2 = y + 3 * x;
        long long option3 = 2 * y + x;

        // Find the minimum
        long long min_cost = min({option1, option2, option3});

        cout << min_cost << "\n";
    }

    return 0;
}