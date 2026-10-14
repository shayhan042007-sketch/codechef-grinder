# [Sharing Cookies (SHARING)](https://www.codechef.com/problems/SHARING)

- **Difficulty Rating**: 232
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has $A$ cookies and Bob has $B$ cookies, where $A > B$. We need to determine if Alice can give a specific number of cookies $x$ to Bob such that they both end up with the same number of cookies. If it is possible, output the value of $x$; otherwise, output $-1$.

## Intuition & Mathematical Observation
To make the number of cookies equal, we set up the following equation where $x$ is the number of cookies transferred:
$$A - x = B + x$$

Rearranging the terms to solve for $x$:
$$A - B = 2x$$
$$x = \frac{A - B}{2}$$

From this equation, we can derive two necessary conditions for a valid solution:
1. **Parity**: Since $x$ must be an integer, $(A - B)$ must be divisible by $2$. If $(A - B) \pmod 2 \neq 0$, it is impossible to equalize the cookies, and we output $-1$.
2. **Positivity**: Since $A > B$, the value $(A - B)$ is always positive, ensuring $x > 0$.

If $(A - B)$ is even, the result is simply $(A - B) / 2$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    
    // Read input until EOF
    while (cin >> A >> B) {
        // Check if the difference is even
        if ((A - B) % 2 == 0) {
            cout << (A - B) / 2 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```