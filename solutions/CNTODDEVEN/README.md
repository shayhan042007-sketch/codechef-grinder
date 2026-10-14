# [Count Odd Even Divisors (CNTODDEVEN)](https://www.codechef.com/problems/CNTODDEVEN)

- **Difficulty Rating**: 538
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to determine how many of its divisors are odd and how many are even. A divisor $d$ of $N$ is any integer such that $N$ is perfectly divisible by $d$ (i.e., $N \pmod d = 0$).

## Intuition & Mathematical Observation
Since the constraint on $N$ is very small ($1 \le N \le 100$), we do not need to perform prime factorization or complex number theory. We can simply iterate through every integer $i$ from $1$ to $N$:
1. Check if $i$ is a divisor of $N$ using the condition `N % i == 0`.
2. If it is a divisor, check its parity:
   - If `i % 2 != 0`, it is an **odd divisor**.
   - If `i % 2 == 0`, it is an **even divisor**.
3. Maintain two counters and increment them accordingly.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the input integer. Given $T \le 100$ and $N \le 100$, the total number of operations is approximately $10^4$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts and the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to find the count of odd divisors and even divisors.
 * Since N is small (1 <= N <= 100), we can iterate from 1 to N to find all divisors.
 * A divisor 'd' of N satisfies (N % d == 0).
 * If d is odd (d % 2 != 0), increment the odd count.
 * If d is even (d % 2 == 0), increment the even count.
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_count = 0;
    int even_count = 0;
    
    // Iterate through all numbers from 1 to N to find divisors
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            if (i % 2 != 0) {
                odd_count++;
            } else {
                even_count++;
            }
        }
    }
    
    cout << odd_count << " " << even_count << "\n";
}

int main() {
    // Fast I/O for performance
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