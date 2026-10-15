#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to select exactly two items (i, j) where i != j.
 * Let the costs be A[i] and A[j].
 * Let the tastiness be B[i] and B[j].
 * The more expensive item (let's say A_max) gets a discount:
 * discount = min(A_max / 2, 100)
 * Final cost = (A[i] + A[j]) - discount
 * We need to maximize (B[i] + B[j]) such that Final cost <= K.
 * 
 * Constraints:
 * N <= 100, A_i, B_i, K <= 400.
 * O(N^2) is perfectly acceptable.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int max_tastiness = 0;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int cost_i = A[i];
            int cost_j = A[j];
            
            // Identify the more expensive item
            int expensive = max(cost_i, cost_j);
            int cheaper = min(cost_i, cost_j);
            
            // Calculate discount: 50% of expensive or 100, whichever is smaller
            int discount = min(expensive / 2, 100);
            
            // Total cost calculation
            int total_cost = (expensive + cheaper) - discount;
            
            if (total_cost <= K) {
                found = true;
                int current_tastiness = B[i] + B[j];
                if (current_tastiness > max_tastiness) {
                    max_tastiness = current_tastiness;
                }
            }
        }
    }

    if (!found) {
        cout << 0 << "\n";
    } else {
        cout << max_tastiness << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}