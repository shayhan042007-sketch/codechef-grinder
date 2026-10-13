# [Chef and Contest (CHEFCONTEST)](https://www.codechef.com/problems/CHEFCONTEST)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Chefina participated in a contest. Chef solved a problem in $X$ minutes and incurred $P$ wrong submissions. Chefina solved a problem in $Y$ minutes and incurred $Q$ wrong submissions. Each wrong submission adds 10 minutes to the total penalty. We need to determine who has the lower penalty (the winner) or if it is a draw.

## Intuition & Mathematical Observation
The total penalty for a participant is calculated as:
$$\text{Total Penalty} = \text{Time Taken} + (\text{Wrong Submissions} \times 10)$$

1. Calculate Chef's penalty: $S_1 = X + (P \times 10)$
2. Calculate Chefina's penalty: $S_2 = Y + (Q \times 10)$
3. Compare $S_1$ and $S_2$:
   - If $S_1 < S_2$, Chef wins.
   - If $S_2 < S_1$, Chefina wins.
   - If $S_1 = S_2$, it is a Draw.

Since the constraints are small ($X, Y, P, Q \le 100$), standard integer arithmetic is perfectly safe from overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated penalties.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's total penalty = X + (P * 10)
 * Chefina's total penalty = Y + (Q * 10)
 * We need to compare these two values and output the winner.
 * Constraints are small (X, Y, P, Q <= 100), so standard integer types are sufficient.
 */

void solve() {
    long long X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    long long chef_penalty = X + (P * 10);
    long long chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << "\n";
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << "\n";
    } else {
        cout << "Draw" << "\n";
    }
}

int main() {
    // Fast I/O setup
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