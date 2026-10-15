# [Which Division (WHICHDIV)](https://www.codechef.com/problems/WHICHDIV)

- **Difficulty Rating**: 867
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize a competitive programmer into one of three divisions based on their rating ($R$):
- **Division 1**: Rating $\ge 2000$
- **Division 2**: $1600 \le \text{Rating} < 2000$
- **Division 3**: Rating $< 1600$

Given the rating $R$, we need to output the corresponding division number (1, 2, or 3).

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the ranges are mutually exclusive and cover all possible values of $R$, we can use a simple `if-else if-else` structure:

1. First, check if $R \ge 2000$. If true, the user is in Division 1.
2. If the first condition fails, check if $R \ge 1600$. Since we already know $R < 2000$ (because the first check failed), this condition effectively captures the range $[1600, 1999]$, which corresponds to Division 2.
3. If both previous conditions fail, the rating must be less than 1600, placing the user in Division 3.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only store the rating variable and do not use any extra data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Which Division
 * Logic:
 * - Division 1: R >= 2000
 * - Division 2: 1600 <= R < 2000
 * - Division 3: R < 1600
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long r;
        cin >> r;
        
        if (r >= 2000) {
            cout << 1 << "\n";
        } else if (r >= 1600) {
            cout << 2 << "\n";
        } else {
            cout << 3 << "\n";
        }
    }
    
    return 0;
}
```