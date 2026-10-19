# [A - Books (BIT2A)](https://www.codechef.com/problems/BIT2A)

- **Difficulty Rating**: 1175
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a sorted array $A$ of $N$ integers, for every element $A[i]$, we need to determine how many elements in the array are strictly greater than $A[i]$. The output should be a sequence of $N$ integers corresponding to these counts.

## Intuition & Mathematical Observation
Since the input array $A$ is already sorted in non-decreasing order, all elements strictly greater than $A[i]$ must appear after the last occurrence of $A[i]$. 

1. For any element $A[i]$, we need to find the first index $j$ such that $A[j] > A[i]$.
2. In C++, the `std::upper_bound` function efficiently finds the first element in a sorted range that is strictly greater than a given value.
3. Once we have the iterator to this element, the number of elements strictly greater than $A[i]$ is simply the number of elements from that iterator to the end of the array.
4. This can be calculated using `std::distance(it, A.end())` or by subtracting the index of the iterator from the total size $N$.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the size of the array. Each `upper_bound` call takes $O(\log N)$ time, and we perform this for each of the $N$ elements.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sorted list A of size N.
 * For each element A[i], we need to find the number of elements strictly greater than A[i].
 * Since the array is sorted, all elements strictly greater than A[i] must appear after the 
 * last occurrence of A[i] in the array.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // upper_bound returns an iterator to the first element strictly greater than A[i]
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        
        // The number of elements strictly greater is the distance from the iterator to the end
        int count = distance(it, A.end());
        
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```