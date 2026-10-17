# [Pizza Party (PIZZAPARTY)](https://www.codechef.com/problems/PIZZAPARTY)

- **Difficulty Rating**: 238
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef is hosting a party. There are $A$ friends (boys) and $B$ girls invited. Including Chef himself, there are $A+1$ boys in total. Each boy consumes 4 slices of pizza, and each girl consumes 3 slices. Given that each pizza contains 8 slices, calculate the minimum number of pizzas required to ensure everyone gets enough to eat.

## Intuition & Mathematical Observation
1. **Total Consumption**: 
   - Total boys = $A + 1$
   - Total girls = $B$
   - Total slices required = $(A + 1) \times 4 + (B \times 3)$
2. **Pizza Calculation**:
   - Since each pizza provides 8 slices, we need to divide the total slices by 8.
   - Because we cannot order a fraction of a pizza, we must round up to the nearest whole number if there is a remainder.
   - This is a classic **ceiling division** problem. In integer arithmetic, the ceiling of $X/Y$ can be calculated as `(X + Y - 1) / Y`.
   - Therefore, the formula is: `(total_slices + 7) / 8`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Chef is a boy. Total boys = A + 1.
 * - Total girls = B.
 * - Each boy eats 4 slices, each girl eats 3 slices.
 * - Total slices needed = (A + 1) * 4 + (B * 3).
 * - Each pizza has 8 slices.
 * - Number of pizzas needed = ceil(Total slices / 8).
 * - Integer ceiling division: (total_slices + 7) / 8.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read A and B directly as per the problem description
    if (cin >> A >> B) {
        long long total_boys = A + 1;
        long long total_girls = B;
        
        long long total_slices = (total_boys * 4) + (total_girls * 3);
        
        // Calculate ceiling division: (total_slices + 8 - 1) / 8
        long long pizzas_needed = (total_slices + 7) / 8;
        
        cout << pizzas_needed << endl;
    }

    return 0;
}
```