#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each index i, we choose either A[i] or B[i].
 * Let x_i be the chosen value (0 or 1).
 * Score = sum(x_i) for i = 1 to N.
 * We want Score to be odd.
 * 
 * Let's categorize the indices based on (A[i], B[i]):
 * 1. (0, 0): Choosing either gives 0. Contribution to score is always 0.
 * 2. (1, 1): Choosing either gives 1. Contribution to score is always 1.
 * 3. (0, 1) or (1, 0): We can choose 0 or 1. Contribution to score can be 0 or 1.
 * 
 * Let 'ones' be the count of indices where (A[i], B[i]) is (1, 1).
 * Let 'diff' be the count of indices where (A[i], B[i]) is (0, 1) or (1, 0).
 * 
 * If 'diff' > 0, we can change the parity of the total score by toggling the choice 
 * at any of these 'diff' indices. Thus, if 'diff' > 0, we can always achieve 
 * either an even or an odd score.
 * 
 * If 'diff' == 0, the score is fixed to the number of (1, 1) pairs.
 * In this case, the score is simply 'ones'. We just check if 'ones' is odd.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int ones = 0;
    int diff = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] == '1' && B[i] == '1') {
            ones++;
        } else if (A[i] != B[i]) {
            diff++;
        }
    }

    if (diff > 0) {
        cout << "YES" << "\n";
    } else {
        if (ones % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}