# [Lockpicking Chef (LPC)](https://www.codechef.com/problems/LPC)

- **Difficulty Rating**: 1311
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ and a secret code $K$ of length $M$, we need to find a substring of $S$ of length $M$ such that the total cost to transform the substring into $K$ is minimized. The cost to change one digit to another in a cyclic system (0-9) is defined as the minimum distance between them, considering both clockwise and counter-clockwise directions.

## Intuition & Mathematical Observation
The core of the problem lies in calculating the cost to transform a single digit $a$ into $b$. Since the digits are cyclic (0-9), the distance between two digits can be calculated in two ways:
1. The direct absolute difference: $|a - b|$
2. The wrap-around distance: $10 - |a - b|$

The cost for a single digit is $\min(|a - b|, 10 - |a - b|)$.

Since the length of the secret code $M$ is very small ($M \le 10$) and the total length of the string $N$ is up to $10^5$, we can use a **Sliding Window** approach. We iterate through every possible starting position $i$ in $S$ (from $0$ to $N-M$) and calculate the total cost to transform the substring $S[i \dots i+M-1]$ into $K$. We keep track of the minimum cost found across all windows.

## Complexity Analysis
- **Time Complexity**: $O(N \times M)$. We iterate through $N-M+1$ possible starting positions, and for each position, we perform $M$ operations. Given the constraints ($N \le 10^5, M \le 10$), the total number of operations is approximately $10^6$, which comfortably fits within the 1-second time limit.
- **Space Complexity**: $O(N + M)$ to store the input strings $S$ and $K$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N and a secret code K of length M.
 * We need to find a substring of S of length M such that the cost to transform
 * it into K is minimized.
 * 
 * The cost to transform a digit 'a' to 'b' in a cyclic system (0-9) is:
 * diff = abs(a - b)
 * cost = min(diff, 10 - diff)
 * 
 * Since N <= 10^5 and M <= 10, we can iterate through all possible starting
 * positions i in S (from 0 to N-M) and calculate the cost to transform
 * S[i...i+M-1] into K.
 */

int calculate_cost(char s_char, char k_char) {
    int s = s_char - '0';
    int k = k_char - '0';
    int diff = abs(s - k);
    return min(diff, 10 - diff);
}

void solve() {
    int N, M;
    cin >> N >> M;
    string S, K;
    cin >> S >> K;

    long long min_total_cost = -1;

    // Iterate through all possible substrings of S of length M
    for (int i = 0; i <= N - M; ++i) {
        long long current_cost = 0;
        for (int j = 0; j < M; ++j) {
            current_cost += calculate_cost(S[i + j], K[j]);
        }

        if (min_total_cost == -1 || current_cost < min_total_cost) {
            min_total_cost = current_cost;
        }
    }

    cout << min_total_cost << "\n";
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