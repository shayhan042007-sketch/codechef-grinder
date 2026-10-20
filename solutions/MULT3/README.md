# [Multiple of 3 (MULT3)](https://www.codechef.com/problems/MULT3)

- **Difficulty Rating**: 297
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a positive integer $N$ ($1 \le N \le 10$), find the nearest multiple of 3 to $N$. If there are two multiples of 3 equidistant from $N$, choose the smaller one.

## Intuition & Mathematical Observation
To find the nearest multiple of 3, we analyze the remainder of $N$ when divided by 3 ($N \pmod 3$):

1.  **If $N \pmod 3 = 0$**: $N$ is already a multiple of 3. The nearest multiple is $N$ itself.
2.  **If $N \pmod 3 = 1$**: The surrounding multiples are $(N-1)$ and $(N+2)$. 
    *   The distance to $(N-1)$ is 1.
    *   The distance to $(N+2)$ is 2.
    *   Since $1 < 2$, the nearest multiple is $N-1$.
3.  **If $N \pmod 3 = 2$**: The surrounding multiples are $(N-2)$ and $(N+1)$.
    *   The distance to $(N-2)$ is 2.
    *   The distance to $(N+1)$ is 1.
    *   Since $1 < 2$, the nearest multiple is $N+1$.

*Note: For $N=1$, $N-1 = 0$. Since 0 is a multiple of 3 ($3 \times 0 = 0$), this logic holds.*

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Multiple of 3
 * Given N, find the nearest multiple of 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long remainder = n % 3;

    if (remainder == 0) {
        // N is already a multiple of 3
        cout << n << "\n";
    } else if (remainder == 1) {
        // N-1 is closer than N+2
        cout << n - 1 << "\n";
    } else {
        // remainder == 2, N+1 is closer than N-2
        cout << n + 1 << "\n";
    }

    return 0;
}
```