#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * Let A_1, A_2, ..., A_{N+1} be the hype levels of people in seats 1, 3, 5, ..., 2N+1.
 * Seat 2 is between seat 1 and 3. Loudness = max(A_1, A_2).
 * Seat 4 is between seat 3 and 5. Loudness = max(A_2, A_3).
 * ...
 * Seat 2i is between seat 2i-1 and 2i+1. Loudness = max(A_i, A_{i+1}).
 * 
 * We need to find the minimum loudness among all empty seats (i = 1 to N).
 * Loudness_i = max(A_i, A_{i+1}) for i = 1 to N.
 * We want min(Loudness_i) for i = 1 to N.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible hype level (max 100)
    long long min_loudness = 200;
    
    // There are N empty seats, corresponding to indices 2, 4, ..., 2N.
    // Seat 2 is between A[0] and A[1].
    // Seat 4 is between A[1] and A[2].
    // Seat 2i is between A[i-1] and A[i].
    for (int i = 0; i < N; ++i) {
        long long current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
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