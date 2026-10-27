#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Alice has C cookies. She wants to reach C' = C + k (where k >= 0) such that:
 * 1. At least one friend has A_i < C'.
 * 2. No friend has A_j == C'.
 * 
 * Since constraints are small (N, C, A_i <= 100), we can iterate k starting from 0.
 * The maximum possible answer is bounded because eventually C' will be greater than 
 * all A_i, satisfying both conditions.
 */

bool is_happy(int C_prime, int N, const vector<int>& A) {
    bool has_less = false;
    for (int x : A) {
        // Condition 2: No friend has equal cookies to Alice
        if (x == C_prime) return false; 
        // Condition 1: At least one friend has strictly less cookies
        if (x < C_prime) has_less = true;
    }
    return has_less;
}

void solve() {
    int N, C;
    if (!(cin >> N >> C)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int k = 0;
    // Brute force search for the minimum k.
    // Given constraints, this loop will terminate very quickly.
    while (true) {
        if (is_happy(C + k, N, A)) {
            cout << k << "\n";
            return;
        }
        k++;
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