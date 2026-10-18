# [Covid Run (CVDRUN)](https://www.codechef.com/problems/CVDRUN)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ cities arranged in a circle, indexed from $0$ to $N-1$. A virus starts at city $X$ and jumps $K$ positions forward every day (i.e., from city $i$ to $(i + K) \pmod N$). We need to determine if the virus will ever reach city $Y$.

## Intuition & Mathematical Observation
The movement of the virus follows the sequence: $X, (X+K) \pmod N, (X+2K) \pmod N, \dots$. 
This is a classic problem of modular arithmetic. We are looking for a non-negative integer $m$ such that:
$$(X + m \cdot K) \equiv Y \pmod N$$
Rearranging this, we get:
$$m \cdot K \equiv (Y - X) \pmod N$$

Since the number of cities $N$ is small ($N \le 1000$), we do not need to solve this using the Extended Euclidean Algorithm. Instead, we can simulate the process. Because there are only $N$ possible cities, if the virus visits a city it has already visited without reaching $Y$, it has entered a cycle and will never reach $Y$. Thus, we can simply track visited cities using a boolean array and stop the simulation if we encounter a repeat or reach the target.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. In the worst case, we visit each of the $N$ cities exactly once before determining if $Y$ is reachable.
- **Space Complexity**: $O(N)$ to store the `visited` array of size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at city X and jumps by K each day in a circular arrangement of N cities.
 * The sequence of cities visited is: X, (X+K)%N, (X+2K)%N, ...
 * This is equivalent to checking if there exists an integer 'm' such that:
 * (X + m * K) % N == Y
 * This is a linear congruence equation: m * K ≡ (Y - X) (mod N).
 * 
 * Given the constraints N <= 1000, we can simply simulate the process.
 * Since there are only N cities, if the virus visits a city it has already visited
 * without reaching Y, it will never reach Y.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // visited array to keep track of infected cities
    vector<bool> visited(N, false);
    
    int current = X;
    bool reached = false;
    
    // Simulate the jumps
    // In the worst case, we visit at most N cities.
    for (int i = 0; i < N; ++i) {
        if (current == Y) {
            reached = true;
            break;
        }
        
        // If we hit a city already visited, we are in a cycle
        if (visited[current]) {
            break;
        }
        
        visited[current] = true;
        current = (current + K) % N;
    }
    
    if (reached) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```