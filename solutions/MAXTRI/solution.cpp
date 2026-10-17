#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have sticks of lengths 1, 2, ..., N.
 * We want to choose three sticks A, B, C such that they form a non-degenerate triangle.
 * The condition for a non-degenerate triangle is:
 * 1. A + B > C
 * 2. A + C > B
 * 3. B + C > A
 * Assuming A <= B <= C, this simplifies to A + B > C.
 * To maximize the perimeter A + B + C, we should pick the largest possible values.
 * Let C = N. To satisfy A + B > N, we should pick the largest possible values for A and B.
 * The largest values less than N are N-1 and N-2.
 * Checking the condition: (N-1) + (N-2) > N
 * 2N - 3 > N
 * N > 3
 * 
 * If N = 3:
 * Sticks are 1, 2, 3. 1 + 2 = 3, which is not > 3. No triangle possible.
 * If N = 4:
 * Sticks are 1, 2, 3, 4. 3 + 2 > 4 (5 > 4). Perimeter = 4 + 3 + 2 = 9.
 * If N > 3:
 * We can always pick N, N-1, and N-2.
 * Perimeter = N + (N-1) + (N-2) = 3N - 3.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        if (n < 4) {
            cout << -1 << "\n";
        } else {
            // The maximum perimeter is formed by the three largest sticks: N, N-1, N-2
            // Perimeter = N + (N-1) + (N-2) = 3N - 3
            long long result = 3 * n - 3;
            cout << result << "\n";
        }
    }

    return 0;
}