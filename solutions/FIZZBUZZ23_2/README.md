# [Survival Time (FIZZBUZZ23_2)](https://www.codechef.com/problems/FIZZBUZZ23_2)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
A family of 5 members needs $X$ buns per person per day. They currently have $N$ buns in stock and have enough food to survive for $D$ additional days without any buns. We need to calculate the total number of days the family can survive, considering both the buns they have and the $D$ days of extra food.

## Intuition & Mathematical Observation
1. **Daily Consumption**: Since there are 5 family members and each requires $X$ buns, the total daily consumption is $5 \times X$.
2. **Buns Sustainability**: The number of days the current stock of $N$ buns will last is given by the integer division $N / (5 \times X)$. 
   - If $N < (5 \times X)$, the result is $0$, which is correct because they don't have enough buns to last even a single full day.
3. **Total Survival Time**: The family survives for the number of days the buns last plus the $D$ days they have extra food.
   - Formula: $\text{Total Days} = \lfloor \frac{N}{5 \times X} \rfloor + D$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Buns required per day = 5 * X.
 * Number of days the buns last = N / (5 * X) (integer division).
 * Total survival days = (Days buns last) + D.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns required by the family of 5 per day
        long long daily_requirement = 5 * x;

        // Number of days the buns can sustain the family
        // If n < daily_requirement, this evaluates to 0
        long long days_with_food = n / daily_requirement;

        // Total survival time
        long long total_days = days_with_food + d;

        cout << total_days << "\n";
    }

    return 0;
}
```