# [Good Subsequence (GOODSUB7)](https://www.codechef.com/problems/GOODSUB7)

- **Difficulty Rating**: 899
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to find the length of the longest "good" subsequence of a given array $A$. A subsequence is defined as "good" if the parity (even or odd) of every pair of adjacent elements in the subsequence is different. In other words, the subsequence must strictly alternate between odd and even numbers.

## Intuition & Mathematical Observation
To maximize the length of an alternating subsequence, we can use a **greedy approach**. 

1. We iterate through the array from left to right.
2. We keep track of the parity of the last element added to our "good" subsequence.
3. For each element in the array, we check its parity:
   - If it is the first element we are picking, we include it.
   - If the current element's parity is different from the parity of the last element we picked, we include it and update our "last parity" tracker.
   - If the parity is the same, we skip the element because picking it would violate the alternating condition.

This greedy strategy works because picking the earliest possible element that satisfies the condition leaves the maximum number of remaining elements to potentially extend the subsequence further.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform a single pass through the input array.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process the input stream on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A sequence is "good" if the parity of adjacent elements is different.
 * This means the sequence must alternate between odd and even numbers.
 * To find the longest good subsequence, we simply need to pick elements 
 * such that we alternate between odd and even.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    int count = 0;
    int last_parity = -1; // -1 means no element picked yet

    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        
        // If it's the first element or the parity is different from the last picked
        if (last_parity == -1 || current_parity != last_parity) {
            count++;
            last_parity = current_parity;
        }
    }

    cout << count << "\n";
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