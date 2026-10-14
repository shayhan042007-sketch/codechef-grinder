# [Chef and Interactive Contests (CHFINTRO)](https://www.codechef.com/problems/CHFINTRO)

- **Difficulty Rating**: 951
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is organizing a contest and wants to categorize participants based on their current ratings. Given $N$ participants, each with a rating $R$, and a minimum threshold rating $r$, we need to determine if each participant is a "Good boi" or a "Bad boi". A participant is considered a "Good boi" if their rating $R$ is greater than or equal to the threshold $r$; otherwise, they are a "Bad boi".

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. For each of the $N$ participants, we are provided with their rating $R$. We simply need to perform a comparison:
- If $R \ge r$, output `Good boi`.
- If $R < r$, output `Bad boi`.

Since the constraints are small ($N \le 1000$), a simple linear scan through the input values is sufficient to solve the problem within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of contestants. We iterate through the list of ratings exactly once, performing a constant-time comparison for each.
- **Space Complexity**: $O(1)$, as we only store a few variables ($N, r, R$) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N contestants and a threshold rating r.
 * For each contestant with rating R:
 * - If R >= r, they are a "Good boi".
 * - If R < r, they are a "Bad boi".
 * 
 * Constraints:
 * N <= 1000
 * 1300 <= r, R <= 1501
 * Time complexity required: O(N)
 * Space complexity required: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long r;
    
    // Read N and r
    if (!(cin >> N >> r)) return 0;

    // Process each contestant
    for (int i = 0; i < N; ++i) {
        long long R;
        cin >> R;
        
        if (R >= r) {
            cout << "Good boi" << "\n";
        } else {
            cout << "Bad boi" << "\n";
        }
    }

    return 0;
}
```