#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to maximize X * Y subject to X + Y = S, X > 0, Y < 0.
 * Y = S - X. Since Y < 0, S - X < 0 => X > S.
 * Product P = X(S - X) = SX - X^2.
 * This is a downward parabola with vertex at X = S/2.
 * For X > S, the function is strictly decreasing.
 * To maximize the product, we need the smallest possible X > S.
 * Given integer constraints, the smallest X is S + 1.
 * Then Y = S - (S + 1) = -1.
 * Product = (S + 1) * (-1) = -(S + 1).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long S;
        cin >> S;
        cout << -(S + 1) << "\n";
    }
    return 0;
}