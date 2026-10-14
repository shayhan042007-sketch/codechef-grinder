#include <iostream>
#include <string>
#include <vector>

/**
 * Problem: KOL15A - Processing a string
 * Approach: Iterate through the string, check if each character is a digit using 
 * the ASCII range '0'-'9', convert to integer, and accumulate the sum.
 * Time Complexity: O(T * |S|)
 * Space Complexity: O(|S|)
 */

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    long long sum = 0;
    for (char c : s) {
        // Check if character is a digit '0'-'9'
        if (c >= '0' && c <= '9') {
            // Convert char digit to its integer value
            sum += (c - '0');
        }
    }
    cout << sum << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}