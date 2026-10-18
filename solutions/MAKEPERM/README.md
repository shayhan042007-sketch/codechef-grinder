# [Make Permutation (MAKEPERM)](https://www.codechef.com/problems/MAKEPERM)

- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, determine if it is possible to transform $A$ into a permutation of numbers from $1$ to $N$ by adding a non-negative integer $B_i$ to each element $A_i$. That is, $A_i + B_i = P_i$, where $P$ is a permutation of $\{1, 2, \dots, N\}$ and $B_i \ge 0$.

## Intuition & Mathematical Observation
The condition $A_i + B_i = P_i$ with $B_i \ge 0$ implies that for every element $A_i$, we must be able to assign a unique value $P_i \in \{1, 2, \dots, N\}$ such that $A_i \le P_i$.

1. **Sorting**: If we sort the array $A$ in non-decreasing order, we align the smallest elements of $A$ with the smallest possible values in the target permutation $\{1, 2, \dots, N\}$.
2. **Greedy Strategy**: After sorting, the $i$-th element (0-indexed) of $A$ must be less than or equal to the $(i+1)$-th value of the permutation. If $A_i > i + 1$, it is impossible to satisfy the condition because even if we matched $A_i$ with the smallest available value in the permutation, that value would be smaller than $A_i$, violating $A_i \le P_i$.
3. **Conclusion**: If $A_i \le i + 1$ for all $i$ in the sorted array, we can always form the permutation. Since we are allowed to add *any* non-negative integer $B_i$, as long as $A_i \le P_i$, we can simply set $B_i = P_i - A_i$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$. Thus, the overall complexity per test case is $O(N \log N)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, we must have C_i >= A_i.
 * By sorting A, we ensure that the smallest elements of A are matched against 
 * the smallest possible values of the permutation. If A_sorted[i] > (i + 1), 
 * it is impossible to satisfy the condition.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to align smallest elements with smallest permutation values
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // If the smallest available A[i] is already greater than the 
        // (i+1)-th smallest value in the permutation, it's impossible.
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```