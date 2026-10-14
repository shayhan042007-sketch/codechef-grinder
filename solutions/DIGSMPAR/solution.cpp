#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N and need to find the smallest X > N such that
 * parity(digitSum(N)) != parity(digitSum(X)).
 * 
 * Since N < 10^9, the digit sum is at most 9 * 9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * In the worst case, we only need to check a few consecutive integers 
 * after N to find one with a different digit sum parity.
 * 
 * Time Complexity: O(T * K * D) where T is test cases, K is the number of 
 * increments (very small, constant), and D is the number of digits (log10(N)).
 * This is well within the 1s time limit.
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    while (true) {
        if ((getDigitSum(x) % 2) != targetParity) {
            cout << x << "\n";
            return;
        }
        x++;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}