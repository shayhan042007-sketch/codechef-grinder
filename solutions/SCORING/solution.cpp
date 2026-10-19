#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A be Alice's score and B be Bob's score.
 * We are given:
 * 1) A - B = X
 * 2) A + B = Y
 * 
 * Adding the two equations:
 * (A - B) + (A + B) = X + Y
 * 2A = X + Y
 * A = (X + Y) / 2
 * 
 * Subtracting the first from the second:
 * (A + B) - (A - B) = Y - X
 * 2B = Y - X
 * B = (Y - X) / 2
 * 
 * Since the problem guarantees a valid solution exists, (X + Y) and (Y - X) 
 * will always be even and non-negative.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate Alice and Bob's scores using the derived formulas
        long long alice = (x + y) / 2;
        long long bob = (y - x) / 2;
        
        cout << alice << " " << bob << "\n";
    }
    
    return 0;
}