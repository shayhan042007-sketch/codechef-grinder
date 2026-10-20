#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * We need to make A[i] == A[N-1-i] for all i.
 * Let K be the number of indices i < N/2 such that A[i] != A[N-1-i].
 * Each operation can change two bits. By choosing indices carefully, 
 * one operation can resolve two mismatched pairs (e.g., if we have two pairs 
 * (0,1) and (0,1), we can make them (1,1) and (1,1)).
 * Thus, the minimum operations required is ceil(K / 2.0).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int mismatches = 0;
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            mismatches++;
        }
    }

    if (mismatches == 0) {
        cout << 0 << endl;
    } else {
        // We need to resolve 'mismatches' number of pairs.
        // Each operation can fix up to 2 pairs.
        cout << (mismatches + 1) / 2 << endl;
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