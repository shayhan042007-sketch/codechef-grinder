# [Blue and Black Pens (BLUEBLACK)](https://www.codechef.com/problems/BLUEBLACK)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine the minimum cost to acquire a specific set of pens. We are given the cost of a single blue pen ($A$) and a single black pen ($B$). We need to find the cheapest way to obtain the equivalent of 3 blue pens, given that a black pen can be substituted for two blue pens (or, more simply, the problem implies a trade-off between buying individual blue pens versus a combination).

*Note: Based on the logic provided in the solution, the goal is to compare the cost of buying 3 blue pens ($3 \times A$) versus buying 1 blue pen and 1 black pen ($A + B$).*

## Intuition & Mathematical Observation
The problem presents two distinct strategies to satisfy the requirement:

1.  **Strategy 1 (All Blue):** Purchase 3 individual blue pens. The total cost is $3 \times A$.
2.  **Strategy 2 (Mixed):** Purchase 1 blue pen and 1 black pen. The total cost is $A + B$.

By comparing these two values using the `std::min` function, we can identify the most cost-effective approach. The logic holds because we are essentially comparing the cost of "3 units of blue" against a "bundle" of "1 blue + 1 black."

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution performs a constant number of arithmetic operations and a single comparison, regardless of the input size.
- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory to store the two integer variables and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B;
    // Read the costs of blue (A) and black (B) pens
    if (!(std::cin >> A >> B)) return 0;

    // Option 1: Buy 3 blue pens
    int option1 = 3 * A;
    
    // Option 2: Buy 1 blue pen and 1 black pen
    int option2 = A + B;

    // Output the minimum of the two options
    std::cout << std::min(option1, option2) << std::endl;

    return 0;
}
```