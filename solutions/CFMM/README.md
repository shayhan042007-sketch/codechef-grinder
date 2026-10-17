# [Making a Meal (CFMM)](https://www.codechef.com/problems/CFMM)

- **Difficulty Rating**: 1214
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ strings, we need to determine the maximum number of times the word **"codechef"** can be formed using the characters available across all the given strings. Each character from the input strings can be used only once.

## Intuition & Mathematical Observation
To form the word "codechef", we require a specific frequency of characters:
- **c**: 2
- **o**: 1
- **d**: 1
- **e**: 2
- **h**: 1
- **f**: 1

The total number of "codechef" strings we can form is constrained by the character that runs out first. By calculating the total frequency of each required character across all input strings and dividing by the frequency required for a single "codechef", we find the limiting factor:

$$\text{meals} = \min\left( \left\lfloor\frac{\text{count}(c)}{2}\right\rfloor, \text{count}(o), \text{count}(d), \left\lfloor\frac{\text{count}(e)}{2}\right\rfloor, \text{count}(h), \text{count}(f) \right)$$

## Complexity Analysis
- **Time Complexity**: $O(S)$, where $S$ is the total number of characters across all $N$ strings. We iterate through each character exactly once to populate the frequency map.
- **Space Complexity**: $O(1)$ (or $O(\Sigma)$ where $\Sigma$ is the alphabet size). Since we only store counts for 26 lowercase English letters, the space used by the map/array is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the string "codechef", we need the following counts of characters:
 * c: 2, o: 1, d: 1, e: 2, h: 1, f: 1
 * 
 * We count the total occurrences of each character across all input strings.
 * The maximum number of "codechef" meals is determined by the limiting character.
 */

void solve() {
    int n;
    cin >> n;
    
    map<char, int> counts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            counts[c]++;
        }
    }
    
    // Calculate how many times we can satisfy each character requirement
    int c_meals = counts['c'] / 2;
    int o_meals = counts['o'] / 1;
    int d_meals = counts['d'] / 1;
    int e_meals = counts['e'] / 2;
    int h_meals = counts['h'] / 1;
    int f_meals = counts['f'] / 1;
    
    // The answer is the minimum of these values
    int ans = min({c_meals, o_meals, d_meals, e_meals, h_meals, f_meals});
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```