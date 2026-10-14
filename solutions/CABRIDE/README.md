# [Cab Rides (CABRIDE)](https://www.codechef.com/problems/CABRIDE)

- **Difficulty Rating**: 945
- **Solved in**: 1 attempt(s)

## Problem Summary
We need to transport $N$ people using cabs that can hold a maximum of 4 people. The cost for a cab carrying $X$ people is defined as $\max(200, 100 \times X)$. We want to minimize the total cost to transport all $N$ people.

## Intuition & Mathematical Observation
First, let's calculate the cost for different numbers of people in a single cab:
- **1 person**: $\max(200, 100) = 200$
- **2 people**: $\max(200, 200) = 200$
- **3 people**: $\max(200, 300) = 300$
- **4 people**: $\max(200, 400) = 400$

**Key Observation:**
The cost per person is 100 for 2, 3, or 4 people, but 200 for 1 person. Therefore, we should avoid having a cab with only 1 person if possible.

- If $N \pmod 4 = 0$: We use $N/4$ cabs of 4 people. Total cost: $(N/4) \times 400$.
- If $N \pmod 4 = 2$: We use $N/4$ cabs of 4 people and one cab of 2 people. Total cost: $(N/4) \times 400 + 200$.
- If $N \pmod 4 = 3$: We use $N/4$ cabs of 4 people and one cab of 3 people. Total cost: $(N/4) \times 400 + 300$.
- If $N \pmod 4 = 1$: If we have at least one cab of 4, we can take one person out to form a group of 3 and a group of 2 (cost $300 + 200 = 500$ instead of $400 + 200 = 600$). If $N=1$, the cost is simply 200.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. Total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize cost, we avoid cabs with only 1 person.
 * We prioritize filling cabs with 4 people, then handle the remainder.
 */

void solve() {
    int N;
    cin >> N;
    
    int cost = 0;
    int full_cabs = N / 4;
    int remainder = N % 4;
    
    cost += full_cabs * 400;
    
    if (remainder == 1) {
        if (full_cabs > 0) {
            // Instead of (400 + 200), use (300 + 200)
            cost = (full_cabs - 1) * 400 + 500;
        } else {
            cost = 200;
        }
    } else if (remainder == 2) {
        cost += 200;
    } else if (remainder == 3) {
        cost += 300;
    }
    
    cout << cost << "\n";
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