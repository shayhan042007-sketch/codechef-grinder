#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * - Cakewalk: solved_by >= P / 2
 * - Hard: solved_by <= P / 10
 * - Balanced: exactly 1 cakewalk AND exactly 2 hard problems.
 * 
 * Constraints:
 * - P <= 10^8, so use long long for thresholds.
 * - N <= 500, O(N) per test case is optimal.
 */

void solve() {
    int N;
    long long P;
    if (!(cin >> N >> P)) return;

    int cakewalk_count = 0;
    int hard_count = 0;

    long long cakewalk_threshold = P / 2;
    long long hard_threshold = P / 10;

    for (int i = 0; i < N; ++i) {
        long long solved_by;
        cin >> solved_by;

        if (solved_by >= cakewalk_threshold) {
            cakewalk_count++;
        } else if (solved_by <= hard_threshold) {
            hard_count++;
        }
    }

    if (cakewalk_count == 1 && hard_count == 2) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}