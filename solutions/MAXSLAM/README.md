# [Maximum Slams (MAXSLAM)](https://www.codechef.com/problems/MAXSLAM)

- **Difficulty Rating**: 224
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef currently has $X$ Grand Slam titles. He aims to reach a total of at least 25 titles. Given that Chef wins 4 Grand Slam titles every year, calculate the minimum number of years required for Chef to reach or exceed the target of 25 titles.

## Intuition & Mathematical Observation
To find the number of years $Y$ required, we first determine the number of additional titles needed:
$$\text{Needed} = 25 - X$$

Since Chef wins 4 titles per year, we need to find the smallest integer $Y$ such that:
$$4 \times Y \geq \text{Needed}$$

This is equivalent to calculating the ceiling of the division:
$$Y = \lceil \frac{25 - X}{4} \rceil$$

In integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated using the formula `(a + b - 1) / b`. Thus, our formula becomes:
$$Y = \frac{(25 - X) + 3}{4}$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Chef needs at least 25 total wins.
 * Current wins = X.
 * Wins needed = 25 - X.
 * Each year, Chef wins 4 Grand Slams.
 * Let Y be the number of years.
 * We need 4 * Y >= 25 - X.
 * Therefore, Y = ceil((25 - X) / 4.0).
 * Using integer arithmetic, this is equivalent to (25 - X + 3) / 4.
 */

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long X;
    if (!(std::cin >> X)) return 0;
    
    long long needed = 25 - X;
    
    // Ceiling division of (needed / 4) is (needed + 3) / 4
    long long years = (needed + 3) / 4;
    
    std::cout << years << std::endl;
    
    return 0;
}
```