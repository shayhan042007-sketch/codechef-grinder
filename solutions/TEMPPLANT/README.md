# [Plant (TEMPPLANT)](https://www.codechef.com/problems/TEMPPLANT)

- **Difficulty Rating**: 675
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ days with temperatures $A_1, A_2, \dots, A_N$. We need to select two consecutive days $(i, i+1)$ to plant a seed. The resulting height of the tree is determined by the minimum temperature of those two days, i.e., $\min(A_i, A_{i+1})$. The goal is to find the maximum possible height we can achieve by choosing the optimal pair of consecutive days.

## Intuition & Mathematical Observation
Since we are looking for the maximum value of $\min(A_i, A_{i+1})$ across all adjacent pairs, we can simply iterate through the array once. 
1. We maintain a variable `max_height` initialized to 0 (or the smallest possible integer).
2. We loop from the first element to the second-to-last element ($i = 0$ to $N-2$).
3. For each index $i$, we calculate the minimum of the current element $A_i$ and the next element $A_{i+1}$.
4. If this minimum value is greater than our current `max_height`, we update `max_height`.
5. After checking all pairs, `max_height` will hold the maximum possible value.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days. Since we iterate through the array exactly once, the total time complexity is $O(T \times N)$, which easily fits within the time limits for $N \le 100$.
- **Space Complexity**: $O(N)$ to store the temperature values in a vector. This could be optimized to $O(1)$ by storing only the previous element, but $O(N)$ is well within memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days with temperatures A_1, A_2, ..., A_N.
 * We need to choose two consecutive days (i, i+1) to plant the seed.
 * The height of the tree is min(A_i, A_{i+1}).
 * We want to maximize this value over all possible i from 1 to N-1.
 * 
 * Complexity:
 * Time: O(N) per test case, where N <= 100. Total time O(T * N) = 10^4 operations.
 * Space: O(N) to store the temperatures.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int max_height = 0;
    // Iterate through all pairs of consecutive days (i, i+1)
    // There are N-1 such pairs.
    for (int i = 0; i < N - 1; ++i) {
        int current_height = min(A[i], A[i + 1]);
        if (current_height > max_height) {
            max_height = current_height;
        }
    }
    
    cout << max_height << "\n";
}

int main() {
    // Fast I/O setup
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