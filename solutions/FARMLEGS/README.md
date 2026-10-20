# [Legs on a Farm (FARMLEGS)](https://www.codechef.com/problems/FARMLEGS)

- **Difficulty Rating**: 709
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the total number of legs $N$ on a farm consisting of cows (4 legs each) and chickens (2 legs each), find the minimum number of animals required to account for exactly $N$ legs.

## Intuition & Mathematical Observation
Let $C$ be the number of cows and $H$ be the number of chickens. We are given the constraint:
$$4C + 2H = N$$

We want to minimize the total number of animals $A = C + H$. 
From the constraint, we can express $H$ in terms of $C$:
$$2H = N - 4C \implies H = \frac{N}{2} - 2C$$

Substituting this into the equation for $A$:
$$A = C + \left(\frac{N}{2} - 2C\right) = \frac{N}{2} - C$$

To minimize $A$, we must **maximize $C$**. Since $H$ cannot be negative ($H \ge 0$), we have:
$$\frac{N}{2} - 2C \ge 0 \implies 2C \le \frac{N}{2} \implies C \le \frac{N}{4}$$

Thus, the maximum number of cows is $\lfloor N/4 \rfloor$. By prioritizing cows (the animals with more legs), we reduce the total count of animals needed to reach the target $N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize the total number of animals (C + H) for a fixed number of legs N,
 * we should maximize the number of animals with the most legs (cows).
 * 
 * Each cow has 4 legs, each chicken has 2.
 * Max cows = N / 4.
 * Remaining legs = N % 4.
 * If remainder is 2, we add 1 chicken. If 0, we add 0 chickens.
 * 
 * Simplified formula:
 * Total animals = (N / 4) + ((N % 4) / 2)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate maximum cows possible
        long long max_cows = n / 4;
        
        // Calculate remaining legs and add chickens if necessary
        long long remaining_legs = n % 4;
        long long chickens = remaining_legs / 2;
        
        cout << max_cows + chickens << "\n";
    }

    return 0;
}
```