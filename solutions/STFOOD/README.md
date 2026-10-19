# [Chef and Street Food (STFOOD)](https://www.codechef.com/problems/STFOOD)

- **Difficulty Rating**: 1268
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to open a new street food store. There are $N$ different types of food available. For each type $i$, we are given:
- $S_i$: The number of existing stores already selling this food.
- $P_i$: The total number of people who visit the street to buy this food.
- $V_i$: The price of one piece of food.

If Chef opens a new store for food type $i$, the total number of stores becomes $S_i + 1$. The $P_i$ people are distributed equally among all $S_i + 1$ stores. Chef's profit for that specific food type is the number of people who visit his store multiplied by the price $V_i$. We need to determine the maximum profit Chef can make by choosing the best food type to sell.

## Intuition & Mathematical Observation
For any food type $i$, if Chef opens a store, the number of people visiting his store is given by the integer division:
$$\text{People per store} = \lfloor \frac{P_i}{S_i + 1} \rfloor$$

The profit for that specific food type is:
$$\text{Profit}_i = \lfloor \frac{P_i}{S_i + 1} \rfloor \times V_i$$

Since we want to maximize the total profit, we simply iterate through all $N$ food types, calculate the potential profit for each, and keep track of the maximum value found.

**Key constraints note:** The maximum possible profit is $10,000 \times 10,000 = 10^8$, which fits comfortably within a standard 32-bit integer (`int`), but using `long long` is good practice to prevent overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of food types. We perform a single pass through the input.
- **Space Complexity**: $O(1)$, as we only store a few variables to keep track of the current and maximum profit.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each food type i:
 * - S_i: number of existing stores
 * - P_i: number of people
 * - V_i: price per piece
 * 
 * Chef opens a new store, so the total number of stores for type i becomes (S_i + 1).
 * The number of people buying from Chef's new store is floor(P_i / (S_i + 1)).
 * The profit for type i is: floor(P_i / (S_i + 1)) * V_i.
 * 
 * We need to find the maximum profit among all N types.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long max_profit = 0;
    
    for (int i = 0; i < N; ++i) {
        long long S, P, V;
        cin >> S >> P >> V;
        
        // Chef opens a store, so total stores = S + 1
        // People per store = floor(P / (S + 1))
        // Profit = (P / (S + 1)) * V
        long long current_profit = (P / (S + 1)) * V;
        
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }
    
    cout << max_profit << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}
```