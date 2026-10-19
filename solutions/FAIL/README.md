# [Failing Grades (FAIL)](https://www.codechef.com/problems/FAIL)

- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes $N$ tests. For Chef to maintain a passing status, his average marks after **every** test (from the 1st test up to the $N$-th test) must be at least 40. Given the marks obtained in each of the $N$ tests, determine if Chef maintained an average of at least 40 after every single test.

## Intuition & Mathematical Observation
The problem requires the average to be $\ge 40$ at every step $k$ (where $1 \le k \le N$).

1. Let $S_k$ be the sum of marks obtained in the first $k$ tests.
2. The average after $k$ tests is defined as $\frac{S_k}{k}$.
3. The condition is $\frac{S_k}{k} \ge 40$.
4. By multiplying both sides by $k$, we get the equivalent condition: **$S_k \ge 40 \times k$**.

We iterate through the input marks, maintaining a running sum. At each step $i$, we check if the current sum is at least $40 \times i$. If this condition fails for any $i$, the answer is "No". If we complete the loop without the condition failing, the answer is "Yes".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ marks exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the running sum and the current test mark.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs his average to be >= 40 after EACH test.
 * Let S_k be the sum of marks after k tests.
 * The average after k tests is S_k / k.
 * The condition is S_k / k >= 40 for all 1 <= k <= N.
 * This is equivalent to S_k >= 40 * k.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (if we process input on the fly).
 */

void solve() {
    int N;
    cin >> N;
    
    long long current_sum = 0;
    bool possible = true;
    
    for (int i = 1; i <= N; ++i) {
        int marks;
        cin >> marks;
        current_sum += marks;
        
        // Check if average >= 40
        // Average = current_sum / i
        // Condition: current_sum / i >= 40  => current_sum >= 40 * i
        if (current_sum < 40LL * i) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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