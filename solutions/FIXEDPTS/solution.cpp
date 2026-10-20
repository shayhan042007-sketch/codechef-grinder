#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * A fixed point is P[i] = i.
 * If we choose K indices to be fixed points, we are left with (N - K) elements 
 * that must be deranged (i.e., none of them can be a fixed point).
 * 
 * A derangement of size M exists if and only if M != 1.
 * - If M = 0, there is 1 derangement (the empty set).
 * - If M = 1, there are 0 derangements (a single element must be a fixed point).
 * - If M >= 2, there is always at least one derangement.
 * 
 * Therefore, we can have exactly K fixed points if and only if (N - K) != 1.
 * This simplifies to:
 * - If N - K == 1, it is impossible (No).
 * - Otherwise, it is possible (Yes).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // The number of elements that are NOT fixed points is (n - k).
        // If n - k == 1, we have one element left that must be placed in its own position,
        // which would create an additional fixed point, making the total count K + 1.
        // Thus, n - k == 1 is the only impossible case.
        if (n - k == 1) {
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
        }
    }

    return 0;
}