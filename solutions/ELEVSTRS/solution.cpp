#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Stairs:
 *    - Distance = N * sqrt(2)
 *    - Velocity = V1
 *    - Time_stairs = (N * sqrt(2)) / V1
 * 
 * 2. Elevator:
 *    - The elevator starts at ground, goes to N (distance N), then back to ground (distance N).
 *    - Total distance for elevator = 2 * N
 *    - Velocity = V2
 *    - Time_elevator = (2 * N) / V2
 * 
 * Comparison:
 * We need to compare (N * sqrt(2)) / V1 vs (2 * N) / V2.
 * To avoid floating point precision issues, we can square both sides:
 * (N^2 * 2) / V1^2 vs (4 * N^2) / V2^2
 * Dividing both sides by N^2 (since N >= 1):
 * 2 / V1^2 vs 4 / V2^2
 * 2 * V2^2 vs 4 * V1^2
 * V2^2 vs 2 * V1^2
 * 
 * If V2^2 < 2 * V1^2, then Time_elevator > Time_stairs, so Stairs are faster.
 * If V2^2 > 2 * V1^2, then Time_elevator < Time_stairs, so Elevator is faster.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, v1, v2;
        cin >> n >> v1 >> v2;

        // Using the derived inequality:
        // Time_stairs = (n * sqrt(2)) / v1
        // Time_elevator = (2 * n) / v2
        // Elevator is faster if (2 * n) / v2 < (n * sqrt(2)) / v1
        // 2 / v2 < sqrt(2) / v1
        // 2 * v1 < v2 * sqrt(2)
        // Squaring both sides: 4 * v1^2 < 2 * v2^2
        // 2 * v1^2 < v2^2
        
        long long stairs_val = 2 * v1 * v1;
        long long elevator_val = v2 * v2;

        if (elevator_val < stairs_val) {
            cout << "Stairs" << "\n";
        } else {
            cout << "Elevator" << "\n";
        }
    }

    return 0;
}