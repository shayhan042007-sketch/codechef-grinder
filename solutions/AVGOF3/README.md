# [Average of Three (AVGOF3)](https://www.codechef.com/problems/AVGOF3)

- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we need to find three **distinct** positive integers $A_1, A_2, A_3$ such that their arithmetic mean is exactly $X$. That is:
$$\frac{A_1 + A_2 + A_3}{3} = X$$
This simplifies to the condition:
$$A_1 + A_2 + A_3 = 3X$$

## Intuition & Mathematical Observation
To satisfy the equation $A_1 + A_2 + A_3 = 3X$, we can choose three integers centered around $X$. A simple and effective approach is to pick the integers immediately preceding, equal to, and succeeding $X$:
- $A_1 = X - 1$
- $A_2 = X$
- $A_3 = X + 1$

**Verification:**
1. **Sum:** $(X - 1) + X + (X + 1) = 3X$.
2. **Mean:** $3X / 3 = X$.
3. **Distinctness:** Since $X-1 < X < X+1$, the three numbers are always distinct.
4. **Constraints:** Given $2 \le X \le 100$, the smallest value is $X=2$. For $X=2$, our set is $\{1, 2, 3\}$. All values are $\ge 1$, satisfying the problem constraints.

This construction works for all valid inputs provided in the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations and output the result. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * We can choose three integers centered around X.
 * Let A1 = X - 1, A2 = X, A3 = X + 1.
 * Sum = (X - 1) + X + (X + 1) = 3X.
 * Mean = 3X / 3 = X.
 * 
 * Constraints:
 * 1 <= A1, A2, A3 <= 1000
 * 2 <= X <= 100
 * 
 * If X = 2:
 * A1 = 2 - 1 = 1
 * A2 = 2
 * A3 = 2 + 1 = 3
 * 1, 2, 3 are distinct and >= 1. This works.
 * 
 * For any X >= 2, X-1, X, X+1 will always be distinct and >= 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Output three distinct integers with mean X
        // Using X-1, X, X+1 satisfies the condition for all X >= 2
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}
```