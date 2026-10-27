# [Exclusion-Inclusion (ONEFROMK)](https://www.codechef.com/problems/ONEFROMK)

- **Difficulty Rating**: 1307
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to perform a sequence of operations. For a fixed $K$, we start with $K$ elements and perform $N-K$ operations. In each operation, we remove one element and add another from the remaining pool until only one element remains. We want to maximize the sum of the elements involved in this process. Specifically, for every $K$ from $1$ to $N$, we need to find the maximum possible sum of the elements that remain in the set throughout the process.

## Intuition & Mathematical Observation
The problem asks us to consider the state where we have $K$ elements and perform operations until we reach a state where we have enough elements to satisfy the constraints. 

1. **The Greedy Strategy**: To maximize the sum for a fixed $K$, we should always aim to keep the largest available elements. 
2. **The Constraint**: When we have $K$ elements and perform $N-K$ operations, we are essentially selecting a subset of the original array. Through the mechanics of the problem, it turns out that for a given $K$, we are effectively forced to keep the $N - K + 1$ largest elements of the array.
3. **Prefix Sums**: Since we need to output the answer for every $K \in [1, N]$, calculating the sum of the largest $N-K+1$ elements repeatedly would be $O(N^2)$. By sorting the array and precomputing prefix sums, we can calculate the sum of any suffix of the sorted array in $O(1)$ time.
   - Let the sorted array be $S$.
   - The sum of the $M$ largest elements is the sum of the suffix starting at index $N-M$.
   - Using a prefix sum array `P`, where `P[i]` is the sum of the first `i` elements, the sum of the largest $M$ elements is `P[N] - P[N-M]`.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case. The sorting step dominates the complexity, while the prefix sum calculation and the loop to print answers both run in $O(N)$.
- **Space Complexity**: $O(N)$ to store the array and the prefix sum array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Problem Analysis:
 * For a fixed K, we perform N - K + 1 operations.
 * In each operation, we add an element and remove one.
 * Effectively, we are choosing N - K + 1 elements from the array A to sum up.
 * The constraint is that we must be able to pick an element at each step i from K to N.
 * This is always satisfied if we pick the largest N - K + 1 elements.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort to easily access the largest elements
    vector<long long> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    // Precompute prefix sums for O(1) range sum queries
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sortedA[i];
    }

    // For each K, we need the sum of the largest (N - K + 1) elements
    for (int K = 1; K <= N; ++K) {
        int count = N - K + 1;
        // Sum of the largest 'count' elements is the suffix sum
        long long current_sum = prefix_sum[N] - prefix_sum[N - count];
        cout << current_sum << (K == N ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
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