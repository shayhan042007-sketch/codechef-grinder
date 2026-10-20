# [Vaccine Production (VACCINE1)](https://www.codechef.com/problems/VACCINE1)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two vaccine manufacturing companies, A and B. Company A starts production on day $D_1$ and produces $V_1$ vaccines per day. Company B starts production on day $D_2$ and produces $V_2$ vaccines per day. We need to determine the earliest day $d$ such that the cumulative number of vaccines produced by both companies reaches or exceeds a target value $P$.

## Intuition & Mathematical Observation
Since the constraints on $D_1, D_2, V_1, V_2$ are small (up to 100) and $P$ is up to 1000, the total number of days required will not be excessively large. 

We can approach this using a **simulation strategy**:
1. Start from day 1 and increment the day counter one by one.
2. On each day, check if the current day is greater than or equal to the start day of each company ($D_1$ and $D_2$ respectively).
3. If a company has started, add its daily production rate ($V_1$ or $V_2$) to a running total.
4. Stop the loop as soon as the running total is greater than or equal to $P$.

Because the maximum possible day is well within a range that a simple loop can handle (even in the worst case, it won't exceed a few thousand iterations), this simulation is highly efficient and easy to implement.

## Complexity Analysis
- **Time Complexity**: $O(d)$, where $d$ is the number of days required to reach the target $P$. Given the constraints, $d$ is small (at most 2000), making the complexity effectively $O(1)$ relative to typical competitive programming limits.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the state of production.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two companies starting production on different days D1 and D2.
 * Company A produces V1 vaccines/day starting from day D1.
 * Company B produces V2 vaccines/day starting from day D2.
 * We need to find the smallest day 'd' such that the total vaccines produced >= P.
 * 
 * Since the constraints are small (D, V <= 100, P <= 1000), we can simulate 
 * day by day. A simple loop up to 2000 days is more than sufficient.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    int total_vaccines = 0;
    int day = 0;

    // Simulate day by day until total_vaccines >= P
    while (total_vaccines < P) {
        day++;
        
        // Check if Company A is producing on this day
        if (day >= D1) {
            total_vaccines += V1;
        }
        
        // Check if Company B is producing on this day
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}
```