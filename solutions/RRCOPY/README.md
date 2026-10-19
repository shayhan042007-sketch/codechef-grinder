# [Copy-Paste (RRCOPY)](https://www.codechef.com/problems/RRCOPY)

- **Difficulty Rating**: 1280
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we are allowed to perform a "copy-paste" operation: select any contiguous subsequence of the current array and insert it anywhere else in the array. We want to find the minimum size of an initial array such that we can generate the target array $A$ using any number of copy-paste operations.

## Intuition & Mathematical Observation
The core of the problem lies in realizing that the copy-paste operation allows us to duplicate any existing subsequence. If we start with an array containing all the **distinct** elements present in $A$, we can simply copy and paste the necessary elements to form the final array $A$. 

Since we cannot create new values that aren't already in our initial array, the initial array must contain at least one instance of every unique number found in $A$. Conversely, if we have all unique elements, we can construct any sequence by repeatedly copying the required elements into their correct positions. Therefore, the minimum size of the initial array is exactly the count of unique elements in $A$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the insertion of $N$ elements into a `std::set`. Given $N \le 10^5$, this fits comfortably within the 2-second time limit.
- **Space Complexity**: $O(N)$ to store the unique elements in the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "Copy-Paste" operation allows us to take any contiguous subsequence and 
 * insert it anywhere. This means if we have a set of unique elements present 
 * in the final array A, we can always start with an initial array containing 
 * exactly those unique elements in any order. 
 * 
 * Since we want the minimal size of the initial array, and we must be able 
 * to generate every element present in A, the smallest possible initial 
 * array must contain every unique element of A exactly once.
 * 
 * Thus, the answer is simply the number of distinct elements in the array A.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a set to count unique elements
    set<int> unique_elements;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        unique_elements.insert(val);
    }
    
    // The size of the set represents the number of distinct elements
    cout << unique_elements.size() << "\n";
}

int main() {
    // Fast I/O for performance
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