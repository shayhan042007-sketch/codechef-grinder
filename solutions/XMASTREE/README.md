# [Christmas Trees (XMASTREE)](https://www.codechef.com/problems/XMASTREE)

- **Difficulty Rating**: 300
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef purchases $N$ Christmas trees at a cost of $A$ rupees each. Later, Chef sells $M$ of these trees at a price of $B$ rupees each. The goal is to calculate the total profit made from these transactions. Note that profit is defined as the total revenue minus the total cost.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation:
1. **Total Cost**: Since Chef buys $N$ trees at $A$ rupees each, the total expenditure is $N \times A$.
2. **Total Revenue**: Since Chef sells $M$ trees at $B$ rupees each, the total income is $M \times B$.
3. **Profit**: The profit is simply the difference between the total revenue and the total cost:
   $$\text{Profit} = (M \times B) - (N \times A)$$

Given the constraints ($N, M \le 100$ and $A, B \le 1000$), the maximum possible value is well within the range of a standard 32-bit integer, though `long long` is used here for safety and good practice.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees each (Total cost = N * A).
 * Chef sold M trees for B rupees each (Total revenue = M * B).
 * Profit = Total Revenue - Total Cost = (M * B) - (N * A).
 * 
 * Constraints:
 * 1 <= M <= N <= 100
 * 100 <= A <= B <= 1000
 * The result fits within a standard 32-bit integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, m, b;
    if (cin >> n >> a >> m >> b) {
        long long total_cost = n * a;
        long long total_revenue = m * b;
        long long profit = total_revenue - total_cost;
        
        cout << profit << endl;
    }
    
    return 0;
}
```