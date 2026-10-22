# [Origin (OG)](https://www.codechef.com/problems/OG)

- **Difficulty Rating**: 1309
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to calculate the sum of the "origins" of all integers from $1$ to $N$. The "origin" of a number is defined as its **digital root**. The digital root of a positive integer is the value obtained by repeatedly summing its digits until a single-digit number remains.

## Intuition & Mathematical Observation
The digital root of a number $n$ follows a repeating pattern of length 9:
- For $n=1, 2, 3, 4, 5, 6, 7, 8, 9$, the digital roots are $1, 2, 3, 4, 5, 6, 7, 8, 9$.
- For $n=10$, the digital root is $1+0=1$.
- For $n=11$, the digital root is $1+1=2$.

The sequence of digital roots is periodic: $1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, \dots$

To find the sum of digital roots from $1$ to $N$:
1. **Full Periods**: There are $N / 9$ full cycles of the sequence $(1, 2, \dots, 9)$. The sum of one cycle is $45$.
2. **Remainder**: There are $N \% 9$ elements remaining after the full cycles. These elements correspond to the sequence $1, 2, \dots, (N \% 9)$. The sum of these is the sum of the first $k$ integers, calculated as $\frac{k(k+1)}{2}$.

**Total Sum Formula**:
$$\text{Total Sum} = \left( \lfloor N/9 \rfloor \times 45 \right) + \frac{(N\%9) \times (N\%9 + 1)}{2}$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * The "origin" of a number is its digital root.
 * The digital root of n is:
 * dr(n) = 1 + (n - 1) % 9
 * 
 * The sequence of digital roots for n = 1, 2, 3, ... is:
 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...
 * 
 * This is a periodic sequence with period 9.
 * The sum of one full period (1 to 9) is 45.
 * 
 * For a given N:
 * Number of full periods = N / 9
 * Remaining elements = N % 9
 * Total Sum = (full_periods * 45) + (sum of 1 to remainder)
 */

using namespace std;

void solve() {
    unsigned long long N;
    if (!(cin >> N)) return;

    unsigned long long full_periods = N / 9;
    unsigned long long remainder = N % 9;

    // Sum of full periods: full_periods * 45
    // Sum of remainder: remainder * (remainder + 1) / 2
    unsigned long long total_sum = (full_periods * 45) + (remainder * (remainder + 1) / 2);

    cout << total_sum << "\n";
}

int main() {
    // Optimize I/O operations for high-frequency test cases
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