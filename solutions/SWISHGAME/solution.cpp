#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the string of length M.
 * Let 'swishes' be the count of 'S' in S.
 * 
 * Case 1: The game ended because Toofan reached K swishes.
 * In this case, the game must have ended exactly at move M.
 * This implies N = M.
 * 
 * Case 2: The game ended because it became impossible to reach K swishes.
 * Let 'swishes' be the number of 'S' in the string S.
 * Let 'rem' be the number of remaining rings after move M, i.e., N - M.
 * The game ends when the current swishes + remaining rings < K.
 * Specifically, the game ends at move M if:
 * 1. At move M-1, it was still possible to win (swishes_at_M-1 + (N - (M-1)) >= K).
 * 2. At move M, it is impossible to win (swishes_at_M + (N - M) < K).
 * 
 * Since the game ends at M, it means at move M, the condition (swishes + (N - M) < K) 
 * must hold. The smallest N that satisfies this is when the game becomes impossible 
 * exactly at M.
 * 
 * If swishes >= K, the game ends at M, so N = M.
 * If swishes < K, the game ends at M if the number of remaining rings (N-M) 
 * is such that even if all remaining rings were swishes, he couldn't reach K.
 * The condition for impossibility is: swishes + (N - M) = K - 1.
 * Therefore, N = K - 1 - swishes + M.
 */

void solve() {
    int M, K;
    cin >> M >> K;
    string S;
    cin >> S;

    int swishes = 0;
    for (char c : S) {
        if (c == 'S') {
            swishes++;
        }
    }

    if (swishes >= K) {
        // Game ended because he reached K swishes
        cout << M << "\n";
    } else {
        // Game ended because it became impossible to reach K swishes
        // He has 'swishes' count. He needs K.
        // He has (N - M) rings left.
        // The game ends at M if swishes + (N - M) == K - 1
        // N = K - 1 - swishes + M
        long long N = (long long)K - 1 - swishes + M;
        cout << N << "\n";
    }
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