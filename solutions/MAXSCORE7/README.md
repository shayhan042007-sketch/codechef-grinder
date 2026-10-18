# [Maximum Score (MAXSCORE7)](https://www.codechef.com/problems/MAXSCORE7)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ consisting only of $0$s and $1$s, we perform an operation where we choose two adjacent elements $A[i]$ and $A[i+1]$, add $|A[i] - A[i+1]|$ to our total score, and remove both elements from the array. We repeat this process until the array is empty. The goal is to maximize the total score.

## Intuition & Mathematical Observation
The value $|A[i] - A[i+1]|$ is:
- **1** if the pair is $(0, 1)$ or $(1, 0)$.
- **0** if the pair is $(0, 0)$ or $(1, 1)$.

To maximize the score, we want to maximize the number of operations that result in a score of $1$. Each such operation consumes exactly one $0$ and one $1$. 

Since we can remove any adjacent pair, we can effectively "bring" any $0$ and any $1$ together by removing the elements between them (which will contribute $0$ to the score). Therefore, the total number of $(0, 1)$ or $(1, 0)$ pairs we can form is limited only by the total count of $0$s ($c_0$) and $1$s ($c_1$) available in the array. 

The maximum number of pairs we can form is simply $\min(c_0, c_1)$. Any remaining elements will be of the same type (all $0$s or all $1$s) and will contribute $0$ to the score when paired together.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the array once to count the $0$s and $1$s.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A consists only of 0s and 1s.
 * Each operation removes two elements and adds |A[i] - A[i+1]| to the score.
 * |A[i] - A[i+1]| is 1 if the pair is (0, 1) or (1, 0), and 0 otherwise.
 * To maximize the score, we maximize the number of (0, 1) pairs.
 * This is limited by the total count of 0s and 1s: min(c0, c1).
 */

void solve() {
    int n;
    cin >> n;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) c0++;
        else c1++;
    }
    
    // The maximum score is the number of pairs of (0, 1) we can form.
    cout << min(c0, c1) << "\n";
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