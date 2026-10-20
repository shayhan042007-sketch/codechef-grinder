# [Laddu (LADDU)](https://www.codechef.com/problems/LADDU)

- **Difficulty Rating**: 1241
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the maximum number of months a user can redeem their "Laddus" for, based on their activity history. Each activity (winning a contest, contributing, finding bugs, or hosting a contest) awards a specific number of Laddus. Depending on whether the user is from "INDIAN" or "NON_INDIAN", the redemption cost per month differs (200 for Indian, 400 for non-Indian).

## Intuition & Mathematical Observation
1. **Activity Scoring**: We process each activity string and update a running total (`total_laddus`).
    - `CONTEST_WON`: Base 300 + bonus `max(0, 20 - rank)`.
    - `TOP_CONTRIBUTOR`: 300.
    - `BUG_FOUND`: `severity` points.
    - `CONTEST_HOSTED`: 50.
2. **Redemption Logic**: Since we want the maximum number of months, we perform integer division of the `total_laddus` by the user's specific threshold (200 or 400).
3. **Data Types**: While the constraints are small enough for `int`, using `long long` for `total_laddus` is a safe practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of activities per test case. We iterate through each activity exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Calculate total laddus based on activity rules:
 *    - CONTEST_WON: 300 + max(0, 20 - rank)
 *    - TOP_CONTRIBUTOR: 300
 *    - BUG_FOUND: severity
 *    - CONTEST_HOSTED: 50
 * 2. Determine redemption threshold based on origin:
 *    - INDIAN: 200
 *    - NON_INDIAN: 400
 * 3. Calculate max months: total_laddus / threshold
 * 
 * Time Complexity: O(T * activities)
 * Space Complexity: O(1)
 */

void solve() {
    int activities;
    string origin;
    cin >> activities >> origin;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    cout << (total_laddus / threshold) << "\n";
}

int main() {
    // Fast I/O
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