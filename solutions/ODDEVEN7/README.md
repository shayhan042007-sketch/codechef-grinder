# [Odd Even (ODDEVEN7)](https://www.codechef.com/problems/ODDEVEN7)

- **Difficulty Rating**: 877
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to find the size of the largest subset that can be rearranged such that no two adjacent elements have the same parity (i.e., the sequence must alternate between odd and even numbers).

## Intuition & Mathematical Observation
To form an alternating sequence of odd ($O$) and even ($E$) numbers, we must place them in a pattern like $O, E, O, E, \dots$ or $E, O, E, O, \dots$.

Let $O$ be the count of odd numbers and $E$ be the count of even numbers in the given array:
1. **Case 1: $O = E$**: We can use all elements to form a sequence of length $O + E$ (e.g., $O, E, O, E, \dots$).
2. **Case 2: $O \neq E$**: We are limited by the count of the minority parity. If we have $min(O, E)$ of one type, we can pair each of them with one of the majority type. This allows us to use all $min(O, E)$ elements of the minority type and $min(O, E)$ elements of the majority type. Additionally, we can add one more element of the majority type at the beginning or end of the sequence.
   - The maximum length is $min(O, E) + (min(O, E) + 1) = 2 \times min(O, E) + 1$.

Combining these, the answer is $O + E$ if $O = E$, and $2 \times min(O, E) + 1$ otherwise.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the parities.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A "good" array has alternating parities (Odd, Even, Odd, Even... or Even, Odd, Even, Odd...).
 * To maximize the size of a subset that can be rearranged into a good array, we need to 
 * count the number of odd integers (O) and even integers (E) in the input array.
 * 
 * In an alternating sequence:
 * - If we have O odds and E evens:
 *   - If O == E, we can use all O + E elements (e.g., O, E, O, E...).
 *   - If O != E, the maximum length is limited by the smaller count. 
 *     Specifically, if we have more of one type, we can place them such that 
 *     the sequence is (Majority, Minority, Majority, Minority, Majority).
 *     The maximum length is 2 * min(O, E) + 1.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == even_count) {
        cout << odd_count + even_count << "\n";
    } else {
        cout << 2 * min(odd_count, even_count) + 1 << "\n";
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