# [Unequal Shuffle (UNQSHF)](https://www.codechef.com/problems/UNQSHF)

- **Difficulty Rating**: 726
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $A$ and $B$ of length $N$ consisting only of characters 'a' and 'b', determine if it is possible to rearrange (shuffle) both strings independently such that for every index $i$ ($0 \le i < N$), the characters at that position are different ($A'[i] \neq B'[i]$).

## Intuition & Mathematical Observation
To satisfy the condition $A'[i] \neq B'[i]$ for all $i$, we must pair every 'a' in $A'$ with a 'b' in $B'$, and every 'b' in $A'$ with an 'a' in $B'$.

1. Let $countA_a$ be the number of 'a's in $A$ and $countA_b$ be the number of 'b's in $A$.
2. Let $countB_a$ be the number of 'a's in $B$ and $countB_b$ be the number of 'b's in $B$.

For the condition to hold:
- Every 'a' in $A$ must be matched with a 'b' in $B$. Thus, we need $countA_a = countB_b$.
- Every 'b' in $A$ must be matched with an 'a' in $B$. Thus, we need $countA_b = countB_a$.

Since the total length of both strings is $N$, we know that $countA_a + countA_b = N$ and $countB_a + countB_b = N$. If the first condition ($countA_a = countB_b$) is met, the second condition is automatically satisfied because $countA_b = N - countA_a$ and $countB_a = N - countB_b$. Therefore, the strings can be shuffled to satisfy the condition if and only if the number of 'a's in $A$ equals the number of 'b's in $B$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the strings. We iterate through each string exactly once to count the characters.
- **Space Complexity**: $O(N)$ to store the input strings (or $O(1)$ if processing character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To satisfy A'[i] != B'[i], every 'a' in A must be paired with a 'b' in B,
 * and every 'b' in A must be paired with an 'a' in B.
 * This is possible if and only if the count of 'a's in A equals the count of 'b's in B.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA_a = 0;
    for (char c : A) {
        if (c == 'a') countA_a++;
    }

    int countB_b = 0;
    for (char c : B) {
        if (c == 'b') countB_b++;
    }

    if (countA_a == countB_b) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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