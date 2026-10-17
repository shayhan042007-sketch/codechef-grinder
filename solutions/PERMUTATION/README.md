# [Convert to permutation (PERMUTATION)](https://www.codechef.com/problems/PERMUTATION)

- **Difficulty Rating**: 1197
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to transform it into a permutation of numbers from $1$ to $N$. The only allowed operation is to increase any element $A[i]$ by $1$. We need to find the minimum number of operations required to achieve this, or determine if it is impossible.

## Intuition & Mathematical Observation
1. **Target State**: A permutation of size $N$ must contain exactly the set $\{1, 2, \dots, N\}$.
2. **Greedy Strategy**: Since we can only increase values, if we sort the input array $A$ in non-decreasing order, the smallest element $A[0]$ should ideally be transformed into $1$, the second smallest $A[1]$ into $2$, and so on.
3. **Feasibility**: For each sorted element $A[i]$, the target value is $T_i = i + 1$. 
    - If $A[i] > i + 1$, it is impossible to reach the target value because we can only increase numbers. In this case, we output `-1`.
    - If $A[i] \le i + 1$, the cost to transform $A[i]$ to $i + 1$ is exactly $(i + 1) - A[i]$.
4. **Optimality**: Sorting ensures that we match the smallest available values to the smallest available targets, which minimizes the total sum of differences.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, resulting in an overall complexity of $O(N \log N)$ per test case.
- **Space Complexity**: $O(N)$ to store the array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To convert an array A into a permutation of size N (containing 1 to N),
 * we need to map each element A[i] to a unique value in {1, 2, ..., N}.
 * Since we can only increase elements, an element A[i] can be transformed into 
 * a target value T if and only if A[i] <= T.
 * 
 * To minimize the total operations (sum of (T_i - A[i])), we should sort the 
 * array A in non-decreasing order and match the sorted elements with the 
 * sorted target permutation {1, 2, ..., N}.
 * 
 * If at any point after sorting, A[i] > (i + 1), it is impossible to transform 
 * A[i] into (i + 1) because we can only increase values. Thus, we output -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to greedily match the smallest available A[i] 
    // with the smallest available target value (1, 2, ..., N).
    sort(A.begin(), A.end());

    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        long long target = i + 1;
        if (A[i] > target) {
            // Cannot decrease A[i] to reach target
            cout << -1 << "\n";
            return;
        }
        operations += (target - A[i]);
    }

    cout << operations << "\n";
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