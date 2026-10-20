#include <iostream>
#include <algorithm>

/**
 * Problem: CLIPLX
 * RCB needs X points from Y matches.
 * Win = 2 pts, Tie = 1 pt, Loss = 0 pts.
 * Let W be the number of wins.
 * Points = 2*W + (number of ties).
 * To minimize W, we maximize ties. We can tie at most (Y - W) matches.
 * Total points = 2*W + (Y - W) = W + Y.
 * We need W + Y >= X, so W >= X - Y.
 * Since W must be at least 0, W = max(0, X - Y).
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        
        if (x <= y) {
            std::cout << 0 << "\n";
        } else {
            std::cout << (x - y) << "\n";
        }
    }

    return 0;
}