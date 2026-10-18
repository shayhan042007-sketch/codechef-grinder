#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an initial sequence X and a transformed sequence Y.
 * We need to find a pivot index i (1 <= i <= N) such that if we set P = X[i],
 * and create a list of pairs (abs(X[j] - P), X[j]), sorting them according to the
 * specified rules results in the sequence Y.
 * 
 * Constraints: N <= 100.
 * This allows an O(N^2 log N) approach:
 * For each possible pivot index i from 1 to N:
 * 1. Calculate P = X[i-1].
 * 2. Construct the list of pairs L = {(abs(X[j] - P), X[j]) for j in 0..N-1}.
 * 3. Sort L based on the custom comparator:
 *    (A, B) < (C, D) if A < C or (A == C and B < D).
 * 4. Extract the second elements of the sorted list into a new sequence Y_calc.
 * 5. Compare Y_calc with the given Y. If they match, i is a valid pivot.
 * 6. If no index works, output -1.
 */

bool check(int n, const vector<int>& x, const vector<int>& y, int pivot_idx) {
    int p = x[pivot_idx];
    vector<pair<int, int>> l;
    for (int val : x) {
        l.push_back({abs(val - p), val});
    }
    
    sort(l.begin(), l.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    
    for (int i = 0; i < n; ++i) {
        if (l[i].second != y[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> y[i];
    
    for (int i = 0; i < n; ++i) {
        if (check(n, x, y, i)) {
            cout << i + 1 << "\n";
            return;
        }
    }
    
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}