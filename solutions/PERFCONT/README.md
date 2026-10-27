# [A Balanced Contest (PERFCONT)](https://www.codechef.com/problems/PERFCONT)

- **Difficulty Rating**: 1184
- **Solved in**: 3 attempt(s)

## Problem Summary
The goal is to determine if a contest is "balanced" based on the number of participants who solved each problem. A contest is considered balanced if and only if:
1. There is **exactly one** "cakewalk" problem (solved by at least $P/2$ participants).
2. There are **exactly two** "hard" problems (solved by at most $P/10$ participants).

Given $N$ problems and the total number of participants $P$, we must categorize each problem based on the number of successful submissions and verify the conditions.

## Intuition & Mathematical Observation
- **Thresholds**: 
    - A problem is a "cakewalk" if `solved_by >= P / 2`.
    - A problem is "hard" if `solved_by <= P / 10`.
- **Data Types**: Since $P$ can be as large as $10^8$, the thresholds should be calculated using `long long` to prevent any potential overflow issues, although standard `int` would technically suffice for $10^8$.
- **Logic**: We iterate through the $N$ problems once. We maintain two counters: `cakewalk_count` and `hard_count`. After processing all problems, we check if `cakewalk_count == 1` and `hard_count == 2`.
- **Edge Cases**: Ensure that a problem cannot be both a cakewalk and a hard problem simultaneously (though given the constraints $P/2 > P/10$, this is naturally handled by the `if-else if` structure).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of problems. We perform a single pass over the input array.
- **Space Complexity**: $O(1)$, as we only store a few integer counters regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * - Cakewalk: solved_by >= P / 2
 * - Hard: solved_by <= P / 10
 * - Balanced: exactly 1 cakewalk AND exactly 2 hard problems.
 * 
 * Constraints:
 * - P <= 10^8, so use long long for thresholds.
 * - N <= 500, O(N) per test case is optimal.
 */

void solve() {
    int N;
    long long P;
    if (!(cin >> N >> P)) return;

    int cakewalk_count = 0;
    int hard_count = 0;

    long long cakewalk_threshold = P / 2;
    long long hard_threshold = P / 10;

    for (int i = 0; i < N; ++i) {
        long long solved_by;
        cin >> solved_by;

        if (solved_by >= cakewalk_threshold) {
            cakewalk_count++;
        } else if (solved_by <= hard_threshold) {
            hard_count++;
        }
    }

    if (cakewalk_count == 1 && hard_count == 2) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
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