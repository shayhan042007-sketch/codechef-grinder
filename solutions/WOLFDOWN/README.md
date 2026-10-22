# [Wolf Down (WOLFDOWN)](https://www.codechef.com/problems/WOLFDOWN)

- **Difficulty Rating**: 1022
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given a string of length $N$ consisting of '0's (birds) and '1's (wolves). In each second, every wolf at position $i$ checks if there is a bird at position $i+1$. If there is, the bird is eaten, and the wolf moves to position $i+1$. If there is no bird at $i+1$, the wolf stays at position $i$. We need to determine how many birds remain safe after the process stabilizes.

## Intuition & Mathematical Observation
The problem describes a local interaction where wolves move forward only if they can consume a bird. Since $N$ is small ($N \le 100$), a direct simulation of the process is efficient enough.

1. **State Representation**: We track the positions of all wolves and the status of each position (whether it contains a bird or not).
2. **Simulation Logic**: In each time step, we identify all birds that are immediately to the right of a wolf. Since multiple wolves might target the same bird or different birds simultaneously, we must ensure that the state updates correctly.
3. **Termination**: The process will naturally stabilize when no more birds can be eaten (i.e., no wolf has a bird at its immediate right). Since there are at most $N$ birds, the simulation will terminate within $N$ steps.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case. We iterate through the simulation for at most $N$ seconds, and in each second, we iterate through the wolf positions (at most $N$). Given $N \le 100$, $N^2 = 10,000$, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the positions of the wolves and the status of the birds in the array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * The simulation approach is valid given N <= 100.
 * We simulate the process for at most N seconds until no more birds can be eaten.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> wolf_pos;
    vector<bool> is_bird(N, false);
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            wolf_pos.push_back(i);
        } else {
            is_bird[i] = true;
        }
    }

    // Simulation:
    // A bird is eaten if a wolf is at pos x and bird is at x+1.
    // We simulate for N seconds because a wolf can move at most N times.
    for (int t = 0; t < N; ++t) {
        vector<int> next_wolf_pos = wolf_pos;
        vector<bool> will_be_eaten(N, false);
        
        // Identify which birds get eaten this second
        for (int i = 0; i < wolf_pos.size(); ++i) {
            int p = wolf_pos[i];
            if (p + 1 < N && is_bird[p + 1]) {
                will_be_eaten[p + 1] = true;
            }
        }

        // Update state
        for (int i = 0; i < wolf_pos.size(); ++i) {
            int p = wolf_pos[i];
            if (p + 1 < N && will_be_eaten[p + 1]) {
                is_bird[p + 1] = false;
                next_wolf_pos[i] = p + 1;
            }
        }
        wolf_pos = next_wolf_pos;
    }

    int safe_birds = 0;
    for (int i = 0; i < N; ++i) {
        if (is_bird[i]) {
            safe_birds++;
        }
    }
    cout << safe_birds << "\n";
}

int main() {
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