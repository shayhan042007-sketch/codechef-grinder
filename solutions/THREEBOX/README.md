# [Three Boxes (THREEBOX)](https://www.codechef.com/problems/THREEBOX)

- **Difficulty Rating**: 1183
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given three items with sizes $A, B,$ and $C$, and a bag with capacity $D$. You need to determine the minimum number of bags required to carry all three items, given that each bag has a maximum capacity of $D$.

## Intuition & Mathematical Observation
The problem asks for the minimum number of bags. Since we only have three items, the answer must be 1, 2, or 3. We can determine the answer using a greedy approach based on the sum of the items:

1.  **Check for 1 bag**: If the sum of all three items $(A + B + C)$ is less than or equal to $D$, we can fit everything into a single bag.
2.  **Check for 2 bags**: If we cannot fit everything in one bag, we check if we can fit them into two. Since we want to minimize bags, we try to pair the items. Given the constraint $A \le B \le C$, if the sum of the two smallest items $(A + B)$ is $\le D$, or if the sum of the smallest and the middle item $(A + C)$ is $\le D$, we can distribute the items into two bags. 
    *   *Note*: We don't need to check $(B + C)$ because if $B + C \le D$, then $A + B$ or $A + C$ would also be $\le D$ (since $A \le B \le C$).
3.  **Default to 3 bags**: If neither of the above conditions is met, it is impossible to fit the items into fewer than 3 bags.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes with sizes A, B, C and a bag capacity D.
 * Constraints: 1 <= A <= B <= C <= D <= 100.
 * 
 * Logic:
 * 1. If A + B + C <= D, we can fit all three in 1 bag.
 * 2. If A + B + C > D, we check if we can fit two boxes in one bag.
 *    Since A <= B <= C, the largest possible pairs are (A+B), (A+C), or (B+C).
 *    - If A + B + C > D, we definitely need at least 2 bags.
 *    - If A + C <= D, we can put (A+C) in one bag and B in another (2 bags).
 *    - If A + B <= D, we can put (A+B) in one bag and C in another (2 bags).
 *    - If even the smallest pair (A+B) > D, we need 3 bags.
 */

void solve() {
    int A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return;

    if (A + B + C <= D) {
        cout << 1 << "\n";
    } else if (A + B <= D || A + C <= D) {
        // If the sum of the two smallest or the smallest and middle fits, 
        // we can use 2 bags.
        cout << 2 << "\n";
    } else {
        // Otherwise, each item requires its own bag.
        cout << 3 << "\n";
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