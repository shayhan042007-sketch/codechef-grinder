#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1].
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Odd, Even, Odd, Even, ...
 * Pattern 2: Even, Odd, Even, Odd, ...
 * 
 * To find the minimum changes, we count how many elements in the original array
 * violate Pattern 1 (let this be count1) and how many violate Pattern 2 (count2).
 * The answer is min(count1, count2).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Pattern 1: A[0] is Odd (A[i] % 2 == 1 if i even, 0 if i odd)
    int count1 = 0;
    for (int i = 0; i < N; ++i) {
        int expected_parity = (i % 2 == 0) ? 1 : 0;
        if (abs(A[i] % 2) != expected_parity) {
            count1++;
        }
    }

    // Pattern 2: A[0] is Even (A[i] % 2 == 0 if i even, 1 if i odd)
    int count2 = 0;
    for (int i = 0; i < N; ++i) {
        int expected_parity = (i % 2 == 0) ? 0 : 1;
        if (abs(A[i] % 2) != expected_parity) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
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