#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: SUNNYDAY
 * Chef goes to the picnic if X > 24.
 * Constraints: 1 <= T <= 100, 1 <= X <= 100.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Check if the temperature is strictly greater than 24
        if (x > 24) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}