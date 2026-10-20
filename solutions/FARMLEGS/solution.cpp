#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let C be the number of cows and H be the number of chickens.
 * We are given: 4*C + 2*H = N
 * We want to minimize the total number of animals: A = C + H.
 * 
 * From the equation 4*C + 2*H = N, we can divide by 2:
 * 2*C + H = N/2
 * H = N/2 - 2*C
 * 
 * Substitute H into the total animals equation:
 * A = C + (N/2 - 2*C)
 * A = N/2 - C
 * 
 * To minimize A, we need to maximize C.
 * Since H must be non-negative (H >= 0):
 * N/2 - 2*C >= 0
 * 2*C <= N/2
 * C <= N/4
 * 
 * The maximum integer value for C is floor(N/4).
 * Substituting C = floor(N/4) into A = N/2 - C:
 * A_min = N/2 - floor(N/4)
 * 
 * This formula works for all even N.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate maximum cows possible
        long long max_cows = n / 4;
        
        // Calculate minimum animals using the derived formula
        // Total animals = (n/2) - cows
        long long min_animals = (n / 2) - max_cows;
        
        cout << min_animals << "\n";
    }

    return 0;
}