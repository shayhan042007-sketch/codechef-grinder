#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * M >= N / 2  <=>  2 * M >= N
 * 
 * Constraints:
 * 1 <= N, M <= 1000
 * The values fit comfortably within standard integer types.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem description implies a single test case structure, 
    // but standard competitive programming practice often involves test cases.
    // Given the prompt asks to handle multiple test cases if requested, 
    // we check if there's an input for t. However, based on the sample, 
    // we will read N and M directly.
    
    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Logic: If errors (M) are at least half of total lines (N), he is a NEWBIE.
    // Condition: M >= N / 2.0
    // Equivalent to: 2 * M >= N
    if (2 * M >= N) {
        cout << "NEWBIE" << "\n";
    } else {
        cout << "PRO" << "\n";
    }

    return 0;
}