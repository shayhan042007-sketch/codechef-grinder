#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N plates with P_i meatballs. We need to select the minimum number of plates
 * such that the sum of meatballs is at least M.
 * 
 * Strategy:
 * 1. To minimize the number of plates, we should always pick the plates with the 
 *    largest number of meatballs first (Greedy approach).
 * 2. Sort the array of meatballs in descending order.
 * 3. Keep adding the largest plates until the sum is >= M.
 * 4. If the total sum of all plates is less than M, it's impossible, output -1.
 * 
 * Constraints:
 * N <= 7 (This is very small, but the logic works for any N).
 * M, P_i <= 10^18 (Must use long long).
 */

void solve() {
    int N;
    long long M;
    if (!(cin >> N >> M)) return;

    vector<long long> P(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        total_sum += P[i];
    }

    // If total meatballs available are less than M, impossible.
    if (total_sum < M) {
        cout << -1 << "\n";
        return;
    }

    // Sort in descending order to pick largest plates first
    sort(P.rbegin(), P.rend());

    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        current_sum += P[i];
        count++;
        if (current_sum >= M) {
            cout << count << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}