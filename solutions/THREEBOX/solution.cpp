#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes with sizes A, B, C and a bag capacity D.
 * Constraints: 1 <= A <= B <= C <= D <= 100.
 * 
 * Logic:
 * 1. If A + B + C <= D, we can fit all three in 1 bag.
 * 2. If A + B + C > D, we check if we can fit two boxes in one bag.
 *    Since A <= B <= C, the largest possible pairs are (A+B), (A+C), or (B+C).
 *    - If A + B + C > D, we definitely need at least 2 bags.
 *    - If A + C <= D, we can put (A+C) in one bag and B in another (2 bags).
 *    - If A + B <= D, we can put (A+B) in one bag and C in another (2 bags).
 *    - If even the smallest pair (A+B) > D, we need 3 bags.
 * 
 * Simplified logic:
 * - If A + B + C <= D: return 1
 * - Else if A + B <= D or A + C <= D: return 2
 * - Else: return 3
 */

void solve() {
    int A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return;

    if (A + B + C <= D) {
        cout << 1 << "\n";
    } else if (A + B <= D || A + C <= D) {
        // Note: B + C is always >= A + C, so if A+C > D, B+C is definitely > D.
        // We only need to check if any pair fits.
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
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