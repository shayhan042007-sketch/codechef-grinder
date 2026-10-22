# [The Rating Dilemma (RATING)](https://www.codechef.com/problems/RATING)

- **Difficulty Rating**: 909
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given an integer $S$, which represents the sum of two ratings $X$ and $Y$ (i.e., $X + Y = S$). We are given the constraint that $Y$ must be a negative integer ($Y < 0$). Our goal is to find the values of $X$ and $Y$ such that the product $X \cdot Y$ is maximized.

## Intuition & Mathematical Observation
We need to maximize the product $P = X \cdot Y$ subject to:
1. $X + Y = S$
2. $Y < 0$

From the first equation, we can express $Y$ as $Y = S - X$. Substituting this into the product equation:
$P = X(S - X) = SX - X^2$

This is a downward-opening parabola. To maximize $P$, we look at the constraints. Since $Y < 0$, it follows that $S - X < 0$, which implies $X > S$. 

Because the function $f(X) = SX - X^2$ is strictly decreasing for $X > S/2$, and we are constrained to $X > S$, the product is maximized when $X$ is as small as possible. The smallest integer $X$ greater than $S$ is $X = S + 1$.

Substituting $X = S + 1$ back into the equation for $Y$:
$Y = S - (S + 1) = -1$

Thus, the maximum product is:
$P = (S + 1) \cdot (-1) = -(S + 1)$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a simple arithmetic operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to maximize X * Y subject to X + Y = S, X > 0, Y < 0.
 * Y = S - X. Since Y < 0, S - X < 0 => X > S.
 * Product P = X(S - X) = SX - X^2.
 * This is a downward parabola with vertex at X = S/2.
 * For X > S, the function is strictly decreasing.
 * To maximize the product, we need the smallest possible X > S.
 * Given integer constraints, the smallest X is S + 1.
 * Then Y = S - (S + 1) = -1.
 * Product = (S + 1) * (-1) = -(S + 1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long S;
        cin >> S;
        // The result is derived as -(S + 1)
        cout << -(S + 1) << "\n";
    }
    return 0;
}
```