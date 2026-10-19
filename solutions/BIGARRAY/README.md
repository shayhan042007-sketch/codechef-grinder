# [Obtain the Sum (BIGARRAY)](https://www.codechef.com/problems/BIGARRAY)

- **Difficulty Rating**: 1368
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$, we consider the sequence of integers from $1$ to $N$. We are told that one element $x$ was removed from this sequence, and the sum of the remaining elements is $S$. Our task is to find the value of $x$. If no such $x$ exists (i.e., $x$ is not in the range $[1, N]$), we should output $-1$.

## Intuition & Mathematical Observation
The sum of the first $N$ natural numbers is given by the arithmetic series formula:
$$\text{TotalSum} = \frac{N \times (N + 1)}{2}$$

If we remove one element $x$ from this sequence, the new sum $S$ is:
$$S = \text{TotalSum} - x$$

Rearranging this equation to solve for $x$:
$$x = \text{TotalSum} - S$$

**Key Considerations:**
1. **Constraints**: $N$ can be up to $10^9$. Calculating $N \times (N+1)$ results in approximately $10^{18}$, which fits within a 64-bit integer (`long long`), but intermediate calculations might overflow if not handled carefully. Using `__int128_t` is a safe practice to prevent overflow during the multiplication.
2. **Validation**: After calculating $x$, we must verify that $1 \le x \le N$. If $x$ falls outside this range, it implies the given $S$ is invalid for the sequence of length $N$, and we output $-1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated sum.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * TotalSum = N * (N + 1) / 2
 * We need: TotalSum - x = S
 * Therefore: x = TotalSum - S
 * 
 * Constraints:
 * N <= 10^9, S <= 10^18.
 * TotalSum can be up to ~5 * 10^17.
 * Using __int128_t for the calculation of TotalSum ensures no overflow occurs
 * during the intermediate multiplication (n * (n + 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n_in, s_in;
        cin >> n_in >> s_in;

        // Use __int128 to prevent overflow during n * (n + 1)
        unsigned __int128 n = (unsigned __int128)n_in;
        unsigned __int128 s = (unsigned __int128)s_in;
        unsigned __int128 total_sum = (n * (n + 1)) / 2;

        // Check if total_sum > s to avoid negative results before checking range
        if (total_sum > s) {
            unsigned __int128 x = total_sum - s;
            if (x >= 1 && x <= n) {
                cout << (long long)x << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```