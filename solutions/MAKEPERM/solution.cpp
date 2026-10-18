#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, we must have C_i >= A_i.
 * This means for every element in the target permutation (1 to N), we must be able 
 * to map it to an element in A such that the value in the permutation is >= the 
 * value in A.
 * 
 * Let's sort array A in non-decreasing order.
 * Let the sorted array be A_sorted.
 * Let the target permutation be P = {1, 2, ..., N}.
 * 
 * If we sort A, we can greedily check if A_sorted[i] <= (i + 1) for all i from 0 to N-1.
 * If A_sorted[i] > (i + 1) for any i, then even if we pick the smallest available 
 * values for the permutation, we cannot satisfy the condition because the smallest 
 * possible value we could assign to A_sorted[i] is at least A_sorted[i], which 
 * would exceed the value (i + 1).
 * 
 * Actually, the condition is simpler: if we sort A, we need to be able to map 
 * each A[i] to a distinct value in {1, ..., N} such that A[i] <= P[i].
 * By sorting A, we ensure that the smallest elements of A are matched against 
 * the smallest possible values of the permutation. If A_sorted[i] > i + 1, 
 * it is impossible to satisfy the condition for that element and all subsequent 
 * elements because they are all larger.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // The smallest value we can assign to A[i] is A[i] itself.
        // If A[i] is already greater than the (i+1)-th smallest value 
        // in the permutation (which is i+1), we can't form a permutation.
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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