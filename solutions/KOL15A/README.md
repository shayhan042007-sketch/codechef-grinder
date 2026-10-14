# [Processing a string (KOL15A)](https://www.codechef.com/problems/KOL15A)

- **Difficulty Rating**: 1125
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a string $S$ consisting of both uppercase English alphabets and digits (0-9), the task is to calculate the sum of all the individual digits present in the string.

## Intuition & Mathematical Observation
The core of the problem lies in identifying which characters in the string are numeric digits. 
1. **Character Encoding**: In C++, characters are represented by their ASCII values. The digits '0' through '9' are stored in contiguous memory locations.
2. **Identification**: We can iterate through each character $c$ of the string and check if it falls within the range `['0', '9']`.
3. **Conversion**: To convert a character digit to its actual integer value, we subtract the ASCII value of '0' from the character: `int value = c - '0'`. For example, if $c = '5'$, its ASCII value is 53 and '0' is 48; $53 - 48 = 5$.
4. **Accumulation**: We maintain a running sum variable and add the integer value of every identified digit to it.

## Complexity Analysis
- **Time Complexity**: $O(T \times |S|)$, where $T$ is the number of test cases and $|S|$ is the length of the string. We perform a single pass over each string.
- **Space Complexity**: $O(|S|)$ to store the input string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

/**
 * Problem: KOL15A - Processing a string
 * Approach: Iterate through the string, check if each character is a digit using 
 * the ASCII range '0'-'9', convert to integer, and accumulate the sum.
 * Time Complexity: O(T * |S|)
 * Space Complexity: O(|S|)
 */

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    long long sum = 0;
    for (char c : s) {
        // Check if character is a digit '0'-'9'
        if (c >= '0' && c <= '9') {
            // Convert char digit to its integer value
            sum += (c - '0');
        }
    }
    cout << sum << "\n";
}

int main() {
    // Optimize I/O operations
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