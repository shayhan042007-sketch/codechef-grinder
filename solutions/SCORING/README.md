# [Scoring (SCORING)](https://www.codechef.com/problems/SCORING)

- **Difficulty Rating**: 569
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the difference between Alice's and Bob's scores ($A - B = X$) and the sum of their scores ($A + B = Y$), determine the individual scores of Alice ($A$) and Bob ($B$). It is guaranteed that a valid integer solution exists.

## Intuition & Mathematical Observation
This is a classic system of linear equations with two variables:
1. $A - B = X$
2. $A + B = Y$

To solve for $A$ and $B$:
* **Adding the equations**: $(A - B) + (A + B) = X + Y \implies 2A = X + Y \implies A = \frac{X + Y}{2}$
* **Subtracting the equations**: $(A + B) - (A - B) = Y - X \implies 2B = Y - X \implies B = \frac{Y - X}{2}$

Since the problem guarantees that a valid solution exists, $X+Y$ and $Y-X$ will always be even, ensuring that $A$ and $B$ are integers.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A be Alice's score and B be Bob's score.
 * We are given:
 * 1) A - B = X
 * 2) A + B = Y
 * 
 * Adding the two equations:
 * 2A = X + Y  => A = (X + Y) / 2
 * 
 * Subtracting the first from the second:
 * 2B = Y - X  => B = (Y - X) / 2
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate Alice and Bob's scores using the derived formulas
        long long alice = (x + y) / 2;
        long long bob = (y - x) / 2;
        
        cout << alice << " " << bob << "\n";
    }
    
    return 0;
}
```