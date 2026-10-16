# [Far from origin (FARFROMO)](https://www.codechef.com/problems/FARFROMO)

- **Difficulty Rating**: 750
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the coordinates of two points, Alex at $(X_1, Y_1)$ and Bob at $(X_2, Y_2)$, determine who is farther from the origin $(0, 0)$. If Alex is farther, output "ALEX"; if Bob is farther, output "BOB"; if they are at the same distance, output "EQUAL".

## Intuition & Mathematical Observation
The distance of a point $(x, y)$ from the origin $(0, 0)$ is defined by the Euclidean distance formula:
$$d = \sqrt{x^2 + y^2}$$

To compare the distances of Alex and Bob, we need to compare $\sqrt{X_1^2 + Y_1^2}$ and $\sqrt{X_2^2 + Y_2^2}$. Since the square root function is monotonically increasing for non-negative values, we can compare the squared distances instead:
$$D_1^2 = X_1^2 + Y_1^2$$
$$D_2^2 = X_2^2 + Y_2^2$$

**Why use squared distances?**
1. **Precision**: Calculating square roots often involves floating-point numbers, which can lead to precision errors. Comparing integers (squared distances) is exact.
2. **Efficiency**: Calculating a square root is computationally more expensive than simple multiplication and addition.

Given the constraints $-1000 \le X, Y \le 1000$, the maximum squared distance is $1000^2 + 1000^2 = 2,000,000$, which fits well within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations for each input, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coordinates and squared distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare the distances of Alex (X1, Y1) and Bob (X2, Y2), we can compare
 * the squared distances to avoid floating point precision issues and the 
 * computational cost of sqrt().
 * 
 * Squared distance of Alex: D1^2 = X1^2 + Y1^2
 * Squared distance of Bob: D2^2 = X2^2 + Y2^2
 * 
 * If D1^2 > D2^2, Alex is farther.
 * If D2^2 > D1^2, Bob is farther.
 * If D1^2 == D2^2, they are at the same distance.
 * 
 * Constraints: -1000 <= X, Y <= 1000.
 * The maximum squared distance is 1000^2 + 1000^2 = 2,000,000.
 * This fits comfortably within a standard 32-bit integer, but using long long
 * is a good practice to prevent overflow in more complex scenarios.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long dist1_sq = x1 * x1 + y1 * y1;
        long long dist2_sq = x2 * x2 + y2 * y2;

        if (dist1_sq > dist2_sq) {
            cout << "ALEX" << "\n";
        } else if (dist2_sq > dist1_sq) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}
```