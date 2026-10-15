#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Which Division
 * Logic:
 * - Division 1: R >= 2000
 * - Division 2: 1600 <= R < 2000
 * - Division 3: R < 1600
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long r;
        cin >> r;
        
        if (r >= 2000) {
            cout << 1 << "\n";
        } else if (r >= 1600) {
            cout << 2 << "\n";
        } else {
            cout << 3 << "\n";
        }
    }
    
    return 0;
}