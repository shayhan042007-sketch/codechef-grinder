# [Bus Seating (BUSSEAT)](https://www.codechef.com/problems/BUSSEAT)

- **Difficulty Rating**: 640
- **Solved in**: 1 attempt(s)

## Problem Summary
In a bus with $N$ rows, each containing 2 seats, passengers board one by one. The seating strategy is as follows:
1. Passengers prefer to occupy an empty row first.
2. If no empty rows are available, they will sit in a row that already has one person.

We need to calculate the total number of people who end up sitting next to someone else after $K$ passengers have boarded.

## Intuition & Mathematical Observation
The problem can be broken down into two phases based on the number of passengers $K$ relative to the number of rows $N$:

1. **Phase 1 ($K \le N$):** 
   Every passenger can choose an empty row. Since each passenger occupies their own row, no one is sitting next to anyone else. The result is **0**.

2. **Phase 2 ($K > N$):** 
   - The first $N$ passengers occupy one seat in each of the $N$ rows. At this point, every row has exactly one person.
   - The remaining $(K - N)$ passengers must sit in a row that already contains one person.
   - When one of these $(K - N)$ passengers sits in a row, they join the person already there. This results in **2** people sitting next to someone (the person who was already there and the new arrival).
   - Therefore, the total number of people sitting next to someone is $(K - N) \times 2$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * Strategy:
 * 1. People prefer to sit in an empty row.
 * 2. If no empty row is available, they sit next to someone.
 * 
 * If K <= N:
 * Each person takes one row. No one sits next to anyone. Result = 0.
 * 
 * If K > N:
 * The first N people will each take one row.
 * The remaining (K - N) people must sit in a row that already has 1 person.
 * Each of these (K - N) people makes 2 people "sitting next to somebody".
 * Total = (K - N) * 2.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            cout << 0 << "\n";
        } else {
            // The first n people occupy one seat in each of the n rows.
            // The remaining (k - n) people sit in rows that already have 1 person.
            // Each of these (k - n) people joins an existing person, 
            // meaning 2 people per join are now sitting next to someone.
            cout << (k - n) * 2 << "\n";
        }
    }

    return 0;
}
```