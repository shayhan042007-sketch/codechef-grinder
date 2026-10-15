# [New-Pro Coder (SPC2025)](https://www.codechef.com/problems/SPC2025)

- **Difficulty Rating**: 467
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to classify a coder based on their performance. Given $N$ (the total number of lines of code written) and $M$ (the number of lines containing errors), we need to determine if the coder is a "NEWBIE" or a "PRO". The classification rule is:
- If the number of error lines $M$ is at least half of the total lines $N$ ($M \ge N/2$), the coder is a **NEWBIE**.
- Otherwise, the coder is a **PRO**.

## Intuition & Mathematical Observation
The condition given is $M \ge \frac{N}{2}$. 

To avoid potential precision issues associated with floating-point division (or the need to cast to `double`), we can algebraically manipulate the inequality by multiplying both sides by 2:
$$2 \times M \ge N$$

This allows us to perform the check using simple integer arithmetic, which is both faster and safer in competitive programming environments.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a single constant-time comparison.
- **Space Complexity**: $O(1)$, as we only store two integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * M >= N / 2  <=>  2 * M >= N
 * 
 * Constraints:
 * 1 <= N, M <= 1000
 * The values fit comfortably within standard integer types.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    // Read the total lines (N) and error lines (M)
    if (!(cin >> N >> M)) return 0;

    // Logic: If errors (M) are at least half of total lines (N), he is a NEWBIE.
    // Condition: M >= N / 2.0
    // Equivalent to: 2 * M >= N
    if (2 * M >= N) {
        cout << "NEWBIE" << "\n";
    } else {
        cout << "PRO" << "\n";
    }

    return 0;
}
```