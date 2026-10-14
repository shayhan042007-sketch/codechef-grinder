# [The Tom and Jerry Game! (EOEO)](https://www.codechef.com/problems/EOEO)

- **Difficulty Rating**: 1337
- **Solved in**: 1 attempt(s)

## Problem Summary
Tom starts with a number $TS$ and Jerry starts with a number $JS$ (where $1 \le JS < TS$). In each turn, both players divide their current numbers by 2 if they are even. The game ends when at least one of them becomes odd. Jerry wins if his number becomes odd while Tom's number remains even. We need to find the number of possible starting values for $JS$ such that Jerry wins.

## Intuition & Mathematical Observation
Let $TS = 2^k \cdot m$, where $m$ is an odd integer. 
The game mechanics dictate that we divide both numbers by 2 repeatedly until one becomes odd. Effectively, we are removing the common power of 2 from both numbers.

1. **Tom's Final State**: Since we divide $TS$ by $2^k$, Tom's number will always become $m$ (an odd number).
2. **Jerry's Final State**: Let $JS = 2^p \cdot n$, where $n$ is an odd integer. After dividing both by $2^{\min(k, p)}$, Jerry's number becomes $JS' = \frac{2^p \cdot n}{2^{\min(k, p)}}$.
3. **Winning Condition**: Jerry wins if his final number $JS'$ is even. This occurs if and only if $p > k$.

If $p > k$, then $JS$ must be a multiple of $2^{k+1}$. 
Therefore, the problem reduces to counting how many multiples of $2^{k+1}$ exist in the range $[1, TS-1]$. Since $TS$ is a multiple of $2^k$ but not $2^{k+1}$ (because $m$ is odd), the number of such multiples is simply:
$$\text{Count} = \lfloor \frac{TS}{2^{k+1}} \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(\log(TS))$ per test case. We perform a loop to find the highest power of 2 that divides $TS$, which takes logarithmic time relative to the value of $TS$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * The game proceeds by dividing both TS and JS by 2 as long as both are even.
 * This is equivalent to removing all factors of 2 from both numbers.
 * Jerry wins if his final number is even, which happens if JS has a higher 
 * power of 2 than TS.
 * 
 * We need to count how many JS in [1, TS] satisfy:
 * 1. JS is a multiple of 2^(k+1)
 * 2. JS < TS
 * 
 * The number of such values is floor(TS / 2^(k+1)).
 */

void solve() {
    long long ts;
    cin >> ts;

    // Find the power of 2 that divides TS (2^k)
    long long temp_ts = ts;
    long long power_of_2 = 1;
    while (temp_ts % 2 == 0) {
        power_of_2 *= 2;
        temp_ts /= 2;
    }

    // We need JS to be a multiple of (power_of_2 * 2)
    // such that JS < TS.
    long long divisor = power_of_2 * 2;
    long long ans = ts / divisor;

    cout << ans << "\n";
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