# [Sell All the Cars (CARSELL)](https://www.codechef.com/problems/CARSELL)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef owns $N$ cars, each with an initial price $P_i$. Every year, the price of every unsold car decreases by 1 unit. Chef can sell at most one car per year. The goal is to determine the maximum total profit Chef can achieve by selling all $N$ cars, given that the price of a car cannot drop below 0.

## Intuition & Mathematical Observation
To maximize the total profit, we must minimize the impact of the annual price depreciation. Since every unsold car loses 1 unit of value each year, we should prioritize selling the most expensive cars as early as possible.

1. **Sorting**: By sorting the car prices in descending order ($P'_1 \ge P'_2 \ge \dots \ge P'_N$), we ensure that the highest values are captured before they depreciate significantly.
2. **Depreciation**: 
   - In year 0, we sell the first car at price $P'_1$.
   - In year 1, the second car has depreciated by 1, so its price is $P'_2 - 1$.
   - In year $i$ (0-indexed), the car originally worth $P'_i$ will have depreciated by $i$ units.
3. **Constraint**: The price of a car cannot be negative. Therefore, the profit from the $i$-th car sold is $\max(0, P'_i - i)$.
4. **Modulo Arithmetic**: Since the total profit can be large, we perform the summation modulo $1,000,000,007$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear pass to calculate the total profit takes $O(N)$. Thus, the overall complexity is dominated by the sort: $O(N \log N)$.
- **Space Complexity**: $O(N)$ to store the prices of the $N$ cars.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize profit, we sell the most expensive cars first.
 * Sorting in descending order ensures we capture the highest values 
 * before they depreciate. The profit for the i-th car (0-indexed) 
 * is max(0, P[i] - i).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    
    // Sort in descending order to sell the most expensive cars first
    sort(P.begin(), P.end(), greater<long long>());
    
    long long total_profit = 0;
    long long MOD = 1000000007;
    
    for (int i = 0; i < N; ++i) {
        // The price of the car at index i after i years is max(0, P[i] - i)
        long long current_price = P[i] - i;
        if (current_price > 0) {
            total_profit = (total_profit + current_price) % MOD;
        }
    }
    
    cout << total_profit << "\n";
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