#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N baskets, each having a fruit type F_i and a price P_i.
 * We need to choose one fruit type (from 1 to M) such that we buy all baskets
 * containing that fruit type, and the total cost is minimized.
 * 
 * Constraints:
 * T <= 1000, N, M <= 50.
 * Since N and M are small, we can use an array to store the total cost for each fruit type.
 * We must ensure we only consider fruit types that actually appear in the input.
 * 
 * Complexity:
 * Time: O(T * N)
 * Space: O(M)
 */

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // cost_map stores the sum of prices for each fruit type.
    // exists_map tracks if a fruit type is present in the baskets.
    vector<long long> cost_map(M + 1, 0);
    vector<bool> exists_map(M + 1, false);

    for (int i = 0; i < N; ++i) {
        cost_map[F[i]] += P[i];
        exists_map[F[i]] = true;
    }

    long long min_price = -1;

    for (int i = 1; i <= M; ++i) {
        if (exists_map[i]) {
            if (min_price == -1 || cost_map[i] < min_price) {
                min_price = cost_map[i];
            }
        }
    }

    cout << min_price << "\n";
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