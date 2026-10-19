#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A subsequence is "cool" if the averages of all its non-empty subsequences 
 * are present in the complement subsequence.
 * 
 * Consider a subsequence of length 1, say [x].
 * The only non-empty subsequence is [x], and its average is x.
 * The condition requires that x must be present in the complement subsequence.
 * This means if we pick an element x from the array, there must be at least 
 * one more occurrence of x in the remaining array.
 * 
 * If the array contains any duplicate element x, we can pick a subsequence [x, x].
 * The non-empty subsequences are [x], [x], [x, x].
 * Their averages are x, x, x.
 * If there is at least one x in the complement, the condition is satisfied.
 * 
 * Actually, even simpler: if there is any duplicate element x in the array,
 * we can pick a subsequence of length 1, [x]. The complement will contain 
 * at least one x (since there were at least two x's originally).
 * The average of [x] is x, and x is in the complement.
 * Thus, [x] is a cool subsequence.
 * 
 * If all elements are distinct, can we have a cool subsequence?
 * If we pick a subsequence of length K > 1, the averages of its subsequences
 * must be in the complement. If all elements are distinct, the average of 
 * a subsequence of length > 1 is rarely an integer, and even if it is, 
 * it's unlikely to be in the complement.
 * 
 * Conclusion:
 * If there is any duplicate element x, [x] is a cool subsequence.
 * If all elements are distinct, no such subsequence exists (output -1).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    int duplicate = -1;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
        if (counts[A[i]] > 1) {
            duplicate = A[i];
        }
    }

    if (duplicate != -1) {
        cout << 1 << "\n";
        cout << duplicate << "\n";
    } else {
        cout << -1 << "\n";
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