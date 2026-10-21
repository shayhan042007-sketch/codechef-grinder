# [Bakery Problem (BAKERY7)](https://www.codechef.com/problems/BAKERY7)

- **Difficulty Rating**: 284
- **Solved in**: 2 attempt(s)

## Problem Summary
You need to purchase $N$ cakes. There are two ways to buy them:
1. **Standard Price**: Each cake costs 100 units. Total cost = $N \times 100$.
2. **Bribe Price**: You pay a one-time bribe of $K$ units, and then each cake costs 60 units. Total cost = $K + (N \times 60)$.

The goal is to determine the minimum cost to acquire exactly $N$ cakes.

## Intuition & Mathematical Observation
The problem is a simple comparison between two linear functions of $N$:
* Let $f(N) = 100N$
* Let $g(N) = 60N + K$

To find the minimum cost, we simply calculate both values and output the smaller one using the `min()` function. Since $N$ and $K$ can be large, using `long long` in C++ is a safe practice to prevent potential integer overflow, although given the constraints of typical beginner problems, standard integers might suffice.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  - The solution performs a constant number of arithmetic operations and a comparison, regardless of the input size.
- **Space Complexity**: $O(1)$
  - We only use a few variables to store the input and the calculated costs, requiring constant auxiliary space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to buy N cakes.
 * Option 1: No bribe. Cost = N * 100.
 * Option 2: Bribe. Cost = K + (N * 60).
 * We need to find the minimum of these two options.
 */

int main() {
    // Fast I/O setup for efficiency
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    if (cin >> N >> K) {
        // Calculate costs for both scenarios
        long long cost_no_bribe = N * 100;
        long long cost_with_bribe = K + (N * 60);

        // Output the minimum of the two
        cout << min(cost_no_bribe, cost_with_bribe) << endl;
    }

    return 0;
}
```