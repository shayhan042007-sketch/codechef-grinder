# [Chef And Salary Pay (HCAGMAM1)](https://www.codechef.com/problems/HCAGMAM1)

- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef works for 30 days. For each day, we are given a string of length 30 consisting of '0's (absent) and '1's (present). 
- Chef earns $X$ amount for every day he is present.
- Chef earns an additional bonus of $Y$ for every day in his **longest consecutive streak** of working days.
- The goal is to calculate the total salary earned by Chef at the end of the 30-day period.

## Intuition & Mathematical Observation
To calculate the total salary, we need two distinct values:
1. **Total Working Days**: This is simply the count of all '1's in the string.
2. **Longest Consecutive Streak**: This is the maximum number of '1's appearing consecutively. 

**Algorithm:**
- Iterate through the string once.
- Maintain a counter for the current streak of '1's. Whenever we encounter a '0', compare the current streak with the maximum streak found so far, update the maximum if necessary, and reset the current streak to zero.
- Keep a running total of all '1's encountered.
- After the loop, perform one final check to update the maximum streak (in case the string ends with a streak of '1's).
- The final salary is calculated as: `(Total Working Days * X) + (Longest Streak * Y)`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N=30$. Since $N$ is constant and small, this is effectively $O(1)$ per test case. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(N)$ to store the input string, which is $O(1)$ given the fixed constraint of 30 days.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef And Salary Pay
 * Approach:
 * 1. Calculate the total number of working days (count of '1's).
 * 2. Calculate the longest streak of consecutive '1's.
 * 3. Salary = (Total '1's * X) + (Longest Streak * Y).
 * 4. Since the string length is fixed at 30, a simple linear scan is O(N) per test case,
 *    which is well within the time limit for 10^4 test cases.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    string s;
    cin >> s;

    long long total_working_days = 0;
    long long max_streak = 0;
    long long current_streak = 0;

    for (char c : s) {
        if (c == '1') {
            total_working_days++;
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 0;
        }
    }
    // Final check in case the string ends with a streak
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }

    long long salary = (total_working_days * X) + (max_streak * Y);
    cout << salary << "\n";
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