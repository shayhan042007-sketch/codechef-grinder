#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * To maximize John's total votes with the minimum number of swaps, we should
 * always swap the smallest pack from A with the largest pack from B, provided
 * that the pack from A is smaller than the pack from B.
 * 
 * Algorithm:
 * 1. Calculate the current sum of A and B.
 * 2. If sum(A) > sum(B), 0 swaps are needed.
 * 3. Sort A in ascending order and B in descending order.
 * 4. Iterate and swap A[i] with B[i] as long as A[i] < B[i] and sum(A) <= sum(B).
 * 5. Keep track of the number of swaps.
 * 6. If after all possible beneficial swaps sum(A) is still <= sum(B), return -1.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int swaps = 0;
    int i = 0;
    while (sumA <= sumB) {
        // If we run out of packs to swap, it's impossible
        if (i >= N || i >= M || A[i] >= B[i]) {
            cout << -1 << "\n";
            return;
        }
        
        // Perform swap
        sumA = sumA - A[i] + B[i];
        sumB = sumB - B[i] + A[i];
        swaps++;
        i++;
    }

    cout << swaps << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}