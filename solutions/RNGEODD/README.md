# [Range Odd (RNGEODD)](https://www.codechef.com/problems/RNGEODD)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $L$ and $R$, the task is to print all odd integers in the range $[L, R]$ inclusive, separated by a single space.

## Intuition & Mathematical Observation
The problem asks us to traverse a range of integers and identify those that are not divisible by 2. 

1. **Linear Scan**: Since the constraints on $L$ and $R$ are relatively small (up to $10^6$), a simple loop iterating from $L$ to $R$ is efficient enough.
2. **Parity Check**: For each number $i$ in the range, we check if `i % 2 != 0`. If true, the number is odd and should be printed.
3. **Formatting**: To ensure the output is formatted correctly (space-separated without a trailing space), we use a boolean flag `first` to manage the spacing logic.

*Optimization Note:* While a linear scan is $O(N)$, one could also solve this in $O(1)$ by finding the first odd number $\ge L$ and incrementing by 2 until $R$ is reached. However, given the constraints, the linear approach is perfectly acceptable and highly readable.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N = R - L + 1$. We visit each number in the range exactly once. Given $R \le 10^6$, this performs well within the typical 1-second time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables for storage regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Range Odd
 * Approach: Iterate from L to R, check if the number is odd (n % 2 != 0),
 * and print it if it is. Since the constraints are up to 10^6, a simple
 * linear scan is O(N) which is well within the time limit.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    if (!(cin >> L >> R)) return 0;

    bool first = true;
    for (long long i = L; i <= R; ++i) {
        if (i % 2 != 0) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}
```