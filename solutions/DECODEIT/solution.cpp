#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The encoding scheme maps 4 bits to one of the first 16 lowercase English letters.
 * This is equivalent to interpreting the 4-bit binary string as an integer 
 * between 0 and 15, where 0000 maps to 'a' (index 0) and 1111 maps to 'p' (index 15).
 * 
 * Complexity:
 * Time: O(N) where N is the length of the string, as we process each block of 4 bits once.
 * Space: O(N) to store the input string, or O(1) if processed character by character.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    // Process the string in chunks of 4 bits
    for (int i = 0; i < n; i += 4) {
        int val = 0;
        // Convert 4-bit binary substring to integer
        for (int j = 0; j < 4; ++j) {
            val = (val << 1) | (s[i + j] - '0');
        }
        // Map integer 0-15 to 'a'-'p'
        result += (char)('a' + val);
    }
    cout << result << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}