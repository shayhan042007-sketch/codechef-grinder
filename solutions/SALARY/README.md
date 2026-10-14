# [The Minimum Number Of Moves (SALARY)](https://www.codechef.com/problems/SALARY)

- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ workers, each with a specific salary $W_i$. In one operation, we can choose any one worker and increase the salaries of all *other* $N-1$ workers by 1. The goal is to find the minimum number of operations required to make all workers' salaries equal.

## Intuition & Mathematical Observation
The key to solving this problem is to realize that the operation "increase everyone except worker $i$ by 1" is **relative**. 

If we want to make all salaries equal, we are essentially trying to bring every worker's salary up to the level of the current maximum salary. However, since we can only increase salaries, we can think about this in reverse:
1. Instead of increasing $N-1$ workers, consider the difference between each worker's salary and the minimum salary in the group.
2. Every time we perform an operation on a worker who is *not* the one with the minimum salary, we are effectively reducing the gap between that worker and the minimum salary.
3. Mathematically, to make all elements equal, we must perform enough operations such that every worker reaches the value of the initial maximum salary. 
4. The total number of operations required is exactly the sum of the differences between each salary $W_i$ and the minimum salary $min(W)$. 

**Formula:**
$$\text{Operations} = \sum_{i=1}^{N} (W_i - \min(W))$$

This works because each operation reduces the "distance" of the other $N-1$ elements from the target by 1, and we continue until all elements are equal to the initial maximum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of workers. We iterate through the array twice: once to find the minimum and once to calculate the sum of differences.
- **Space Complexity**: $O(N)$ to store the salaries in a vector. This can be optimized to $O(1)$ if we calculate the sum and minimum on the fly while reading the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation "increase all except one" is mathematically equivalent 
 * to decreasing the chosen worker's salary relative to the others.
 * To make all salaries equal, we must perform enough operations to 
 * bring every worker's salary up to the initial maximum.
 * The total number of operations is the sum of (W_i - min(W_i)) for all i.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_val = 20000; // Constraint is 10000, so this is safe
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_val) {
            min_val = w[i];
        }
    }
    
    // The number of operations required is the sum of differences 
    // between each salary and the minimum salary.
    long long operations = 0;
    for (int i = 0; i < n; ++i) {
        operations += (w[i] - min_val);
    }
    
    cout << operations << "\n";
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