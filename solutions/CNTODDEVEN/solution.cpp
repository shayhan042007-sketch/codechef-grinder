#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to find the count of odd divisors and even divisors.
 * Since N is small (1 <= N <= 100), we can iterate from 1 to N to find all divisors.
 * A divisor 'd' of N satisfies (N % d == 0).
 * If d is odd (d % 2 != 0), increment the odd count.
 * If d is even (d % 2 == 0), increment the even count.
 * 
 * Time Complexity: O(T * N), where T <= 100 and N <= 100. Total operations ~ 10^4, well within 1s.
 * Space Complexity: O(1).
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_count = 0;
    int even_count = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            if (i % 2 != 0) {
                odd_count++;
            } else {
                even_count++;
            }
        }
    }
    
    cout << odd_count << " " << even_count << "\n";
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