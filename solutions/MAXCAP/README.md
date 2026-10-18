# [Maximum Capacity (MAXCAP)](https://www.codechef.com/problems/MAXCAP)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
A lift has a maximum capacity of **8 people** and a maximum weight limit of **500 kg**. Given $X$ friends, each weighing $Y$ kg, determine if they can all fit in the lift simultaneously without exceeding either constraint.

## Intuition & Mathematical Observation
The problem imposes two independent constraints that must be satisfied simultaneously:
1. **Capacity Constraint**: The number of people $X$ must be less than or equal to 8 ($X \le 8$).
2. **Weight Constraint**: The total weight of the group, calculated as $X \times Y$, must be less than or equal to 500 ($X \times Y \le 500$).

If both conditions evaluate to true, the output should be `YES`. If either condition is violated, the output should be `NO`. Since the constraints on $X$ and $Y$ are small, standard integer types are sufficient, though `long long` is used for safety.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not allocate any extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The lift has two constraints:
 * 1. Maximum number of people: 8
 * 2. Maximum weight capacity: 500 kg
 * 
 * Given X friends each weighing Y kg:
 * - Total weight = X * Y
 * - Condition 1: X <= 8
 * - Condition 2: X * Y <= 500
 * 
 * If both conditions are met, output YES, otherwise NO.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Check both constraints
        // Constraint 1: Number of people <= 8
        // Constraint 2: Total weight <= 500
        if (x <= 8 && (x * y) <= 500) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```