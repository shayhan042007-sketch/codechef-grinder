# [Interesting Match (INTMTCH)](https://www.codechef.com/problems/INTMTCH)

- **Difficulty Rating**: 240
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a match is "Interesting" or "Boring" based on the scores of two players, $X$ and $Y$. A match is considered "Interesting" if the absolute difference between the two scores is at most 2 (i.e., $|X - Y| \le 2$). Otherwise, it is considered "Boring".

## Intuition & Mathematical Observation
The core of the problem is a simple conditional check. Given two integers $X$ and $Y$:
1. Calculate the absolute difference: `abs(X - Y)`.
2. Compare this value against the threshold of 2.
3. If the difference is $\le 2$, output "Interesting".
4. If the difference is $> 2$, output "Boring".

Since the constraints are very small ($0 \le X, Y \le 10$), this approach is highly efficient and avoids any potential overflow issues.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic and comparison operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the two integer variables.

## Solution Code

```cpp
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
```