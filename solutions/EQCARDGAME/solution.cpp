#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has 52 cards. There are K people in total.
 * She needs to distribute the cards equally among K people.
 * Let N be the number of cards remaining after discarding some.
 * N must be a multiple of K, and N <= 52.
 * To minimize the number of discarded cards (52 - N), 
 * we need to maximize N such that N <= 52 and N % K == 0.
 * 
 * N = 52 - (52 % K)
 * Discarded cards = 52 - N = 52 % K
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int k;
        cin >> k;
        
        // The number of cards to discard is simply 52 modulo K.
        // If 52 is divisible by K, 52 % K is 0, which is correct.
        // Otherwise, 52 % K gives the remainder that must be removed
        // to make the remaining count a multiple of K.
        int result = 52 % k;
        
        cout << result << "\n";
    }
    
    return 0;
}