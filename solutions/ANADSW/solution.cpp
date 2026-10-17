#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can swap any two elements A[i] and A[j] if |i - j| > 1.
 * 
 * Case N = 1: Always sorted. YES.
 * Case N = 2: If A[1] <= A[2], YES. If A[1] > A[2], we cannot swap (distance is 1), so NO.
 * Case N = 3: We can swap (1, 3). This allows us to reach any permutation of the array 
 * because we can effectively swap (1, 2) by:
 * Swap (1, 3), then (2, 3), then (1, 3).
 * Wait, let's re-verify:
 * If N >= 4, we can swap any two adjacent elements.
 * To swap A[i] and A[i+1]:
 * Pick an index k such that k is not i and not i+1.
 * Swap(A[i], A[k]), Swap(A[i+1], A[k]), Swap(A[i], A[k]).
 * This is possible if there exists at least one k such that |i-k| > 1 and |i+1-k| > 1.
 * For N >= 4, such a k always exists.
 * 
 * For N = 3:
 * We can swap (1, 3). Can we swap (1, 2)?
 * Swap (1, 3) -> (A3, A2, A1).
 * We cannot swap (1, 2) or (2, 3) directly.
 * Actually, for N=3, the only reachable permutations from (A1, A2, A3) are:
 * (A1, A2, A3) and (A3, A2, A1).
 * So for N=3, we check if the array is already sorted OR if swapping the ends makes it sorted.
 * 
 * General rule:
 * If N=1, YES.
 * If N=2, check if sorted.
 * If N=3, check if sorted OR (A[3], A[2], A[1]) is sorted.
 * If N >= 4, we can perform any swap, so we can always sort the array. YES.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check if sorted
        bool sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i + 1]) sorted = false;
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Check if swapping ends makes it sorted
        swap(A[0], A[2]);
        sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i + 1]) sorted = false;
        if (sorted) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, we can perform any adjacent swap, so any permutation is reachable.
        cout << "YES" << "\n";
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