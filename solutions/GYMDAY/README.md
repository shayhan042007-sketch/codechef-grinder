# [International Gym Day (GYMDAY)](https://www.codechef.com/problems/GYMDAY)

- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a gym membership priced at $X$ coins. He has a total budget of $Y$ coins. For every trial session he attends (up to $Y$ sessions), he spends 1 coin, but the membership price is reduced by $D\%$ per session attended. We need to find the minimum number of trial sessions $n$ such that Chef can afford the discounted membership price with his remaining budget. If it is impossible to afford the membership even after attending all $Y$ sessions, output -1.

## Intuition & Mathematical Observation
1. **Budget Constraint**: If Chef attends $n$ sessions, he spends $n$ coins. His remaining budget is $Y - n$.
2. **Discount Calculation**: The membership price is reduced by $n \times D\%$. The new price becomes $X \times (1 - \frac{n \times D}{100})$.
3. **Affordability Condition**: Chef can afford the membership if:
   $$(Y - n) \ge X \times \left(1 - \frac{n \times D}{100}\right)$$
4. **Avoiding Floating Point Errors**: To ensure precision, we multiply the entire inequality by 100:
   $$(Y - n) \times 100 \ge X \times (100 - n \times D)$$
5. **Search Strategy**: Since the constraints on $X$ and $Y$ are very small ($X, Y \le 50$), we can iterate through all possible values of $n$ from $0$ to $Y$. The first $n$ that satisfies the inequality is our answer. If we finish the loop without finding such an $n$, it is impossible.

## Complexity Analysis
- **Time Complexity**: $O(Y)$ per test case, where $Y$ is the budget. Given $Y \le 50$, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n be the number of trial sessions.
 * Cost of n sessions = n coins.
 * Remaining budget = Y - n.
 * Discount percentage = n * D %.
 * Discounted membership price = X * (1 - (n * D) / 100).
 * Chef can purchase if: (Y - n) >= X * (1 - (n * D) / 100).
 * 
 * Multiplying by 100 to avoid floating point issues:
 * 100 * (Y - n) >= X * (100 - n * D)
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // Check if he can afford it without any sessions
    if (Y >= X) {
        cout << 0 << "\n";
        return;
    }

    // Try increasing number of sessions from 1 to Y
    for (int n = 1; n <= Y; ++n) {
        // Remaining budget after n sessions
        int remaining_budget = Y - n;
        
        // Discounted price: X * (100 - n * D) / 100
        // To avoid float, check: remaining_budget * 100 >= X * (100 - n * D)
        if (remaining_budget * 100 >= X * (100 - n * D)) {
            cout << n << "\n";
            return;
        }
    }

    // If no n works, it's impossible
    cout << -1 << "\n";
}

int main() {
    // Fast I/O
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