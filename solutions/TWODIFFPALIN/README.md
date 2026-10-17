# [Two Different Palindromes (TWODIFFPALIN)](https://www.codechef.com/problems/TWODIFFPALIN)

- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $A$ zeros and $B$ ones, determine if it is possible to construct at least two distinct binary strings that are both palindromes using exactly $A$ zeros and $B$ ones.

## Intuition & Mathematical Observation
To form a palindrome, the counts of characters must satisfy specific parity constraints:
1. **Parity Constraint**: In any palindrome, at most one character can have an odd frequency (the character placed at the exact center). If both $A$ and $B$ are odd, the total length $A+B$ is even, meaning there is no middle element. Thus, both $A$ and $B$ must be even for a palindrome to exist. If both are odd, it is impossible to form even one palindrome.
2. **Uniqueness Constraint**: If either $A=1$ or $B=1$, the structure of the palindrome is extremely restricted. For example, if $A=1$, the zero must be placed in the center to maintain symmetry. This forces a single unique configuration, making it impossible to form *two* different palindromes.
3. **General Case**: If $A$ and $B$ are both even, or if one is even and the other is greater than 1, we can typically arrange the characters in at least two distinct ways (e.g., by swapping blocks of characters while maintaining symmetry).

**Conclusion**: The answer is "No" if $(A \text{ is odd AND } B \text{ is odd})$ OR $(A=1 \text{ OR } B=1)$. Otherwise, the answer is "Yes".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and logical comparisons.
- **Space Complexity**: $O(1)$, as no additional data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different binary strings that are both palindromes 
 * and contain exactly A zeros and B ones.
 * 
 * Logic:
 * 1. If both A and B are odd, we cannot form a palindrome because a palindrome 
 *    of even length requires both counts to be even.
 * 2. If A=1 or B=1, the position of the single character is fixed at the center 
 *    to maintain symmetry, allowing only one unique palindrome.
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // Check if both are odd (impossible to form a palindrome)
    // or if either is 1 (only one unique palindrome possible)
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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