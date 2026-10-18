#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has score A, Bob has score B. Both are 2-digit numbers without '0'.
 * Alice can reverse her score (A_rev) and/or Bob's score (B_rev).
 * We need to check if any of the following combinations result in A_new > B_new:
 * 1. A > B
 * 2. A_rev > B
 * 3. A > B_rev
 * 4. A_rev > B_rev
 * 
 * Since the numbers are 2-digit, reversing a number 'xy' results in 'yx'.
 * Given the constraints (11 <= A, B < 100), this is a simple O(1) check per test case.
 */

int reverse_num(int n) {
    int tens = n / 10;
    int units = n % 10;
    return units * 10 + tens;
}

void solve() {
    int A, B;
    cin >> A >> B;
    
    int A_rev = reverse_num(A);
    int B_rev = reverse_num(B);
    
    // Check all 4 possible scenarios
    if (A > B || A_rev > B || A > B_rev || A_rev > B_rev) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}