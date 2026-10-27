#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Problem Analysis:
 * For a fixed K, we perform N - K + 1 operations.
 * In each operation, we add an element and remove one.
 * Effectively, we are choosing N - K + 1 elements from the array A to sum up.
 * The constraint is that we must be able to pick an element at each step i from K to N.
 * This is always satisfied if we pick the largest N - K + 1 elements.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sortedA[i];
    }

    for (int K = 1; K <= N; ++K) {
        int count = N - K + 1;
        // Sum of the largest 'count' elements
        long long current_sum = prefix_sum[N] - prefix_sum[N - count];
        cout << current_sum << (K == N ? "" : " ");
    }
    cout << "\n";
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