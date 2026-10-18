#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The lift has two constraints:
 * 1. Maximum number of people: 8
 * 2. Maximum weight capacity: 500 kg
 * 
 * Given X friends each weighing Y kg:
 * - Total weight = X * Y
 * - Condition 1: X <= 8
 * - Condition 2: X * Y <= 500
 * 
 * If both conditions are met, output YES, otherwise NO.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Check both constraints
        // Constraint 1: Number of people <= 8
        // Constraint 2: Total weight <= 500
        if (x <= 8 && (x * y) <= 500) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}