# [Non Adjacent Flips (NONADJFLIP)](https://www.codechef.com/problems/NONADJFLIP)

- **Difficulty Rating**: 1128
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to transform it into a string of all '0's. In one operation, we can choose any set of indices such that no two indices are adjacent, and flip the bits at those positions (0 becomes 1, 1 becomes 0). We need to find the minimum number of operations required to make the entire string '0'.

## Intuition & Mathematical Observation
The problem asks for the minimum number of operations to clear all '1's. We can categorize the state of the string into three cases:

1.  **Case 0: No '1's present.**
    If the string is already all '0's, the number of operations required is **0**.

2.  **Case 1: No adjacent '1's.**
    If there are '1's but no two '1's are adjacent (e.g., "10101"), we can select all indices containing '1' in a single operation because none of them are adjacent. Thus, the answer is **1**.

3.  **Case 2: Adjacent '1's present.**
    If there are adjacent '1's (e.g., "110"), we cannot flip them in a single operation. However, we can always partition any set of indices into two subsets such that no two indices within the same subset are adjacent (for example, all even indices and all odd indices). By flipping the "even" set of '1's first and the "odd" set of '1's second, we can clear any configuration in at most **2** operations. Since we have adjacent '1's, we know 1 operation is insufficient, so the answer is **2**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single linear scan to check for the presence of '1's and adjacent '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. If there are no 1s, the answer is 0.
 * 2. If there are no adjacent 1s, we can flip all 1s in a single operation. Answer is 1.
 * 3. If there are adjacent 1s, we need 2 operations. We can partition the 1s into 
 *    two sets (e.g., even indices and odd indices) such that no two 1s in the 
 *    same set are adjacent.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_one = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_one = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_one) {
        cout << 0 << "\n";
    } else if (!has_adjacent_ones) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
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