# [Reselling Items (RESELL)](https://www.codechef.com/problems/RESELL)

- **Difficulty Rating**: 903
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ items, each with a specific resale value $A_i$. There are two types of buying costs:
1. The first $K$ items purchased cost **5 coins** each.
2. Any items purchased after the first $K$ cost **10 coins** each.

The goal is to select a subset of items to purchase such that the total profit (Total Resale Value - Total Cost) is maximized.

## Intuition & Mathematical Observation
To maximize profit, we must prioritize items with the highest resale values. 

1. **Sorting**: By sorting the items in descending order, we ensure that we consider the most valuable items first.
2. **Greedy Strategy**:
   - We have $K$ "discounted" slots (cost 5). We should assign the $K$ most valuable items to these slots, provided their resale value $A_i > 5$.
   - For all remaining items (index $i \ge K$), we should only purchase them if their resale value $A_i > 10$, as the cost to acquire them is 10.
3. **Profit Calculation**:
   - For the first $K$ items: If $A_i > 5$, add $(A_i - 5)$ to the total profit.
   - For the remaining items: If $A_i > 10$, add $(A_i - 10)$ to the total profit.

This greedy approach works because each item's profit is independent of the others, and sorting allows us to make the optimal decision for each slot type.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan through the array takes $O(N)$. Thus, the overall complexity is $O(N \log N)$ per test case.
- **Space Complexity**: $O(N)$ to store the resale values of the $N$ items.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize profit, we sort items by resale value descending.
 * We use the K discount slots (cost 5) for the highest values, 
 * then use the standard slots (cost 10) for the rest, 
 * provided the profit for each item is positive.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to pick the best items first
    sort(A.rbegin(), A.rend());

    long long total_profit = 0;
    for (int i = 0; i < N; ++i) {
        if (i < K) {
            // Use the discount slot (cost 5)
            if (A[i] > 5) {
                total_profit += (A[i] - 5);
            }
        } else {
            // Use the standard slot (cost 10)
            if (A[i] > 10) {
                total_profit += (A[i] - 10);
            }
        }
    }

    cout << total_profit << "\n";
}

int main() {
    // Fast I/O
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