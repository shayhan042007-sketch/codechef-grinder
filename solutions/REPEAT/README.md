# [Odd Repeat (REPEAT)](https://www.codechef.com/problems/REPEAT)

- **Difficulty Rating**: 1218
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array of length $N + K - 1$ containing the first $N$ positive odd numbers. However, one specific odd number $x$ is repeated $K$ times instead of once. Given the total sum $S$ of the array, the value of $N$, and the frequency $K$, we need to identify the value of $x$.

## Intuition & Mathematical Observation
1. **Sum of Odd Numbers**: The first $N$ positive odd numbers are $1, 3, 5, \dots, (2N-1)$. The sum of the first $N$ odd numbers is a well-known mathematical property:
   $$\sum_{i=1}^{N} (2i - 1) = N^2$$

2. **Formulating the Equation**:
   - Let the original set of $N$ odd numbers sum to $N^2$.
   - In the modified array, the number $x$ appears $K$ times instead of once.
   - This means we have added $(K-1)$ extra instances of $x$ to the original sum.
   - Therefore, the total sum $S$ can be expressed as:
     $$S = N^2 + (K - 1) \cdot x$$

3. **Solving for $x$**:
   - Rearranging the equation to isolate $x$:
     $$S - N^2 = x \cdot (K - 1)$$
     $$x = \frac{S - N^2}{K - 1}$$

Since the problem guarantees that a valid solution exists, this formula will always yield the correct integer $x$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N positive odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N positive odd numbers is given by the formula:
 * Sum_N = N^2.
 * 
 * Let x be the number that appears K times.
 * The array consists of all N odd numbers (summing to N^2) plus (K-1) extra copies of x.
 * Therefore, the total sum S is:
 * S = N^2 - x + (K * x)
 * S = N^2 + x * (K - 1)
 * 
 * Rearranging to solve for x:
 * x * (K - 1) = S - N^2
 * x = (S - N^2) / (K - 1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, s;
        cin >> n >> k >> s;

        // Calculate N^2
        long long n_squared = n * n;

        // Calculate the difference S - N^2
        long long diff = s - n_squared;

        // Calculate x = (S - N^2) / (K - 1)
        long long x = diff / (k - 1);

        cout << x << "\n";
    }

    return 0;
}
```