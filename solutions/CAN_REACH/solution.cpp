#include <iostream>

using namespace std;

/**
 * Problem: CAN_REACH
 * Logic:
 * To reach (x, y) from (0, 0) using steps of size K, both x and y must be 
 * divisible by K. If x % K == 0 and y % K == 0, it is possible to reach 
 * the destination by taking (x/K) steps in the x-direction and (y/K) 
 * steps in the y-direction.
 */

void solve() {
    int x, y, K;
    if (!(cin >> x >> y >> K)) return;
    
    // Check if both coordinates are divisible by K
    if (x % K == 0 && y % K == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}