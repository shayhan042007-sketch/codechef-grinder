# [Signal (P2BAR)](https://www.codechef.com/problems/P2BAR)

- **Difficulty Rating**: 657
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$ representing a signal, we need to count the total number of '1's that appear after the first occurrence of a '0'. If no '0' exists in the string, the answer is 0.

## Intuition & Mathematical Observation
The problem asks us to track a state change. We are looking for '1's, but only those that occur *after* the signal has been "silenced" (i.e., after the first '0' is encountered).

1. **State Tracking**: We can use a boolean flag, `foundSilence`, initialized to `false`.
2. **Transition**: As we iterate through the string, the moment we encounter a '0', we set `foundSilence` to `true`. This flag remains `true` for the rest of the iteration.
3. **Counting**: For every character we visit, if the character is '1' AND `foundSilence` is `true`, we increment our counter.
4. **Efficiency**: Since we only need to traverse the string once, this approach is optimal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we perform a single pass through the input.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count the number of '1's that appear after the first occurrence of a '0'.
 * 
 * Approach:
 * 1. Iterate through the string.
 * 2. Maintain a boolean flag `foundSilence` initialized to false.
 * 3. If we encounter a '0', set `foundSilence` to true.
 * 4. If we encounter a '1' and `foundSilence` is true, increment the counter.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long count = 0;
    bool foundSilence = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            foundSilence = true;
        } else if (S[i] == '1') {
            if (foundSilence) {
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O for performance
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