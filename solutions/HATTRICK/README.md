# [Hattrick (HATTRICK)](https://www.codechef.com/problems/HATTRICK)

- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket over consisting of 6 balls, a "hattrick" is defined as taking 3 consecutive wickets. Given the results of 6 balls (where 'W' represents a wicket and any other character represents a non-wicket), determine if a hattrick occurred during the over.

## Intuition & Mathematical Observation
Since the input size is fixed at 6 balls, we are looking for a pattern of three consecutive 'W's. 
- Let the balls be represented by an array $S = [s_0, s_1, s_2, s_3, s_4, s_5]$.
- A hattrick occurs if there exists an index $i$ (where $0 \le i \le 3$) such that $s_i = s_{i+1} = s_{i+2} = 'W'$.
- We can iterate through all possible starting positions of a 3-ball window and check if all elements in that window are 'W'. If we find such a window, we immediately conclude "YES"; otherwise, if we exhaust all windows without finding one, we conclude "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the number of balls is fixed at 6, the loop runs a constant number of times (4 iterations), making the execution time independent of input size.
- **Space Complexity**: $O(1)$. We only store 6 characters/strings, which requires a constant amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HATTRICK
 * A hattrick is defined as 3 consecutive wickets ('W') in an over of 6 balls.
 * We need to check if any sequence of 3 consecutive balls contains 'W'.
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check all possible windows of size 3: (0,1,2), (1,2,3), (2,3,4), (3,4,5)
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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