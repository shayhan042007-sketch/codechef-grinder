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
 * 
 * Constraints:
 * T <= 100, N <= 100, S_i, P_i, V_i <= 10,000.
 * Max profit per type = (10,000 / 1) * 10,000 = 100,000,000.
 * This fits within a standard 32-bit signed integer, but using long long is safer.
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