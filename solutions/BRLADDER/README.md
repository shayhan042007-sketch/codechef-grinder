# [Bear and Ladder (BRLADDER)](https://www.codechef.com/problems/BRLADDER)

- **Difficulty Rating**: 999
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if two given cities, $a$ and $b$, are connected by a road in a specific ladder-like structure. The structure consists of:
1. **Horizontal roads**: Connecting $(2i+1)$ and $(2i+2)$ for $i \ge 0$.
2. **Vertical roads**: Connecting $(2i+1)$ and $(2i+3)$ for $i \ge 0$, and $(2i)$ and $(2i+2)$ for $i \ge 1$.

Given $Q$ queries, each containing two integers $a$ and $b$, we must output "YES" if a direct road exists between them, and "NO" otherwise.

## Intuition & Mathematical Observation
By analyzing the structure, we can categorize the connections based on the difference between the two city numbers:

1.  **Horizontal Connections ($|a - b| = 1$):**
    *   These connect an odd number with the next even number (e.g., 1-2, 3-4, 5-6).
    *   A road exists if the smaller number is odd.
2.  **Vertical Connections ($|a - b| = 2$):**
    *   These connect two numbers of the same parity (e.g., 1-3, 3-5, 2-4, 4-6).
    *   A road exists if both numbers are odd or both numbers are even.
3.  **No Connection:**
    *   If the absolute difference is neither 1 nor 2, no direct road exists between the cities.

By ensuring $a < b$ (using `swap` if necessary), we simplify the logic to checking `b - a == 1` or `b - a == 2` and verifying the parity conditions.

## Complexity Analysis
- **Time Complexity**: $O(Q)$, where $Q$ is the number of queries. Each query is processed in $O(1)$ time using simple arithmetic and conditional checks.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Horizontal roads: (2i+1) - (2i+2). Condition: |a - b| == 1 AND min(a, b) is odd.
 * 2. Vertical roads: (2i+1) - (2i+3) OR (2i) - (2i+2). Condition: |a - b| == 2 AND parity is same.
 */

void solve() {
    long long a, b;
    cin >> a >> b;

    // Ensure a is the smaller value to simplify logic
    if (a > b) swap(a, b);

    // Case 1: Horizontal road (e.g., 1-2, 3-4)
    if (b - a == 1) {
        if (a % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    // Case 2: Vertical road (e.g., 1-3, 2-4)
    else if (b - a == 2) {
        if (a % 2 == b % 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    // Case 3: No road exists
    else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        solve();
    }
    return 0;
}
```