# [Digit Sum Parities (DIGSMPAR)](https://www.codechef.com/problems/DIGSMPAR)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the smallest integer $X > N$ such that the parity of the sum of digits of $X$ is different from the parity of the sum of digits of $N$.

## Intuition & Mathematical Observation
The parity of the sum of digits of an integer $N$ is defined as `(sum of digits of N) % 2`. 

When we increment an integer $N$ to $N+1$, the sum of digits changes in a predictable way. Specifically, if $N$ does not end in a 9, the sum of digits increases by exactly 1, which flips the parity. If $N$ ends in one or more 9s, the sum of digits decreases significantly, but the parity will still flip or remain the same depending on the number of trailing 9s.

Because the parity of the digit sum changes very frequently (at most every 10 increments, and usually every 1 increment), we can simply perform a linear search starting from $N+1$. We check each subsequent integer until we find one whose digit sum parity differs from the parity of $N$. Given the constraints ($N \le 10^9$), this search will terminate almost immediately.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot K \cdot \log_{10}(N))$, where $T$ is the number of test cases, $K$ is the number of increments (which is a very small constant, $K \le 10$), and $\log_{10}(N)$ is the number of digits in $N$. This is highly efficient and well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current sum and parity.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N and need to find the smallest X > N such that
 * parity(digitSum(N)) != parity(digitSum(X)).
 * 
 * Since N < 10^9, the digit sum is at most 9 * 9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * In the worst case, we only need to check a few consecutive integers 
 * after N to find one with a different digit sum parity.
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    // Linear search for the smallest X > N with different parity
    while (true) {
        if ((getDigitSum(x) % 2) != targetParity) {
            cout << x << "\n";
            return;
        }
        x++;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```