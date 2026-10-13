# [Which Fuel is Cheaper (CHEAPFUEL)](https://www.codechef.com/problems/CHEAPFUEL)

- **Difficulty Rating**: 926
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the initial prices of petrol ($X$) and diesel ($Y$), the monthly price increase for each ($A$ and $B$ respectively), and a duration of $K$ months. We need to determine which fuel will be cheaper after $K$ months, or if they will cost the same.

## Intuition & Mathematical Observation
To find the price of each fuel after $K$ months, we apply the simple linear growth formula:
- **Final Petrol Price**: $P_{final} = X + (A \times K)$
- **Final Diesel Price**: $D_{final} = Y + (B \times K)$

By calculating these two values, we can perform a direct comparison:
1. If $P_{final} < D_{final}$, petrol is cheaper.
2. If $D_{final} < P_{final}$, diesel is cheaper.
3. If $P_{final} == D_{final}$, the prices are the same.

Given the constraints ($X, Y, A, B, K \le 1000$), the maximum possible value is $1,000 + (1,000 \times 1,000) = 1,001,000$. This fits well within a standard 32-bit integer, though `long long` is used to ensure safety against potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial price of petrol: X
 * Initial price of diesel: Y
 * Monthly increase for petrol: A
 * Monthly increase for diesel: B
 * Number of months: K
 * 
 * Price of petrol after K months: X + (A * K)
 * Price of diesel after K months: Y + (B * K)
 */

void solve() {
    long long X, Y, A, B, K;
    if (!(cin >> X >> Y >> A >> B >> K)) return;

    long long final_petrol = X + (A * K);
    long long final_diesel = Y + (B * K);

    if (final_petrol < final_diesel) {
        cout << "PETROL" << "\n";
    } else if (final_diesel < final_petrol) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "SAME PRICE" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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