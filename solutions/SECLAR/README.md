# [Find Second Largest (SECLAR)](https://www.codechef.com/problems/SECLAR)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to accept three distinct integers as input, each provided on a separate line, and determine which of the three is the second largest.

## Intuition & Mathematical Observation
Since we are only dealing with three integers, the most straightforward and robust approach is to store them in a collection (like a `std::vector` or an array) and sort them in ascending order. 

Once sorted, the elements are arranged such that:
- `v[0]` is the smallest.
- `v[1]` is the **second largest**.
- `v[2]` is the largest.

By sorting, we eliminate the need for complex `if-else` conditional logic to compare the numbers manually, making the code cleaner and less prone to logical errors.

## Complexity Analysis
- **Time Complexity**: $O(1)$. Sorting a fixed-size array of 3 elements takes constant time.
- **Space Complexity**: $O(1)$. We only use a fixed amount of memory to store the three integers.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Find Second Largest
 * Approach: Read three integers from three separate lines, store in a vector,
 * sort, and output the middle element.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    
    // Reading the three integers from three separate lines
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;
    if (!(cin >> c)) return 0;

    // Store elements in a vector
    vector<long long> v = {a, b, c};
    
    // Sorting the vector to easily identify the second largest
    sort(v.begin(), v.end());
    
    // The second largest element will be at index 1 after sorting
    cout << v[1] << endl;

    return 0;
}
```