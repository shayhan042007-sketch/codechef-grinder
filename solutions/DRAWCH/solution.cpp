#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total matches = N.
 * Matches played = M.
 * Matches remaining = K = N - M.
 * Alice's current wins = A.
 * Bob's current wins = B = M - A.
 * 
 * Let 'x' be the number of matches Alice wins in the remaining K matches.
 * Then Bob wins (K - x) matches.
 * Total wins for Alice = A + x.
 * Total wins for Bob = B + (K - x).
 * 
 * For a tie: A + x = B + K - x
 * 2x = B + K - A
 * 2x = (M - A) + (N - M) - A
 * 2x = N - 2A
 * 
 * Since x must be an integer such that 0 <= x <= K:
 * 1. (N - 2A) must be even (which is always true if N and 2A have the same parity, 
 *    but actually N - 2A is even if N is even, and odd if N is odd).
 *    Wait, let's re-evaluate: 2x = N - 2A.
 *    This implies (N - 2A) must be non-negative and even.
 *    If N - 2A < 0, then x < 0 (impossible).
 *    If N - 2A is odd, then x is not an integer (impossible).
 *    Also, we must satisfy x <= K, where K = N - M.
 * 
 * Simplified condition:
 * A tie is possible if and only if:
 * 1. (N - 2A) >= 0
 * 2. (N - 2A) % 2 == 0
 * 3. x = (N - 2A) / 2
 * 4. x <= (N - M)
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int A = 0;
    for (char c : S) {
        if (c == '1') A++;
    }

    int B = M - A;
    int K = N - M;

    // We need to find if there exists x (0 <= x <= K) such that:
    // A + x = B + (K - x)
    // A + x = (M - A) + K - x
    // 2x = M - 2A + K
    // 2x = N - 2A
    
    int diff = N - 2 * A;
    
    if (diff >= 0 && diff % 2 == 0) {
        int x = diff / 2;
        if (x >= 0 && x <= K) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    } else {
        cout << "No" << "\n";
    }
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