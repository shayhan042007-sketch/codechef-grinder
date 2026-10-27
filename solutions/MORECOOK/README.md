# [More Cookies (MORECOOK)](https://www.codechef.com/problems/MORECOOK)

- **Difficulty Rating**: 890
- **Solved in**: 3 attempt(s)

## Problem Summary
Alice has $C$ cookies and $N$ friends, each having $A_i$ cookies. Alice wants to increase her cookie count to $C' = C + k$ (where $k \ge 0$) such that two conditions are met:
1. There is at least one friend with strictly fewer cookies than Alice ($A_i < C'$).
2. No friend has exactly the same number of cookies as Alice ($A_j \neq C'$ for all $j$).

The goal is to find the minimum non-negative integer $k$ that satisfies these conditions.

## Intuition & Mathematical Observation
Given the small constraints ($N, C, A_i \le 100$), we do not need a complex mathematical formula. We can use a **brute-force simulation** approach:
1. Start with $k = 0$ and calculate $C' = C + k$.
2. Check the two conditions:
   - Iterate through the array $A$ to ensure no $A_i$ equals $C'$. If any $A_i == C'$, the current $C'$ is invalid, so we increment $k$ and try again.
   - Simultaneously, track if there is at least one $A_i < C'$.
3. The first $k$ that satisfies both conditions is our answer. Since the constraints are very small, this loop will terminate almost instantly.

## Complexity Analysis
- **Time Complexity**: $O(T \times K \times N)$, where $T$ is the number of test cases, $K$ is the number of increments needed (which is small given the constraints), and $N$ is the number of friends. In the worst case, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the array of cookies for each friend.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Alice has C cookies. She wants to reach C' = C + k (where k >= 0) such that:
 * 1. At least one friend has A_i < C'.
 * 2. No friend has A_j == C'.
 * 
 * Since constraints are small (N, C, A_i <= 100), we can iterate k starting from 0.
 */

bool is_happy(int C_prime, int N, const vector<int>& A) {
    bool has_less = false;
    for (int x : A) {
        // Condition 2: No friend has equal cookies to Alice
        if (x == C_prime) return false; 
        // Condition 1: At least one friend has strictly less cookies
        if (x < C_prime) has_less = true;
    }
    return has_less;
}

void solve() {
    int N, C;
    if (!(cin >> N >> C)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int k = 0;
    // Brute force search for the minimum k.
    while (true) {
        if (is_happy(C + k, N, A)) {
            cout << k << "\n";
            return;
        }
        k++;
    }
}

int main() {
    // Optimize I/O operations
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