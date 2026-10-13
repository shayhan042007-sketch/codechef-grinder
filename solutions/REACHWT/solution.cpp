#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to reach exactly N kg using 1kg weights (cost 20) and 2kg weights (cost 30).
 * Let x be the number of 1kg weights and y be the number of 2kg weights.
 * We want to minimize Cost = 20x + 30y subject to x + 2y = N, where x, y >= 0.
 * 
 * From x + 2y = N, we get x = N - 2y.
 * Since x >= 0, we must have N - 2y >= 0, so 2y <= N, or y <= N/2.
 * Substituting x into the cost function:
 * Cost = 20(N - 2y) + 30y
 * Cost = 20N - 40y + 30y
 * Cost = 20N - 10y
 * 
 * To minimize the cost, we need to maximize y.
 * Since y must be an integer and y <= N/2, the maximum value for y is floor(N/2).
 * 
 * Substituting y = floor(N/2) into the cost function:
 * If N is even, y = N/2: Cost = 20N - 10(N/2) = 20N - 5N = 15N.
 * If N is odd, y = (N-1)/2: Cost = 20N - 10((N-1)/2) = 20N - 5(N-1) = 15N + 5.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Using the derived formula:
        // If N is even, cost is 15 * N
        // If N is odd, cost is 15 * N + 5
        long long cost;
        if (n % 2 == 0) {
            cost = 15 * n;
        } else {
            cost = 15 * n + 5;
        }
        
        cout << cost << "\n";
    }
    
    return 0;
}