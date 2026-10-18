# [Yoga Class (YOGACLASS)](https://www.codechef.com/problems/YOGACLASS)

- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ hours available for yoga classes. There are two types of sessions:
1. **Type 1**: Lasts 1 hour and earns $X$ coins.
2. **Type 2**: Lasts 2 hours and earns $Y$ coins.

The goal is to maximize the total earnings by choosing an optimal combination of these sessions such that the total duration does not exceed $N$ hours.

## Intuition & Mathematical Observation
To maximize earnings, we need to evaluate the most efficient way to spend every 2-hour block of time. 

1. **Comparing Options**: For any 2-hour window, we have two choices:
   - Take one Type 2 session (earning $Y$).
   - Take two Type 1 sessions (earning $2 \times X$).
   - Therefore, the maximum earnings for any 2-hour block is `max(Y, 2 * X)`.

2. **Handling Remaining Time**: 
   - We can fit `N / 2` blocks of 2 hours into the total time $N$.
   - If $N$ is odd, there will be 1 hour remaining after filling the 2-hour blocks. This remaining hour must be filled with a Type 1 session (earning $X$).

3. **Final Formula**:
   - `Total Earnings = (N / 2) * max(Y, 2 * X) + (N % 2) * X`

This approach ensures we always pick the most profitable session type for every available hour.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize earnings for N hours.
 * For every 2-hour block, we choose between one Type 2 session (Y) 
 * or two Type 1 sessions (2 * X).
 * Remaining 1 hour (if N is odd) is filled with a Type 1 session (X).
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Calculate the best way to earn for a 2-hour duration
        long long earnings_for_two_hours = max(y, 2 * x);
        
        // Calculate total: (number of 2-hour blocks * best 2-hour earnings) 
        // + (remaining 1 hour * X if N is odd)
        long long total_earnings = (n / 2) * earnings_for_two_hours + (n % 2) * x;
        
        cout << total_earnings << "\n";
    }

    return 0;
}
```