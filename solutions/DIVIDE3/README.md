# [Divide into 3 (DIVIDE3)](https://www.codechef.com/problems/DIVIDE3)

- **Difficulty Rating**: 350
- **Solved in**: 2 attempt(s)

## Problem Summary
Given $N$ toffees, we need to divide them among 3 friends such that the difference between the maximum and minimum number of toffees received by any friend is minimized. We need to output this minimum difference.

## Intuition & Mathematical Observation
Let the number of toffees given to the three friends be $a, b,$ and $c$, where $a + b + c = N$. We want to minimize the value of $\max(a, b, c) - \min(a, b, c)$.

By distributing the toffees as evenly as possible (using the quotient and remainder of $N/3$):

1.  **If $N$ is divisible by 3 ($N \pmod 3 = 0$):**
    We can give exactly $N/3$ to each friend.
    - $a = N/3, b = N/3, c = N/3$
    - $\max = N/3, \min = N/3$
    - **Difference = 0**

2.  **If $N \pmod 3 = 1$:**
    We can give $N/3$ to two friends and $N/3 + 1$ to the third.
    - $a = N/3, b = N/3, c = N/3 + 1$
    - $\max = N/3 + 1, \min = N/3$
    - **Difference = 1**

3.  **If $N \pmod 3 = 2$:**
    We can give $N/3$ to one friend and $N/3 + 1$ to the other two.
    - $a = N/3, b = N/3 + 1, c = N/3 + 1$
    - $\max = N/3 + 1, \min = N/3$
    - **Difference = 1**

**Conclusion:** If $N$ is a multiple of 3, the answer is 0; otherwise, the answer is 1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a simple constant-time modulo operation.
- **Space Complexity**: $O(1)$ as we only use a single variable to store the input.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * We have N toffees to be divided among 3 friends.
 * We want to minimize (max(a, b, c) - min(a, b, c)) where a + b + c = N.
 * 
 * If N % 3 == 0, we can distribute equally (N/3, N/3, N/3), diff = 0.
 * If N % 3 != 0, we distribute as evenly as possible, diff = 1.
 */

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (std::cin >> n) {
        if (n % 3 == 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
    
    return 0;
}
```