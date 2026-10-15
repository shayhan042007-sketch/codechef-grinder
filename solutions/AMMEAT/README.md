# [Andrew and the Meatballs (AMMEAT)](https://www.codechef.com/problems/AMMEAT)

- **Difficulty Rating**: 1275
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ plates, each containing a specific number of meatballs. We need to select the minimum number of plates such that the total number of meatballs collected is at least $M$. If it is impossible to reach the target $M$ even by picking all available plates, we must output -1.

## Intuition & Mathematical Observation
To minimize the number of plates used, we should prioritize plates with the highest number of meatballs. This is a classic **Greedy** approach:

1. **Greedy Choice**: By sorting the plates in descending order, we ensure that each plate we add contributes the maximum possible amount to our current sum. This allows us to reach the target $M$ using the fewest number of items.
2. **Feasibility Check**: Before attempting to select plates, we calculate the sum of all meatballs available. If the total sum is strictly less than $M$, it is mathematically impossible to satisfy the condition, so we return -1.
3. **Data Types**: Since $M$ and the number of meatballs per plate can be as large as $10^{18}$, we must use `long long` in C++ to prevent integer overflow.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, where $N$ is the number of plates. This is dominated by the sorting step. Given the constraints, this is highly efficient.
- **Space Complexity**: $O(N)$ to store the number of meatballs on each plate.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N plates with P_i meatballs. We need to select the minimum number of plates
 * such that the sum of meatballs is at least M.
 * 
 * Strategy:
 * 1. To minimize the number of plates, we should always pick the plates with the 
 *    largest number of meatballs first (Greedy approach).
 * 2. Sort the array of meatballs in descending order.
 * 3. Keep adding the largest plates until the sum is >= M.
 * 4. If the total sum of all plates is less than M, it's impossible, output -1.
 * 
 * Constraints:
 * N <= 7 (This is very small, but the logic works for any N).
 * M, P_i <= 10^18 (Must use long long).
 */

void solve() {
    int N;
    long long M;
    if (!(cin >> N >> M)) return;

    vector<long long> P(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        total_sum += P[i];
    }

    // If total meatballs available are less than M, impossible.
    if (total_sum < M) {
        cout << -1 << "\n";
        return;
    }

    // Sort in descending order to pick largest plates first
    sort(P.rbegin(), P.rend());

    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        current_sum += P[i];
        count++;
        if (current_sum >= M) {
            cout << count << "\n";
            return;
        }
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