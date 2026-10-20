#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial distance covered in 10 hours = 10 * X.
 * Let 'n' be the number of additional hours.
 * Let 'v' be the average speed in these 'n' hours. 
 * Since the max speed is 100 km/h, the maximum distance covered in 'n' hours is 100 * n.
 * We want the new average speed to be at least Y:
 * (10 * X + distance_in_n_hours) / (10 + n) >= Y
 * 10 * X + distance_in_n_hours >= Y * (10 + n)
 * distance_in_n_hours >= Y * (10 + n) - 10 * X
 * 
 * Since the maximum distance he can cover in 'n' hours is 100 * n, we need:
 * 100 * n >= Y * (10 + n) - 10 * X
 * 100 * n >= 10 * Y + n * Y - 10 * X
 * n * (100 - Y) >= 10 * (Y - X)
 * n >= (10 * (Y - X)) / (100 - Y)
 * 
 * Since n must be an integer, we take the ceiling of the division.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // We need to find the smallest integer n such that:
        // n * (100 - y) >= 10 * (y - x)
        // n >= ceil( (10 * (y - x)) / (100 - y) )
        
        long long numerator = 10 * (y - x);
        long long denominator = 100 - y;
        
        // Integer ceiling division: (a + b - 1) / b
        long long n = (numerator + denominator - 1) / denominator;
        
        cout << n << "\n";
    }

    return 0;
}