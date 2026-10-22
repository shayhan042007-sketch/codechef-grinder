#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Range Odd
 * Approach: Iterate from L to R, check if the number is odd (n % 2 != 0),
 * and print it if it is. Since the constraints are up to 10^6, a simple
 * linear scan is O(N) which is well within the time limit.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    if (!(cin >> L >> R)) return 0;

    bool first = true;
    for (long long i = L; i <= R; ++i) {
        if (i % 2 != 0) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}