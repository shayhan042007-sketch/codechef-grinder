#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare the distances of Alex (X1, Y1) and Bob (X2, Y2), we can compare
 * the squared distances to avoid floating point precision issues and the 
 * computational cost of sqrt().
 * 
 * Squared distance of Alex: D1^2 = X1^2 + Y1^2
 * Squared distance of Bob: D2^2 = X2^2 + Y2^2
 * 
 * If D1^2 > D2^2, Alex is farther.
 * If D2^2 > D1^2, Bob is farther.
 * If D1^2 == D2^2, they are at the same distance.
 * 
 * Constraints: -1000 <= X, Y <= 1000.
 * The maximum squared distance is 1000^2 + 1000^2 = 2,000,000.
 * This fits comfortably within a standard 32-bit integer, but using long long
 * is a good practice to prevent overflow in more complex scenarios.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long dist1_sq = x1 * x1 + y1 * y1;
        long long dist2_sq = x2 * x2 + y2 * y2;

        if (dist1_sq > dist2_sq) {
            cout << "ALEX" << "\n";
        } else if (dist2_sq > dist1_sq) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}