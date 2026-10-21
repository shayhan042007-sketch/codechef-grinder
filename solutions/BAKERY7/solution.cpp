#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to buy N cakes.
 * Option 1: No bribe. Cost = N * 100.
 * Option 2: Bribe. Cost = K + (N * 60).
 * We need to find the minimum of these two options.
 * 
 * The input format specifies a single line with N and K, 
 * not multiple test cases.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    if (cin >> N >> K) {
        long long cost_no_bribe = N * 100;
        long long cost_with_bribe = K + (N * 60);

        cout << min(cost_no_bribe, cost_with_bribe) << endl;
    }

    return 0;
}