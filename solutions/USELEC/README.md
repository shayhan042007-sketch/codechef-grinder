# [Elections (USELEC)](https://www.codechef.com/problems/USELEC)

- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ states (where $N$ is odd). For each state, we know the number of votes for candidate A ($A_i$) and candidate B ($B_i$). Candidate A wins a state if $A_i > B_i$. To win the election, candidate A must win more than $N/2$ states. We have $X$ additional votes that can be distributed among any states to increase candidate A's count. We need to determine if it is possible for candidate A to win the election using at most $X$ votes.

## Intuition & Mathematical Observation
1. **Winning Condition**: Since $N$ is odd, the majority is defined as $\lfloor N/2 \rfloor + 1$ states.
2. **Cost Calculation**: 
   - If $A_i > B_i$, the state is already won.
   - If $A_i \le B_i$, candidate A needs $B_i - A_i + 1$ additional votes to win that specific state.
3. **Greedy Strategy**: 
   - First, count how many states are already won by A.
   - If the count is already greater than $N/2$, the answer is "YES".
   - Otherwise, calculate the cost to flip the remaining states needed to reach the majority.
   - To minimize the total votes used, we should always pick the states that require the fewest additional votes. Therefore, we store the costs of all "losing" states, sort them in ascending order, and pick the first `needed` number of states.
   - If the sum of these costs is $\le X$, it is possible to win.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting of the costs vector. The initial pass through the states takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the costs of the states that candidate A is currently losing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We have N states (N is odd).
 * - A wins a state if A_i > B_i.
 * - A wins the election if A wins > N/2 states.
 * - Chef has X votes to distribute.
 * - To win a state i where A_i <= B_i, Chef needs (B_i - A_i + 1) votes.
 * - Strategy:
 *   1. Count how many states A is already winning.
 *   2. For states A is not winning, calculate the cost to win: (B_i - A_i + 1).
 *   3. Sort these costs in ascending order.
 *   4. Greedily pick the cheapest states to win until A has > N/2 states.
 *   5. If total cost <= X, output YES, else NO.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int current_wins = 0;
    vector<long long> costs;

    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) {
            current_wins++;
        } else {
            // Cost to win this state is B[i] - A[i] + 1
            costs.push_back((long long)B[i] - A[i] + 1);
        }
    }

    // Target wins needed is (N / 2) + 1
    int target = (N / 2) + 1;
    
    if (current_wins >= target) {
        cout << "YES" << "\n";
        return;
    }

    int needed = target - current_wins;
    sort(costs.begin(), costs.end());

    long long total_cost = 0;
    bool possible = false;
    if (needed <= (int)costs.size()) {
        for (int i = 0; i < needed; ++i) {
            total_cost += costs[i];
        }
        if (total_cost <= X) {
            possible = true;
        }
    }

    if (possible) {
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