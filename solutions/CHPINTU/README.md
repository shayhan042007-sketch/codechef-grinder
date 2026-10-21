# [Pintu and Fruits (CHPINTU)](https://www.codechef.com/problems/CHPINTU)

- **Difficulty Rating**: 1313
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ baskets of fruits. Each basket $i$ contains a fruit of type $F_i$ and has a price $P_i$. We need to select exactly one fruit type $k$ (where $1 \le k \le M$) such that if we buy all baskets containing fruit type $k$, the total cost is minimized. We are only allowed to consider fruit types that are actually present in the input.

## Intuition & Mathematical Observation
Since the constraints are small ($N, M \le 50$), we can aggregate the total cost for each fruit type independently. 

1. **Data Aggregation**: We use an array `cost_map` of size $M+1$ to store the cumulative sum of prices for each fruit type.
2. **Tracking Presence**: We use a boolean array `exists_map` to keep track of which fruit types are actually present in the baskets. This is crucial because we must ignore fruit types that do not appear in the input.
3. **Minimization**: After iterating through all $N$ baskets and populating our maps, we iterate through the range $[1, M]$. For every index $i$ where `exists_map[i]` is true, we compare `cost_map[i]` with our current `min_price` and update it if a smaller value is found.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of baskets. We iterate through the baskets once to aggregate costs and then iterate through $M$ fruit types to find the minimum.
- **Space Complexity**: $O(M)$, where $M$ is the maximum number of fruit types, used to store the `cost_map` and `exists_map`.

## Solution Code

```cpp
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
```