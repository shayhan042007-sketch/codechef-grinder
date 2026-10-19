# [Cool Subsequences (COOLSUB)](https://www.codechef.com/problems/COOLSUB)

- **Difficulty Rating**: 1239
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find a non-empty subsequence of a given array $A$ such that the average of every non-empty subsequence of our chosen subsequence is present in the remaining elements (the complement) of the original array. If no such subsequence exists, we should output -1.

## Intuition & Mathematical Observation
The condition for a "cool" subsequence is quite restrictive. Let's analyze the simplest possible case: a subsequence of length 1, containing a single element $x$.

1.  **Subsequence of length 1:** If we choose a subsequence $[x]$, its only non-empty subsequence is $[x]$ itself. The average of this subsequence is $x$.
2.  **Condition:** The condition states that the average ($x$) must be present in the complement of our chosen subsequence.
3.  **Implication:** If we pick one instance of $x$ as our subsequence, the complement must contain at least one more instance of $x$ for the condition to hold.
4.  **Conclusion:** If the array contains any duplicate elements, we can simply pick a subsequence of length 1 consisting of that duplicate element. The complement will contain the other instance of that element, satisfying the condition.
5.  **Distinct Elements:** If all elements in the array are distinct, any subsequence we pick will have a complement that does not contain any of the elements we picked. Since the average of any subsequence of distinct numbers is either not an integer or is an element not present in the complement, it is impossible to satisfy the condition. Thus, if all elements are distinct, the answer is -1.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the map implementation. Using `std::map` results in $O(N \log N)$, while `std::unordered_map` would yield $O(N)$ on average. Given the constraints, $O(N \log N)$ is well within the limits.
- **Space Complexity**: $O(N)$ to store the frequency map of the elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * If there is any duplicate element x in the array, we can pick a subsequence 
 * of length 1, [x]. The complement will contain at least one x (since there 
 * were at least two x's originally). The average of [x] is x, and x is in 
 * the complement. Thus, [x] is a cool subsequence.
 * 
 * If all elements are distinct, no such subsequence exists (output -1).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    int duplicate = -1;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
        // If we find an element that has appeared before, we found our answer
        if (counts[A[i]] > 1) {
            duplicate = A[i];
        }
    }

    if (duplicate != -1) {
        // Output length of subsequence and the element itself
        cout << 1 << "\n";
        cout << duplicate << "\n";
    } else {
        // No duplicates found, impossible to satisfy the condition
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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