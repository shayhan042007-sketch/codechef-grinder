#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points scored is S = P1 + P2.
 * The serve changes every K points.
 * 
 * - Points 0 to K-1: Chef serves (0 // K = 0)
 * - Points K to 2K-1: Cook serves (1 // K = 0, but wait...)
 * 
 * Let's trace:
 * Total points S.
 * Number of completed K-point cycles = S / K (integer division).
 * If the number of completed cycles is even, it's Chef's turn.
 * If the number of completed cycles is odd, it's Cook's turn.
 * 
 * Example 1: P1=1, P2=3, K=2. S = 4. 4 / 2 = 2 (even) -> CHEF. Correct.
 * Example 2: P1=0, P2=3, K=2. S = 3. 3 / 2 = 1 (odd) -> COOK. Correct.
 * Example 3: P1=34, P2=55, K=2. S = 89. 89 / 2 = 44 (even) -> CHEF. Correct.
 * 
 * Complexity:
 * Time: O(1) per test case, O(T) total.
 * Space: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;
        
        long long total_points = p1 + p2;
        long long cycles = total_points / k;
        
        if (cycles % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }
    
    return 0;
}