# [Distribute Apples (DSTAPLS)](https://www.codechef.com/problems/DSTAPLS)

- **Difficulty Rating**: 1374
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ apples and $K$ boxes. Two distribution methods are compared:
1. **Method 1**: Distribute 1 apple to each of the $K$ boxes, repeating this process until all $N$ apples are distributed. This results in every box containing exactly $N/K$ apples.
2. **Method 2**: Distribute $K$ apples into one box at a time. This results in $N/K$ boxes receiving $K$ apples each, while the remaining boxes receive 0 apples.

We need to determine if these two distributions result in the same outcome for all boxes.

## Intuition & Mathematical Observation
*   **Method 1 Result**: Every box contains exactly $N/K$ apples.
*   **Method 2 Result**: Some boxes contain $K$ apples, and others contain $0$ apples.

For the distributions to be identical, every box must contain the same number of apples. In Method 2, this only happens if $K$ is equal to $0$ (impossible) or if the number of boxes receiving $K$ apples is exactly $K$ (meaning every box gets $K$ apples). 

If we look at the condition where the distributions are the same:
- Method 1 gives $N/K$ apples per box.
- Method 2 gives $K$ apples to $N/K$ boxes.

The distributions are identical if and only if the number of apples per box in Method 1 ($N/K$) is **not** a multiple of $K$. If $(N/K)$ is a multiple of $K$, it implies that the apples are distributed in such a way that the "gaps" created by Method 2 align with the uniform distribution of Method 1. Specifically, if $(N/K) \% K == 0$, the distributions are different. Otherwise, they are the same.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

/**
 * Problem Analysis:
 * Method 1 results in every box having (N/K) apples.
 * Method 2 results in (N/K) boxes having K apples and others having 0.
 * 
 * The distributions are the same if (N/K) % K == 0.
 * If (N/K) is divisible by K, the distributions are different (Output NO).
 * Otherwise, they are the same (Output YES).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate apples per box for Method 1
        long long apples_per_box = n / k;
        
        // Check if the distribution is the same
        if (apples_per_box % k == 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }

    return 0;
}
```