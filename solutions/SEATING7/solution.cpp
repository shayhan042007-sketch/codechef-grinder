#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N seats, M are occupied. K people arrive one by one.
 * Each person takes the lowest numbered available seat.
 * Since N is small (up to 100), we can use a boolean array to track
 * occupied seats and iterate to find the lowest available seat for each of the K people.
 * 
 * Time Complexity: O(T * (N + K * N)) which is O(T * N^2).
 * Given N=100 and T=100, this is ~10^6 operations, well within the 1s limit.
 */

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<bool> occupied(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int seat;
        cin >> seat;
        occupied[seat] = true;
    }

    vector<int> results;
    for (int k = 0; k < K; ++k) {
        for (int seat = 1; seat <= N; ++seat) {
            if (!occupied[seat]) {
                occupied[seat] = true;
                results.push_back(seat);
                break;
            }
        }
    }

    for (int i = 0; i < K; ++i) {
        cout << results[i] << (i == K - 1 ? "" : " ");
    }
    cout << "\n";
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