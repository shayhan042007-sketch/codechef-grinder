#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You owe X dollars. You pay 100 dollars.
 * The change due is (100 - X) dollars.
 * The driver only has 10 dollar bills.
 * The driver can only return multiples of 10 that are <= (100 - X).
 * 
 * Let R = 100 - X be the amount to be returned.
 * The driver returns floor(R / 10) * 10.
 * 
 * Example 1: X = 90, R = 10. floor(10/10)*10 = 10.
 * Example 2: X = 100, R = 0. floor(0/10)*10 = 0.
 * Example 3: X = 66, R = 34. floor(34/10)*10 = 30.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change due
        int change_due = 100 - x;
        
        // The driver returns the largest multiple of 10 <= change_due
        // Integer division in C++ automatically performs floor for positive numbers
        int result = (change_due / 10) * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}