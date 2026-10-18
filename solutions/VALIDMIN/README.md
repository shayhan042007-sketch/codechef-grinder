# [Valid Minimum (VALIDMIN)](https://www.codechef.com/problems/VALIDMIN)

- **Difficulty Rating**: 1132
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $P, Q,$ and $R$, determine if there exist three integers $A, B,$ and $C$ such that:
- $\min(A, B) = P$
- $\min(B, C) = Q$
- $\min(C, A) = R$

If such a triplet $(A, B, C)$ exists, output `YES`; otherwise, output `NO`.

## Intuition & Mathematical Observation
Let the given values be $P, Q, R$. Without loss of generality, assume we sort these values such that $v_1 \le v_2 \le v_3$.

Consider the relationship between $A, B,$ and $C$. If we assume $A \le B \le C$, then:
- $\min(A, B) = A$
- $\min(B, C) = B$
- $\min(C, A) = A$

The set of minimums becomes $\{A, B, A\}$. Notice that the smallest value ($A$) appears twice. 

If we sort the input values $P, Q, R$ into $v_1, v_2, v_3$, the condition for a valid triplet to exist is that the two smallest values must be equal ($v_1 = v_2$). 
- If $v_1 = v_2$, we can set $A = v_1, B = v_1, C = v_3$. 
- Calculating the minimums: $\min(v_1, v_1) = v_1$, $\min(v_1, v_3) = v_1$, $\min(v_3, v_1) = v_1$. This matches the set $\{v_1, v_1, v_3\}$.
- If $v_1 < v_2$, it is impossible to satisfy the condition because the smallest value would only appear once, which contradicts the structure of the minimums of three variables.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting three elements takes constant time, and the comparison is also constant time.
- **Space Complexity**: $O(1)$, as we only store three integers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the given values be P, Q, R. Sort them such that v1 <= v2 <= v3.
 * For a valid triplet (A, B, C) to exist, the two smallest values 
 * among the minimums must be equal.
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    // Sort the input to easily identify the two smallest values
    sort(arr, arr + 3);
    
    // After sorting, the two smallest values are arr[0] and arr[1].
    // They must be equal for a valid tuple to exist.
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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