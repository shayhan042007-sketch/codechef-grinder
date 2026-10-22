#include <iostream>

/**
 * Problem Analysis:
 * The "origin" of a number is its digital root.
 * The digital root of n is:
 * dr(n) = 1 + (n - 1) % 9
 * 
 * The sequence of digital roots for n = 1, 2, 3, ... is:
 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...
 * 
 * This is a periodic sequence with period 9.
 * The sum of one full period (1 to 9) is 45.
 * 
 * For a given N:
 * Number of full periods = N / 9
 * Remaining elements = N % 9
 * Total Sum = (full_periods * 45) + (sum of 1 to remainder)
 * 
 * Complexity: O(1) per test case, O(T) total.
 */

using namespace std;

void solve() {
    unsigned long long N;
    if (!(cin >> N)) return;

    unsigned long long full_periods = N / 9;
    unsigned long long remainder = N % 9;

    // Sum of full periods: full_periods * 45
    // Sum of remainder: remainder * (remainder + 1) / 2
    unsigned long long total_sum = (full_periods * 45) + (remainder * (remainder + 1) / 2);

    cout << total_sum << "\n";
}

int main() {
    // Optimize I/O operations for high-frequency test cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}