# [Chef and Serves (CHSERVE)](https://www.codechef.com/problems/CHSERVE)

- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of table tennis, Chef and Cook take turns serving. The serve changes every $K$ points. Specifically, the first $K$ points are served by Chef, the next $K$ points by Cook, the next $K$ by Chef, and so on. Given the current scores of Chef ($P_1$) and Cook ($P_2$), determine whose turn it is to serve.

## Intuition & Mathematical Observation
The total number of points played so far is $S = P_1 + P_2$. Since the serve switches every $K$ points, we can determine the number of "serve cycles" that have been completed by calculating $S / K$ (using integer division).

- If the number of completed cycles is **even** (0, 2, 4, ...), it means we are currently in a block where Chef is serving.
- If the number of completed cycles is **odd** (1, 3, 5, ...), it means we are currently in a block where Cook is serving.

**Example Walkthrough:**
- If $P_1=1, P_2=3, K=2$: Total $S=4$. Cycles $= 4/2 = 2$. Since 2 is even, it is **CHEF**'s turn.
- If $P_1=0, P_2=3, K=2$: Total $S=3$. Cycles $= 3/2 = 1$. Since 1 is odd, it is **COOK**'s turn.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points scored is S = P1 + P2.
 * The serve changes every K points.
 * 
 * Number of completed K-point cycles = S / K (integer division).
 * If the number of completed cycles is even, it's Chef's turn.
 * If the number of completed cycles is odd, it's Cook's turn.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;
        
        long long total_points = p1 + p2;
        long long cycles = total_points / k;
        
        if (cycles % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }
    
    return 0;
}
```