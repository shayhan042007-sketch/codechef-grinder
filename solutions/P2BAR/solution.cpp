#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count the number of '1's that appear after the first occurrence of a '0'.
 * 
 * Approach:
 * 1. Iterate through the string.
 * 2. Maintain a boolean flag `foundSilence` initialized to false.
 * 3. If we encounter a '0', set `foundSilence` to true.
 * 4. If we encounter a '1' and `foundSilence` is true, increment the counter.
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the length of the string.
 * Space: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long count = 0;
    bool foundSilence = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            foundSilence = true;
        } else if (S[i] == '1') {
            if (foundSilence) {
                count++;
            }
        }
    }

    cout << count << "\n";
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