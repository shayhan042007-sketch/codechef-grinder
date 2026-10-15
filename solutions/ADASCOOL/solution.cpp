#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M grid of students. Each student must move to an adjacent cell.
 * This is equivalent to finding a perfect matching in the grid graph.
 * A grid graph is a bipartite graph. A perfect matching exists if and only if
 * the total number of vertices (N * M) is even.
 * 
 * If N * M is even, it means at least one of N or M must be even.
 * If both N and M are odd, N * M is odd, and a perfect matching is impossible
 * because the number of black and white cells in a checkerboard coloring 
 * will differ by 1.
 * 
 * Therefore, the condition for "YES" is (N * M) % 2 == 0, which simplifies to:
 * (N is even) OR (M is even).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If the total number of cells is even, a perfect matching exists.
        // This happens if at least one dimension is even.
        if ((n * m) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}