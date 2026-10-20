# [Xor Palindrome (XOR_PAL)](https://www.codechef.com/problems/XOR_PAL)

- **Difficulty Rating**: 1129
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we want to make the string a palindrome. In one operation, we can choose any index $i$ and flip both $A[i]$ and $A[N-1-i]$ (i.e., $0 \to 1$ or $1 \to 0$). We need to find the minimum number of operations required to make the string a palindrome.

## Intuition & Mathematical Observation
To make a string a palindrome, we must satisfy $A[i] = A[N-1-i]$ for all $0 \le i < N/2$.

1. **Identify Mismatches**: First, iterate through the first half of the string and count how many pairs $(A[i], A[N-1-i])$ are not equal. Let this count be `mismatches`.
2. **Analyze Operations**:
   - If `mismatches == 0`, the string is already a palindrome, so the answer is `0`.
   - If `mismatches > 0`, each operation allows us to flip a pair. By choosing the indices where $A[i] \neq A[N-1-i]$, one operation can fix exactly one mismatch. 
   - However, we can also choose to flip pairs that are *already* matching. If we have two mismatched pairs, we can fix both in one operation by flipping the bits strategically.
   - Mathematically, to fix $K$ mismatched pairs, we need $\lceil K/2 \rceil$ operations. This is because each operation can resolve up to 2 mismatched pairs simultaneously.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string once to count the mismatches.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * We need to make A[i] == A[N-1-i] for all i.
 * Let K be the number of indices i < N/2 such that A[i] != A[N-1-i].
 * Each operation can change two bits. By choosing indices carefully, 
 * one operation can resolve two mismatched pairs.
 * Thus, the minimum operations required is ceil(K / 2.0).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int mismatches = 0;
    // Count pairs that do not match
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            mismatches++;
        }
    }

    if (mismatches == 0) {
        cout << 0 << endl;
    } else {
        // We need to resolve 'mismatches' number of pairs.
        // Each operation can fix up to 2 pairs, so we use integer division 
        // to calculate ceil(mismatches / 2.0) as (mismatches + 1) / 2.
        cout << (mismatches + 1) / 2 << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```