# [Swapping Marks Digits (SWMA)](https://www.codechef.com/problems/SWMA)

- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each have a 2-digit score ($A$ and $B$ respectively), where neither score contains the digit '0'. Before comparing their scores, Alice is allowed to reverse the digits of her score, Bob's score, both, or neither. We need to determine if it is possible for Alice's final score to be strictly greater than Bob's final score after applying any of these four combinations of reversals.

## Intuition & Mathematical Observation
Since the numbers are always 2-digit integers, reversing a number $N = 10x + y$ simply results in $N_{rev} = 10y + x$. 

There are only four possible scenarios to check for the condition $A_{final} > B_{final}$:
1. **No reversals**: $A > B$
2. **Alice reverses**: $A_{rev} > B$
3. **Bob reverses**: $A > B_{rev}$
4. **Both reverse**: $A_{rev} > B_{rev}$

If any of these conditions evaluate to true, Alice can achieve a higher score than Bob. We can implement a helper function to calculate the reversed integer and use a simple `if` statement to check all four conditions.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a fixed number of arithmetic operations and comparisons, the execution time is constant regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the scores and their reversed counterparts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has score A, Bob has score B. Both are 2-digit numbers without '0'.
 * Alice can reverse her score (A_rev) and/or Bob's score (B_rev).
 * We need to check if any of the following combinations result in A_new > B_new:
 * 1. A > B
 * 2. A_rev > B
 * 3. A > B_rev
 * 4. A_rev > B_rev
 */

int reverse_num(int n) {
    int tens = n / 10;
    int units = n % 10;
    return units * 10 + tens;
}

void solve() {
    int A, B;
    cin >> A >> B;
    
    int A_rev = reverse_num(A);
    int B_rev = reverse_num(B);
    
    // Check all 4 possible scenarios
    if (A > B || A_rev > B || A > B_rev || A_rev > B_rev) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
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