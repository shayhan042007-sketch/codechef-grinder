# [Hello Equation (HLEQN)](https://www.codechef.com/problems/HLEQN)

- **Difficulty Rating**: 1315
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $X$, determine if there exist positive integers $a$ and $b$ ($a, b \ge 1$) such that the equation $2a + 2b + ab = X$ holds true.

## Intuition & Mathematical Observation
The equation $2a + 2b + ab = X$ can be solved using the technique of **Simon's Favorite Factoring Trick**. 

1. Start with the given equation:
   $ab + 2a + 2b = X$
2. Add 4 to both sides to make the expression factorable:
   $ab + 2a + 2b + 4 = X + 4$
3. Factor the left side:
   $(a + 2)(b + 2) = X + 4$

Let $A = a + 2$ and $B = b + 2$. Since the problem constraints state $a \ge 1$ and $b \ge 1$, it follows that $A \ge 3$ and $B \ge 3$. 

Therefore, the problem reduces to checking if $X + 4$ has any two factors $A$ and $B$ such that $A \cdot B = X + 4$, where both $A \ge 3$ and $B \ge 3$. We can iterate through all possible values of $A$ starting from 3 up to $\sqrt{X+4}$. If we find an $A$ that divides $X+4$ such that $B = (X+4)/A$ is also $\ge 3$, then a solution exists.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{X})$ per test case, as we only iterate up to the square root of $X+4$ to find divisors.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * 2a + 2b + ab = X
 * Add 4 to both sides:
 * ab + 2a + 2b + 4 = X + 4
 * (a + 2)(b + 2) = X + 4
 * 
 * Let A = a + 2, B = b + 2.
 * Since a >= 1 and b >= 1, we must have A >= 3 and B >= 3.
 * We need to find if there exist factors A and B of (X + 4) such that:
 * A * B = X + 4, where A >= 3 and B >= 3.
 * 
 * Complexity: O(sqrt(X)) per test case.
 */

void solve() {
    long long X;
    if (!(cin >> X)) return;
    
    long long target = X + 4;
    bool found = false;
    
    // We check divisors A of target.
    // If A is a divisor, B = target / A.
    // We need A >= 3 and B >= 3.
    for (long long A = 3; A * A <= target; ++A) {
        if (target % A == 0) {
            long long B = target / A;
            if (B >= 3) {
                found = true;
                break;
            }
        }
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```