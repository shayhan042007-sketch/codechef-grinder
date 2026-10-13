# [Dice Number (DICENUM)](https://www.codechef.com/problems/DICENUM)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each roll a 6-sided die three times. They want to form the largest possible 3-digit number using their three respective rolls as digits. Your task is to determine who forms the larger number, or if they form the same number (a tie).

## Intuition & Mathematical Observation
To maximize a number formed by a set of digits, the largest digits must be placed in the highest place-value positions. 
1. For any set of three digits, the maximum number is obtained by sorting the digits in **descending order**.
2. For example, if the rolls are $\{3, 5, 2\}$, the largest number is formed by placing $5$ in the hundreds place, $3$ in the tens place, and $2$ in the units place, resulting in $532$.
3. By sorting both Alice's and Bob's rolls in descending order, we can easily construct their maximum possible scores and compare them using standard integer comparison.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since the number of dice rolls is fixed at 3, sorting takes constant time $O(3 \log 3)$, which is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only store a fixed number of integers (three for Alice and three for Bob) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order. For example, if Alice rolls 3, 2, 5, the digits 
 * sorted descending are 5, 3, 2, forming the number 532.
 * 
 * We perform this for both Alice and Bob and compare the resulting 3-digit numbers.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> a(3), b(3);
        for (int i = 0; i < 3; ++i) cin >> a[i];
        for (int i = 0; i < 3; ++i) cin >> b[i];

        // Sort both arrays in descending order to form the largest possible number
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        // Construct the numbers
        // Since digits are 1-6, the max number is 666, which fits in int.
        int alice_score = a[0] * 100 + a[1] * 10 + a[2];
        int bob_score = b[0] * 100 + b[1] * 10 + b[2];

        if (alice_score > bob_score) {
            cout << "Alice" << "\n";
        } else if (bob_score > alice_score) {
            cout << "Bob" << "\n";
        } else {
            cout << "Tie" << "\n";
        }
    }

    return 0;
}
```