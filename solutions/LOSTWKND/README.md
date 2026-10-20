# [Lost Weekends (LOSTWKND)](https://www.codechef.com/problems/LOSTWKND)

- **Difficulty Rating**: 1063
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef has 5 days of work to complete. For each day $i$ (from 1 to 5), he spends $A_i$ hours at the office. Each hour spent at the office is equivalent to $P$ hours of work. Chef has a total of 24 hours available each day. We need to determine if the total work required exceeds the total capacity of the 5 weekdays (120 hours). If the total work required is greater than 120 hours, Chef must work on the weekend; otherwise, he does not.

## Intuition & Mathematical Observation
The problem asks us to compare the total work required against the total available time in a 5-day work week.

1.  **Total Work Calculation**: For each day $i$, the work done is $A_i \times P$ hours. The total work for the week is:
    $$\text{Total Work} = (A_1 + A_2 + A_3 + A_4 + A_5) \times P$$
2.  **Total Capacity**: Since there are 5 days in a work week and each day has 24 hours, the total capacity is:
    $$\text{Total Capacity} = 5 \times 24 = 120 \text{ hours}$$
3.  **Decision Logic**:
    *   If $\text{Total Work} > 120$, output `"Yes"` (he needs the weekend).
    *   Otherwise, output `"No"`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of operations (summing 5 integers and one multiplication).
- **Space Complexity**: $O(1)$. We only use a few variables to store the input values and the running sum.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of home work.
 * Total work required in home hours = (A_1 + A_2 + A_3 + A_4 + A_5) * P.
 * Total available hours in 5 weekdays = 5 * 24 = 120 hours.
 * 
 * If the total work required exceeds 120 hours, Chef must work on the weekend.
 * Otherwise, he can finish within the 5 weekdays.
 */

void solve() {
    long long total_work_needed = 0;
    long long val;
    
    // Read the 5 days of work
    for (int i = 0; i < 5; ++i) {
        cin >> val;
        total_work_needed += val;
    }
    
    // Read P
    long long P;
    cin >> P;
    
    // Calculate total work in home hours
    total_work_needed *= P;
    
    // Total hours available in 5 weekdays (5 days * 24 hours/day)
    const long long total_hours_available = 120;
    
    // If total work needed is greater than available, he must work on weekends
    if (total_work_needed > total_hours_available) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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