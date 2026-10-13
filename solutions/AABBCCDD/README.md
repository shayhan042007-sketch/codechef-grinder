# [AabBcCDd (AABBCCDD)](https://www.codechef.com/problems/AABBCCDD)

- **Difficulty Rating**: 972
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ containing both uppercase and lowercase English letters, we are allowed two operations:
1. Convert any uppercase letter to its lowercase equivalent.
2. Choose exactly one lowercase letter and merge all its occurrences into another lowercase letter.

The goal is to maximize the frequency of a single character after performing these operations.

## Intuition & Mathematical Observation
1. **Normalization**: Since we can convert any uppercase letter to lowercase, we should treat 'A' and 'a' as the same character. We can count the total occurrences of each letter (ignoring case) by mapping both 'A' and 'a' to the index 0, 'B' and 'b' to index 1, and so on.
2. **Merging Strategy**: We are allowed to pick one character and add its entire count to another character. To maximize the final count of a single character, we should identify the character that already has the highest frequency (`max1`) and the character that has the second-highest frequency (`max2`).
3. **Optimization**: By merging the character with the second-highest frequency into the character with the highest frequency, we achieve the maximum possible count for any single character in the string. The result is simply `max1 + max2`.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies and then iterate through the fixed-size alphabet array (size 26) to find the two largest values.
- **Space Complexity**: $O(1)$, as we only use a fixed-size array of 26 integers to store the character frequencies, regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Convert all uppercase letters to lowercase to normalize counts.
 * 2. Count the frequency of each letter (a-z).
 * 3. To maximize the score, merge the character with the second-highest 
 *    frequency into the character with the highest frequency.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Frequency array for 26 letters
    vector<int> freq(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else {
            freq[c - 'a']++;
        }
    }

    // Find the two largest frequencies
    int max1 = 0, max2 = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > max1) {
            max2 = max1;
            max1 = freq[i];
        } else if (freq[i] > max2) {
            max2 = freq[i];
        }
    }

    // The result is the sum of the two largest frequencies
    cout << max1 + max2 << "\n";
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