# [Equal Card Game (EQCARDGAME)](https://www.codechef.com/problems/EQCARDGAME)

- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has a standard deck of 52 cards. She wants to distribute these cards equally among $K$ people. If the cards cannot be distributed equally, she must discard the minimum number of cards possible such that the remaining cards can be divided evenly among the $K$ people. We need to find the minimum number of cards to discard.

## Intuition & Mathematical Observation
To distribute cards equally among $K$ people, the total number of cards $N$ must be a multiple of $K$. Since we start with 52 cards and want to discard the minimum number, we are looking for the largest integer $N \le 52$ such that $N$ is divisible by $K$.

The number of cards to discard is given by the remainder of the division of 52 by $K$:
- If $52$ is divisible by $K$, the remainder is $0$, meaning no cards need to be discarded.
- If $52$ is not divisible by $K$, the remainder $52 \pmod K$ represents the "extra" cards that prevent an equal distribution. Removing exactly these cards leaves us with $52 - (52 \pmod K)$ cards, which is the largest multiple of $K$ less than or equal to 52.

Thus, the answer is simply `52 % K`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the modulo operation is performed in constant time. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
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
```