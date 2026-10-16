# [Selling Donuts (DONUTSELL)](https://www.codechef.com/problems/DONUTSELL)

- **Difficulty Rating**: 754
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ types of donuts, each with a specific initial quantity. A sequence of $M$ customers arrives, each requesting a donut of a specific type. If the requested donut type has a quantity greater than zero, the shop sells one (decrementing the count). If the quantity is zero, the customer leaves unsatisfied. The goal is to calculate the total number of "sad" (unsatisfied) customers.

## Intuition & Mathematical Observation
The problem can be modeled as a direct simulation. Since the constraints are small enough, we don't need complex data structures. 
1. We store the inventory of donuts in an array (or vector) of size $N+1$ to accommodate 1-based indexing.
2. For each customer request, we check the current inventory of that specific donut type.
3. If `A[type] > 0`, we decrement the count, representing a successful sale.
4. If `A[type] == 0`, we increment a counter for sad customers.
5. This greedy approach works because each customer's request is independent and the order is fixed.

## Complexity Analysis
- **Time Complexity**: $O(T \times M)$, where $T$ is the number of test cases and $M$ is the number of customers. We iterate through each customer request exactly once per test case.
- **Space Complexity**: $O(N)$, where $N$ is the number of donut types, required to store the inventory counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Selling Donuts
 * Approach:
 * We are given N types of donuts with initial counts A_i.
 * M customers arrive sequentially, each requesting a specific type B_i.
 * If A[B_i] > 0, we decrement A[B_i] and the customer is satisfied.
 * If A[B_i] == 0, the customer is sad.
 * We need to count the total number of sad customers.
 * 
 * Time Complexity: O(T * M), where T is test cases and M is number of customers.
 * Space Complexity: O(N) to store the donut counts.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Using a vector to store donut counts. 
    // Since types are 1-indexed, we use size N+1.
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts left of this type, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
}

int main() {
    // Fast I/O setup
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