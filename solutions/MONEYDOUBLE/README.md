# [Money Double (MONEYDOUBLE)](https://www.codechef.com/problems/MONEYDOUBLE)

- **Difficulty Rating**: 784
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with an initial amount of $X$ rupees and has $Y$ years. Each year, Chef can choose one of two operations:
1. **Add 1000**: $X = X + 1000$
2. **Double**: $X = X \times 2$

The goal is to maximize the final amount of money after $Y$ years.

## Intuition & Mathematical Observation
To maximize the final amount, we need to decide at each step whether to add 1000 or double the current amount. 

Comparing the two operations:
- If we add 1000 then double: $(X + 1000) \times 2 = 2X + 2000$
- If we double then add 1000: $(X \times 2) + 1000 = 2X + 1000$

Since $2X + 2000 > 2X + 1000$, it is always mathematically superior to perform the addition before the multiplication. However, because the number of years $Y$ is very small ($Y \le 10$), we can simply use a **Greedy Approach**. At each of the $Y$ steps, we compare the result of adding 1000 versus doubling the current amount and choose the option that yields the larger value for the next step.

## Complexity Analysis
- **Time Complexity**: $O(Y)$ per test case. Since $Y \le 10$, this is effectively $O(1)$ constant time per test case.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * At each year, we compare (X + 1000) and (X * 2).
 * We greedily pick the larger value to ensure we maximize the 
 * potential for future growth.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    for (int i = 0; i < Y; ++i) {
        long long add_option = X + 1000;
        long long double_option = X * 2;
        
        // Greedily choose the operation that results in more money
        if (add_option > double_option) {
            X = add_option;
        } else {
            X = double_option;
        }
    }
    cout << X << "\n";
}

int main() {
    // Fast I/O for performance
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