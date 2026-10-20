#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Multiple of 3
 * Given N, find the nearest multiple of 3.
 * 
 * Logic:
 * A number N is a multiple of 3 if N % 3 == 0.
 * If N % 3 == 0, the nearest multiple is N itself.
 * If N % 3 == 1, the multiples surrounding N are (N-1) and (N+2).
 *    Distance to (N-1) is 1, distance to (N+2) is 2. So N-1 is closer.
 * If N % 3 == 2, the multiples surrounding N are (N-2) and (N+1).
 *    Distance to (N-2) is 2, distance to (N+1) is 1. So N+1 is closer.
 * 
 * Since the problem states N is a positive integer (1 <= N <= 10),
 * we must ensure that for N=1, the result is 0 (as 0 is a multiple of 3).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long remainder = n % 3;

    if (remainder == 0) {
        cout << n << "\n";
    } else if (remainder == 1) {
        // For N=1, 1-1 = 0. 0 is a multiple of 3.
        cout << n - 1 << "\n";
    } else {
        // remainder == 2
        cout << n + 1 << "\n";
    }

    return 0;
}