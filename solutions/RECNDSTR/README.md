# [Chef and String (RECNDSTR)](https://www.codechef.com/problems/RECNDSTR)

- **Difficulty Rating**: 1206
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we define two operations:
1. **Left Shift ($L$):** Move the first character of the string to the end. (e.g., "abc" $\rightarrow$ "bca")
2. **Right Shift ($R$):** Move the last character of the string to the beginning. (e.g., "abc" $\rightarrow$ "cab")

We need to determine if there exists a string $V$ such that shifting $V$ to the left results in $S$ AND shifting $V$ to the right results in $S$.

## Intuition & Mathematical Observation
Let $L(V) = S$ and $R(V) = S$.
- If $L(V) = S$, then $V$ must be the string obtained by shifting $S$ to the **right** by one position ($V = R(S)$).
- If $R(V) = S$, then $V$ must be the string obtained by shifting $S$ to the **left** by one position ($V = L(S)$).

Therefore, for such a $V$ to exist, the right-shifted version of $S$ must be equal to the left-shifted version of $S$. 

**Special Case:** If the length of the string is 1 or 2, any shift results in the same string or a trivial equality, so the answer is always "YES". For strings of length $N > 2$, we simply compare the two shifted strings.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform string slicing and concatenation, which takes linear time relative to the length of the string.
- **Space Complexity**: $O(N)$ to store the shifted versions of the string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length N.
 * L(V) = S implies V is the right-shift of S.
 * R(V) = S implies V is the left-shift of S.
 * We check if the right-shift of S is equal to the left-shift of S.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Strings of length 1 or 2 will always satisfy the condition
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Construct L(S): Move first char to end
    string left_shifted = s.substr(1) + s[0];
    
    // Construct R(S): Move last char to front
    string right_shifted = s.back() + s.substr(0, n - 1);
    
    if (left_shifted == right_shifted) {
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