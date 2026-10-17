# [Chess Win (CHESSWIN)](https://www.codechef.com/problems/CHESSWIN)

- **Difficulty Rating**: 236
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the current scores of two players, $A$ and $B$ (where $A < B$), determine the minimum number of additional matches $N$ one must win to ensure that the final score of the first player becomes strictly greater than the second player's score.

## Intuition & Mathematical Observation
The goal is to reach a state where the first player's score is greater than the second player's score. 
Let the number of additional matches won be $N$. The new score for the first player will be $A + N$, while the second player's score remains $B$.

We require:
$$A + N > B$$

Rearranging the inequality to solve for $N$:
$$N > B - A$$

Since $N$ must be an integer, the smallest integer greater than $(B - A)$ is $(B - A) + 1$. 

**Example Verification:**
- If $A=0, B=1$: $N > 1 - 0 \implies N > 1$. The minimum integer is $2$.
- If $A=2, B=4$: $N > 4 - 2 \implies N > 2$. The minimum integer is $3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic calculation regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Current score is A : B, where A < B.
 * We want to play N more matches such that we can end up with a score (A + N) : B
 * where (A + N) > B.
 * 
 * To minimize N, we assume we win all N matches.
 * So, A + N > B
 * N > B - A
 * Since N must be an integer, the minimum N is (B - A) + 1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    if (cin >> A >> B) {
        // Calculate the difference and add 1 to exceed the current score B
        int diff = B - A;
        int result = diff + 1;
        cout << result << "\n";
    }

    return 0;
}
```