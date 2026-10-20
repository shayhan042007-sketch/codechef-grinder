#include <iostream>
#include <cmath>

/**
 * Problem: Interesting Match
 * The problem asks to check if the absolute difference between two integers X and Y
 * is at most 2.
 * 
 * Constraints: 0 <= X, Y <= 10.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y;
    // Read X and Y directly as per the problem input format
    if (std::cin >> x >> y) {
        // Calculate absolute difference
        int diff = std::abs(x - y);

        // Check if the difference is at most 2
        if (diff <= 2) {
            std::cout << "Interesting" << std::endl;
        } else {
            std::cout << "Boring" << std::endl;
        }
    }

    return 0;
}