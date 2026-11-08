#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * 2a + 2b + ab = X
 * Add 4 to both sides:
 * ab + 2a + 2b + 4 = X + 4
 * (a + 2)(b + 2) = X + 4
 * 
 * Let A = a + 2, B = b + 2.
 * Since a >= 1 and b >= 1, we must have A >= 3 and B >= 3.
 * We need to find if there exist factors A and B of (X + 4) such that:
 * A * B = X + 4, where A >= 3 and B >= 3.
 * 
 * Complexity: O(sqrt(X)) per test case.
 */

void solve() {
    long long X;
    if (!(cin >> X)) return;
    
    long long target = X + 4;
    bool found = false;
    
    // We check divisors A of target.
    // If A is a divisor, B = target / A.
    // We need A >= 3 and B >= 3.
    for (long long A = 3; A * A <= target; ++A) {
        if (target % A == 0) {
            long long B = target / A;
            if (B >= 3) {
                found = true;
                break;
            }
        }
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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