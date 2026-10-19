#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N items with resale values A_i.
 * Buying an item costs 5 coins if it is among the first K items bought.
 * Buying an item costs 10 coins if it is bought after the first K items.
 * 
 * To maximize profit, we should:
 * 1. Sort the items in descending order of their resale value A_i.
 * 2. For each item, calculate the potential profit:
 *    - If we buy it as one of the first K items, profit = A_i - 5.
 *    - If we buy it as one of the subsequent items, profit = A_i - 10.
 * 3. We should only buy an item if the profit is positive.
 * 4. Since we want to maximize profit, we should prioritize the items that give 
 *    the highest profit.
 * 5. Specifically, we have K slots that cost 5 and infinite slots that cost 10.
 *    We should use the K slots for the items with the highest A_i values, 
 *    provided A_i > 5. Then, for the remaining items, we should buy them 
 *    if A_i > 10.
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
            // Use the discount slot
            if (A[i] > 5) {
                total_profit += (A[i] - 5);
            }
        } else {
            // Use the standard slot
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