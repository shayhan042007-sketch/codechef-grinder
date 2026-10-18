# [Encoded String (DECODEIT)](https://www.codechef.com/problems/DECODEIT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to decode a string of length $N$ (where $N$ is a multiple of 4) consisting of '0's and '1's. The string is encoded by dividing it into blocks of 4 bits. Each 4-bit block corresponds to one of the first 16 lowercase English letters ('a' through 'p'), where 'a' corresponds to `0000` (0) and 'p' corresponds to `1111` (15). We need to output the decoded string.

## Intuition & Mathematical Observation
The encoding scheme is a direct mapping of a 4-bit binary number to its decimal equivalent. 
- A 4-bit binary string $b_3b_2b_1b_0$ can be converted to an integer using the formula: $val = b_3 \cdot 2^3 + b_2 \cdot 2^2 + b_1 \cdot 2^1 + b_0 \cdot 2^0$.
- Since the mapping starts at 'a' for 0, the character corresponding to a decimal value $V$ is simply `'a' + V`.
- We can process the input string in chunks of 4. For each chunk, we convert the binary representation to an integer using bitwise operations (left shifting and ORing) and then convert that integer to the corresponding character.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once, processing each bit exactly once.
- **Space Complexity**: $O(N)$ to store the input string and the resulting decoded string. If we processed the input character by character without storing it, the auxiliary space could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The encoding scheme maps 4 bits to one of the first 16 lowercase English letters.
 * This is equivalent to interpreting the 4-bit binary string as an integer 
 * between 0 and 15, where 0000 maps to 'a' (index 0) and 1111 maps to 'p' (index 15).
 * 
 * Complexity:
 * Time: O(N) where N is the length of the string, as we process each block of 4 bits once.
 * Space: O(N) to store the input string, or O(1) if processed character by character.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    // Process the string in chunks of 4 bits
    for (int i = 0; i < n; i += 4) {
        int val = 0;
        // Convert 4-bit binary substring to integer
        for (int j = 0; j < 4; ++j) {
            val = (val << 1) | (s[i + j] - '0');
        }
        // Map integer 0-15 to 'a'-'p'
        result += (char)('a' + val);
    }
    cout << result << "\n";
}

int main() {
    // Fast I/O for competitive programming
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