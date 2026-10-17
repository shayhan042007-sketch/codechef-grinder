# [Make Subarray (MAKESUB)](https://www.codechef.com/problems/MAKESUB)

- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to make all the '1's in the string form a single contiguous block. We are allowed to change any '0' to a '1'. We need to find the minimum number of '0's that must be changed to '1' to satisfy the condition.

## Intuition & Mathematical Observation
1. **Edge Case**: If the string contains no '1's, the condition is already satisfied (a block of zero '1's is technically contiguous). In this case, the answer is 0.
2. **Identifying the Range**: If there are '1's in the string, let the index of the first occurrence be `first` and the index of the last occurrence be `last`.
3. **The Strategy**: To make all '1's contiguous, every '0' located between the `first` index and the `last` index must be flipped to a '1'. Any '0's appearing before the `first` index or after the `last` index do not need to be changed, as they do not break the contiguity of the existing '1's.
4. **Calculation**: The minimum number of changes required is simply the count of '0's in the substring $S[first \dots last]$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass to find the indices and another pass (or a combined pass) to count the zeros.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the input character by character.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We want all '1's to form a single contiguous block.
 * We can only change '0' to '1'.
 * 
 * If there are no '1's, the condition is already satisfied (0 changes).
 * If there are '1's, let the first occurrence of '1' be at index 'first'
 * and the last occurrence of '1' be at index 'last'.
 * To make all '1's contiguous, every '0' between 'first' and 'last'
 * must be changed to '1'.
 * 
 * The number of changes required is the count of '0's in the range [first, last].
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int first = -1;
    int last = -1;

    // Find the first and last occurrence of '1'
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // If no '1's exist, 0 changes needed.
    if (first == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count '0's between first and last index
    int changes = 0;
    for (int i = first; i <= last; ++i) {
        if (S[i] == '0') {
            changes++;
        }
    }

    cout << changes << "\n";
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