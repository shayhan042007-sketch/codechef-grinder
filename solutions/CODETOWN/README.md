# [Reach Codetown (CODETOWN)](https://www.codechef.com/problems/CODETOWN)

- **Difficulty Rating**: 1022
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to determine if a given 8-character string $S$ can be transformed into the target string "CODETOWN". The transformation rules allow replacing a consonant with any other consonant and a vowel with any other vowel. Essentially, we must verify if the vowel/consonant structure of the input string matches the structure of "CODETOWN" exactly.

## Intuition & Mathematical Observation
The problem defines a transformation rule based on character types (vowel vs. consonant). Since we can replace any vowel with any other vowel and any consonant with any other consonant, the specific identity of the characters does not matter as much as their **type**.

1.  **Identify the Pattern**: The target string is "CODETOWN".
    *   Index 0: 'C' (Consonant)
    *   Index 1: 'O' (Vowel)
    *   Index 2: 'D' (Consonant)
    *   Index 3: 'E' (Vowel)
    *   Index 4: 'T' (Consonant)
    *   Index 5: 'O' (Vowel)
    *   Index 6: 'W' (Consonant)
    *   Index 7: 'N' (Consonant)
    *   **Pattern**: `C V C V C V C C`

2.  **Verification**: For any input string $S$ of length 8, we simply iterate through each index $i$ from 0 to 7 and check if `isVowel(S[i])` is equal to `isVowel(target[i])`. If this condition holds for all indices, the transformation is possible.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string (which is fixed at 8). Thus, the complexity is $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for the target string and loop variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The rule states we can transition from T1 to T2 if:
 * 1. A consonant is replaced by a consonant.
 * 2. A vowel is replaced by a vowel.
 * 
 * This implies that the "vowel/consonant" status of the character at each 
 * position (index 0 to 7) must be invariant.
 */

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve() {
    string s;
    cin >> s;
    string target = "CODETOWN";
    
    bool possible = true;
    for (int i = 0; i < 8; ++i) {
        // Check if the vowel/consonant status matches at every index
        if (isVowel(s[i]) != isVowel(target[i])) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
```