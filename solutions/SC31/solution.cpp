#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each weapon type behaves independently. For a specific weapon type j:
 * - If a contestant has it (1) and another has it (1), they destroy each other (1 XOR 1 = 0).
 * - If one has it (1) and the other doesn't (0), the winner gets it (1 XOR 0 = 1).
 * - If neither has it (0), the winner doesn't have it (0 XOR 0 = 0).
 * 
 * This is exactly the behavior of the XOR operation. Since XOR is associative 
 * and commutative, the final state of the winner's weapons is simply the 
 * XOR sum of all initial weapon strings, regardless of the order of battles.
 * 
 * Complexity:
 * Time: O(T * N * L), where L=10 is the length of the string.
 * Space: O(L) to store the running XOR sum.
 */

void solve() {
    int N;
    cin >> N;
    
    // We can represent the 10-bit string as an integer or a bitset.
    // Since the length is fixed at 10, an integer is sufficient.
    int final_xor = 0;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        // Convert binary string to integer
        int current_val = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '1') {
                current_val |= (1 << (9 - j));
            }
        }
        
        // XOR the current contestant's weapons into the running total
        final_xor ^= current_val;
    }
    
    // Count the number of set bits in the final XOR result
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if ((final_xor >> i) & 1) {
            count++;
        }
    }
    
    cout << count << "\n";
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