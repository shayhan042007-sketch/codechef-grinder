#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's total penalty = X + (P * 10)
 * Chefina's total penalty = Y + (Q * 10)
 * We need to compare these two values and output the winner.
 * Constraints are small (X, Y, P, Q <= 100), so standard integer types are sufficient.
 */

void solve() {
    long long X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    long long chef_penalty = X + (P * 10);
    long long chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << "\n";
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << "\n";
    } else {
        cout << "Draw" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}