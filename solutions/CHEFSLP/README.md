# [Chef and Pairing Slippers (CHEFSLP)](https://www.codechef.com/problems/CHEFSLP)

- **Difficulty Rating**: 930
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef has $N$ slippers in total, consisting of $L$ left slippers and $R$ right slippers (where $R = N - L$). A pair consists of one left slipper and one right slipper. Given the cost $X$ of one pair, calculate the maximum total revenue Chef can generate by selling as many pairs as possible.

## Intuition & Mathematical Observation
1. **Identify the components**: We are given the total number of slippers ($N$) and the number of left slippers ($L$).
2. **Calculate the missing component**: Since $N$ is the sum of left and right slippers, the number of right slippers is simply $R = N - L$.
3. **Forming pairs**: A pair requires exactly one left and one right slipper. Therefore, the number of complete pairs we can form is limited by the smaller quantity between $L$ and $R$.
   - `max_pairs = min(L, N - L)`
4. **Calculate Revenue**: Once we have the maximum number of pairs, we multiply this by the cost per pair ($X$) to get the total revenue.
5. **Data Types**: While the constraints are small, using `long long` for the final calculation is a good practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: CHEFSLP
 * Logic:
 * 1. Total slippers = N
 * 2. Left slippers = L
 * 3. Right slippers = N - L
 * 4. Max pairs = min(L, N - L)
 * 5. Total revenue = Max pairs * X
 */

void solve() {
    int n, l, x;
    if (!(cin >> n >> l >> x)) return;
    
    // Calculate right slippers
    int r = n - l;
    
    // The number of pairs is limited by the minimum of left or right slippers
    int max_pairs = min(l, r);
    
    // Output the total revenue
    cout << (long long)max_pairs * x << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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