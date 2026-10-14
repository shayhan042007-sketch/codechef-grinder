#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * A person is at index i (1-indexed) if A[i] == 1.
 * Social distancing is followed if for any two people at indices i and j (i < j),
 * the distance (j - i) is at least 6.
 * 
 * Algorithm:
 * Keep track of the index of the last person seen.
 * Iterate through the array. If we find a person (A[i] == 1):
 * 1. If this is not the first person seen, check if (current_index - last_person_index) < 6.
 * 2. If the condition is met, social distancing is violated (return "NO").
 * 3. Update last_person_index to current_index.
 * If the loop finishes without violations, return "YES".
 * 
 * Complexity:
 * Time: O(N) per test case, where N <= 100. Total O(T * N).
 * Space: O(N) to store the array, or O(1) if processed on the fly.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_pos = -10; // Initialize with a value such that distance is > 6
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
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
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}