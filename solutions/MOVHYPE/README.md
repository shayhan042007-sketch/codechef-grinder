# [Movie Hype (MOVHYPE)](https://www.codechef.com/problems/MOVHYPE)

- **Difficulty Rating**: 921
- **Solved in**: 1 attempt(s)

## Problem Summary
In a theater with $2N+1$ seats, people are sitting in all odd-numbered seats ($1, 3, 5, \dots, 2N+1$). Each person has a "hype level." For every empty seat (even-numbered seats $2, 4, \dots, 2N$), the loudness is defined as the maximum of the hype levels of the two people sitting immediately adjacent to it. We need to find the minimum loudness among all empty seats.

## Intuition & Mathematical Observation
- The theater has $N+1$ people sitting at indices $1, 3, 5, \dots, 2N+1$. Let's represent their hype levels as an array $A$ of size $N+1$, where $A_0, A_1, \dots, A_N$ correspond to the people in these seats.
- An empty seat at position $2i$ (where $i$ ranges from $1$ to $N$) is located between the person at seat $2i-1$ and the person at seat $2i+1$.
- In our 0-indexed array $A$, the person at seat $2i-1$ is $A_{i-1}$ and the person at seat $2i+1$ is $A_i$.
- Therefore, the loudness of the $i$-th empty seat is $\max(A_{i-1}, A_i)$.
- To solve the problem, we iterate through all adjacent pairs in the array $A$, calculate the maximum of each pair, and track the minimum value found across all such pairs.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of empty seats. We perform a single pass through the array of $N+1$ people to compare adjacent pairs.
- **Space Complexity**: $O(N)$ to store the hype levels of the $N+1$ people. (Note: This could be optimized to $O(1)$ by processing the input on the fly, but $O(N)$ is well within limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * Let A_0, A_1, ..., A_N be the hype levels of people in seats 1, 3, 5, ..., 2N+1.
 * Seat 2 is between seat 1 and 3. Loudness = max(A_0, A_1).
 * Seat 4 is between seat 3 and 5. Loudness = max(A_1, A_2).
 * ...
 * Seat 2i is between seat 2i-1 and 2i+1. Loudness = max(A_{i-1}, A_i).
 * 
 * We need to find the minimum loudness among all empty seats (i = 1 to N).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible hype level
    long long min_loudness = 200;
    
    // There are N empty seats.
    // The i-th empty seat (0-indexed loop) is between A[i] and A[i+1].
    for (int i = 0; i < N; ++i) {
        long long current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```