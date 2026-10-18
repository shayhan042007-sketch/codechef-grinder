#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * 
 * We want to maximize earnings.
 * Since Y > X, we should prioritize Type 2 sessions as much as possible.
 * 
 * Strategy:
 * 1. Calculate how many 2-hour sessions we can fit: N / 2.
 * 2. The remaining time (N % 2) will be 0 or 1 hour.
 * 3. If 1 hour remains, we fill it with a Type 1 session.
 * 4. Total earnings = (N / 2) * Y + (N % 2) * X.
 * 
 * Wait, is it possible that 2 * X > Y?
 * The problem states Y > X, but it does not guarantee Y > 2 * X.
 * If 2 * X > Y, it is actually more profitable to take two Type 1 sessions 
 * instead of one Type 2 session.
 * 
 * Therefore, the maximum earnings for 2 hours is max(Y, 2 * X).
 * Total earnings = (N / 2) * max(Y, 2 * X) + (N % 2) * X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Calculate earnings for 2 hours
        long long earnings_for_two_hours = max(y, 2 * x);
        
        // Calculate total
        long long total_earnings = (n / 2) * earnings_for_two_hours + (n % 2) * x;
        
        cout << total_earnings << "\n";
    }

    return 0;
}