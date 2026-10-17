#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A win gives 3 points, a loss gives 0 points, and a draw gives 1 point.
 * Let w_a be the number of wins for team A, and d_a be the number of draws for team A.
 * Let w_b be the number of wins for team B, and d_b be the number of draws for team B.
 * 
 * Since every draw involves both teams, the number of draws for A must equal the number of draws for B.
 * Let D be the number of draws.
 * Score of A: X = 3 * w_a + D
 * Score of B: Y = 3 * w_b + D
 * 
 * We want to minimize D.
 * From the equations:
 * X % 3 = D % 3
 * Y % 3 = D % 3
 * 
 * This implies that D must be a non-negative integer such that D % 3 = X % 3 and D % 3 = Y % 3.
 * Since we want the minimum D, and we know that X = 3*w_a + D and Y = 3*w_b + D,
 * we can observe that D = X % 3 is the smallest non-negative value satisfying the condition.
 * 
 * Let's check:
 * If X = 1, Y = 1: X % 3 = 1, Y % 3 = 1. Min D = 1. (Correct)
 * If X = 3, Y = 0: X % 3 = 0, Y % 3 = 0. Min D = 0. (Correct)
 * If X = 11, Y = 5: 11 % 3 = 2, 5 % 3 = 2. Min D = 2. (Correct)
 * If X = 9, Y = 9: 9 % 3 = 0, 9 % 3 = 0. Min D = 0. (Correct)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The minimum number of draws is simply the remainder when the score is divided by 3.
        // Since X % 3 must equal Y % 3 for a valid scenario to exist, 
        // we can output either X % 3 or Y % 3.
        cout << (x % 3) << "\n";
    }

    return 0;
}