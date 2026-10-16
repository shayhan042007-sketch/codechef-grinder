# [Change One (CHANGEONE7)](https://www.codechef.com/problems/CHANGEONE7)

- **Difficulty Rating**: 738
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we are allowed to change exactly one element in the array to any integer value. The goal is to minimize the difference between the maximum and minimum elements of the array (the range) after this modification.

## Intuition & Mathematical Observation
To minimize the range $(max - min)$, we want to either increase the minimum value or decrease the maximum value.

1.  **Sort the array**: Let the sorted array be $S_0, S_1, \dots, S_{N-1}$.
2.  **Strategy 1 (Change the minimum)**: If we change the smallest element $S_0$ to match the second smallest element $S_1$, the new minimum becomes $S_1$. The new range is $S_{N-1} - S_1$.
3.  **Strategy 2 (Change the maximum)**: If we change the largest element $S_{N-1}$ to match the second largest element $S_{N-2}$, the new maximum becomes $S_{N-2}$. The new range is $S_{N-2} - S_0$.
4.  **Edge Case**: If $N=2$, we can change one element to match the other, resulting in a range of $0$.

By comparing these two strategies, the minimum possible range is $\min(S_{N-1} - S_1, S_{N-2} - S_0)$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. Given the constraints, this is well within the time limits.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We must change exactly one element to minimize (max(A) - min(A)).
 * 
 * Let the sorted array be S_0, S_1, ..., S_{N-1}.
 * 
 * To minimize the range by changing one element, we have two main strategies:
 * 1. Change the minimum element (S_0) to be equal to the second minimum (S_1).
 *    The new range becomes S_{N-1} - S_1.
 * 2. Change the maximum element (S_{N-1}) to be equal to the second maximum (S_{N-2}).
 *    The new range becomes S_{N-2} - S_0.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to easily identify min, max, second min, and second max
    sort(A.begin(), A.end());

    // If N=2, we can always make them equal (range 0)
    if (N == 2) {
        cout << 0 << "\n";
        return;
    }

    // Option 1: Change A[0] to A[1], range becomes A[N-1] - A[1]
    int option1 = A[N - 1] - A[1];
    
    // Option 2: Change A[N-1] to A[N-2], range becomes A[N-2] - A[0]
    int option2 = A[N - 2] - A[0];

    cout << min(option1, option2) << "\n";
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