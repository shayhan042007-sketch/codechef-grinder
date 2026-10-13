#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob play a game where they pick numbers a and b (1 <= a, b <= 5).
 * Sum = a + b.
 * If Sum is odd, Alice wins.
 * If Sum is even, Bob wins.
 * 
 * Constraints:
 * T <= 1000
 * 1 <= a, b <= 5
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 * Space complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int sum = a + b;
        
        // Check if sum is odd or even
        if (sum % 2 != 0) {
            // Sum is odd, Alice wins
            cout << "Alice" << "\n";
        } else {
            // Sum is even, Bob wins
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}