# [Peaceful Party (MAYOR_PARTY)](https://www.codechef.com/problems/MAYOR_PARTY)

- **Difficulty Rating**: 898
- **Solved in**: 2 attempt(s)

## Problem Summary
The mayor wants to invite people from three different regions (A, B, and C) to a party. However, there is a conflict constraint: people from region B cannot be invited if people from either region A or region C are invited. We are given the number of people in each region ($P_A, P_B, P_C$) and need to determine the maximum number of people that can be invited while respecting the constraint.

## Intuition & Mathematical Observation
The constraint states that region B is incompatible with both A and C. This leaves us with two mutually exclusive strategies to maximize the total number of guests:

1.  **Invite from A and C:** Since there is no stated conflict between A and C, we can invite everyone from both regions. The total number of people would be $P_A + P_C$.
2.  **Invite from B:** If we choose to invite people from region B, we cannot invite anyone from A or C. The total number of people would be $P_B$.

To find the optimal solution, we simply compare these two scenarios and take the maximum:
$$\text{Result} = \max(P_A + P_C, P_B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and a comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input values.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The mayor can either invite people from regions A and C together, 
 * or invite people from region B alone.
 * 
 * Conflict constraints:
 * - B cannot be with A.
 * - B cannot be with C.
 * 
 * Valid sets:
 * - {A, C} -> Sum = P_A + P_C
 * - {B}    -> Sum = P_B
 * 
 * Result = max(P_A + P_C, P_B)
 */

void solve() {
    int pa, pb, pc;
    if (!(cin >> pa >> pb >> pc)) return;
    
    int option1 = pa + pc;
    int option2 = pb;
    
    cout << max(option1, option2) << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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