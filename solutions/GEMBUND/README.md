# [Gem Bundles (GEMBUND)](https://www.codechef.com/problems/GEMBUND)

- **Difficulty Rating**: 603
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $R$ red, $B$ blue, and $G$ green gems. Each individual gem can be sold for 3 coins. Alternatively, you can combine one of each color (1 Red, 1 Blue, 1 Green) into a "bundle" that sells for 10 coins. The goal is to maximize the total number of coins earned by choosing the optimal number of bundles to create.

## Intuition & Mathematical Observation
Let $k$ be the number of bundles created. Since each bundle requires one of each color, $k$ can range from $0$ to $\min(R, B, G)$.

If we create $k$ bundles, the remaining gems are $(R-k)$ red, $(B-k)$ blue, and $(G-k)$ green. The total coins earned is:
$$\text{Total} = (k \times 10) + ((R-k) + (B-k) + (G-k)) \times 3$$

Expanding this expression:
$$\text{Total} = 10k + 3(R + B + G - 3k)$$
$$\text{Total} = 10k + 3(R + B + G) - 9k$$
$$\text{Total} = k + 3(R + B + G)$$

From this formula, we can see that for every bundle we create, we gain 1 extra coin compared to selling the gems individually (since $10 > 3+3+3$). Therefore, to maximize the total coins, we must maximize $k$. The maximum possible value for $k$ is simply $\min(R, B, G)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and a minimum calculation.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each bundle of (1R, 1B, 1G) sells for 10 coins.
 * Selling gems individually yields 3 coins per gem.
 * 
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 * Simplifying this shows that each bundle adds 1 extra coin 
 * compared to selling gems individually.
 * Thus, we maximize k by taking k = min(R, B, G).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, b, g;
        cin >> r >> b >> g;

        // Maximum number of bundles possible
        long long k = min({r, b, g});

        // Calculate total coins based on the derived formula
        long long total_coins = (k * 10) + ((r - k) + (b - k) + (g - k)) * 3;

        cout << total_coins << "\n";
    }

    return 0;
}
```