# [Nearest Square (NEARSQ)](https://www.codechef.com/problems/NEARSQ)

- **Difficulty Rating**: 570
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$, the task is to find the largest perfect square that is less than or equal to $N$.

## Intuition & Mathematical Observation
To find the largest perfect square less than or equal to $N$, we can utilize the square root function. 

1. Let $B = \lfloor\sqrt{N}\rfloor$. This represents the largest integer whose square does not exceed $N$.
2. By squaring $B$ (i.e., $B \times B$), we obtain the largest perfect square that is $\le N$.
3. **Example**: If $N = 10$, $\sqrt{10} \approx 3.16$. The floor of this value is $3$. Since $3^2 = 9$, and $9 \le 10$, the answer is $9$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the `sqrt` function and basic arithmetic operations run in constant time.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: NEARSQ
 * Logic: 
 * We need the largest square number A <= N.
 * If we take B = floor(sqrt(N)), then B*B is the largest square <= N.
 * Example: N = 10, sqrt(10) = 3.16, floor = 3, 3*3 = 9.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Calculate the integer part of the square root
    int B = static_cast<int>(sqrt(N));
    
    // Output the square of that integer
    cout << B * B << endl;
}

int main() {
    // Optimize I/O operations
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