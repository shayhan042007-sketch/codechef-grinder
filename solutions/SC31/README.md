# [Weapon Value (SC31)](https://www.codechef.com/problems/SC31)

- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ contestants, each possessing a set of 10 types of weapons, represented as a binary string of length 10. When two contestants battle, they compare their weapons: for each weapon type, if both possess it, they both lose it; if only one possesses it, that person keeps it; if neither possesses it, nothing happens. This process continues until only one contestant remains. We need to find the number of weapons the final winner possesses.

## Intuition & Mathematical Observation
The interaction described is equivalent to the **XOR (exclusive OR)** operation:
- $1 \oplus 1 = 0$ (Both lose the weapon)
- $1 \oplus 0 = 1$ (The weapon is kept)
- $0 \oplus 0 = 0$ (The weapon remains absent)

Since the XOR operation is both **associative** and **commutative**, the order in which the battles occur does not matter. The final state of the winner's weapons is simply the XOR sum of all the initial weapon strings provided by the $N$ contestants. 

By converting each 10-character binary string into an integer, we can compute the total XOR sum efficiently. Finally, we count the number of set bits (1s) in the resulting integer to determine the number of weapons the winner has.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times L)$, where $T$ is the number of test cases, $N$ is the number of contestants, and $L=10$ is the length of the binary string. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(L)$, as we only need to store the running XOR sum and the current string being processed.

## Solution Code

```cpp
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
 */

void solve() {
    int N;
    cin >> N;
    
    // We can represent the 10-bit string as an integer.
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
```