#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N positive odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N positive odd numbers is given by the formula:
 * Sum_N = N^2.
 * 
 * Let x be the number that appears K times.
 * The array consists of all N odd numbers (summing to N^2) plus (K-1) extra copies of x.
 * Therefore, the total sum S is:
 * S = N^2 - x + (K * x)
 * S = N^2 + x * (K - 1)
 * 
 * Rearranging to solve for x:
 * x * (K - 1) = S - N^2
 * x = (S - N^2) / (K - 1)
 * 
 * Since the problem guarantees a valid solution exists, this formula will always
 * yield the correct integer x.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, s;
        cin >> n >> k >> s;

        // Calculate N^2
        long long n_squared = n * n;

        // Calculate the difference S - N^2
        long long diff = s - n_squared;

        // Calculate x = (S - N^2) / (K - 1)
        long long x = diff / (k - 1);

        cout << x << "\n";
    }

    return 0;
}