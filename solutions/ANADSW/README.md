# [Anti Adjacent Swaps (ANADSW)](https://www.codechef.com/problems/ANADSW)

- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we are allowed to swap any two elements $A[i]$ and $A[j]$ if and only if $|i - j| > 1$. We need to determine if it is possible to sort the array in non-decreasing order using any number of these operations.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the reachability of permutations based on the size of $N$:

1.  **Case $N=1$**: The array is always sorted. Output: **YES**.
2.  **Case $N=2$**: The only possible indices are $(0, 1)$. Since $|0 - 1| = 1$, we cannot perform any swaps. The array must already be sorted. Output: **YES** if $A[0] \le A[1]$, else **NO**.
3.  **Case $N=3$**: We can swap $A[0]$ and $A[2]$ because $|0 - 2| = 2 > 1$. However, we cannot swap $(0, 1)$ or $(1, 2)$. This means we can only reach two states: the original array $(A_0, A_1, A_2)$ and the swapped state $(A_2, A_1, A_0)$. We check if either of these is sorted.
4.  **Case $N \ge 4$**: For any two adjacent elements $A[i]$ and $A[i+1]$, we can swap them using an auxiliary element $A[k]$ (where $k \neq i, i+1$). Since $N \ge 4$, there is always at least one index $k$ such that $|i-k| > 1$ and $|i+1-k| > 1$. By performing a sequence of swaps—$(i, k)$, then $(i+1, k)$, then $(i, k)$—we can effectively swap any two adjacent elements. Since we can perform any adjacent swap, we can generate any permutation of the array. Thus, the array can always be sorted. Output: **YES**.

## Complexity Analysis

- **Time Complexity**: $O(N)$ per test case, as we perform a single pass to check if the array is sorted.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can swap any two elements A[i] and A[j] if |i - j| > 1.
 * 
 * For N >= 4, we can perform any adjacent swap using an auxiliary element,
 * making any permutation reachable.
 * For N = 3, we can only swap the ends (0 and 2).
 * For N = 2, no swaps are possible.
 * For N = 1, already sorted.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check if original is sorted
        bool sorted = is_sorted(A.begin(), A.end());
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Check if swapping ends makes it sorted
        swap(A[0], A[2]);
        if (is_sorted(A.begin(), A.end())) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, any permutation is reachable.
        cout << "YES" << "\n";
    }
}

int main() {
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