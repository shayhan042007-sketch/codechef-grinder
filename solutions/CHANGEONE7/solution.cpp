#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We must change exactly one element to minimize (max(A) - min(A)).
 * 
 * Let the sorted array be S_1, S_2, ..., S_N.
 * The current range is S_N - S_1.
 * 
 * To minimize the range by changing one element, we have two main strategies:
 * 1. Change the minimum element (S_1) to be equal to the second minimum (S_2).
 *    The new range becomes S_N - S_2.
 * 2. Change the maximum element (S_N) to be equal to the second maximum (S_{N-1}).
 *    The new range becomes S_{N-1} - S_1.
 * 
 * Since we want the minimum of these two possibilities, the answer is min(S_N - S_2, S_{N-1} - S_1).
 * 
 * Constraints: N >= 2, so S_2 and S_{N-1} always exist.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to easily identify min, max, second min, and second max
    sort(A.begin(), A.end());

    // If N=2, we can always make them equal (range 0)
    if (N == 2) {
        cout << 0 << "\n";
        return;
    }

    // Option 1: Change A[0] to A[1], range becomes A[N-1] - A[1]
    int option1 = A[N - 1] - A[1];
    
    // Option 2: Change A[N-1] to A[N-2], range becomes A[N-2] - A[0]
    int option2 = A[N - 2] - A[0];

    cout << min(option1, option2) << "\n";
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