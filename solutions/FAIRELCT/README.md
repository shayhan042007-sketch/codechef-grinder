# [Fair Elections (FAIRELCT)](https://www.codechef.com/problems/FAIRELCT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
John Jackson and Jack Johnson are competing in an election. John has $N$ packs of votes and Jack has $M$ packs of votes. John wants to win the election, meaning he needs the sum of his votes to be strictly greater than the sum of Jack's votes. We are allowed to swap one pack of votes from John with one pack from Jack. We need to find the minimum number of swaps required to make John's total votes greater than Jack's, or determine if it is impossible.

## Intuition & Mathematical Observation
To make John's sum larger while using the minimum number of swaps, we should adopt a **greedy strategy**:
1. **Identify the bottleneck**: John needs to increase his total sum. To do this most efficiently, he should always give away his smallest pack of votes and receive the largest available pack from Jack.
2. **Sorting**: By sorting John's packs in ascending order and Jack's packs in descending order, we ensure that at each step $i$, we are comparing the smallest possible value from John ($A[i]$) with the largest possible value from Jack ($B[i]$).
3. **Condition**: We only perform a swap if $A[i] < B[i]$. If $A[i] \ge B[i]$, swapping will not increase John's total sum (or will decrease it), meaning no further beneficial swaps are possible.
4. **Termination**: If at any point John's sum becomes strictly greater than Jack's, we stop and return the count of swaps. If we exhaust all possible swaps (or encounter a case where $A[i] \ge B[i]$) and John's sum is still not greater than Jack's, it is impossible to win.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot (N \log N + M \log M))$, where $T$ is the number of test cases. Sorting the arrays dominates the complexity, while the linear scan to perform swaps takes $O(\min(N, M))$.
- **Space Complexity**: $O(N + M)$ to store the vote packs for both candidates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * To maximize John's total votes with the minimum number of swaps, we should
 * always swap the smallest pack from A with the largest pack from B, provided
 * that the pack from A is smaller than the pack from B.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    // Sort A ascending and B descending to greedily pick best swaps
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int swaps = 0;
    int i = 0;
    while (sumA <= sumB) {
        // If we run out of packs to swap or the swap is not beneficial, it's impossible
        if (i >= N || i >= M || A[i] >= B[i]) {
            cout << -1 << "\n";
            return;
        }
        
        // Perform swap
        sumA = sumA - A[i] + B[i];
        sumB = sumB - B[i] + A[i];
        swaps++;
        i++;
    }

    cout << swaps << "\n";
}

int main() {
    // Optimize I/O operations
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