# [Ballon d Or (BLNDOR)](https://www.codechef.com/problems/BLNDOR)

- **Difficulty Rating**: 1062
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array consisting only of integers $1$ and $2$, determine if the product of all elements in the array can be expressed as $k^8$ for some integer $k$.

## Intuition & Mathematical Observation
1. **Analyze the Product**: Since the array contains only $1$s and $2$s, the product of all elements is determined solely by the number of $2$s. If there are $c$ occurrences of the number $2$, the product is $1^{(N-c)} \times 2^c = 2^c$.
2. **Formulate the Condition**: We need to check if $2^c = k^8$ for some integer $k$.
3. **Solve for $c$**: 
   - For $k^8$ to be a power of $2$, $k$ itself must be a power of $2$ (let $k = 2^x$).
   - Substituting this into the equation: $2^c = (2^x)^8 = 2^{8x}$.
   - By equating the exponents, we get $c = 8x$.
4. **Conclusion**: The condition $c = 8x$ implies that the count of $2$s in the array must be a multiple of $8$. This holds true even if $c=0$ (since $0$ is a multiple of $8$ and $2^0 = 1 = 1^8$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the size of the array. We iterate through the array exactly once to count the occurrences of $2$.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to keep track of the count of $2$s.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains only 1s and 2s.
 * Let 'c' be the count of 2s in the array.
 * The product of all elements is 1^(N-c) * 2^c = 2^c.
 * We need to check if 2^c = k^8 for some integer k.
 * Since 2^c = k^8, k must be a power of 2, say k = 2^x.
 * Then 2^c = (2^x)^8 = 2^(8x).
 * This implies c = 8x, meaning c must be a multiple of 8.
 */

void solve() {
    int n;
    cin >> n;
    int count_twos = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 2) {
            count_twos++;
        }
    }

    // Check if the count of 2s is a multiple of 8
    if (count_twos % 8 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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