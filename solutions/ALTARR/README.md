# [Alternating Array (ALTARR)](https://www.codechef.com/problems/ALTARR)

- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to make the array "alternating." An array is considered alternating if the parity (even or odd) of any two adjacent elements is different. We need to find the minimum number of elements that must be changed to satisfy this condition.

## Intuition & Mathematical Observation
An alternating array must follow one of two possible parity patterns:
1. **Pattern 1**: The sequence starts with an **Odd** number (Odd, Even, Odd, Even, ...).
2. **Pattern 2**: The sequence starts with an **Even** number (Even, Odd, Even, Odd, ...).

For any index $i$ (0-indexed):
- In **Pattern 1**, the parity at index $i$ should be `i % 2`. (If $i$ is even, it should be odd; if $i$ is odd, it should be even).
- In **Pattern 2**, the parity at index $i$ should be `(i + 1) % 2`. (If $i$ is even, it should be even; if $i$ is odd, it should be odd).

To find the minimum changes required, we calculate the number of mismatches for both patterns compared to the original array. The final answer is the minimum of these two counts, as we only need to transform the array into one of the two valid alternating configurations.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array twice (once for each pattern).
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input on the fly, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1].
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Odd, Even, Odd, Even, ...
 * Pattern 2: Even, Odd, Even, Odd, ...
 * 
 * To find the minimum changes, we count how many elements in the original array
 * violate Pattern 1 (let this be count1) and how many violate Pattern 2 (count2).
 * The answer is min(count1, count2).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Pattern 1: A[0] is Odd (A[i] % 2 == 1 if i even, 0 if i odd)
    int count1 = 0;
    for (int i = 0; i < N; ++i) {
        int expected_parity = (i % 2 == 0) ? 1 : 0;
        if (abs(A[i] % 2) != expected_parity) {
            count1++;
        }
    }

    // Pattern 2: A[0] is Even (A[i] % 2 == 0 if i even, 1 if i odd)
    int count2 = 0;
    for (int i = 0; i < N; ++i) {
        int expected_parity = (i % 2 == 0) ? 0 : 1;
        if (abs(A[i] % 2) != expected_parity) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
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