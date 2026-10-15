# [Sunny Day (SUNNYDAY)](https://www.codechef.com/problems/SUNNYDAY)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef decides to go for a picnic if and only if the temperature $X$ is strictly greater than 24 degrees Celsius. Given $T$ test cases, each containing an integer $X$, determine whether Chef will go for the picnic or not.

## Intuition & Mathematical Observation
The problem defines a simple conditional logic:
- If $X > 24$, the output should be `YES`.
- Otherwise (if $X \le 24$), the output should be `NO`.

Since the constraints are small ($1 \le X \le 100$) and the number of test cases is manageable ($1 \le T \le 100$), a direct `if-else` statement inside a loop is the most efficient approach.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant time $O(1)$ check for each test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: SUNNYDAY
 * Chef goes to the picnic if X > 24.
 * Constraints: 1 <= T <= 100, 1 <= X <= 100.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Check if the temperature is strictly greater than 24
        if (x > 24) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```