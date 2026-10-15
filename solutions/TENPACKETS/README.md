# [Buy Ten Packets (TENPACKETS)](https://www.codechef.com/problems/TENPACKETS)

- **Difficulty Rating**: 669
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to purchase exactly 10 packets of noodles. He has two options available:
1. Buy a pack of 2 for $X$ rupees.
2. Buy a pack of 4 for $Y$ rupees.

The goal is to find the minimum cost to obtain exactly 10 packets.

## Intuition & Mathematical Observation
To get exactly 10 packets using combinations of 2-packs and 4-packs, we can represent 10 as $2a + 4b = 10$, where $a$ is the number of 2-packs and $b$ is the number of 4-packs.

The possible non-negative integer solutions for $(b, a)$ are:
1. **(0, 5)**: 0 packs of 4 and 5 packs of 2. Cost = $5X$.
2. **(1, 3)**: 1 pack of 4 and 3 packs of 2. Cost = $Y + 3X$.
3. **(2, 1)**: 2 packs of 4 and 1 pack of 2. Cost = $2Y + X$.

Note: We cannot have 3 packs of 4 because $3 \times 4 = 12 > 10$.

Since the problem guarantees $X < Y \le 2X$, we know that a 4-pack is always cheaper than or equal to two 2-packs. Therefore, we should prioritize buying as many 4-packs as possible to minimize the cost. By calculating all three valid combinations and taking the minimum, we ensure the optimal cost is found regardless of the specific values of $X$ and $Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated costs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * We need to represent 10 as a sum of 2s and 4s.
 * Possible combinations (number of 4-packs, number of 2-packs):
 * 1. (0, 5): 0 * Y + 5 * X = 5X
 * 2. (1, 3): 1 * Y + 3 * X = Y + 3X
 * 3. (2, 1): 2 * Y + 1 * X = 2Y + X
 * 
 * We need to find the minimum of {5X, Y + 3X, 2Y + X}.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Calculate the three possible costs
        long long option1 = 5 * x;
        long long option2 = y + 3 * x;
        long long option3 = 2 * y + x;

        // Find the minimum
        long long min_cost = min({option1, option2, option3});

        cout << min_cost << "\n";
    }

    return 0;
}
```