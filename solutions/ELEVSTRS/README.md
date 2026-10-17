# [From heaven to earth (ELEVSTRS)](https://www.codechef.com/problems/ELEVSTRS)

- **Difficulty Rating**: 1066
- **Solved in**: 1 attempt(s)

## Problem Summary
You are at the ground floor of a building with $N$ floors. You need to reach the $N$-th floor. You have two options:
1. **Stairs**: You walk up the stairs. The distance covered is the diagonal of the building's height, which is $N \times \sqrt{2}$. Your speed is $V_1$.
2. **Elevator**: The elevator starts at the ground floor, travels to the $N$-th floor, and then returns to the ground floor (though you only care about the time to reach the $N$-th floor). The distance covered is $N$ (up) + $N$ (down) = $2N$. Your speed is $V_2$.

Determine which option is faster.

## Intuition & Mathematical Observation
To determine the faster option, we compare the time taken for both:
*   $Time_{stairs} = \frac{N\sqrt{2}}{V_1}$
*   $Time_{elevator} = \frac{2N}{V_2}$

We want to check if $Time_{elevator} < Time_{stairs}$:
$$\frac{2N}{V_2} < \frac{N\sqrt{2}}{V_1}$$

Since $N > 0$, we can divide both sides by $N$:
$$\frac{2}{V_2} < \frac{\sqrt{2}}{V_1}$$

Rearranging the inequality:
$$2V_1 < V_2\sqrt{2}$$

To avoid floating-point precision issues, we square both sides:
$$4V_1^2 < 2V_2^2$$
$$2V_1^2 < V_2^2$$

*   If $V_2^2 > 2V_1^2$, the **Elevator** is faster.
*   Otherwise, the **Stairs** are faster (or equal).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We compare the time taken by stairs vs elevator.
 * Time_stairs = (N * sqrt(2)) / V1
 * Time_elevator = (2 * N) / V2
 * 
 * By simplifying the inequality (2 * N) / V2 < (N * sqrt(2)) / V1,
 * we derive: 2 * V1^2 < V2^2
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, v1, v2;
        cin >> n >> v1 >> v2;

        // Using the derived inequality: 2 * v1^2 < v2^2
        // If this holds, the elevator is faster.
        long long stairs_val = 2 * v1 * v1;
        long long elevator_val = v2 * v2;

        if (elevator_val > stairs_val) {
            cout << "Elevator" << "\n";
        } else {
            cout << "Stairs" << "\n";
        }
    }

    return 0;
}
```