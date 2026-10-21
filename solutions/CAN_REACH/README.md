# [Can_Reach (CAN_REACH)](https://www.codechef.com/problems/CAN_REACH)

- **Difficulty Rating**: 990
- **Solved in**: 2 attempt(s)

## Problem Summary
You are starting at the origin $(0, 0)$ on a 2D plane. You are allowed to move exactly $K$ units in any of the four cardinal directions (up, down, left, or right) in a single step. Given a target coordinate $(x, y)$, determine if it is possible to reach this point starting from $(0, 0)$ using any number of steps.

## Intuition & Mathematical Observation
To reach a coordinate $(x, y)$ from $(0, 0)$ using steps of size $K$:
1. Each move changes either the x-coordinate or the y-coordinate by exactly $K$ units.
2. After any number of moves, the x-coordinate will be a multiple of $K$ (i.e., $x = n \cdot K$ for some integer $n$), and the y-coordinate will also be a multiple of $K$ (i.e., $y = m \cdot K$ for some integer $m$).
3. Therefore, the target $(x, y)$ is reachable if and only if both $x$ and $y$ are perfectly divisible by $K$. 
4. If $x \pmod K == 0$ and $y \pmod K == 0$, we can reach the destination by taking $|x/K|$ steps horizontally and $|y/K|$ steps vertically. Otherwise, it is impossible.

*Note: Since the problem allows moving in both positive and negative directions, we do not need to worry about the signs of $x$ and $y$.*

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not use any auxiliary data structures.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: CAN_REACH
 * Logic:
 * To reach (x, y) from (0, 0) using steps of size K, both x and y must be 
 * divisible by K. If x % K == 0 and y % K == 0, it is possible to reach 
 * the destination by taking (x/K) steps in the x-direction and (y/K) 
 * steps in the y-direction.
 */

void solve() {
    int x, y, K;
    if (!(cin >> x >> y >> K)) return;
    
    // Check if both coordinates are divisible by K
    // We use absolute values to handle negative coordinates correctly
    if (abs(x) % K == 0 && abs(y) % K == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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