#include <iostream>
#include <vector>

/**
 * Problem: IPCCERT
 * Complexity Analysis:
 * Time Complexity: O(N * K)
 * Space Complexity: O(1)
 * 
 * The logic remains O(N * K). By ensuring we use fast I/O and minimal 
 * memory allocation, we ensure the solution passes within the time limit.
 */

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    long long M;

    if (!(cin >> N >> M >> K)) return 0;

    int eligible_count = 0;

    for (int i = 0; i < N; ++i) {
        long long total_time = 0;
        for (int j = 0; j < K; ++j) {
            int t;
            cin >> t;
            total_time += t;
        }

        int Q;
        cin >> Q;

        // Criteria:
        // 1. Total time watched >= M
        // 2. Questions asked <= 10
        if (total_time >= M && Q <= 10) {
            eligible_count++;
        }
    }

    cout << eligible_count << "\n";

    return 0;
}