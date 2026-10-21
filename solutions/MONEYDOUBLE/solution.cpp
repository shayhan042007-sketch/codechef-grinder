#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X rupees initially and Y years.
 * Each year, he can either:
 * 1. Add 1000: X = X + 1000
 * 2. Double: X = X * 2
 * 
 * Since Y is very small (up to 10), we want to maximize the final amount.
 * Intuitively, doubling is more effective when X is large, and adding 1000 
 * is more effective when X is small.
 * 
 * Let's compare the two operations:
 * If we add 1000 then double: (X + 1000) * 2 = 2X + 2000
 * If we double then add 1000: (X * 2) + 1000 = 2X + 1000
 * 
 * Clearly, adding 1000 before doubling is always better than doubling before adding 1000.
 * Therefore, the optimal strategy is to perform all additions of 1000 first, 
 * and then perform all doublings.
 * 
 * However, since Y is only 10, we can simply simulate the greedy choice:
 * At each step, compare (X + 1000) * 2^(remaining_years - 1) vs (X * 2) * 2^(remaining_years - 1).
 * Actually, it is simpler: at any point, if we have Y years left, we should 
 * choose the operation that results in a larger value.
 * Since (X + 1000) * 2 > X * 2 + 1000, we should always add 1000 first 
 * if it helps, but wait—the doubling is multiplicative.
 * 
 * Actually, for any year, we check:
 * Option A: (X + 1000)
 * Option B: (X * 2)
 * We pick the max and move to the next year.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    for (int i = 0; i < Y; ++i) {
        long long add_option = X + 1000;
        long long double_option = X * 2;
        
        if (add_option > double_option) {
            X = add_option;
        } else {
            X = double_option;
        }
    }
    cout << X << "\n";
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