# [Work Smarter, Not Harder (SMARTER)](https://www.codechef.com/problems/SMARTER)

- **Difficulty Rating**: 924
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum integer wait time $w$ that the hare can afford such that it still finishes the race before the tortoise. 
- The tortoise travels distance $L$ at speed $V_1$.
- The hare travels distance $L$ at speed $V_2$ but can wait for $w$ units of time before starting.
- We need to find the largest integer $w \ge 0$ such that:
  $$\text{Hare's Total Time} < \text{Tortoise's Total Time}$$

## Intuition & Mathematical Observation
1. **Time Calculation**: Since the tortoise and hare must cover distance $L$ at constant speeds $V_1$ and $V_2$, their travel times are $\lceil L/V_1 \rceil$ and $\lceil L/V_2 \rceil$ respectively. Using integer arithmetic, $\lceil a/b \rceil$ is equivalent to `(a + b - 1) / b`.
2. **Inequality Setup**:
   - Let $T_{tortoise} = \lceil L/V_1 \rceil$
   - Let $T_{hare\_run} = \lceil L/V_2 \rceil$
   - The condition is: $w + T_{hare\_run} < T_{tortoise}$
3. **Solving for $w$**:
   - Rearranging the inequality: $w < T_{tortoise} - T_{hare\_run}$
   - Since $w$ must be an integer, the maximum value is $w_{max} = T_{tortoise} - T_{hare\_run} - 1$.
4. **Edge Case**: If $T_{tortoise} - T_{hare\_run} - 1 < 0$, it means the hare cannot win even with a wait time of 0, so we output `-1`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and calculated times.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time (T_tortoise) = ceil(L / V1)
 * Hare time (T_hare) = w + ceil(L / V2)
 * 
 * Condition to win: T_hare < T_tortoise
 * w + ceil(L / V2) < ceil(L / V1)
 * w < ceil(L / V1) - ceil(L / V2)
 * 
 * Max integer w = ceil(L / V1) - ceil(L / V2) - 1
 */

void solve() {
    long long L, V1, V2;
    cin >> L >> V1 >> V2;

    // Calculate ceil(L / V1) using integer division
    long long t_tortoise = (L + V1 - 1) / V1;
    
    // Calculate ceil(L / V2) using integer division
    long long t_hare_run = (L + V2 - 1) / V2;

    // We need w < t_tortoise - t_hare_run
    long long max_w = t_tortoise - t_hare_run - 1;

    if (max_w < 0) {
        cout << -1 << "\n";
    } else {
        cout << max_w << "\n";
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