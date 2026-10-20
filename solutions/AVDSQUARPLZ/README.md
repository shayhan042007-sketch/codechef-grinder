# [Avoid Squares Please (AVDSQUARPLZ)](https://www.codechef.com/problems/AVDSQUARPLZ)

- **Difficulty Rating**: 960
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation of the numbers from $1$ to $N$ such that for any two adjacent elements $a_i$ and $a_{i+1}$ in the permutation, their product $a_i \times a_{i+1}$ is **not** a perfect square.

## Intuition & Mathematical Observation
The condition requires that no two adjacent numbers multiply to a perfect square. A naive approach like reversing the sequence ($N, N-1, \dots, 1$) fails for certain values (e.g., $N=8$, where $8 \times 2 = 16$).

Since the constraints on $N$ are relatively small ($N \le 500$), we can leverage the fact that the space of permutations is large and the density of "invalid" adjacent pairs is low. A randomized approach is highly effective here:
1. Start with an initial permutation (e.g., $1, 2, \dots, N$).
2. Check if the current permutation satisfies the condition.
3. If it does not, perform a random shuffle of the array.
4. Repeat until a valid permutation is found.

Because the probability of a random permutation being valid is high for these constraints, this approach converges almost instantaneously.

## Complexity Analysis
- **Time Complexity**: $O(T \times K \times N)$, where $T$ is the number of test cases, $N$ is the size of the permutation, and $K$ is the number of shuffles required. In practice, $K$ is very small (often 1 or 2), making the solution extremely efficient.
- **Space Complexity**: $O(N)$ to store the permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to arrange numbers from 1 to N such that no two adjacent elements 
 * have a product that is a perfect square.
 * 
 * Given N <= 500, a randomized approach (Las Vegas algorithm) is highly 
 * efficient. We shuffle the array until the condition is satisfied.
 */

bool is_perfect_square(int n) {
    int root = round(sqrt(n));
    return root * root == n;
}

bool check(const vector<int>& p) {
    for (size_t i = 0; i < p.size() - 1; ++i) {
        if (is_perfect_square(p[i] * p[i + 1])) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    
    // Random shuffle is very likely to find a valid permutation quickly
    // for N <= 500.
    mt19937 rng(1337);
    while (!check(p)) {
        shuffle(p.begin(), p.end(), rng);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```