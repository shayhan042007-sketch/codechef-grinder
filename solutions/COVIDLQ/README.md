# [COVID Pandemic and Long Queue (COVIDLQ)](https://www.codechef.com/problems/COVIDLQ)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a queue represented by an array of size $N$ containing only $0$s and $1$s. A $1$ represents a person, and a $0$ represents an empty space. The rule for social distancing is that any two people must be at least 6 positions apart. Specifically, if two people are at indices $i$ and $j$ (where $i < j$), the condition $j - i \ge 6$ must hold. We need to determine if the given queue configuration follows this rule.

## Intuition & Mathematical Observation
The problem requires us to ensure that no two $1$s are placed too close to each other. 
- If we encounter a $1$ at index $i$, we need to check the position of the previously encountered $1$ (let's call it `last_pos`).
- If `i - last_pos < 6`, the social distancing rule is violated, and we can immediately conclude the answer is "NO".
- If we traverse the entire array without violating this condition, the answer is "YES".
- To handle the first person encountered, we can initialize `last_pos` to a value small enough (e.g., $-10$) so that the initial check `i - (-10) < 6` will always be false, allowing the first person to be placed without restriction.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the queue. We iterate through the array exactly once. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ by processing the input values on the fly without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * A person is at index i if A[i] == 1.
 * Social distancing is followed if for any two people at indices i and j (i < j),
 * the distance (j - i) is at least 6.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize last_pos with a value such that the first person 
    // encountered does not trigger a violation (distance > 6).
    int last_pos = -10; 
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            // Check if the distance from the last person is less than 6
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            // Update the position of the last person seen
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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