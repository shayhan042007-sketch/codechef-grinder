#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N cars with initial prices P_i.
 * Each year, the price of every unsold car decreases by 1.
 * To maximize profit, we should sell the most expensive cars first.
 * If we sort the prices in descending order, say P'_1 >= P'_2 >= ... >= P'_N,
 * then in year 0 (first year), we sell the car with price P'_1.
 * In year 1, the price of the remaining cars has decreased by 1, so the car
 * originally worth P'_2 is now worth max(0, P'_2 - 1).
 * In year k, the car originally worth P'_{k+1} is worth max(0, P'_{k+1} - k).
 * 
 * The total profit is the sum of max(0, P'_i - (i-1)) for i = 1 to N.
 * Since we need the result modulo 1,000,000,007, we perform the sum
 * and take the modulo at each step or at the end.
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
        // The price of the car at index i (0-indexed) after i years is max(0, P[i] - i)
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