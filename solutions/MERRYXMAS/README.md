# [Merry Christmas! (MERRYXMAS)](https://www.codechef.com/problems/MERRYXMAS)

- **Difficulty Rating**: 454
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has three activities to perform with durations of 1, 2, and 4 hours respectively. Given a total available time $X$ hours, the goal is to determine the maximum number of activities Chef can complete.

## Intuition & Mathematical Observation
To maximize the number of activities performed, we should prioritize the activities with the shortest durations. This is a classic **Greedy Algorithm** approach:

1.  **Sort the durations**: The durations are already given as 1, 2, and 4.
2.  **Greedy Selection**: 
    *   First, attempt to complete the 1-hour activity. If $X \ge 1$, we perform it and subtract 1 from $X$.
    *   Next, attempt to complete the 2-hour activity. If the remaining $X \ge 2$, we perform it and subtract 2 from $X$.
    *   Finally, attempt to complete the 4-hour activity. If the remaining $X \ge 4$, we perform it and subtract 4 from $X$.

By always picking the smallest available duration, we ensure that we leave as much time as possible for subsequent activities, thereby maximizing the total count.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the number of activities is fixed (3), resulting in a constant number of operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the time and the count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three activities with durations: 1, 2, and 4 hours.
 * To maximize the number of activities, we should always pick the shortest 
 * available activities first (Greedy approach).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    int count = 0;
    
    // Try to perform the 1-hour activity
    if (X >= 1) {
        count++;
        X -= 1;
    }
    
    // Try to perform the 2-hour activity
    if (X >= 2) {
        count++;
        X -= 2;
    }
    
    // Try to perform the 4-hour activity
    if (X >= 4) {
        count++;
        X -= 4;
    }

    cout << count << "\n";

    return 0;
}
```