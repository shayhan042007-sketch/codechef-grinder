#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to turn all 1s into 0s.
 * 1. If there are no 1s, the answer is 0.
 * 2. If there are no adjacent 1s, we can flip all 1s in a single operation. Answer is 1.
 * 3. If there are adjacent 1s, we check if we can do it in 2 operations.
 *    - In one operation, we can pick a set of non-adjacent indices.
 *    - If we have adjacent 1s (e.g., "11"), we can't flip them both at once.
 *    - However, we can split the 1s into two sets such that no two 1s in the same set are adjacent.
 *    - For example, "11" can be split into {1} and {2}.
 *    - Any string can be partitioned into two sets of non-adjacent indices (e.g., odd indices and even indices).
 *    - Thus, the answer is at most 2.
 *    - The only case where it's 2 is if there exists at least one pair of adjacent 1s.
 *    - Wait, is it always 2 if there are adjacent 1s? Yes, because we can pick all 1s at odd positions
 *      in one move and all 1s at even positions in another move.
 *    - The only constraint is that we cannot pick adjacent indices.
 *    - If we have "11", we need 2 operations.
 *    - If we have "101", we need 1 operation.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_one = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_one = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_one) {
        cout << 0 << "\n";
    } else if (!has_adjacent_ones) {
        cout << 1 << "\n";
    } else {
        // If there are adjacent 1s, we check if we can do it in 2.
        // The only case where it might be more than 2 is if we can't split
        // the adjacent 1s. But we can always split any string into two sets
        // of non-adjacent indices (e.g., all indices i where i%2==0 and all i where i%2!=0).
        // So 2 is always sufficient if there are adjacent 1s.
        cout << 2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}