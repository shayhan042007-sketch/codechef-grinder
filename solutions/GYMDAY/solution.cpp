#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n be the number of trial sessions.
 * Cost of n sessions = n coins.
 * Remaining budget = Y - n.
 * Discount percentage = n * D %.
 * Discounted membership price = X * (1 - (n * D) / 100).
 * Chef can purchase if: (Y - n) >= X * (1 - (n * D) / 100).
 * 
 * Multiplying by 100 to avoid floating point issues:
 * 100 * (Y - n) >= X * (100 - n * D)
 * 
 * Constraints:
 * X, Y <= 50.
 * Since n cannot exceed Y (as he pays 1 coin per session), 
 * n ranges from 0 to Y.
 * Given the small constraints, a simple linear search from 0 to Y is optimal.
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // Check if he can afford it without any sessions
    if (Y >= X) {
        cout << 0 << "\n";
        return;
    }

    // Try increasing number of sessions from 1 to Y
    for (int n = 1; n <= Y; ++n) {
        // Remaining budget after n sessions
        int remaining_budget = Y - n;
        
        // Discounted price: X * (100 - n * D) / 100
        // To avoid float, check: remaining_budget * 100 >= X * (100 - n * D)
        if (remaining_budget * 100 >= X * (100 - n * D)) {
            cout << n << "\n";
            return;
        }
    }

    // If no n works, it's impossible
    cout << -1 << "\n";
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