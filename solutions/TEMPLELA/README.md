# [Temple Land (TEMPLELA)](https://www.codechef.com/problems/TEMPLELA)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given sequence of integers representing the heights of strips in a temple follows a specific "Temple" pattern. A valid temple sequence must satisfy:
1. The sequence must start and end with 1.
2. The sequence must increase by exactly 1 until it reaches the center, and then decrease by exactly 1.
3. The total length of the sequence must be odd to allow for a single peak element.

## Intuition & Mathematical Observation
To validate the sequence, we can break down the requirements into logical checks:
*   **Parity Check**: If the length $N$ is even, it is impossible to have a symmetric peak, so we immediately return "no".
*   **Boundary Check**: The first and last elements must be 1.
*   **Pattern Verification**: 
    *   For the first half (including the center), the element at index $i$ must be $i + 1$.
    *   For the second half, the element at index $i$ must be $N - i$. 
    *   By iterating through the array once, we can verify if every element matches these expected values based on its position.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of strips. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process elements on the fly, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The length Ni must be odd for a unique center to exist.
 * 2. The first element H[0] must be 1.
 * 3. The last element H[Ni-1] must be 1.
 * 4. The sequence must increase by 1 until the center, then decrease by 1.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Condition 1: Length must be odd
    if (n % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: Start and end must be 1
    if (h[0] != 1 || h[n - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int center = n / 2;
    
    // Check increasing part and decreasing part
    for (int i = 0; i < n; ++i) {
        if (i <= center) {
            // Should be 1, 2, 3, ..., center+1
            if (h[i] != i + 1) {
                cout << "no" << "\n";
                return;
            }
        } else {
            // Should be center, ..., 1
            // The height at index i should be (n - i)
            if (h[i] != (n - i)) {
                cout << "no" << "\n";
                return;
            }
        }
    }

    cout << "yes" << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> s;
    while (s--) {
        solve();
    }
    return 0;
}
```