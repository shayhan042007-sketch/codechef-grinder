# [Cooler (COOLER7)](https://www.codechef.com/problems/COOLER7)

- **Difficulty Rating**: 555
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total time required to cool a substance from an initial temperature $N$ to a target temperature $M$. The rule provided is that to decrease the temperature by 1 degree (from $T$ to $T-1$), it takes $T$ minutes. We need to find the sum of time taken for each 1-degree drop until the target $M$ is reached.

## Intuition & Mathematical Observation
To cool the substance from $N$ to $M$, we perform a series of steps:
1. $N \to N-1$ takes $N$ minutes.
2. $N-1 \to N-2$ takes $N-1$ minutes.
3. ...
4. $M+1 \to M$ takes $M+1$ minutes.

The total time is the sum of the arithmetic progression: $N + (N-1) + (N-2) + \dots + (M+1)$.

Using the formula for the sum of an arithmetic series:
$$\text{Sum} = \frac{\text{Number of terms} \times (\text{First term} + \text{Last term})}{2}$$

- **Number of terms**: $N - M$
- **First term**: $N$
- **Last term**: $M + 1$

Thus, the total time is:
$$\text{Total Time} = \frac{(N - M) \times (N + M + 1)}{2}$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation is performed using a constant-time mathematical formula.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To drop the temperature from T to T-1, it takes T minutes.
 * To go from N to M, we need to perform the drop (N-M) times.
 * The sequence of times taken is:
 * N -> N-1: N minutes
 * N-1 -> N-2: N-1 minutes
 * ...
 * M+1 -> M: M+1 minutes
 * 
 * Total time = N + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic progression sum.
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * First term = N
 * Last term = M + 1
 * Total time = (N - M) * (N + M + 1) / 2
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Using the arithmetic series sum formula:
        // Sum = (n - m) * (n + m + 1) / 2
        // Since n and m are small (up to 40), this fits in a standard integer,
        // but long long is used for safety.
        long long total_time = (n - m) * (n + m + 1) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}
```