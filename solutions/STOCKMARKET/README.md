# [Chef and Stocks (STOCKMARKET)](https://www.codechef.com/problems/STOCKMARKET)

- **Difficulty Rating**: 948
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a list of predicted stock prices for $N$ days. He wants to maximize his total profit by choosing to skip exactly one day. The goal is to calculate the maximum possible sum of the stock prices after removing the price of the day that yields the lowest value.

## Intuition & Mathematical Observation
The total profit is the sum of all stock prices $A_1, A_2, \dots, A_N$. If we must skip exactly one day, the total profit becomes:
$$\text{Total Profit} = \left( \sum_{i=1}^{N} A_i \right) - A_{\text{skipped}}$$

To maximize this expression, we need to subtract the smallest possible value from the total sum. Therefore, the strategy is:
1. Calculate the sum of all elements in the array.
2. Identify the minimum element in the array.
3. Subtract the minimum element from the total sum to get the maximum possible profit.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days. We iterate through the array exactly once to calculate the sum and find the minimum value.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the running sum and the minimum value (excluding the input storage).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - (A_i skipped).
 * To maximize this, we need to minimize the value of the skipped day (A_i).
 */

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    long long total_sum = 0;
    long long min_val = 101; // Since max A_i is 100 per constraints
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }
    
    // We skip the day with the minimum profit to maximize the remaining sum
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O for performance
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