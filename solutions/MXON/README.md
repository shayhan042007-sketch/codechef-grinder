# [Maximum Ones (MXON)](https://www.codechef.com/problems/MXON)

- **Difficulty Rating**: 943
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, we are allowed to perform an operation at most $K$ times. In one operation, we can choose an index $i$ ($0 \le i < N-1$) and update $S[i] = \max(S[i], S[i+1])$. The goal is to maximize the total number of '1's in the string after performing at most $K$ operations.

## Intuition & Mathematical Observation
The operation $S[i] = \max(S[i], S[i+1])$ effectively allows a '1' to propagate one position to the left. If $S[i+1]$ is '1', we can change $S[i]$ to '1' in a single operation. 

Since the constraint on $N$ is very small ($N \le 10$), the total number of possible binary strings is $2^{10} = 1024$. This small state space allows us to explore all reachable configurations using **Breadth-First Search (BFS)**. 

- We treat each binary string as a state.
- An edge exists between two states if one can be transformed into the other using exactly one operation.
- We keep track of the number of operations used to ensure we do not exceed $K$.
- By tracking visited states (string + operations used), we avoid redundant calculations and cycles.

## Complexity Analysis
- **Time Complexity**: $O(2^N \cdot N \cdot K)$. With $N \le 10$ and $K$ being relatively small, the number of states is manageable. Each state transition takes $O(N)$ time to generate the next string.
- **Space Complexity**: $O(2^N \cdot K)$ to store the visited states in the `set` or `map`.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation S[i] = max(S[i], S[i+1]) effectively propagates a '1' from right to left.
 * Since N is very small (N <= 10), we can use Breadth-First Search (BFS) to explore
 * all reachable states within K operations.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // BFS queue stores {current_string, operations_used}
    queue<pair<string, int>> q;
    q.push({S, 0});
    
    // Visited set to prevent redundant processing
    set<pair<string, int>> visited;
    visited.insert({S, 0});
    
    int max_ones = 0;
    for (char c : S) if (c == '1') max_ones++;
    
    while (!q.empty()) {
        pair<string, int> curr = q.front();
        q.pop();
        
        string s = curr.first;
        int ops = curr.second;
        
        // Update max_ones found so far
        int current_ones = 0;
        for (char c : s) if (c == '1') current_ones++;
        max_ones = max(max_ones, current_ones);
        
        // If we still have operations left, try all possible moves
        if (ops < K) {
            for (int i = 0; i < N - 1; ++i) {
                // Only perform operation if it changes the string
                if (s[i+1] == '1' && s[i] == '0') {
                    string next_s = s;
                    next_s[i] = '1';
                    
                    if (visited.find({next_s, ops + 1}) == visited.end()) {
                        visited.insert({next_s, ops + 1});
                        q.push({next_s, ops + 1});
                    }
                }
            }
        }
    }
    cout << max_ones << "\n";
}

int main() {
    // Optimize I/O operations
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