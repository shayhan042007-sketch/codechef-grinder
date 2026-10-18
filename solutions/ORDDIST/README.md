# [Ordered Distances (ORDDIST)](https://www.codechef.com/problems/ORDDIST)

- **Difficulty Rating**: 1112
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an initial sequence $X$ of $N$ integers and a target sequence $Y$, we need to determine if there exists a "pivot" element $P$ chosen from the elements of $X$ such that sorting the elements of $X$ based on their absolute distance from $P$ results in the sequence $Y$. Specifically, for a chosen pivot $P$, we define a pair for each element $x \in X$ as $(|x - P|, x)$. We sort these pairs primarily by their distance $|x - P|$ (ascending) and secondarily by the value $x$ itself (ascending). If the resulting sequence of values matches $Y$, the index of the chosen pivot (1-based) is the answer. If no such pivot exists, output -1.

## Intuition & Mathematical Observation
The constraints are small ($N \le 100$), which suggests that we do not need an optimized mathematical formula or a complex data structure. Since there are only $N$ possible candidates for the pivot (each element in $X$), we can use a **Brute Force** approach:

1. Iterate through every index $i$ from $0$ to $N-1$ in the array $X$.
2. Treat $X[i]$ as the pivot $P$.
3. Generate the list of pairs $(|X[j] - P|, X[j])$ for all $j$.
4. Sort this list using the specified criteria:
   - Primary key: Absolute difference $|X[j] - P|$.
   - Secondary key: The value $X[j]$ itself.
5. Compare the sorted sequence with the given array $Y$.
6. If they match, return $i+1$. If the loop finishes without a match, return -1.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2 \log N)$, where $T$ is the number of test cases. For each test case, we iterate $N$ times, and inside each iteration, we perform a sort operation that takes $O(N \log N)$. Given $N \le 100$, $100^2 \log 100 \approx 66,000$ operations per test case, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the input arrays and the temporary list of pairs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an initial sequence X and a transformed sequence Y.
 * We need to find a pivot index i (1 <= i <= N) such that if we set P = X[i],
 * and create a list of pairs (abs(X[j] - P), X[j]), sorting them according to the
 * specified rules results in the sequence Y.
 */

bool check(int n, const vector<int>& x, const vector<int>& y, int pivot_idx) {
    int p = x[pivot_idx];
    vector<pair<int, int>> l;
    for (int val : x) {
        l.push_back({abs(val - p), val});
    }
    
    // Sort based on distance, then by value
    sort(l.begin(), l.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    
    // Check if the sorted sequence matches Y
    for (int i = 0; i < n; ++i) {
        if (l[i].second != y[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> y[i];
    
    // Try every element as a potential pivot
    for (int i = 0; i < n; ++i) {
        if (check(n, x, y, i)) {
            cout << i + 1 << "\n";
            return;
        }
    }
    
    cout << -1 << "\n";
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