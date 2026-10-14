#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 * Also, x must be positive (since A > B, A - B > 0, so x > 0).
 * Additionally, Alice must have enough cookies to give, i.e., A - x >= 0.
 * Since x = (A - B) / 2, A - (A - B) / 2 = (2A - A + B) / 2 = (A + B) / 2.
 * This is always >= 0 given A > B >= 1.
 * 
 * Therefore, the condition is: (A - B) % 2 == 0.
 * If true, output (A - B) / 2.
 * Otherwise, output -1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice handles input until EOF or 
    // based on a test case count if specified. The prompt mentions "Handle multiple 
    // test cases", so we read until input ends.
    while (cin >> A >> B) {
        if ((A - B) % 2 == 0) {
            cout << (A - B) / 2 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}