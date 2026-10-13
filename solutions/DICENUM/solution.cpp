#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order. For example, if Alice rolls 3, 2, 5, the digits 
 * sorted descending are 5, 3, 2, forming the number 532.
 * 
 * We perform this for both Alice and Bob and compare the resulting 3-digit numbers.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> a(3), b(3);
        for (int i = 0; i < 3; ++i) cin >> a[i];
        for (int i = 0; i < 3; ++i) cin >> b[i];

        // Sort both arrays in descending order to form the largest possible number
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        // Construct the numbers
        // Since digits are 1-6, the max number is 666, which fits in int.
        int alice_score = a[0] * 100 + a[1] * 10 + a[2];
        int bob_score = b[0] * 100 + b[1] * 10 + b[2];

        if (alice_score > bob_score) {
            cout << "Alice" << "\n";
        } else if (bob_score > alice_score) {
            cout << "Bob" << "\n";
        } else {
            cout << "Tie" << "\n";
        }
    }

    return 0;
}