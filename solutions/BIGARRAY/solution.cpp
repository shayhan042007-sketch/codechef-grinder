#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * TotalSum = N * (N + 1) / 2
 * We need: TotalSum - x = S
 * Therefore: x = TotalSum - S
 * 
 * Constraints:
 * N <= 10^9, S <= 10^18.
 * TotalSum can be up to ~5 * 10^17.
 * Using __int128_t for the calculation of TotalSum ensures no overflow occurs
 * during the intermediate multiplication (n * (n + 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n_in, s_in;
        cin >> n_in >> s_in;

        // Use __int128 to prevent overflow during n * (n + 1)
        unsigned __int128 n = (unsigned __int128)n_in;
        unsigned __int128 s = (unsigned __int128)s_in;
        unsigned __int128 total_sum = (n * (n + 1)) / 2;

        // Check if total_sum > s to avoid negative results before checking range
        if (total_sum > s) {
            unsigned __int128 x = total_sum - s;
            if (x >= 1 && x <= n) {
                cout << (long long)x << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}