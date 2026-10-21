#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: RATIO2
 * Goal: Find minimum operations (increment/decrement) to satisfy X >= 2Y or Y >= 2X.
 * Constraints: 2 <= X, Y <= 10.
 * Since the constraints are very small, we can use a brute-force approach or 
 * simple logic to check all possible target states.
 * 
 * Given the constraints are small, we can iterate through a reasonable range 
 * of possible values for X and Y and find the minimum operations.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // If condition already met
    if (X >= 2 * Y || Y >= 2 * X) {
        cout << 0 << "\n";
        return;
    }

    long long min_ops = 1e18;

    // Since X, Y <= 10, the target values won't be very far from the current values.
    // We can check a range of values around X and Y.
    // Let's check values from 0 to 30 (sufficient given constraints).
    for (long long i = 0; i <= 30; ++i) {
        for (long long j = 0; j <= 30; ++j) {
            if (i == 0 && j == 0) continue; // Problem states positive integers
            
            if (i >= 2 * j || j >= 2 * i) {
                long long ops = abs(X - i) + abs(Y - j);
                if (ops < min_ops) {
                    min_ops = ops;
                }
            }
        }
    }
    cout << min_ops << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}