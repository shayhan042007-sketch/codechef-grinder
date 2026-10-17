# [Change Please (CHANGE_PLZ)](https://www.codechef.com/problems/CHANGE_PLZ)

- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an amount $X$ that you owe for a ride. You pay with a 100-dollar bill. The driver needs to return the change, which is $(100 - X)$. However, the driver only carries 10-dollar bills. You need to calculate how much money the driver will return to you, given that they can only return the largest multiple of 10 that is less than or equal to the total change due.

## Intuition & Mathematical Observation
1. **Calculate Change Due**: The total change the driver owes you is $R = 100 - X$.
2. **Constraint**: The driver can only return multiples of 10.
3. **Mathematical Logic**: To find the largest multiple of 10 less than or equal to $R$, we can use integer division. In C++, dividing an integer by 10 automatically truncates the decimal part (effectively performing a `floor` operation for positive numbers).
4. **Formula**: By calculating `(R / 10) * 10`, we strip away the remainder (the units digit) and keep only the tens place, which gives us the correct amount to be returned.

**Example Walkthrough:**
- If $X = 66$, then $R = 100 - 66 = 34$.
- `34 / 10` results in `3`.
- `3 * 10` results in `30`.
- The driver returns 30 dollars.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, making the per-test-case complexity $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You owe X dollars. You pay 100 dollars.
 * The change due is (100 - X) dollars.
 * The driver only has 10 dollar bills.
 * The driver can only return multiples of 10 that are <= (100 - X).
 * 
 * Let R = 100 - X be the amount to be returned.
 * The driver returns floor(R / 10) * 10.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change due
        int change_due = 100 - x;
        
        // The driver returns the largest multiple of 10 <= change_due
        // Integer division in C++ automatically performs floor for positive numbers
        int result = (change_due / 10) * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}
```