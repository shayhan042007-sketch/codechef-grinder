# [Truth Teller And Liars 101 (TRUTHLIE)](https://www.codechef.com/problems/TRUTHLIE)

- **Difficulty Rating**: 1097
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given $N$ truth-tellers and $M$ liars. We need to determine if it is possible to select a group of exactly $X$ people such that in any subset of size $X$, the number of truth-tellers is strictly greater than the number of liars. If possible, find the smallest such $X$. If not, output -1.

## Intuition & Mathematical Observation
To ensure that the number of truth-tellers ($T$) is strictly greater than the number of liars ($L$) in a group of size $X$, we must satisfy the condition:
$$T > L$$
Since $T + L = X$, we can substitute $T = X - L$:
$$X - L > L \implies X > 2L$$

To guarantee this condition holds for *any* subset of size $X$ we might pick, we must consider the worst-case scenario: picking as many liars as possible. The maximum number of liars we can possibly include in a group of size $X$ is limited by the total number of liars available, $M$.

Thus, the condition becomes:
$$X > 2M$$
The smallest integer $X$ satisfying this is $X = 2M + 1$.

Finally, we must ensure that it is physically possible to form a group of size $X$ using the available people ($N$ truth-tellers and $M$ liars). Therefore, $X$ must be less than or equal to the total number of people:
$$X \le N + M$$

If $2M + 1 \le N + M$, the answer is $2M + 1$. Otherwise, it is impossible, and we output -1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to pick X people such that the number of truth-tellers (T) is 
 * strictly greater than the number of liars (L) in any subset of size X.
 * 
 * Let the subset have k truth-tellers and (X-k) liars.
 * We need k > X - k, which means 2k > X.
 * The worst case is picking the maximum possible number of liars, which is M.
 * If we pick X people, the minimum number of truth-tellers is max(0, X - M).
 * So we need 2 * (X - M) > X  => 2X - 2M > X => X > 2M.
 * The smallest integer X is 2M + 1.
 * We also must have X <= N + M.
 */

void solve() {
    int N, M;
    cin >> N >> M;

    int X = 2 * M + 1;
    // Check if it's possible to pick X people from the total pool N + M
    if (X <= N + M) {
        cout << X << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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